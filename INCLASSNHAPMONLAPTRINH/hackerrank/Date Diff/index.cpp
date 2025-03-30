#include<iostream>
using namespace std;
// hướng đi: dùng vòng lặp tạo biến nhỏ là ngày cho tháng, + ngày còn lại, đếm số ngày
int doi(int n){
    switch(n){
        case 1: case 3: case 5:case 7:case 8:case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 28;
    }
}
//thiếu ngày 29
void ngay(int a,int b){
    if(a==29 and b==2){
        cout<<59;
    }
    else if(a>doi(b) or a<=0 or b<=0 or b>12){
        cout<<"NA";
    }
    else{
    int ans=0;
    for(int i=1;i<=b;i++){
        if(i==b){
            ans+=a;
        }
        else{
            ans+=doi(i);
        }
    }
    cout<< ans-1;
}}
int main(){
    int a,b;
    cin>>a>>b;
    ngay(a,b);
    // cout<<doi(2);
    return 0;
}