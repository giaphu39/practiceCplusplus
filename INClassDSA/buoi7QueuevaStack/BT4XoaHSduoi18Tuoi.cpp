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
bool RemoveHead(LIST& l){ // có thể tích hợp lấy ra giá trị x bị xóa
    // có thể dùng hàm bool để là hàm xác định có xóa được không
    if(l.pHead == NULL) return false;

    NODE* deleteNODE = l.pHead;
    
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) l.pTail = NULL; // quên mất dòng này thì không ảnh hưởng kết quả nhưng rất quan trọng vì nó là bản chất nếu không có thì Tail vẫn sai

    delete deleteNODE;
    return true;
}

bool RemoveTail(LIST& l){
    NODE* p = l.pHead;
    NODE* deleteNODE = l.pTail;

    if(p == NULL ) return false; // trường hợp 1: không có gì để xóa
    else if(p == deleteNODE){ // trường hợp 2: chỉ có 1 phần tử để xóa
        // cắt đứt liên kết rồi mới xóa
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
        
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
    return true;

}
// hàm remove after Q 
// TH1: Q là null không xóa được, TH2: Q là nút cuối không xóa gì nhưng vẫn xem là xóa được
// TH3: p (nốt cần xóa != NULL) thì đầu tiên xét nó phải nốt cuối nếu nó là nốt cuối thì cho Q làm nốt cuối, sau cùng thì cho Q liên kết p->pNext
bool RemoveAfterQ(LIST& l, NODE* q){ // phần tử x nếu muốn lấy ra giá trị cần xóa
    NODE* p = NULL;

    if(q == NULL) return false;
    else{
        p = q->pNext;

        if(p == NULL) return true; // Q là nốt cuối
        if(p == l.pTail){
            l.pTail = q;
        }
       
        q->pNext = p->pNext; // nốt prev (q) sẽ liên kết nốt sau p( bị xóa )
        
        delete p;
    }
    return true;
}


void Fun(LIST& l){ // tìm kiếm tên năm sinh giống lặp mảng 2 lần sau đó đánh dấu số đã được chọn để không in lại
    NODE* p = l.pHead;
    if( p == NULL){
        cout<<"LIST rong";
        return;
    }
    
    NODE* q = NULL;
    while(p!= NULL){ // không lặp phần tử cuối
        int tuoi = 2025 - LayRaSoNam(p);
        
        if( tuoi < 18){
            if(p == l.pHead){
                RemoveHead(l);
                p = l.pHead;
                q = NULL;
                continue;
            }
            else{
                RemoveAfterQ(l,q);
                p = q->pNext;
                continue;
            }   
            
        }
        q = p;
        p = p->pNext;
    }

}





void PrintList(LIST L) {
    NODE* p;
    if (L.pHead == NULL)
        cout << "Empty";
    else {
        p = L.pHead;
        while (p) {
        cout << p->info.birth << " " << p->info.name << endl;
        p = p->pNext;
        }
    }
}


int main() {
    LIST L;
    CreateList(L); //Input
    Fun(L);           //Search-Sort
    PrintList(L);   //Output
    return 0;
}
