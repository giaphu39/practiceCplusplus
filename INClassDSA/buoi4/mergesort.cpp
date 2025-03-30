
#include<iostream>
using namespace std;

#define min(x,y) (x > y ? y : x)
#define IMAX 1000

int B[IMAX], C[IMAX];
void Input(int *v, int& n)
{
	int tmp;
	cin >> tmp;
    int i=0;
	while (tmp >= 0) {
		v[i++] = tmp;
        cin>>tmp;
	}
    n = i ;
}
void Merge(int A[], int nB, int nC, int k) {
    int p = 0, pb = 0, pc = 0, ib = 0, ic = 0;
    int kb = min(k, nB), kc = min(k, nC);
    while ((nB > 0) && (nC > 0)) {
        if (B[pb + ib] <= C[pc + ic]) {
            A[p++] = B[pb + ib]; ib++;
            if (ib == kb) {
                pb += kb; nB -= kb; ib = 0; kb = min(k, nB);
            }
        } else {
            A[p++] = C[pc + ic]; ic++;
            if (ic == kc) {
                pc += kc; nC -= kc; ic = 0; kc = min(k, nC);
            }
        }
    }
    while (ib < kb) A[p++] = B[pb + ib++];
    while (ic < kc) A[p++] = C[pc + ic++];
}

void MergeSort(int A[], int n, int k) {
    int p, pb, pc, i;
    while (k < n) {
        p = pb = pc = 0;
        while (p < n) {
            if (pb < n) {
                for (i = 0; (i < k) && (pb + i < n); i++) B[pb + i] = A[pb + i];
            }
            pb += k;
            if (pc < n) {
                for (i = 0; (i < k) && (pc + i < n); i++) C[pc + i] = A[pc + i];
            }
            pc += k;
            Merge(A + p, min(k, n - p), min(k, n - (p + k)), k);
            p += 2 * k;
        }
        k *= 2;
    }
}

void Output(int *v,const int& n)
{
	for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int A[100];
    int n;
	Input(A,n);

    MergeSort(A,n,1);
    Output(A,n);
    return 0;
}


#include <iostream>
using namespace std;

#define min(x, y) ((x) > (y) ? (y) : (x))
#define IMAX 1000

int B[IMAX], C[IMAX];

void Input(int *v, int &n) {
    int tmp, i = 0;
    cin >> tmp;
    while (tmp >= 0) {
        v[i++] = tmp;
        cin >> tmp;
    }
    n = i; // Sửa lỗi cập nhật n
}

void Merge(int A[], int nB, int nC, int k) {
    int p = 0, ib = 0, ic = 0; // p: vị trí ghi vào A[], ib: vị trí trong B[], ic: vị trí trong C[]
    
    // Trộn hai mảng con B[] và C[] vào A[] theo thứ tự tăng dần
    while (ib < nB && ic < nC) { // Khi cả hai mảng còn phần tử  // nghiên cứu đổi dảo ngược sort

        // đổi chỗ này lại
        if (B[ib] <= C[ic]) {    // Nếu phần tử ở B nhỏ hơn hoặc bằng phần tử ở C
            A[p++] = B[ib++];    // Chép phần tử từ B vào A, tăng chỉ số ib
        } else {
            A[p++] = C[ic++];    // Chép phần tử từ C vào A, tăng chỉ số ic
        }
    }

    // Chép các phần tử còn lại của B vào A (nếu còn)
    while (ib < nB) {
        A[p++] = B[ib++];
    }

    // Chép các phần tử còn lại của C vào A (nếu còn)
    while (ic < nC) {
        A[p++] = C[ic++];
    }
}

void MergeSort(int A[], int n, int k) {
    // k là để chỉ lấy bao nhiêu phần tử 
    // 

    while (k < n) { // Bước tăng dần kích thước đoạn con từ k = 1, 2, 4, 8, ...
        int p = 0; // Con trỏ bắt đầu của mỗi cặp đoạn con
        
        while (p < n) { // Lặp qua từng cặp đoạn con trong mảng
            int nB = min(k, n - p);     // Số phần tử của đoạn B (tối đa k phần tử)
            // n - p là tính số phần tử  còn lại trong trường hợp mảng B các phần tử còn lại không đủ k

            int nC = min(k, n - (p + k)); // Số phần tử của đoạn C (tối đa k phần tử)
            // n - (p + K) là số phần tử còn lại khi lấy đoạn B ra ( luôn lấy đoạn B đủ số k ra trước)

            // Sao chép phần tử từ A[] sang B[] và C[]
            for (int i = 0; i < nB; i++) B[i] = A[p + i]; 
            for (int i = 0; i < nC; i++) C[i] = A[p + k + i];

            // Trộn hai đoạn con đã sắp xếp vào lại A[]
            // nghĩa là lấy ra các phân tử theo thứ tự của A rồi xếp lại nó luôn
            Merge(A + p, nB, nC, k); 

            p += 2 * k; // Chuyển đến cặp tiếp theo là xét cho hết các phần tử trong dãy
            // vì k là số phần tử lấy của mỗi mảng nên *2

        }
        k *= 2; // Tăng gấp đôi kích thước đoạn con
    }
}


void Output(int *v, const int &n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int A[IMAX], n;
    Input(A, n);

    MergeSort(A, n, 1);
    Output(A, n);
    
    return 0;
}
