
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300


// ý tưởng là lưu space và khi gặp space thì tìm từ bỏ vào hết stack

struct NODE{
    int data;
    NODE* pNext;
};


struct Stack{
    NODE* pHead;
    NODE* pTail;
};


void createEmptyStack(Stack& s){
    s.pHead = NULL;
    s.pTail = NULL;
}

NODE* createNODE(int x){
    NODE* p = new NODE;
    if(p == NULL){
        exit(1);
    }
    p->data = x;
    p->pNext = NULL;

    return p;
}

void Push(Stack& s, NODE* p){

    if(s.pHead == NULL){
        s.pHead = p;
        s.pTail = p;
    }
    else{
        p->pNext = s.pHead;
        s.pHead = p;
    }

}

//bool Pop(Stack& s, string& x){ // sai pop phải là ở đầu
//    NODE* p = s.pHead;
//    NODE* deleteNODE = s.pTail;
//    if(s.pTail == NULL) return 0;
//    else if( s.pHead == s.pTail){
//        x = s.pHead ->data;
//        s.pHead = NULL;
//        s.pTail = NULL;
//
//        delete deleteNODE;
//    }
//    else{
//        while( p->pNext ->pNext !=NULL){
//            p = p->pNext;
//        }
//
//
//        p->pNext = NULL;
//        s.pTail = p;
//        delete deleteNODE;
//
//    }
//    return true;
//}

bool Pop(Stack& s, int& x){ // sai pop phải là ở đầu
    NODE* p = s.pHead;
    NODE* deleteNODE = s.pHead;
    if(p == NULL) return false;
    else{
        x = deleteNODE->data;
        p = p->pNext;
        s.pHead = p;
        delete deleteNODE;

        return true;
    }
}
bool isChu(char a){
    return (a >='A' && a <='Z') || (a >='a' && a <='z');
}
bool isspace(char a){
    return a==' ';
}


void decimal_to_binary(int n){
    if(n == 0){ // nhớ trường hợp này là quan trọng nhất
        cout << 0;
        return;
    }

    Stack s;
    createEmptyStack(s);
    while(n != 0){
        int temp = n % 2;
        NODE* p = createNODE(temp);
        Push(s,p);

        n/= 2;
    }

    int temp;
    while(Pop(s,temp)){ // dừng khi NULL
        cout << temp;
    }
}




int main() {
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}

