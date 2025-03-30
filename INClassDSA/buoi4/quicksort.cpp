
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

void quick_sort_ascending(vector<int> &a, int left, int right, int &dem){
    int pivot=a[(left+right)/2]; // khi đổi mid thì giá trị so sánh vẫn không đổi
    int i=left, j=right;
    dem++;
     cout<<"["<<left<<" - "<<right<<"]: ";
    while(i<j){
        while(a[i]< pivot) i++;
        while(a[j]> pivot) j--;
        if(i<=j) {
            swap(a[i], a[j]);
            i++;j--;
        }
    }
    for (int i = left; i <= right; i++)
        cout << a[i] << "\t";
    cout<<endl;
    if(left<j) quick_sort_ascending(a, left, j,dem);
    if(i<right) quick_sort_ascending(a, i, right,dem);
}


void Sort(vector<int> &A)
{
     int dem=0;
	quick_sort_ascending(A,0,A.size()-1,dem);
}


int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
