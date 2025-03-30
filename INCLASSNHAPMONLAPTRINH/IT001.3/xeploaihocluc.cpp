// Write your code here
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float a,b,c,tb;
    cin>>a>>b>>c;
    tb=(a+b+c)/3;
    cout<<"DTB = "<<fixed<<setprecision(2)<<tb<<endl;
    if(tb>=9 and tb<=10){
        cout<<"Loai: XUAT SAC";
    }
    else if (tb>=8 and tb<9){
        cout<<"Loai: GIOI";
    }
    else if (tb>=7 and tb<8){
        cout<<"Loai: KHA";
    }
    else if (tb>=6 and tb<7){
        cout<<"Loai: TB KHA";
    }
    else if (tb>=5 and tb<6){
        cout<<"Loai: TB";
    }
    else if (tb>=4 and tb<5){
        cout<<"Loai: YEU";
    }
    else if (tb<4){
        cout<<"Loai: KEM";
    }
    return 0;
}