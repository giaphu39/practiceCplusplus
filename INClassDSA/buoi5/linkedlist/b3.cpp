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
void AddTail(LIST& l, Node* p){
    if(l.pHead == NULL){ // tương tự AddHead
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else{
        l.pTail->pNext = p; // gán địa chỉ của giá trị cuối ds khi chưa thêm p vào gán đến p sau đó cho p là Tail
        l.pTail = p;
    }
}
void CreateList(LIST& l){
    while(true){
        int temp1, temp2;
        cin>>temp1;
        if(temp1 == -1) return;

        cin>>temp2;
        if(temp1==0){
            Node* p = CreateNode(temp2);
            AddHead(l,p);
            
        }
        if(temp1==1){
            Node* p = CreateNode(temp2);
            AddTail(l,p);
        }
    }
    // int temp1; cin>>temp1; // thao tác gì
    // if(temp1 == -1) return;
    // int temp2; cin>>temp2; // giá trị gì

    // while(1){
    //     if( temp2 == 0 ){
    //         Node* p = CreateNode(temp2);
    //         AddHead(l,p);
    //         cin>>temp1;
    //         if(temp1 == -1) return;
    //         cin>> temp2;
    //     }
    //     if( temp2 == 1 ){
    //         Node* p = CreateNode(temp2);
    //         AddTail(l,p);
    //         cin>>temp1;
    //         if(temp1 == -1) return;
    //         cin>> temp2;
    //     }
    // }
    // while(temp != -1){
    //     Node* p = CreateNode(temp);
    //     AddHead(l,p);
    //     cin>>temp;
    // }
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
