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
    output(a);
    int mid;
    while(l <= r){
        
        mid = l + (r - l )/2;
        cout<<"Left="<<l << "   Right="<<r<< "         Mid="<<mid<<endl; // đặt ở đây mới đúng vì khi bắt đầu dù chạy tiếp hay không chạy tiếp vẫn in ra
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
        // cout<<"Left="<<l << "   Right="<<r<< "         Mid="<<mid;
    }
    // cout<<"Left="<<l << "   Right="<<r<< "         Mid="<<mid;
   
    
}


int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
