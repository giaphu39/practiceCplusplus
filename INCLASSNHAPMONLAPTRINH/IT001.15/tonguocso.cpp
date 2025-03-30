#include<iostream>
using namespace std;
#include<cmath>
// mảng đánh dấu
// long long *mark=new long long[1000000];

// dùng mảng vào thao tác trên nó có độ phức tạp cao hơn
bool sol(unsigned long long n){
    if(n<=1) return false;
    for(unsigned long long i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
//ý tưởng: / số đó nếu chia hết thì chia tiếp trong vòng lặp
unsigned long long sol2(unsigned long long n){
    unsigned long long ans=1;
    for(unsigned long long i=2;i<=sqrt(n);i++){
        // if(n==1) break;
        // if(mark[i]) continue;
        if(i==n) break;
        if(n%i==0){
            ans+=i;
            // mark[i]=1;
            unsigned long long u=(n/i);
            if(u!=i){
                ans+=u;
                // mark[u]=1;
            }
        }
    }
    return ans;
}
unsigned long long sol3(unsigned long long n){
    unsigned long long ans=1;
    for(unsigned long long i=2;i<n;i++){
        if(n%i==0){
            ans+=i;
        }
    }
    return ans;
}
int main(){
    unsigned long long n;
    cin>>n;
    cout<<sol2(n);
    // if(sol(n)) cout<<1;
    // else{
    //     cout<<sol2(n);
    // }
}