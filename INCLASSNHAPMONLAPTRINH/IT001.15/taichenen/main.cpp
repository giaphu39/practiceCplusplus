#include <iostream>

using namespace std;
//Một số nguyên candles là số cây nến ban đầu bạn có với 1 ≤ candles ≤ 15

//- Một số nguyên makeNew chỉ số phần sáp thừa mà bạn có thể dùng để tạo ra một cây nến mới, 2 ≤ makeNew ≤ 5

int solguide(int n, int m){
    int u=n%m; // số sáp dư
    int newcandle=n/m; // đc tạo ra từ sáp
    // sau đó số sáp dư cộng cái sáp mới % cho m thì lại tạo tiếp còn dư ? ,
    // ?+ số sáp mới cho đến khi ? =0


    //newcandle
}

int sol(int n, int m){
    int ans=n;
    int newca=n/m;
    int du=n%m;
                    n/=m;
    ans+=newca;
    //while(newca+du!=0){ // sai dừng phải là khi ko thể tạo thêm newca
    while(newca!=0){
        int du1=(newca+du)%m;
        int newca1=(newca+du)/m;
        du=du1;
        newca=newca1;
        ans+=newca;
    }
    return ans;
}
int dungdequy(int n, int m){

}
int main()
{
    int n,mn;
    cin>>n>>mn;
    cout<<sol(n,mn);
    return 0;
}
