#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  
#include<vector>
void Input(vector<int>& a)
{

	int tmp;
	cin >> tmp;
	while (tmp != -1) {
		a.push_back(tmp);
		cin >> tmp;
	}
    
}

void heapify1(vector<int>& a, int k, int n) { // sửa trong đây nếu có input trùng số sẽ quyết định chọn nhánh bên nào
	int j = 2*k+1;
	while (j < n) {
			if (j + 1 < n) 
				if (a[j] < a[j + 1]) j = j + 1;
			if (a[k] >= a[j]) return;
			swap(a[k], a[j]); 	
			k = j; j = 2*k + 1;
	}
}
void heapify(vector<int> &a, int i, int heapSize) { // về nhà nghiên cứu cách sửa practice heapsort slide đc tim
    int childL= i*2 +1;
    int childR= i*2 +2;
    int Max = i;
    if(childL < heapSize && a[childL] > a[Max]) Max = childL; // nếu giá trị trùng thì chỉnh ở đây
    if(childR < heapSize && a[childR] > a[Max]) Max = childR;

    if(Max != i){
        swap(a[i],a[Max]);
        heapify(a,heapSize,Max);
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

void Reverseheapify(vector<int>& a, int k, int n) {
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
void Output1(vector<int>& A, int N, int x) {
    cout<<"buildHeap: ";
    for (int i = 0; i < N; i++)
        if(i == N-1) cout<< A[i];
        else cout<< A[i]<< "-";
    cout<<endl;
}

void Output(vector<int>& A, int N, int x) {
    cout<<"N="<<x<<": ";
    for (int i = 0; i < N; i++)
        if(i == N-1) cout<< A[i];
        else cout<< A[i]<< "-";
    cout<<endl;
}

void buildHeap(vector<int>& a, int n) {
	int i;
	i = (n - 1) / 2;
	while (i >= 0) {
			heapify(a, i, n);
			i--;
	}
}

void ReversebuildHeap(vector<int>& a, int n) {
	int i;
	i = (n - 1) / 2;
	while (i >= 0) {
			Reverseheapify(a, i, n);
			i--;
	}
}
void heapSort(vector<int>& a) {
    int n=a.size();
	buildHeap(a, n);
    
    Output1(a,n,n);
    int N = n;
	while (n > 0) {
			n = n - 1;
			swap(a[0], a[n]);
			heapify(a, 0, n);

            Output(a,N,n);
	}
}
void ReverseheapSort(vector<int>& a) {
    int n = a.size();
    if ( n==0){
        cout<<"Empty";
        return;
    }
	ReversebuildHeap(a, n);
    
    Output1(a,n,n);
    int N = n;
	while (n > 0) {
			n = n - 1;
			swap(a[0], a[n]);
			Reverseheapify(a, 0, n);

            Output(a,N,n);
	}
}



int main() {
    vector<int> A;

    Input(A);
    heapSort(A);
    // ReverseheapSort(A);
   
    return 0;
}
