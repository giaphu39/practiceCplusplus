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
   
    // đối xứng qua trục hoành 
    //  0x phải bằng và 0y phải khác nhau và + nhau ra 0
    int flag= 0;
    NODE* temp = NULL;
    while(p != NULL){
        temp = p->pNext;
        while(temp != NULL){
            if(p->info.ox == temp->info.ox && p->info.oy != temp->info.oy && (p->info.oy + temp->info.oy ==0)){ // tổng các điểm oy 
                flag =1;
                output1(p->info.ox, p->info.oy);
                output1(temp->info.ox, temp->info.oy);
                cout<<endl;
            }

            temp = temp->pNext; // nhớ phải có cái này
        }
        
        p = p->pNext;
    }
    if(!flag) cout<<"NotFound";


}


int main() {
    LIST L; 
    CreateList(L);  //Input
    Fun(L);	           //Output
    return 0;
}
