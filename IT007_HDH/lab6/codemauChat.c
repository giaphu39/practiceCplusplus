/*######################################
# University of Information Technology #
# IT007 Operating System #
#  #
# File: bai.c #
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <termios.h>

#define MAX_LINE 100       /* Maximum length of command */
#define HISTORY_SIZE 100   /* Số lệnh lưu trong lịch sử */

// Lịch sử lệnh, hỗ trợ việc phím lên, xuống
char *history[HISTORY_SIZE];
int history_count = 0;

// Hàm xử lý Ctrl+C (dừng lệnh con, không thoát shell)
void sigint_handler(int sig) {
    printf("\nit007sh> ");
    fflush(stdout);
}

// Hàm thêm lệnh vào lịch sử
void add_history(const char *cmd) {
    if(history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(cmd); // hàm strdup copy value trong arg đưa vào con trỏ mới
    } else { // trường hợp đã đầy kích thước thì giải phóng con trỏ đầu history và dời từng cái về trước sau đó mới gán mới 
        free(history[0]);
        for(int i=1;i<HISTORY_SIZE;i++) history[i-1] = history[i];
        history[HISTORY_SIZE-1] = strdup(cmd);
    }
}

// Hàm hiển thị lệnh từ lịch sử khi nhấn phím lên/ xuống 
void show_history(int index) {
    if(index >= 0 && index < history_count) {
        printf("\rit007sh> %s", history[index]);
        fflush(stdout);
    }
}

