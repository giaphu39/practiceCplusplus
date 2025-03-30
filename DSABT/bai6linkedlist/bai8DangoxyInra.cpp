
#include <cmath>
#include <iostream>







using namespace std; 

int n;


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
void Nhap(LIST& l){
    cin >> n;
    int i = 0;
    while( true ){
        int temp;cin>>temp;
        if(i >= n) return;
        else{
            int temp2; cin>>temp2;
            NODE* p = CreateNODE(temp,temp2);
            AddTail(l,p);
        }
        i++;
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
void output3(int x, int y){
    cout<<"("<<x<<", "<<y<<")"<<endl;
}
void output2(int x, int y){
    cout<<"("<<x<<","<<y<<")"<<"   ";
}
float tinhKhoangCach(int x1, int x2, int y1, int y2){
    return sqrt(float(1)*(x1 - x2)*(x1 - x2) + float(1)*(y1-y2)*(y1-y2));
}


void Xuat(LIST L) {
    NODE* p;
    if (L.pHead == NULL)
        cout << "Empty";
    else {
        p = L.pHead;
        while (p) {
        output3(p->info.ox,p->info.oy);
        p = p->pNext;
        }
    }
}



int main() {
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    Xuat(points);

    return 0;
}
