
#include <iostream>
using namespace std;




struct NODE{
    int info;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};


void CreateEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;

}

NODE* CreateNode(int x){
    NODE* p = new NODE;

    if(p == NULL){
        exit(1); // nếu cấp phát mà vẫn không có địa chỉ thì lỗi
    }

    p->info = x;
    p->pNext = NULL;

    return p;
}  

void AddHead(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{

        // tạo liên kết
        p -> pNext = l.pHead;
        l.pHead = p;

    }
} 
void AddTail(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{

        // tạo liên kết
        l.pTail ->pNext = p;

        l.pTail = p;

    }
}


void CreateList(LIST& l){
    while(true){
        int temp; cin >> temp;
        if(temp == -1) break;
        else{
            NODE* p = CreateNode(temp);
            AddTail(l , p);
        }
    }
}

void RemoveHead(LIST& l){
    if(l.pHead == NULL) return;

    NODE* deleteNODE = l.pHead;
    
    l.pHead = l.pHead->pNext;

    delete deleteNODE;
}

void RemoveTail(LIST& l){
    NODE* p = l.pHead;
    NODE* deleteNODE = l.pTail;

    if(p == NULL ) return; // trường hợp 1: không có gì để xóa
    else if(p == deleteNODE){ // trường hợp 2: chỉ có 1 phần tử để xóa
        // cắt đứt liên kết rồi mới xóa
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
        return;
    }
    // trường hợp 3: bình thường
    else{
        while(p->pNext -> pNext != NULL){ // lẩy thằng tiếp theo mà trỏ tới địa chỉ NULL ( cuối cùng )
            p = p->pNext;
        }
    
        
    
        p->pNext = NULL;
        l.pTail = p;
        delete deleteNODE;
    }

}


void PrintList(LIST l){
    NODE* p = l.pHead;
    if(p == NULL){
        cout<<"Empty List."<<endl;
        return;
    }

    while(p!= NULL){
        cout << p->info<<" ";
        p = p->pNext;
        
    }
    cout<<endl;
}


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveTail(L);
    PrintList(L);

    return 0;
}
