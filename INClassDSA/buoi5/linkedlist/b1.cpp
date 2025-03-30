#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* pNext;
};

struct LIST{
    Node* pHead;
    Node* pTail;
};

void CreateEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNode(int x){
    Node* p = new Node;
    if( p == NULL){
        exit(1); // cấp phát lỗi
    }
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddHead(LIST &l, Node* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void CreateList(LIST& l){
    int temp; cin>> temp;
    while(temp != -1){
        Node* p = CreateNode(temp);
        AddHead(l,p);
        cin>>temp;
    }
}
void PrintList(LIST l){
    Node* p = l.pHead;
    if(l.pHead == NULL){
        cout<<"Empty List.";
        return;
    }
    // while(p->pNext != NULL){ // sai do không in cái cuối ra
    while(p != NULL){
        cout<<p->info<<" ";
        p = p->pNext;
    }
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList(L);

    return 0;
}
