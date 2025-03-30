#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100  

//đổi ở đây
// int N = 5;
int N;


void Output(int A[], int N) {
    for (int i = 0; i < N; i++)
        cout<< A[i]<< " ";
    cout<<endl;
}


void quickSort(int *a, int left, int right) {
	if (left >= right) return;
    int mid =(left+right)/2;
	int x = a[(left+right)/2], i = left, j = right;
    cout << "[" << i << " - " << j << "]: ";
    Output(a, N);
    cout << "Mid: " << x << endl;
	while(i < j) {          // có thể cho dấu bằng tại đây thì sẽ phân hoặc cách đoạn khác nhau
		while (a[i] < x) i++;  // cũng có thể cho dấu bằng tại đây
		while (a[j] >= x){
            if(a[j]==x && j== mid){
                break;
            }
            j--;
        } // đổi dấu 2 cái while
        // while(a[j] >= x) j--;
		if (i <= j) {
		    swap(a[i], a[j]); i++; j--; 
        }
	}
	if(left < j) quickSort(a, left, j);
    if(i < right) quickSort(a, i, right);
}
void ReversequickSort(int *a, int left, int right) {
	if (left >= right) return;
	int x = a[(left+right)/2], i = left, j = right;
    cout << "[" << i << " - " << j << "]: ";
    Output(a, N);
    cout << "Mid: " << x << endl;
	while(i < j) {
		while (a[i] > x) i++; 
		while (a[j] < x) j--;
		if (i <= j) {
		    swap(a[i], a[j]); i++; j--; 
        }
	}
    //lỗi chỗ này
	// if(left < j) quickSort(a, left, j);
    // if(i < right) quickSort(a, i, right);
    if(left < j) ReversequickSort(a, left, j);
    if(i < right) ReversequickSort(a, i, right);
}

int main() {
    // int A[]={12, 2, 18,30, 5, 1, 6, 4, 15 };
    //đổi ở đây
    cin>>N;
    int A[]={2,5,3,2,6,8,2};
    // int A[] = {1,9,3,7,4,5};
    quickSort(A,0,N-1);
    // ReversequickSort(A,0,N-1);
    Output(A,N);
    return 0;
}





