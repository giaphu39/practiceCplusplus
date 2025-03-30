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


void Fun(LIST& l){
    NODE* p = l.pHead;
    if(l.pHead == NULL){
        cout<<"Empty";
        return;
    }
   
    float SoMax = -1;
    float SoMin = 1000000;
    while(p != NULL){
        SoMax = max(SoMax, tinhKhoangCach(p->info.ox,0,p->info.oy,0)) ;
        SoMin = min(SoMin, tinhKhoangCach(p->info.ox,0,p->info.oy,0)) ;
        p = p->pNext;
    }

    p= l.pHead;
    while(p != NULL){
        if(tinhKhoangCach(p->info.ox,0,p->info.oy,0) == SoMax){
            output2(p->info.ox, p->info.oy);
        }
        p = p->pNext;
    }

    cout<<endl;

    p= l.pHead;
    while(p != NULL){
        if(tinhKhoangCach(p->info.ox,0,p->info.oy,0) == SoMin){
            output2(p->info.ox, p->info.oy);
        }
        p = p->pNext;
    }



}


int main() {
    LIST L; 
    CreateList(L);  //Input
    Fun(L);	           //Output
    return 0;
}
