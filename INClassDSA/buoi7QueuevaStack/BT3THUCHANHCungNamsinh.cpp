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

int LayRaSoNam(NODE* p){
    return p->info.birth % 10000;
}

int mark[5000]; // mảng đánh dấu số năm đã in ra chưa
void Fun(LIST l){ // tìm kiếm tên năm sinh giống lặp mảng 2 lần sau đó đánh dấu số đã được chọn để không in lại
    NODE* p = l.pHead;
    if( p == NULL){
        cout<<"LIST rong";
        return;
    }
    

    NODE* j;
    bool flag =0; // cho biết đã Found chưa
    while(p!= l.pTail){ // không lặp phần tử cuối
        j = p->pNext;
        int soNamp = LayRaSoNam(p);
        bool chuaduocinlandau =0;
        while(j != NULL && !mark[soNamp]){
            int soNamj = LayRaSoNam(j);

            if(soNamp == soNamj){
                mark[soNamp] = 1; // đánh dấu năm đã trùng cũng như cho biết có năm trùng chưa
                if(!chuaduocinlandau){
                    chuaduocinlandau =1;
                    flag = 1;
                    Output(p);
                }
                Output(j);

            }
            j = j->pNext;
        }
        p = p->pNext;
    }

    if(!flag) cout<<"NOTFOUND";
}
int main() {
    LIST l;
    CreateList(l);
    Fun(l);
    // printList(l);
    return 0;
}
