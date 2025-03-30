#include <iostream>
using namespace std;

int input(){
    int a;
    std::cin>>a;
    return a;
}
int input(int &b){
    std::cin>>b;
    return b;
}
int TongUocChung(int a, int b){
    int min=std::min(a,b);
    int ans=0;
    // cout<<a<<endl<<b<<endl;
    for(int i=1;i<=min;i++){
        if(a%i==0 and b%i==0){
            ans+=i;
        }
    }
    // int i=1;
    // while(i<=min){
    //     if(a%i==0 && b%i==0){
    //         ans+=i;
    //     }
    //     i++;
    // }
    return ans;
}

int main(){
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}