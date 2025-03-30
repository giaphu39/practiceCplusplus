#include <iostream>
#include <math.h>
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



void output1(int x, int y){
    cout<<"("<<x<<","<<y<<")"<<" ";
}
void output2(int x, int y){
    cout<<"("<<x<<","<<y<<")"<<"   ";
}
float tinhKhoangCach(int x1, int x2, int y1, int y2){
    return sqrt(float(1)*(x1 - x2)*(x1 - x2) + float(1)*(y1-y2)*(y1-y2));
}


NODE* DiemGanGocToaDoNhat(LIST& l){
    NODE* p = l.pHead;
    if(l.pHead == NULL){
        cout<<"Empty";
        return NULL;
    }
   
    float SoMax = -1;
    // float SoMin = 1000000;
    float SoMin = tinhKhoangCach(p->info.ox, 0, p->info.oy, 0);
    while(p != NULL){
        SoMax = max(SoMax, tinhKhoangCach(p->info.ox,0,p->info.oy,0)) ;
        SoMin = min(SoMin, tinhKhoangCach(p->info.ox,0,p->info.oy,0)) ;
        p = p->pNext;
    }

    // p= l.pHead;
    // while(p != NULL){
    //     if(tinhKhoangCach(p->info.ox,0,p->info.oy,0) == SoMax){
    //         output2(p->info.ox, p->info.oy);
    //     }
    //     p = p->pNext;
    // }

    // cout<<endl;

    p= l.pHead;
    while(p != NULL){
        if(tinhKhoangCach(p->info.ox,0,p->info.oy,0) == SoMin){
            return p;
        }
        p = p->pNext;
    }



}
void Nhap(LIST& l){
    cin >> n;

    int i = 0;
    while(i<n){
        int temp1, temp2;
        cin>>temp1>>temp2;

        NODE* p = CreateNODE(temp1,temp2);
        AddTail(l,p);
        i++;
    }
}


void Xuat(NODE* p){
    cout<<"("<<p->info.ox<<", "<<p->info.oy<<")";
}


int main() {
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    std::cout << "Diem gan goc toa do nhat la: ";
    Xuat(DiemGanGocToaDoNhat(points));

    return 0;
}
