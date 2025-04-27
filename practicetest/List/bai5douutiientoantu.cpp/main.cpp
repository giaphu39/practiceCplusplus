
#include <iostream>
#include <iomanip>
using namespace std;

struct NODE_CHAR{
    char info;
    NODE_CHAR *pNext;
};

struct stack{
    NODE_CHAR *top;
};
NODE_CHAR *CreateNode(float x){
    NODE_CHAR *p=new NODE_CHAR;
    p->info=x;
    p->pNext=NULL;
    return p;
}








NODE_CHAR *CreateNODE(char x){
    NODE_CHAR *p=new NODE_CHAR;
    p->info=x;
    p->pNext=NULL;
    return p;
}
void createEmptyStack(stack& s){
    s.top = NULL;
}

bool Push(stack& s, NODE_CHAR* p){
    NODE_CHAR* temp = s.top;
    if(p == NULL) return false;
    else if(temp == NULL){
        s.top = p;
    }
    else{
        p->pNext = s.top;
        s.top = p;
    }
    return true;
}
bool Pop(stack& s, char& x){
    NODE_CHAR* deleteNODE = s.top;
    if(s.top == NULL) return false;
    else{
        x = deleteNODE->info;
        s.top = deleteNODE->pNext;
        delete deleteNODE;
    }
    return true;
}

 stack s;

NODE_CHAR* input_infix(){

    createEmptyStack(s);

    char a, b;

    cin >> a >> b;

    NODE_CHAR* A = CreateNode(a);
    NODE_CHAR* B = CreateNode(b);

    // tạo stack chỉ để tạo liên kết
    Push(s,A);
    Push(s,B);

    return B;
}

int Level(char a){
    if(a == '^') return 3;
    if( a == '*' || a == '/' || a == '%') return 2;
    if(a == '+' || a == '-') return 1;
}
char Compare(char a, char b){
    if(Level(a) > Level(b)) return '>';
    if(Level(a) == Level(b)) return '=';
    if(Level(a) < Level(b)) return '<';
}

NODE_CHAR* infix_to_postfix(NODE_CHAR* infix){
    char s1, s2;
    char s3;

    Pop(s,s2);
    Pop(s,s1);
    s3 = Compare(s1,s2);

    NODE_CHAR* p1 = CreateNode(s1);
    NODE_CHAR *p2 = CreateNode(s2);
    NODE_CHAR* p3 = CreateNode(s3);

    Push(s,p2);
    Push(s,p3);
    Push(s,p1);

    return p1;
}


void out(NODE_CHAR* postfix){
    NODE_CHAR* p = postfix;
    while(p != NULL){
        cout << p->info << " ";
        p = p ->pNext;
    }

}
















int main() {
    NODE_CHAR *infix=NULL;
    NODE_CHAR *postfix;

    infix=input_infix();

    postfix=infix_to_postfix(infix);
    out(postfix);
    return 0;
}
