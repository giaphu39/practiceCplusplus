#include <iostream>
using namespace std;
#define MAX 100

struct User{
    int birth;
    char name[100];
};
struct NODE {
    // int info; // chỗ này có vẻ sai
    User info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};


//###INSERT CODE HERE - Áp dụng câu 1-2-3

// nhớ còn có test case trùng tên , viết thường viết hoa đều có ý nghĩa tìm kiếm như nhau

void CreateEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;
}
#include <cstring>
NODE* CreateNODE(int date, char s[MAX]){
    NODE* p = new NODE;

    p->info.birth = date;
    // p->info.name = s;
    strcpy(p->info.name, s); // không thể gán con trỏ như trên mà phải copy từng phần tử qua
    
    // for(int i =0 ;i< MAX; i++){
    //     p->info.name[i] = s[i];
    // } // sai vì copy những phần tử outrange
    
    p->pNext = NULL;

    return p; // đây là quan trọng nhất đã sai khúc này
}
void addTail(LIST& l, NODE* p){

    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;    
    }
    else{
        // p->pNext = l.pTail;
        l.pTail->pNext = p; // không được sai chỗ này nữa
        l.pTail = p;
    }
}

void CreateList(LIST& l){
    CreateEmptyList(l);

    int n; cin>> n;
    int i =0 ;

    while(i< n){
        int birth;
        char s[MAX]; // phải cấp phát tĩnh vì đây là mảng
        cin>> birth;
        cin.ignore(1);
        cin.getline(s,MAX);
        NODE* p = CreateNODE(birth,s);
        addTail(l,p);

        i++; // không được sai chỗ này nữa
    }
}
void printList(LIST l){
    NODE* p = l.pHead;
    if( p == NULL){
        cout<<"LIST rong";
        return;
    }
    
    while(p!=NULL){
        cout<< p->info.birth << " "<<p->info.name<<endl;
        p = p->pNext;
    }
}
void Output(NODE* p){
    cout<< p->info.birth << " "<<p->info.name<<endl;
}

void Fun(LIST l){ // tìm kiếm tên giống tên được nhập rồi xuất ra thông tin
    NODE* p = l.pHead;
    if( p == NULL){
        cout<<"LIST rong";
        return;
    }
    
    char Search[MAX];
    // cin.ignore(1);

    cin.getline(Search, MAX);


    bool DaIn =0;
    while(p!=NULL){
        if(strcmp(p->info.name, Search) == 0){
            DaIn =1 ;
            Output(p);
        }
        p = p->pNext;
    }

    if(!DaIn) cout<<"NOTFOUND";
}
int main() {
    LIST l;
    CreateList(l);
    Fun(l);
    // printList(l);
    return 0;
}
