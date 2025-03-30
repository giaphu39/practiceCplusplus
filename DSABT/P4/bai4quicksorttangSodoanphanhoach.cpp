
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


void Output(vector<int> &v)
{
	for(int i = 0; i < v.size() ; i++){
		cout<<v[i]<<"       ";
	}
}

void QuickSort(vector<int>& a, int l, int r, int& Count){
    int mid = l + (r-l)/2;
    int pirot = a[mid];

    Count++;
    int i=l;
    int j=r;
    while(i < j){
        while(a[i] < pirot) i++;
        while(a[j] > pirot) j--;

        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(l < j) QuickSort(a,l,j,Count);
    if(i < r) QuickSort(a,i,r,Count);

}


void Sort(vector<int>& a){
    int l=0;
    int r=a.size()-1;
    int Count=0;
    QuickSort(a,l,r,Count);
    cout<<Count;

}











int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
