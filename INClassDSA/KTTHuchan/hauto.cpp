#include<iostream>
using namespace std;
#include<string>
#include<stack>

bool isToanHang(char a){
    if(a >= '0' && a <='9') return true;
    return false;
}

bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}

int doUuTien(char a){
    if(a == '+' || a =='-' ) return 1;
    if(a == '*' || a =='/') return 2;
    return 0;
}

bool xuLi(string s){
    stack<char> temp;

    for(int i = 0 ;  s[i] != '#'; i++){
        if(isToanHang(s[i])){
            cout << s[i];
        }
        else{
            if(isBracket(s[i])){
                if(s[i] == '('){
                    temp.push(s[i])
                }
                else{
                    while(true){
                        char dau = temp.top();
                        temp.pop();
                        if(dau == ')') break;
                        else{
                            cout << dau;
                        }
                        if(temp.empty()){
                            return false;
                        }
                    }
                }
            }
            int dau = temp.top();
            if(doUuTien(dau) >= doUuTien(s[i])){
                
            }
            
        }
    }

    return true;
}














int main(){
    string s;
    getline(cin, s);
    xuLi(s);

    return 0;
}