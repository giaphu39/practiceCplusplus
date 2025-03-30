#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//nhớ: dấu * hoặc space phải tác động đến i
// số * mỗi hàng bằng số i

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    //tam giác qua phải
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    
    //tam giác xuống dưới qua phải
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    
    cout<<endl;
    //tam giác cách dòng qua trái
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>=1;j--){
            cout<<" ";
        }
        // cout<<endl;
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    //tam giác qua phải rỗng
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<"*"<<endl;
        }
        else if(i==n){
            for(int j=1;j<=n;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        else{
            cout<<"*";
            for(int j=2;j<i;j++){
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
    }
    return 0;
}
