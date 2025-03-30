#include <iostream>
#include <math.h>
using namespace std; 

struct POINT{
    int ox, oy;
};

struct NODE {
    POINT info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void PrintList(LIST L) {
    NODE* p;
    if (L.pHead == NULL)
        cout << "Empty";
    else {
        p = L.pHead;
        while (p) {
        cout << "(" << p->info.ox << ","<< p->info.oy <<")\n";
        p = p->pNext;
        }
    }
}





void CreateEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;
}


NODE* CreateNODE(int x, int y){
    NODE* p = new NODE;
    if( p == NULL){
        exit(1); // cấp phát lỗi
    }
    p->info.ox = x;
    p->info.oy = y;
    p->pNext = NULL;
    return p;
}
void AddHead(LIST &l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST& l, NODE* p){
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
    CreateEmptyList(l);
    while(true){
        int temp;cin>>temp;
        if(temp == -1) return;
        else{
            int temp2; cin>>temp2;
            NODE* p = CreateNODE(temp,temp2);
            AddTail(l,p);
        }
    }
}
// void PrintList(LIST l){
//     NODE* p = l.pHead;
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

// void PrintList(LIST l){
//     NODE* p = l.pHead;
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




void output1(int x, int y){
    cout<<"("<<x<<","<<y<<")"<<" ";
}
void output2(int x, int y){
    cout<<"("<<x<<","<<y<<")"<<"   ";
}
float tinhKhoangCach(int x1, int x2, int y1, int y2){
    return sqrt(float(1)*(x1 - x2)*(x1 - x2) + float(1)*(y1-y2)*(y1-y2));
}


// void Fun(LIST& l){
//     NODE* p = l.pHead;


//     while(p != NULL){
//         NODE* temp =NULL;
//         if(p->info.ox == p->info.oy){
//             temp = p;
//             p->pNext = p->pNext ->pNext;
//             delete temp;
//         }
//         p = p->pNext;
//     }

// }
void RemoveHead(LIST& l) {
    if (l.pHead == NULL) return;
    NODE* temp = l.pHead;
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) l.pTail = NULL;
    delete temp;
}

void RemoveAfter(LIST& l, NODE* prev) {
    if (prev == NULL || prev->pNext == NULL) return;
    NODE* temp = prev->pNext; // temp là giá trị cần xóa
    prev->pNext = temp->pNext;
    if (temp == l.pTail) l.pTail = prev; // nếu giá trị cần xóa là nốt cuối nghĩa là prev sẽ trỏ tới NULL thì cho nốt cuối là prev
    delete temp;
}

void Fun(LIST& l) {
    while (l.pHead && l.pHead->info.ox == l.pHead->info.oy)
        RemoveHead(l);

    NODE* temp = l.pHead;
    while (temp && temp->pNext) { // xét temp != NULL trước để không trỏ p->pNext không tồn tại và next của nó có NULL
        if (temp->pNext->info.ox == temp->pNext->info.oy)
            RemoveAfter(l, temp); // đã remove giá trị sau đó rồi thì sẽ không chạy tiếp temp tiếp theo
        else
            temp = temp->pNext;
    }
}


int main() {
    LIST L;
    CreateList(L); //Input
    Fun(L);           //Remove
    PrintList(L);   //Output
    return 0;
}
