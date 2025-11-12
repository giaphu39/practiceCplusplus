
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

void Input_infix(char* infix,int& ni){
    cin.getline(infix,MAXN);
    ni = 0;
    for(int i = 0 ; infix[i] != '\0';i++){
        ni++;
    }

}

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

NODE* createNODE(char x){
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool addTail(LIST& l, char x){
    NODE* p = createNODE(x);
    if(p){
        if(l.pHead == NULL){
            l.pHead = p;
            l.pTail = p;
        }
        else{
            l.pTail->pNext = p;
            l.pTail =p;
        }

        return true;
    }
    return 0;
}

bool PopTail(LIST& l, char& x){
    if(l.pTail == NULL) return false;
    NODE* deleteNODE = l.pTail;
    NODE* p = l.pHead;
    if(p == l.pTail){
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else{
        while(p->pNext != l.pTail){
            p = p->pNext;
        }
        p->pNext = NULL;
        l.pTail = p;
    }
    x = deleteNODE->info;
    delete deleteNODE;
    return true;
}

int iThuTu(char x){
    if(x =='+' || x=='-' ) return 1;
    if(x == '*' || x == '/') return 2;
    if(x =='^') return 3;
    return 0;
}
//
//void infix_to_postfix(char* infix,int ni,char* postfix,int& np){
//    LIST l; l.pHead = NULL; l.pTail =NULL;
//    int ind = 0;
//    for(int i =0;i < ni-1;i++){
//        if(infix[i] ==' ') continue;
//        if(infix[i] >= '0' && infix[i] <= ''){
//            postfix[ind++] = infix[i];
//            postfix[ind++]= ' ';
//        }
//        if(infix[i] == '('){
//            addTail(l,infix[i]);
//        }
//        else if(infix[i] == ')'){
//            while(true){
//                char x;
//                PopTail(l,x);
//                if(x == '(') break;
//
//                postfix[ind++] = x;
//                postfix[ind++]= ' ';
//
//            }
//        }
//
//        else if(iThuTu(infix[i])){
//            char x;
//            if(PopTail(l,x)){
//                while(true){
//                    if(iThuTu(infix[i]) >= iThuTu(x)){
//                        postfix[ind++] = x;
//                        postfix[ind++]= ' ';
//                    }
//                    else{
//                        addTail(l,x);
//                        break;
//                    }
//                }
//            }
//        }
//
//
//    }
//
//    char x;
//    while (PopTail(l, x)) {
//        postfix[ind++] = x;
//        postfix[ind++] = ' ';
//    }
//    ni = ind ;
//}
void infix_to_postfix(char* infix, int ni, char* postfix, int& np){
    LIST l; l.pHead = NULL; l.pTail =NULL;
    int ind = 0;

    for(int i = 0; i < ni; i++){
        if(infix[i] == ' ') continue;

        if(infix[i] >= '0' && infix[i] <= '9'){
            postfix[ind++] = infix[i];
            postfix[ind++] = ' ';
        }
        else if(infix[i] == '('){
            addTail(l, infix[i]);
        }
        else if(infix[i] == ')'){
            char x;
            while (true) {
                PopTail(l, x);
                if (x == '(') break;
                postfix[ind++] = x;
                postfix[ind++] = ' ';
            }
        }
        else if(iThuTu(infix[i])){
            char x;
            while (l.pTail != NULL) {
                PopTail(l, x);
                if (x == '(' || iThuTu(x) < iThuTu(infix[i])) {
                    addTail(l, x); // Trả lại x nếu thấp hơn hoặc là dấu mở ngoặc
                    break;
                }
                postfix[ind++] = x;
                postfix[ind++] = ' ';
            }
            addTail(l, infix[i]);
        }

    }

    char x;
    while (PopTail(l, x)) {
        postfix[ind++] = x;
        postfix[ind++] = ' ';
    }

    np = ind;
}

void Output(char* postfix,int& np){
    for(int i =0 ; i < np;i++){
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
