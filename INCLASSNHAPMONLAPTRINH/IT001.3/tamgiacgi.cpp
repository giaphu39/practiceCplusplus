// Write your code here
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double a,b,c,s,p;
    cin>>a>>b>>c;
    p=(a+b+c)/2;
    if(a+b>c and b+c>a and a+c>a){
        if(a==b or a==c or b==c){
            if(a==b and b==c and a==c){
                s=sqrt(p*(p-a)*(p-b)*(p-c));
                cout<<"Tam giac deu,  dien tich = "<<fixed<<setprecision(2)<<s;
            }
            else{
                s=sqrt(p*(p-a)*(p-b)*(p-c));
                cout<<"Tam giac can,  dien tich = "<<fixed<<setprecision(2)<<s;
            }
        }
        else if(a*a+b*b==c*c or a*a+c*c==b*b or b*b+c*c==a*a){
            s=sqrt(p*(p-a)*(p-b)*(p-c));
            cout<<"Tam giac vuong,  dien tich = "<<fixed<<setprecision(2)<<s;
        }
        else{
            s=sqrt(p*(p-a)*(p-b)*(p-c));
            cout<<"Tam giac thuong,  dien tich = "<<fixed<<setprecision(2)<<s;     
        }
    }
    else{
        cout<<"Khong phai tam giac";
    }
    return 0;
}