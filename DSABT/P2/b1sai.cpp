/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

//###INSERT CODE HERE -
int x;
void Input( vector<int>& a){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int temp; cin>> temp;
        a.push_back(temp);
    }
    cin >> x;
}
int binarysearch(vector<int> a, int l, int r, int temp, int& Count){
    while(l <= r){
        int mid = l + (r - l )/2;
        if(a[mid] > temp){
            return mid;
        }
        else{
            r= mid -1;
            Count++;
        }
    }
    return l; // khong tim thay
}

void binarySearch( vector<int> & a){
    int n = a.size();
    int Count=0;
    for(int i = 1 ;i < n ; i++ ){
        int temp = a[i]; 
        int pos = binarysearch(a,0,i-1,temp,Count);
        //tim den gia tri > temp ma nho nhat
        for(int j = i - 1; j>=pos ; j--){ // >= vì lấy luôn tại vị trí cần chèn
            a[j+1] = a[j];
        }
        a[pos] = temp;
    }

    for(int i=0;i<n;i++){
        cout<<a[i] << " ";
    }
    cout<<Count;
    
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
