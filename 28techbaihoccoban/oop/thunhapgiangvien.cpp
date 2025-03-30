#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include<string>

class salary{
private:
    string ngach;
    string ten;
    long long phucap;
    long long luong;
    int bacluong;
    string chuc;

    string chucvu(const string& s){
        string ans;
        ans+= string(1,s[0])+string(1,s[1]);
        return ans;
    }
    int heso(const string& s){
        string ans;
        // ans+=s[2]+s[3]; // sai chỗ này do 2 kiểu char sẽ cộng nhau trước rồi mới ép nó thành string nhưng nó ra kí tự lạ nên lỗi
        //https://chatgpt.com/share/6797c59c-f4cc-800d-a831-7c187ad5a992

        // ans += string(1, s[2]) + string(1, s[3]);
        // ans+=s[2];ans+=s[3];
        ans+=string()+s[2]+s[3]; // nên dùng cách này

        return stoi(ans);
    }
    int bonus(const string& s){
        if(s=="HT") return 2000000;
        else if(s=="HP") return 900000;
        else if(s=="GV")return 500000;
        else return 0; // phai co dong nay de neu sai gia tri se khong bao loi 
    }

public:
    void input(){
        getline(cin,ngach);
        getline(cin,ten);
        cin>>phucap;

    }
    void process(){
        bacluong=heso(ngach);
        chuc=chucvu(ngach);
        luong=phucap*bacluong+bonus(chuc); 
    }
    void output(){
        cout<<ngach<<" "<<ten<<" "<<bacluong<<" "<<luong;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    salary a;
    a.input();
    a.process();
    a.output();
    return 0;
}
