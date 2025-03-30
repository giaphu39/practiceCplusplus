/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

//###INSERT CODE HERE -
void Output(vector<int> &v)
{
	for(int i = 0; i < v.size() ; i++){
		cout<<v[i]<<"       ";
	}
}

void QuickSort(vector<int>& a, int l, int r){
	int mid = l + (r-l)/2;
	int i = l; // phải làm vậy để không biến đổi l và r mới phân đoạn được
	int j = r;

	int pirot = a[mid]; // phần tử chốt
	while(i < j){
		while(a[i] > pirot) i++;
		while(a[j] < pirot) j--;

		if(i <= j){
			swap(a[i] , a[j]);
			i++; j--;
		}
	}

	if(l < j) QuickSort(a,l,j);
	if(i < r) QuickSort(a,i,r);

	if(l==0 && r==a.size()-1){
		Output(a); // in tại đây vì sau khi chạy đệ quy xong hết trả về xong hết thì nó trả về và phải xét điều kiện l và r nó chưa đổi
	}
	
}



int main() {
	vector<int> A;
	Input(A);
	QuickSort(A,0,A.size()-1);

	// Output(A);
	return 0;
}
