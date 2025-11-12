#include<iostream>
using namespace std;
#include<string>
#include<stack>



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
        string dau = temp.top();
        temp.pop();
        cout << dau;
    }
}
bool coToanHang(string s){
    for(int i = 0 ;s[i] != '\0'; i++){
        if(isOperator(s[i])) return true;
    }
    return false;
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
        
           string op1 = temp.top();
           temp.pop();
           string op2 = temp.top();
           temp.pop();

           if(coToanHang(op1) || coToanHang(op2)){
                string addVao = string() +"(" + op2 +")"+ s[i] +"("+ op1 +")";
                temp.push(addVao);
               
           }
           else{
                string addVao = string() + op2 + s[i] + op1;
                temp.push(addVao);
            }
           

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