
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	// while (tmp > 0) {
        while (tmp != -1) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


void Output(vector<int> &v)
{
	for(int i = 0; i < v.size() ; i++){
		cout<<v[i]<<"       ";
	}
    cout<<endl;
}

void inPhanHoach(int n, int i, int j){
    cout<<"N="<<n<<": swap "<<i<<" - "<<j<<endl;
}

void Heapify(vector<int> &a, int heapSize, int i) {
    int childL= i*2 +1;
    int childR= i*2 +2;
    int Max = i;
    if(childL < heapSize && a[childL] > a[Max]) Max = childL; // nếu giá trị trùng thì chỉnh ở đây
    if(childR < heapSize && a[childR] > a[Max]) Max = childR;

    if(Max != i){
        swap(a[i],a[Max]);
        Heapify(a,heapSize,Max);
    }
}
void buildHeap(vector<int> &a, int n) {
    for(int i = n/2 - 1; i >=0; i--){
        Heapify(a,n,i);
    }
    

}

void Sort(vector<int>& a){
    int n= a.size();
    int heapSize= n;

    buildHeap(a,heapSize);

    // inPhanHoach(heapSize,a[0],a[heapSize-1]);

    for(int i= n-1; i> 0 ;i--){
        swap(a[0] , a[i] );
        cout<<"N="<<heapSize<<endl;
        Output(a);
        // inPhanHoach(heapSize,a[0],a[i]); // swap in rồi mới hiệu chỉnh
        heapSize -=1;
        Heapify(a,heapSize,0);
        // inPhanHoach(heapSize,a[0],a[i]);
    }

}


int main() {
	vector<int> A;
	Input(A);
	Sort(A);
    // Output(A);
	return 0;
}
