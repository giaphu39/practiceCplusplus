#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<iomanip>
#include<cstring> //khai bao thu vien cho strlen
class student{
private:
    // char hoten[51];
    string hoten;
    string ngaysinh;
    float d1;
    float d2;
    float d3;
public:
    void input(){
        // fgets(hoten,51,stdin); // phải là 51 vì nó tự add kí tự \0 vào cuối
        // if(hoten[strlen(hoten)-1]=='\n') hoten[strlen(hoten)-1]='\0';
        getline(cin,hoten);
        getline(cin,ngaysinh);
        cin>>d1;
        cin>>d2;
        cin>>d3;
    }
    float tong(){
        return d1+d2+d3;
    }
    void output(){
        // cout<<hoten<<" "<<ngaysinh<<" "<<round(tong()*10)/10;
        cout<<hoten<<" "<<ngaysinh<<" "<<fixed<<setprecision(1)<<tong(); // đề yêu cầu là lấy 1 số sau thập phân không phải làm tròn 
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    student a;
    a.input();
    a.output();
    
    return 0;
}
