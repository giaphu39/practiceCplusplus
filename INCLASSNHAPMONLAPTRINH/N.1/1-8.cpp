#include<iostream>
#include<iomanip>
#include<math.h>
int main(){
    int a,b,c;
    float p,s;
    std::cin>>a>>b>>c;
    p= (a+b+c)/2;
    s=std::sqrt(p*(p-a)*(p-b)*(p-c));
    std::cout<<std::fixed<<std::setprecision(2)<<s;
return 0;
}