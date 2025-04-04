#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
struct NODE {
    int info;
    NODE* pNext;
};

struct Queue {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyQueue(Queue &q) {
    q.pHead = NULL;
    q.pTail = NULL;
}

int isEmpty(Queue &q) {
    if (q.pHead == NULL) //Queue rong
            return 1;
    return 0;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void EnQueue(Queue &q, NODE* p) {
    if (q.pHead == NULL) {
        q.pHead = p;
        q.pTail = q.pHead;
    }
    else {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

int DeQueue(Queue &Q, int &x) {
    NODE *p;
        if (isEmpty(Q) != 1) {
        if (Q.pHead != NULL) {
            p = Q.pHead;
            x = p->info;
            Q.pHead = Q.pHead->pNext;
            if (Q.pHead == NULL) Q.pTail = NULL;
            return 1;
        }
    }
    return 0;
}


void CreateQueue(Queue &q)
{
    CreateEmptyQueue(q);
    while(true){
        int temp; cin>> temp;
        if( temp == -1 ) break;
        NODE* p= CreateNode(temp);
        EnQueue(q,p);

    }
}

void PrintQueue(Queue q)
{
     if(isEmpty(q)){
        cout<<"danh sach rong";
        return;
    }
    else{

        NODE* p = q.pHead;
        while( p != NULL){
            cout<< p->info<< " ";
            p= p->pNext;
        }
    }
}

void printrevese(NODE* p){
    if( p == NULL)  return;

    printrevese(p->pNext);
    cout<< p->info <<" ";
}

void ReversePrintQueue(Queue q)
{

    if(isEmpty(q)){
        cout<<"danh sach rong";
        return;
    }
    else{
        NODE* p = q.pHead;

        printrevese(p);
        
    }
}
int main() {
    Queue s;
    CreateQueue(s);
    ReversePrintQueue(s);
    return 0;
}