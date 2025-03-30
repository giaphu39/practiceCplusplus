#include<iostream>
using namespace std;
int nhap1(){
    int a;cin>>a;
    return a;
}
void nhap2(int* a){
    cin>>*a;
}
int main(){
    int a,b;
    a=nhap1();
    cout<<a<<endl;
    nhap2(&b);
    cout<<b;
    return 0;
}