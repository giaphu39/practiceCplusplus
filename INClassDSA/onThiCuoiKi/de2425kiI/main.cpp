#include <iostream>
#include<string>
using namespace std;

struct Data{
    string sTenQuocGia;
    int iDanSo;
    float fDienTich;
};

struct NODE{
    Data data;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

NODE* createNODE(string ten, int danso, float dientich){
    NODE* p = new NODE;
    p->data.sTenQuocGia = ten;
    p->data.iDanSo = danso;
    p->data.fDienTich = dientich;
    p->pNext = NULL;
    return p;
}

bool addHead(LIST& l, NODE* p){
    if(p == NULL) return 0;
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
    return true;
}

void Nhap(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;

    while(true){
        cout << "Nhap 1 de them, 0 de dung";
        int x; cin >> x;
        if( x == 0) break;
        float dientich;
        int danso;
        string tenqg;
        cout << "nhap vao dan so: ";
        cin >> danso;
        cout << "Nhap vao dien tich: ";
        cin >> dientich;
        cin.ignore();
        getline(cin,tenqg);
        NODE* p = createNODE(tenqg, danso, dientich);
        addHead(l,p);
    }
}

void Swap(NODE*& p, NODE*& q){
//    NODE* temp = p; // sai chỉ sao chép con trỏ không sao chép giá trị
    Data temp = p->data;
    p->data = q->data;
    q->data = temp;

}

void Sort(LIST& l){
    NODE* i = l.pHead;
    NODE *j, *MIN;
    while(i->pNext !=NULL){
        MIN =i;
        j = i->pNext;
        while(j != NULL){
            if(MIN->data.sTenQuocGia > j->data.sTenQuocGia){ // nhớ xét đúng điều kiện
                MIN = j;
            }
            j = j->pNext; // nhớ while nào cũng cần thiết lập bước chạy
        }

        if(MIN != i){
            swap(MIN, i);
        }

        i = i->pNext;
    }
}

void Print(LIST l){
    NODE* p = l.pHead;
    while(p){
        cout << p->data.sTenQuocGia << " ";
    p = p->pNext;
    }
}

int main()
{
    LIST l;
    Nhap(l);
    Sort(l);
    Print(l);

    return 0;
}
