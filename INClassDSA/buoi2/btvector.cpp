#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include<vector>
const int MAX= 200;

void input(vector<int>& a){
    int n;cin>>n;
    srand(time(0)); // hoặc NULL để mỗi lần chạy là giá trị khác nhau

    for(int i=0;i<n;i++){
        a.push_back(rand() %100); // chia dư 100 để lấy phần tử từ 1-> 99
    }
}

void output(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Find01(vector<int> a , int x){
    int i=0;
    int n=a.size();
    while(i<n){
        if(a[i] == x){
            cout<<i<<endl;
            return;
            
        }
        i++;
    }
    cout<<"NotFound"<<endl;
}

void Find02(vector<int> a , int x){
    int i=0;
    int n=a.size();
    bool flag=0;
    while(i<n){
        if(a[i] == x){
            flag=1;
            cout<<i<<" ";
        }
        i++;
    }
    if(!flag) cout<<"NotFound";
    cout<<endl;
}

int main() {
    
    vector<int> a;
    // int n; cin>>n;

    input(a);
    output(a);
    int x; cin>> x;

  

    Find01(a,x);
    Find02(a,x);



    return 0;
}
