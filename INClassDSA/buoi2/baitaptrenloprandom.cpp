#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX= 200;

void input(int *a ,  int n){
    srand(time(0)); // hoặc NULL để mỗi lần chạy là giá trị khác nhau

    for(int i=0;i<n;i++){
        a[i]= rand() %100; // chia dư 100 để lấy phần tử từ 1-> 99
    }
}

void output(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Find01(int a[] , int n , int x){
    int i=0;
    while(i<n){
        if(a[i] == x){
            cout<<i<<endl;
            return;
            
        }
        i++;
    }
    cout<<"NotFound"<<endl;
}

void Find02(int a[] , int n , int x){
    int i=0;
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
    
    int a[MAX];
    int n; cin>>n;

    input(a,n);
    output(a,n);
    int x; cin>> x;

  

    Find01(a,n,x);
    Find02(a,n,x);



    return 0;
}
