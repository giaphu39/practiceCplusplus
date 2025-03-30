#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  

// void Input(int* a, int& n)
// {

// 	int tmp;
// 	cin >> tmp;
//     int i=0;
// 	while (tmp != -100) {
// 		a[i++]=tmp;
// 		cin >> tmp;
// 	}
//     n=i;
// }

void heapify(int *a, int k, int n) {
	int j = 2*k+1;
	while (j < n) {
			if (j + 1 < n) 
				if (a[j] < a[j + 1]) j = j + 1;
			if (a[k] >= a[j]) return;
			swap(a[k], a[j]); 	
			k = j; j = 2*k + 1;
	}
}

// void Reverseheapify(int *a, int k, int n) {
// 	int j = 2*k+1;
// 	while (j < n) {
// 			if (j + 1 < n) 
// 				if (a[j] > a[j + 1]) j = j + 1;
// 			if (a[k] <= a[j]) return;
// 			swap(a[k], a[j]); 	
// 			k = j; j = 2*k + 1;
// 	}
// }

void Reverseheapify(int *a, int k, int n) {
    int j = 2*k+1; // con trái
    while (j < n) {
        if (j + 1 < n) // nếu có con phải
            if (a[j] > a[j + 1]) j = j + 1; // chọn con nhỏ hơn
        if (a[k] <= a[j]) return; // nếu cha đã nhỏ hơn con, thoát
        swap(a[k], a[j]); // nếu chưa đúng, đổi chỗ cha và con
        k = j; // tiếp tục đẩy k xuống con vừa đổi
        j = 2*k + 1;
    }
}


void Output(int A[], int N, int x) {
    cout<<"N="<<x<<": ";
    for (int i = 0; i < N; i++)
        cout<< A[i]<< "-";
           cout<<endl;
}

void buildHeap(int *a, int n) {
	int i;
	i = (n - 1) / 2;
	while (i >= 0) {
			heapify(a, i, n);
			i--;
	}
}

void ReversebuildHeap(int *a, int n) {
	int i;
	i = (n - 1) / 2;
	while (i >= 0) {
			Reverseheapify(a, i, n);
			i--;
	}
}
void heapSort(int *a, int n) {
	buildHeap(a, n);
    
    Output(a,n,n);
    int N = n;
	while (n > 0) {
			n = n - 1;
			swap(a[0], a[n]);
			heapify(a, 0, n);

            Output(a,N,n);
	}
}
void ReverseheapSort(int *a, int n) {
	ReversebuildHeap(a, n);
    
    Output(a,n,n);
    int N = n;
	while (n > 0) {
			n = n - 1;
			swap(a[0], a[n]);
			Reverseheapify(a, 0, n);

            Output(a,N,n);
	}
}



int main() {
    // int A[MAX];
	int A[] ={5,0,3,2,7,4};
    int N; cin>>N;
    // Input(A,N);

    heapSort(A,N);
    // ReverseheapSort(A,N);

    // Output(A,N,0);
    return 0;
}
