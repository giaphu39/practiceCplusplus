/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
void insertionSort_sort_decending(int* a, int n){
    for(int i = 1; i< n; i++){
        int temp = a[i];
        int j;
        for(j = i - 1 ; j > -1; j--){ // chỗ này kiến code có lúc chạy được có lúc không
            if(a[j] > temp){
                break;
            }
            a[j + 1] = a[j];
        }
        // a[j] = temp; // gán sai vị trí
        a[j+1] = temp;
    }
    
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertionSort_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}
