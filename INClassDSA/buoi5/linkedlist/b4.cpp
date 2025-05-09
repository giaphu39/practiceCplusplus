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
        int temp;cin>>temp;
        if(temp == -1) return;
        else{
            Node* p = CreateNode(temp);
            AddTail(l,p);
        }
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

// void PrintList(LIST l){
//     Node* p = l.pHead;
//     if(l.pHead == NULL){
//         cout<<"Empty List.";
//         return;
//     }
//     // while(p->pNext != NULL){ // sai do không in cái cuối ra
//     while(p != NULL){
//         cout<<p->info<<" ";
//         p = p->pNext;
//     }
// }
void PrintList_Odd(Node* l){ // phần tử đầu
    Node* p = l;
    if(l == NULL){
        cout<<"Empty List.";
        return;
    }
    bool flag=0; // đã in số lẻ chưa
    while(p != NULL){
        if(p->info %2 != 0){
            cout<<p->info<<" ";
            flag=1;
        }
        p = p->pNext;
    }
    if(!flag){
        cout<<"Không có số lẻ trong mảng.";
    }
}


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}

