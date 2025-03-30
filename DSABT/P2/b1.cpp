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
    int temp;
    while(1){ // nên dùng while true rồi xét điều kiện mới đúng 
        cin>>temp;
        if(temp == 0) break;
        a.push_back(temp);
    }
    cin >> x;
}


void output(const std:: vector<int>&  a){
    int n = a.size();
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
void binarySearch(vector<int>& a){
    sort(a.begin(),a.end());
    int l=0; int r= a.size()-1;
    int Count=0;
    while(l <= r){
        Count++;
        int mid = l + (r - l )/2;
        if(a[mid] == x){
            // return mid;
            break;
        }
        else if(a[mid] > x){
            r = mid -1;
            
        }
        else{
            l = mid +1;
            
        }
    }
    output(a);
    cout<<Count;
    
}

// void binarySearch( vector<int> & a){
//     int n = a.size();
//     int Count=0;
//     for(int i = 1 ;i < n ; i++ ){
//         int temp = a[i]; 
//         int pos = binarysearch(a,0,i-1,temp,Count);
//         //tim den gia tri > temp ma nho nhat
//         for(int j = i - 1; j>=pos ; j--){ // >= vì lấy luôn tại vị trí cần chèn
//             a[j+1] = a[j];
//         }
//         a[pos] = temp;
//     }

//     for(int i=0;i<n;i++){
//         cout<<a[i] << " ";
//     }
//     cout<<Count;
    
// }

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
