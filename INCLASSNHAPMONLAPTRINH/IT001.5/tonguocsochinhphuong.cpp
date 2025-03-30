

// ý tưởng: số nguyên tố ko là số chính phương và ước số là số chia hết cho nó
// nếu là số nguyên tố thì return 1 luôn
#include <iostream>
using namespace std;
#include <math.h>
bool sol(int n){
    if(n<2){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int sum_all_square(int n){
    int ans=0;
    // for(int i=1;i<=n;i++){
    //     if(i*i>=n){
    //         break;
    //     }
    //     if(n%i==0 and sol(i)==false){
    //         ans+=i;
    //         cout<<i<<endl;
    //     }
    if(sol(n)==true){
        return 1;
    }        
    else{
        for(int i=1;i<=n;i++){
            int j=i*i;
            if(j>n){
                break;
            }
            if(n%j==0){
                ans+=j;
            }
        }
        return ans;
    }

    
    // return ans;
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    cout << sum_all_square(n);
    // sum_all_square(n);
}
