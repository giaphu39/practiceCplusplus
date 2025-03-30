/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
// int temp[100];
// void  merge(int* input,int from,int middle,int to){
//     // int n1 = middle - from + 1; // số lượng phần tử mảng left
//     // int n2=  to - middle;
//     //cách 1 tạo 2 mảng L và R

//     //cách 2 tạo 1 mảng lưu giá trị đổi sau đó gán lại input
//     // int n = to - from;

//     // int i=0; // không nên
//     int i=from;
//     int indexL = from;
//     int indexR = middle + 1;

//     while(indexL <= middle && indexR <= to){
//         if(input[indexL] < input[indexR]){
//             temp[i++] = input[indexL++];
//         }
//         else{
//             temp[i++] = input[indexR++];
//         }
//     }
//     while(indexL <= middle){
//         temp[i++] = input[indexL++];
//     }
//     while(indexR <= to){
//         temp[i++] = input[indexR++];
//     }

//     for(int j = from; j <= to ; j++){
//         input[j] = temp[j];
//     }

    

// }

// void merge(int input[], int from, int middle, int to) {
//     int i = from, j = middle + 1;

//     while (i < j && j <= to) {
//         if (input[i] <= input[j]) {
//             i++;
//         } else {
//             int temp = input[j];

//             // Dịch các phần tử từ i -> j-1 sang phải
//             for (int k = j; k > i; k--) {
//                 input[k] = input[k - 1];
//             }

//             input[i] = temp; // Đặt phần tử nhỏ nhất vào đúng chỗ
//             i++;
//             j++;
//         }
//     }
// }


void merge(int input[], int from, int middle, int to) {
    int n1 = middle - from + 1;
    int n2 = to - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = input[from + i];
    for (int j = 0; j < n2; j++)
        R[j] = input[middle + 1 + j];

    int i = 0, j = 0, k = from;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            input[k++] = L[i++];
        else
            input[k++] = R[j++];
    }

    while (i < n1)
        input[k++] = L[i++];
    while (j < n2)
        input[k++] = R[j++];
}


void mergeSortRange(int input[], int from, int to) {
    if (from < to) { // chi nhỏ nhất cho đến khi còn 1 phần tử
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n) {
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
