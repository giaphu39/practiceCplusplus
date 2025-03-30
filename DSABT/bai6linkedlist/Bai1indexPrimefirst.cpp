#include<iostream>
#include<cmath>

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

bool isPrime(int x){
    if (x <=1) return false;
    else{
        for(int i= 2; i <= sqrt(x); i++){
            if(x % i == 0) return false;
        }
    }
    return true;
}

int search_prime(NODE* p){
    // p là L.phead nên khi đổi trỏ khác thì L cũng đổi tuy nhiên đây là tham chiếu
    int index = 1;
    while(p != NULL){
        if(isPrime(p->info)){
            return index;
        }
        else{
            index +=1;
            p = p-> pNext;
        }
    }

    return 0;
}



int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    cout << search_prime(L.pHead);

    return 0;
}
