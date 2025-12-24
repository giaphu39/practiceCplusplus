#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

void parse(char* input, char** args){
    int i=0;
    char* temp = strtok(input, " "); // lấy token đầu tiên của chuỗi input theo " "
    while(temp){
        args[i++] = temp;
        temp = strtok(NULL, " "); // NULL là lấy chuỗi cũ vị trí bắt đầu tiếp theo sau lần trước
    }
    args[i] = NULL; // biến cuối là NULL để biết báo hiệu kết thúc
}


int main(void)
{   
    char input[MAX_LINE];
    char *args[MAX_LINE / 2 + 1]; /* command line arguments */
    int should_run = 1;           /* flag to determine when to exit
              program */
    while (should_run)
    {
        printf("it007sh>");
        fflush(stdout);
        /**
        Do something
        */
        if (!fgets(input, MAX_LINE, stdin)) continue; // đọc dữ liệu vào input
        input[strcspn(input, "\n")] = 0; //Tìm vị trí đầu tiên của ký tự '\n' trong chuỗi input
        // xóa kí tự xuống dòng vì có thể gây lỗi nếu điền hàm
        if (strcmp(input, "") == 0) continue; // nhập rỗng thì nhập lại

        parse(input, args);
        
        if (args[0] == NULL) continue;

        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            exit(1);
        }

        waitpid(pid, NULL, 0);
    }
    return 0;
}