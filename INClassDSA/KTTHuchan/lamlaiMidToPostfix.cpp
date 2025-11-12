
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

struct stack{
    NODE* pHead;
    NODE* pTail;
};

NODE* createNODE(char x){
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool addTail(stack& s , NODE* ADD){
    if(ADD== NULL) return 0;
    NODE* p = s.pTail;
    if(p == NULL){
        s.pHead =  ADD;
        s.pTail = ADD;
    }
    else{
        s.pTail->pNext = ADD;
        s.pTail = ADD;
    }
    return  true;
}

// bool Pop(stack& s, char& x){
//     NODE* p = s.pTail;
//     if(p == NULL) return 0;
//     if(s.pHead == p){
//         s.pHead = NULL;
//         s.pTail = NULL;

//     }
//     else{
//         NODE* q = s.pHead;
//         while(q ->pNext ->pNext != NULL){
//             q = q->pNext;
//         }

//         q->pNext = NULL;
        
//     }
//     x = p->info;
//     delete p; // sai do s.pTail chưa được cập nhật
//     return true;
// }
bool Pop(stack& s, char& x){
    if (s.pTail == NULL) return false;

    if (s.pHead == s.pTail) { // chỉ 1 phần tử
        x = s.pTail->info;
        delete s.pTail;
        s.pHead = s.pTail = NULL;
        return true;
    }

    NODE* prev = s.pHead;
    while (prev->pNext != s.pTail) {
        prev = prev->pNext;
    }

    x = s.pTail->info;
    delete s.pTail;
    s.pTail = prev;
    s.pTail->pNext = NULL;

    return true;
}

char Top(stack s){
    if(s.pTail == NULL ) return 0;
    return s.pTail->info;
}


void Input_infix(char* infix, int& ni){
    cin.getline(infix,MAXN);
    ni = 0;
    for(int i = 0 ; infix[i] != '\0' ; i++){
        ni++;
    }
}

bool isOperator(char s){
    return (s== '+' || s == '-' || s == '*' || s=='/');
    return 0;
}

bool isBraket(char s){
    return (s == '(' || s == ')');
    return 0;
}

int doUuTien(char s){
    if(s == '+' || s=='-') return 1;
    if(s == '*' || s=='/') return 2;
    if(s == '^') return 3;
    return 0;
}

bool isEmpty(stack s){
    if(s.pHead == NULL && s.pTail == NULL) return 1;
    return 0;
}

void infix_to_postfix(char* infix,int ni,char* postfix,int& np){
    stack s;
    s.pHead = NULL;
    s.pTail = NULL;
    np = 0;
    for(int i = 0 ; infix[i] != '#' ; i++){
        if(infix[i] == ' ') continue;
        if(isBraket(infix[i])){
            if(infix[i] == '('){
                NODE * p = createNODE(infix[i]);
                addTail(s,p);
            }
            if(infix[i] == ')'){
                bool flag = 0;
                while(true){
                    if(s.pHead == NULL){
                        flag = 1;
                        break;
                        
                    }

                    char temp;
                    Pop(s,temp);
                    if(temp == '('){
                        break;
                    }
                    postfix[np++] = temp;
                    postfix[np++] = ' ';
                }
                if(flag) break;
                
                // char temp;
                // Pop(s,temp); // lay ( ra 

            }
        }
        else if( isOperator(infix[i])){
            while(true){
                char temp = Top(s);
                if(temp != NULL && doUuTien(temp) >= doUuTien(infix[i])){
                    char temp;
                    Pop(s,temp);
                    postfix[np++] = temp;
                    postfix[np++] = ' ';
                }
                else break;
            }
            NODE* p = createNODE(infix[i]);
            addTail(s,p);

        }
        else{
            postfix[np++] = infix[i];
            postfix[np++] = ' ';
        }
    }

    while(!isEmpty(s)){
        char temp;
        Pop(s,temp);
        postfix[np++] = temp;
        postfix[np++] = ' ';
    }
}







void Output(char* postfix,int np){
    for(int i =0 ; i< np ; i++){
        cout << postfix[i];
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
