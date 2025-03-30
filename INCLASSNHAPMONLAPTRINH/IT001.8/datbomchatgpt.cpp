#include <iostream>
using namespace std;

const int SIZE = 4;

int density_map[SIZE][SIZE];
int bomb_map[SIZE][SIZE];

// Đếm số lượng bom xung quanh ô (i, j) trong bản đồ bom
int countBombsAround(int i, int j) {
    int count = 0;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && (di != 0 || dj != 0)) {
                count += bomb_map[ni][nj];
            }
        }
    }
    return count;
}

// Kiểm tra tính hợp lệ của bản đồ bom hiện tại so với bản đồ mật độ
bool isValid() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (countBombsAround(i, j) != density_map[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Hàm quay lui để thử các cách đặt bom
bool placeBombs(int row, int col) {
    // Nếu đã hết các hàng, kiểm tra nếu bản đồ thỏa mãn yêu cầu
    if (row == SIZE) {
        return isValid();
    }

    // Chuyển sang cột tiếp theo hoặc dòng tiếp theo nếu hết cột
    int nextRow = (col == SIZE - 1) ? row + 1 : row;
    int nextCol = (col == SIZE - 1) ? 0 : col + 1;

    // Thử không đặt bom tại ô (row, col)
    if (placeBombs(nextRow, nextCol)) return true;

    // Thử đặt bom tại ô (row, col)
    bomb_map[row][col] = 1;
    if (placeBombs(nextRow, nextCol)) return true;

    // Quay lui: bỏ bom ra khỏi ô (row, col)
    bomb_map[row][col] = 0;

    return false;
}

int main() {
    cout << "Nhập bản đồ mật độ (4x4):\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> density_map[i][j];
            bomb_map[i][j] = 0;  // Khởi tạo bản đồ bom với giá trị 0 (không có bom)
        }
    }

    // Gọi hàm quay lui để đặt bom
    if (placeBombs(0, 0)) {
        cout << "Bản đồ bom tương ứng:\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << bomb_map[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "Không tìm được bản đồ bom hợp lệ.\n";
    }

    return 0;
}



// Khai báo mảng 2 chiều matdo và arr, kích thước 4x4.

// Hàm nhapmatdo():
//     - Nhập dữ liệu cho mảng matdo từ đầu vào (mật độ bom xung quanh mỗi ô).

// Hàm cauhinhdau():
//     - Khởi tạo mảng arr toàn là 0 (không có bom ban đầu).

// Hàm ketqua():
//     - In cấu hình hiện tại của mảng arr.

// Hàm dembomxungquanh(dong, cot):
//     - Đếm số lượng bom xung quanh một ô tại vị trí (dong, cot) trong mảng arr.
//     - Kiểm tra 8 ô xung quanh (dong, cot) để xem có bom hay không:
//         - Nếu vị trí nằm trong phạm vi mảng và có bom (arr[di][dj] == 1), tăng biến đếm `count`.
//     - Trả về tổng số bom xung quanh.

// Hàm trungkhop():
//     - Kiểm tra xem cấu hình bom trong mảng arr có khớp với mật độ yêu cầu trong matdo không.
//     - Với mỗi ô trong arr, nếu số lượng bom xung quanh (tính từ hàm dembomxungquanh) khác với giá trị tương ứng trong matdo, trả về `false`.
//     - Nếu tất cả ô đều khớp, trả về `true`.

// Hàm _try(i, j):
//     - Nếu i == 4 (đã duyệt xong toàn bộ mảng 4x4):
//         - Nếu trungkhop() trả về true, in cấu hình hiện tại bằng hàm ketqua().
//         - Kết thúc hàm (return).
    
//     - Xác định vị trí tiếp theo (nexti, nextj) để duyệt:
//         - Nếu j là cột cuối cùng (j == 3), di chuyển đến hàng tiếp theo bằng cách đặt `nexti = i + 1` và `nextj = 0`.
//         - Ngược lại, giữ nguyên hàng và tăng cột: `nexti = i`, `nextj = j + 1`.
    
//     - Gọi đệ quy `_try(nexti, nextj)` với ô (i, j) không có bom.
//     - Đặt bom tại vị trí (i, j) bằng `arr[i][j] = 1`.
//     - Gọi đệ quy `_try(nexti, nextj)` với ô (i, j) có bom.
//     - Xóa bom (backtracking) bằng cách đặt lại `arr[i][j] = 0`.

// Hàm main():
//     - Gọi nhapmatdo() để nhập mật độ bom từ đầu vào.
//     - Gọi cauhinhdau() để khởi tạo cấu hình ban đầu của mảng arr.
//     - Gọi _try(0, 0) để bắt đầu tìm tất cả các cấu hình bom thỏa mãn yêu cầu trong matdo.
//     - Kết thúc chương trình.
