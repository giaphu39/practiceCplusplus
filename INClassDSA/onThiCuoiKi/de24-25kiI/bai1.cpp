#include<bits/stdc++.h>
using namespace std;

struct data{
    string sTen;
    int iDan;
    float fDienTich;
};

struct node{
    data qg;
    node* pNext;
};

struct List{
    node* pHead;
    node* pTail;   
};

node* createNode(int ds, float dt,string Ten){
    node* p = new node;
    p->qg.sTen = Ten;
    p->qg.iDan = ds;
    p->qg.fDienTich = dt;
    p->pNext = NULL;
    return p;
}

bool Insert(List& l, int ds, float dt,string Ten){
    node* p = createNode(ds,dt,Ten);
    if(l.pHead  == NULL){
        l.pHead = p;
        l.pTail = p;
        return 1;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
        return true;
    }
}
void Nhap(List& l){

    while(true){
        int ds; cin >> ds;
        if(ds == -1) break;
        string Ten;
        float dt;
        cin >> dt;
        cin.ignore();
        getline(cin,Ten);
        Insert(l,ds,dt,Ten);
    }
}

int main(){
    List pDanhSach;
    Nhap(pDanhSach);
    return 0;
}