// Hàm phân tách lệnh thành argv
void parse_command(char *input, char **args, int *argc) { // args chứa các từ bị phân tách, argc là biến đếm số từ
    *argc = 0;
    char *token = strtok(input, " \t\n"); // tách từ theo khoảng trắng, tab, xuống dòng
    while(token != NULL) {
        args[(*argc)++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[*argc] = NULL;
}

// Thực thi lệnh đơn (hỗ trợ > và <)
void execute_single_command(char **args, int argc) {
    pid_t pid = fork();
    if(pid == 0) {
        // Child process
        for(int i=0;i<argc;i++) {
            if(strcmp(args[i], ">") == 0) {
                //debug
                // printf("Executing: %s\n", args[0]);
                // for(int j=0;j<argc;j++) printf("arg[%d] = %s\n", j, args[j]);

                int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
                if(fd < 0) {
                    perror("open failed");
                    exit(1);
                }
                // O_WRONLY: mở để ghi
                // O_CREAT: nếu chưa tồn tại thì tạo file
                // O_TRUNC: xóa sạch nội dung cũ trước khi ghi mới
                // owner được đọc ghi, group được đọc, others được đọc, không dùng quyền thực thi vì muốn đầu ra là file txt
                dup2(fd, STDOUT_FILENO);
                //stdout trỏ vào file vừa mở
                close(fd);
                //đóng fd để tránh rò rỉ, lỗi
                args[i] = NULL;
                // cắt chỗ > thành NULL để tạo thành 1 định dạng lệnh đúng cho exec
                break;
            }
            if(strcmp(args[i], "<") == 0) {
                int fd = open(args[i+1], O_RDONLY); // O_RDONLY: mở file để đọc
                dup2(fd, STDIN_FILENO); // chuyển luồng stdin sang file này, có hiệu lực trong tiến trình hiện tại, kêt thúc khi tiến trình kết thúc
                close(fd);
                args[i] = NULL;
                break;
            }
        }


        execvp(args[0], args); //Thay thế toàn bộ memory process bằng chương trình mới
        perror("execvp failed"); // nếu dòng trên thực thi không được thì chạy xuống đây và báo lỗi 
        exit(1);
    } else {
        // Parent process
        waitpid(pid, NULL, 0); // tiến trình cha đợi tiến trình con chạy xong hết mới chạy tiếp
    }
}

void execute_multi_pipe(char *input) {
    char *commands[20]; // tối đa 20 commands trong 1 lệnh 
    int cmd_count = 0; // đếm số commands trong input

    char *pipe_pos = strchr(input, '|'); // Tìm | trong input nếu có thì trả về con trỏ tại vị trí đó
    if(!pipe_pos) { // trường hợp không chứa | thì thực thi câu lệnh bình thường
        char *args[MAX_LINE/2 + 1];
        int argc;
        parse_command(input, args, &argc);
        execute_single_command(args, argc);
        return;
    }

    // Tách chuỗi theo '|'
    char *cmd = strtok(input, "|");
    while(cmd != NULL) {
        commands[cmd_count++] = cmd;
        cmd = strtok(NULL, "|");
    }

    // Mỗi command đã nằm trong commands[i]
    int fd[2], in_fd = 0;

    for(int i = 0; i < cmd_count; i++) {
        pipe(fd);  // tạo pipe mới cho từng cặp

        pid_t pid = fork();
        if(pid == 0) {
            dup2(in_fd, STDIN_FILENO);   // input của lệnh hiện tại, đầu tiên = 0 nghĩa là input từ đầu vào
            if(i < cmd_count - 1) {
                dup2(fd[1], STDOUT_FILENO); // output đi qua pipe tiếp theo (nếu không phải lệnh cuối)
            }
            close(fd[0]);
            close(fd[1]);

            char *args[20];
            int argc = 0;
            parse_command(commands[i], args, &argc);

            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        }

        waitpid(pid, NULL, 0);

        close(fd[1]);
        in_fd = fd[0]; // output pipe này → input pipe kế tiếp
    }
}


int main(void) {
    char input[MAX_LINE];
    char *args[MAX_LINE/2 + 1];
    int argc;

    // Bắt Ctrl+C
    signal(SIGINT, sigint_handler);

    // Tắt canonical mode để đọc phím lên xuống và Backspace
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // lấy ra cấu hình hiện tại
    newt = oldt; // sao chép cấu hình cũ
    newt.c_lflag &= ~(ICANON | ECHO); // Tắt chế độ dòng và tắt hiển thị ký tự
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Áp dụng cấu hình mới

    int history_index = -1;
    int should_run = 1;
    while(should_run) {
        printf("it007sh>");
        fflush(stdout);
        int pos = 0;
        memset(input, 0, sizeof(input));

        // Đọc input từng ký tự
        while(1) {
            char c = getchar();
            if(c == '\n') {
                input[pos] = '\0';
                printf("\n");
                break;
            } else if(c == 27) { // escape 
                getchar(); // skip '['
                char arrow = getchar();
                if(arrow == 'A') { // up
                    if(history_count > 0) { //Nếu chưa chọn lịch sử (history_index < 0) → nhảy đến cuối danh sách, nếu không thì giảm vị trí (up)
                        history_index = (history_index < 0) ? history_count - 1 : history_index - 1;
                        if(history_index < 0) history_index = 0; // nếu lịch sử hết thì giữ nguyên
                        printf("\r\033[K");// đưa con trỏ về đầu dòng, xóa tất cả từ con trỏ → hết dòng
                        show_history(history_index);
                        strcpy(input, history[history_index]); //copy trong lịch sử vào input
                        pos = strlen(input);
                    }
                } else if(arrow == 'B') { // down
                    if(history_count > 0) {// 
                        history_index = (history_index < 0) ? 0 : history_index + 1;
                        if(history_index >= history_count) history_index = history_count - 1; // nếu là vị trí cuối trong lịch sử thì dừng vì không có cái nào ở cuối nữa
                        printf("\r\033[K");
                        show_history(history_index);
                        strcpy(input, history[history_index]);
                        pos = strlen(input);
                    }
                }
            } else if(c == 127 || c == 8) { // Backspace
                if(pos > 0) {
                    pos--;
                    input[pos] = '\0';
                    printf("\b \b"); // con trỏ lùi rồi điền space rồi lùi nên nhìn giống đã xóa kí tự
                    fflush(stdout);
                }
            } else {
                input[pos++] = c;
                putchar(c);
                fflush(stdout);
            }
        }

        if(strlen(input) == 0) continue;
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            printf("Exiting shell.\n");
            should_run = 0;
            break; // thoát vòng while(1)
        }



        add_history(input); // bỏ vào lịch sử trước khi thực thi
        history_index = -1;

        execute_multi_pipe(input);
    }

    // Khôi phục terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
