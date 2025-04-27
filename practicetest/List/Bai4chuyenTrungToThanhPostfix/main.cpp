
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};


//ý tưởng: ( thì bỏ vào gặp ) thì pop ra đến khi gặp (
// số thì in luôn, dấu thì xét nếu rỗng thì bỏ vào, nếu dấu đang xét độ ưu tiên bé hơn hoặc bằng dấu ở đầu thì pop dấu ở đầu ra nhét vào dấu đang xét
// hết tới kết thức rồi thì lấy toàn bộ từ stack ra
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
void push(stack &s, char x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s, char& x) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    x = p->info;
    s.top=s.top->pNext;
    delete p;
}
char& top(stack s) {
    return s.top->info;
}
bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}

int Level(char a){
    if(a == '^') return 3;
    if( a == '*' || a == '/' || a == '%') return 2;
    if(a == '+' || a == '-') return 1;

    if(isBracket(a)) return -1; // luôn thấp nhất để không ai bóc nó ra được
}
bool Compare(char a, char b){
    // Nếu a có độ ưu tiên nhỏ hơn b => phải pop
    // Nếu bằng mà a là phép trái-kết-hợp (left-associative) => cũng pop
    // Toán tử ^ là phải-kết-hợp (right-associative) nên KHÔNG pop khi bằng
    if(Level(a) < Level(b)) return true;
    if(Level(a) == Level(b) && a != '^') return true;
    return false;
}

bool isNumber(char x){
    return (x >='0' && x <='9');
}

void Input_infix(char* infix,int& ni){
    int i =0;
    while(true){
        char temp; cin >> temp;
        if(temp == '#') break;
        infix[i++] = temp;
    }
    ni = i;
}

void infix_to_postfix(char* infix,int ni,char* postfix,int& np){
    stack s; // s này lưu các dấu
    CreateEmptyStack(s);
    int j=0;
    for(int i=0;i<ni;i++){
        if(isNumber(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(isOperator(infix[i])){
            // phải có dòng !empty trước compare vì không sẽ truy xuất đến NULL gây lỗi
            while(!empty(s) && Compare(infix[i],top(s))){
                // phải dùng while cho đến khi thỏa điều kiện dừng chứ không xét 1 lần đk
                char temp;
                pop(s,temp);
                postfix[j++] = temp;
            }
            push(s,infix[i]);
        }

        else if(infix[i] == ')'){
            while(true){
                char temp;
                pop(s,temp);
                if(temp == '(') break;
                postfix[j++] = temp;
            }

        }

        else if(infix[i] == '('){
            push(s, infix[i]);
        }

    }

    while(!empty(s)){
        char temp;
        pop(s,temp);

        postfix[j++] = temp;
    }
    np = j;
}
void Output(char* postfix,int np){
    for(int i = 0 ; i < np ; i++){
        cout << postfix[i] << " ";
    }

}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
