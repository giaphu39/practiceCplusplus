#include <iostream>
using namespace std;


#include<cmath> // để dùng sqrt
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
    int temp; cin>> temp;
    while(temp != -1){
        Node* p = CreateNode(temp);
        // AddHead(l,p);
        AddTail(l,p);
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

void addafterQ(Node* q, Node* p){
    p->pNext = q->pNext;
    q->pNext = p;
}

bool isPrime(int x)
{
    if(x <= 1) return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x % i == 0) return false;
    }
    return true;
}

void add_after_all_prime(LIST& l,int x){
    Node* p = l.pHead;
    if(p == NULL) return;
    while(p != NULL){
        if(isPrime(p -> info)){
            Node* temp = CreateNode(x);
            addafterQ(p,temp);
            p = p->pNext;
        }
        p = p->pNext;
    }
}

int main() {
    LIST L;
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

    return 0;
}
