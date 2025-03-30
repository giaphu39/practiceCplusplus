// Write your code here
#include<iostream>
#include <iomanip>

using namespace std;
int main(){
    int a,b; // phải là kiểu int đề kêu kiểu gì phải lấy kiểu đó
    cin>>a>>b;
    cout<<a<<"  +  "<<b<<"  =  "<<a+b<<endl;
    cout<<a<<"  -  "<<b<<"  =  "<<a-b<<endl;
    cout<<a<<"  x  "<<b<<"  =  "<<a*b<<endl;
    cout<<a<<"  :  "<<b<<"  =  "<<fixed<<setprecision(2)<<static_cast<double>(a)/b<<endl; // vì dùng kiểu int nên chia
    // ko ổn làm tròn sai phải cast thành kiểu double
    return 0;
}