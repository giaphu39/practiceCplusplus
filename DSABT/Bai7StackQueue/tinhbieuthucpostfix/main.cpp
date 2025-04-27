
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, float x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}
float& top(stack s) {
    return s.top->info;
}
bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}
void InputPostFix(char postix[], int &n){ // chỗ char này bao gồm cả số
    // nên là đây là nhập vào toàn bộ số và dấu cần xử lí
    char k;
    cin >> k;
    n=0;
    while (k!='#'){
        postix[n++] = k;
        cin >> k;
    }
}

bool isNumber(char x){
    return (x >='0' && x <='9');
}

float thaoTacDau(float a, float b, char x){
    if(x =='+'){
        return a+b;
    }
    if(x=='-') return a-b;
    if(x == '*')return a*b;
    if(x == '/') return a/b;
    if(x == '^'){
        float ans = 1;
        for(int i = 0; i< b;i++){
            ans *= a;
        }
        return ans;
    }
}

float evaluate_expression(char* postfix,int np){ // np là số phần tử
    stack s;
    CreateEmptyStack(s);

    for(int i = 0 ; i < np ; i++){
        if(isNumber(postfix[i])){
            push(s,float(postfix[i] - '0'));
        }
        else if(isOperator(postfix[i])){
            float b = top(s);
            pop(s);
            float a = top(s);
            pop(s);

            float c = thaoTacDau(a,b,postfix[i]);
            push(s,c);
        }
    }
    return top(s);
}















int main() {
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
