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
// void PrintList(Node* l){
//     Node* p = l;
//     if(l == NULL){
//         cout<<"Empty List.";
//         return;
//     }
//     // while(p->pNext != NULL){ // sai do không in cái cuối ra
//     while(p != NULL){
//         cout<<p->info<<" ";
//         p = p->pNext;
//     }
// }
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

void add_after_k_th(LIST& l,int y,int k){ // với y là giá trị, k là vị trí
    Node* p = l.pHead;
    if(p == NULL) return;
    int i = 1; // vị trí bắt đầu dãy linkedlist
    while(p != NULL){
        if(i == k){
            Node* temp = CreateNode(y);
            addafterQ(p,temp);
            return; // cách dòng sau không  còn ý nghĩa 
            p = p->pNext;
        }
        
        p = p->pNext;
        i++; //tăng vị trí mỗi khi qua node tiếp theo
    }
}
int soChuSo1(int n){
    int Count=0;
    while(n!= 0){
        Count++;
        n/=10;
    }
    return Count;
}
bool isArmstrong(int n){
    if(n <=0 ) return false;
    int soChuSo= soChuSo1(n);
    int N = n;
    int Sum=0;
    while(N !=0){
        int donvi = N % 10;
        Sum += pow(donvi,soChuSo);
        N/=10;
    }
    if(Sum == n) return 1;
    return 0;
}

bool flag =0; // đã in số ra chưa

void reversePrintList(Node* p){
    if(p == NULL) return;

    reversePrintList(p->pNext);

    if(isArmstrong(p->info)){ // điều kiện in
        cout<<p->info<<" ";
        flag=1;
    }

}
void  PrintList_Armstrong(LIST& l){ // phần tử đầu
    Node* p = l.pHead;
    if(l.pHead == NULL){
        cout<<"Empty List.";
        return;
    }
    // bool flag=0; // đã in số prime chưa
    // while(p != NULL){
    //     if(isArmstrong(p->info)){
    //         cout<<p->info<<" ";
    //         flag=1;
    //     }
    //     p = p->pNext;
    // }
    reversePrintList(p);

    if(!flag){
        cout<<"Không có số armstrong trong mảng.";
    }
}

string searchX(Node* l, int X){
    Node* p = l;
    
    while(p != NULL){
        if(p->info == X) return "true";
        p = p->pNext;
    }
    return "false";
}


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}

