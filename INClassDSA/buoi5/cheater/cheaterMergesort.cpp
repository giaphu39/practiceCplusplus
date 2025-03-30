#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
#define min(x,y) (x > y) ? y : x
int B[MAX], C[MAX];

// int N = 7;
int N;

void Output(int A[], int N) {
    for (int i = 0; i < N; i++)
        cout<< A[i]<< " ";
           cout<<endl;
}

void Merge(int A[], int nB, int nC, int k) {
	int p,pb,pc,ib,ic;
	p=pb=pc=ib=ic=0;
	int kb=min(k, nB), kc=min(k, nC); // k là số phần tử tối đa, nB nhỏ hơn khi mà không lấy hết tới k, thường là nC nhỏ hơn k
	// dòng này tính số phần tử mỗi lần merge của mảng 
	// nB và nC mới là phần tử tối đa
	while ((nB > 0) && (nC > 0)) {

		if (B[pb+ib] >= C[pc+ic]) { // giamr daanf
		// if (B[pb+ib] <= C[pc+ic]) {
			A[p++]=B[pb+ib]; ib++;
			if (ib == kb) { // nghĩa là vị trí chọn = số phần tử tối đa -> lấy hết phần tử
				for (; ic<kc; ic++) A[p++] = C[pc+ic]; // lấy hết các phần tử còn lại của mảng còn lại
				pb+=kb;pc+=kc; ib=ic=0;nB-=kb;nC-=kc; // cập nhật cho lần j merge k phần tử tiếp theo
				kb = min(k, nB); kc = min(k, nC);
            }
		}
		else {
			A[p++]=C[pc+ic]; ic++;
			if (ic == kc) {
				for (; ib<kb; ib++) A[p++] = B[pb+ib];
				pb+=kb;pc+=kc; ib=ic=0;nB-=kb;nC-=kc;
				kb = min(k, nB); kc = min(k, nC);
            }
		}
    }

	// ✅ Đảm bảo các phần tử còn lại của B hoặc C đều được đưa vào A
	for (; pb < nB; pb++) A[p++] = B[pb];
	for (; pc < nC; pc++) A[p++] = C[pc];

	cout << "Array A: ";
	Output(A, N);
}

void MergeSort(int A[], int n)
{
	int p, pb, pc, i, k = 1;
	while (k < n) {
		p = pb = pc = 0;
		while (p < n) { // p dùng để trỏ từng cặp có k phần tử
			for (i=0; (p<n) && (i<k); i++) B[pb++]=A[p++];
			for (i=0; (p<n) && (i<k); i++) C[pc++]=A[p++];
        }
		cout << "K=" << k << ": " << endl;
		cout << "Array B: "; Output(B, pb); 
		cout << "Array C: "; Output(C, pc); 
        Merge(A, pb, pc, k); 
        k *= 2;
    }
}

int main() {
	cin>>N;
    int A[]={81, 9, 23, 17, 4, 50};
    MergeSort(A,N);
    cout << "Final: "; Output(A,N);
    return 0;
}