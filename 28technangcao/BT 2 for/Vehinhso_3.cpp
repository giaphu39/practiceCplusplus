#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 1 2 3 4 5 
// 6 7 8 9 10 
// 11 12 13 14 15 
// 16 17 18 19 20 
// 21 22 23 24 25 

// 1 2 3 4 5 
// 2 3 4 5 6 
// 3 4 5 6 7 
// 4 5 6 7 8 
// 5 6 7 8 9 

// ~~~~1
// ~~~22
// ~~333
// ~4444
// 55555

// 1 
// 2 6 
// 3 7 10 
// 4 8 11 13 
// 5 9 12 14 15 

//cho các số và thao tác trên số thì nên đặt biến phụ

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=1;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;

    for(int i=1;i<=n;i++){
        ans=i;
        for(int j=1;j<=n;j++){
            cout<<ans<<" ";
            ans+=1;
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"~";
        }
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    
    cout<<endl;
    //tìm các qui tắc giữa các phần tử trong dòng: ở đây là mỗi lần + (n-1) nhưng giảm dần
    // tách các trường hợp không theo qui tắc ra trước 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int ans;
            if(j==1){
                cout<<i<<" ";
                ans=i;
            }
            else{
                ans=ans+(n+1-j);
                cout<<ans<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
