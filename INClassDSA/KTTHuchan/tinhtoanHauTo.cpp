#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<iomanip>


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
bool isToanHang(char a){
    if(isOperator(a)) return false;
    return true;
}

void Output(stack<string> temp){
    while(!temp.empty()){
        float dau = stof(temp.top());
        temp.pop();
        cout <<setprecision(3) << dau;
        // cout << dau;
    }
}
bool coToanHang(string s){
    for(int i = 0 ;s[i] != '\0'; i++){
        if(isOperator(s[i])) return true;
    }
    return false;
}

float tinhToan(float op1, float op2, char dau){
    if(dau == '+') return op1 + op2 ;
    if(dau == '-') return op1 - op2;
    if(dau == '*') return op1 * op2;
    if(dau == '/') return op1 / op2;
}

bool xuLi(string s){
    stack<string> temp;

    for(int i = 0 ;  s[i] != '#'; i++){
        if(s[i]==' ') continue;
        if (isToanHang(s[i])) {
            string operand = "";
            while (isToanHang(s[i])) { // thieu xet " "
                if(s[i] == ' ') break;
                operand += s[i];
                i++;
            }
            temp.push(operand);
        }
        else{
        
           float op1 =  stof(temp.top());
           temp.pop();
           float op2 =  stof(temp.top());
           temp.pop();

           float ans = tinhToan(op2,op1,s[i]);
           temp.push(to_string(ans));
           

        }
    }



    Output(temp);
    return true;
}














int main(){
    string s;
    getline(cin, s);
    xuLi(s);

    return 0;
}