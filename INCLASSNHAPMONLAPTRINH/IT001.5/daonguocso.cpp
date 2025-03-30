#include<iostream>
#include <math.h>

using namespace std;
int demchuso(int n){
    int dem=0;
    while(n!=0){
        n/=10;
        dem++;
    }
    return dem;
}
int mu(int b){
    int ans=1;
    for(int i=1;i<b;i++){
       ans*=10; 
    }
    return ans;
}
int reverse(int n){
    int ans=0;
    int dem=demchuso(n);
    
    for(int i=dem;i>=1;i--){
        int u=i-1;
        if(i==1) ans+=n%10;//sai do pow bị lệch số
        else ans+=(n%10)*(mu(i));
        n/=10;
    }
    // int dem=demchuso(n)-1;
    // while(n!=0){
    //     int so=n%10;
    //     if (dem!=0) ans+=so;
    //     // if (dem!=0) break;
    //     int mu= pow(10,dem);
    //     ans+=so*mu;
    //     dem--;
    // }
    return ans;
}



//ý tưởng: đếm số chữ số, lấy số sau cùng nhân số chữ số *10 giảm dần đến số cuối



int main() {
    int n;
    cin >> n;
    cout<<mu(demchuso(n))<<endl;
    // cout<<demchuso(n)<<endl;
    cout << reverse(n);
}