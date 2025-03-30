#include <iostream>
#include <cstdlib>
#include <ctime>

#include<algorithm>
using namespace std;

#include<vector>
const int MAX= 200;

void input(vector<int>& a){
    int n;cin>>n;
    srand(time(0)); // hoặc NULL để mỗi lần chạy là giá trị khác nhau

    for(int i=0;i<n;i++){
        a.push_back(rand() %100); // chia dư 100 để lấy phần tử từ 1-> 99
    }

    sort(a.begin(), a.end());
    
}

void output(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Find01(vector<int> a , int x){
    int n= a.size();
    int l=0; int r= n-1;

    while(l<=r){

        int mid=(l+r)/2;
        if(a[mid] == x){
            cout<< mid<<endl;

            return;
        }
        if(x < a[mid]){
            r= mid -1;
        }
        else{
            l=mid + 1;
        }
    }

    cout<<"NotFound"<<endl;
}

// void Find02(vector<int> a , int x){
//     int n= a.size();
//     int l=0; int r= n-1;
//     bool flag=0;

//     while(l<=r){

//         int mid=(l+r)/2;
//         if(a[mid] == x){
//             cout<< mid<< " ";
//         }
//         if(x < a[mid]){
//             r= mid -1;
//         }
//         else{
//             l=mid + 1;
//         }
//     }
//     if(!flag)
//         cout<<"NotFound"<<endl;
// }

int main() {
    
    vector<int> a;
    // int n; cin>>n;

    input(a);
    output(a);
    int x; cin>> x;

  

    Find01(a,x);
    // Find02(a,x);



    return 0;
}
