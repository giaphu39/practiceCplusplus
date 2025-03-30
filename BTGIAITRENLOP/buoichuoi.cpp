// // // #include<iostream>
// // // using namespace std;
// // // #define MAX 100
// // // #include<stdio.h>

// // // void input(char* str){
// // //     str= (char*)calloc(sizeof(char),MAX);
// // //     str=fgets(str,MAX,stdin);
// // //     cout<<"da nhap"<<endl;
// // // }
// // // char* input1(char* str){
// // //     str= (char*)calloc(sizeof(char),MAX);
// // //     str=fgets(str,MAX,stdin);
// // //     cout<<"da nhap"<<endl;
// // //     return str;
// // // }
// // // void output(char str[]){
// // //     cout<<str<<endl;
// // //     cout<<"đã in";
// // // }
// // // int main(){
// // //     char* str;
// // //     input1(str);
// // //     output(str);
// // //     return 0;
// // // }


// // // Online C++ compiler to run C++ program online
// // #include <iostream>
// // using namespace std;
// // #include <stdio.h>
// // #define MAX 100
// // // void Input(char* &str){
// // void Input(char* str[]){
// //     *str = (char*)calloc(sizeof(char),MAX);
// //     *str = fgets(*str,MAX,stdin);
// //     // cout<<"In Input Function"<<str<<endl;
// // }
// // void Output(char str[]){
// //     cout<<str;
// //     cout<<"In Output Function"<<str<<endl;
// // }
// // int main() {
// //     // char* str;
// //     // Input(&str);
// //     // Output(str);
// //     return 0;
// // }

// #include<iostream>
// using namespace std;
// #define MAX 100

// void input(int** a,int* m, int* n){
//     cin>>*m>>*n;
//     // A=calloc()
//     a=(int**)calloc(sizeof(int),m*n);
//     // for(int i=0;i<*m;i++){
//     //     a=calloc(sizeof(int),j)

//     // }
// }
// void output(int** a,int m, int n){
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<a[i][j]<<" ";
//         }
//     }
// }
// int main(){
//     int** a,m,n; // a thành con trỏ bên trong cin dùng malloc
//     input(&a,&m,&n);
//     output(&a,m,n);
// }
#include <iostream>
#include <cstdlib> // cho calloc
using namespace std;
#define MAX 100

// Hàm nhập ma trận 2 chiều
void input(int*** a, int* m, int* n) {
    // Nhập số hàng và số cột
    cin >> *m >> *n;

    // Cấp phát bộ nhớ cho các hàng
    *a = (int**)calloc(*m, sizeof(int*));
    for (int i = 0; i < *m; i++) {
        // Cấp phát bộ nhớ cho các cột trong mỗi hàng
        (*a)[i] = (int*)calloc(*n, sizeof(int));
    }

    // Nhập các phần tử
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            cin >> (*a)[i][j];
        }
    }
}

// Hàm xuất ma trận 2 chiều
void output(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int** a; // Ma trận 2 chiều
    int m, n; // Kích thước

    // Nhập ma trận
    input(&a, &m, &n);

    // Xuất ma trận
    output(a, m, n);

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < m; i++) {
        free(a[i]); // Giải phóng từng hàng
    }
    free(a); // Giải phóng con trỏ hàng

    return 0;
}
