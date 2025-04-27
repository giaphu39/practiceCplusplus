#include <iostream>
#include<string>
using namespace std;


struct DATA{
    int MaSach;
    string TenSach;
    char LoaiSach;
};

struct NODE{
    DATA data;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

void createEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;
}

void strcpy(string& Tensach, string tensach){
    int i =0;
    while(tensach[i]!='\0'){
        Tensach[i] = tensach[i];
        i++;
    }
}

NODE* createNODE(int masach, string tensach, char loaisach){
    NODE* p = new NODE;
    if(p == NULL){
        exit(1);
    }
    else{
        p->data.MaSach = masach;
//        strcpy(p->data.TenSach, tensach);
        p->data.TenSach = tensach;
        p->data.LoaiSach = loaisach;

        p->pNext = NULL; // nhớ chỗ này

        return p;
    }
}

void addTail(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void tachTenSachvaLoaiSach(string& tensach, char& loaisach){
    int i = 0;
    int j;
    while(tensach[i] != '\0'){
        j=i;
        i++;
    }
    loaisach = tensach[j];
    tensach[j] = '\0';
}
// còn xét có thứ tự thì phân biệt hoa thường
// sắp xếp không phân biệt hoa thường
int n;
void createList(LIST& l){
    cin >> n;
    for(int i=0;i<n;i++){
        int masach; string tensach; char loaisach;
        cin >> masach;
        cin.ignore();
        getline(cin,tensach);
//        cin >> loaisach;
        tachTenSachvaLoaiSach(tensach,loaisach);

        NODE* p = createNODE(masach,tensach,loaisach);
        addTail(l,p);

    }
}

void output(LIST l){
    NODE* p =l.pHead;
    if( p == NULL){
        cout<<"LIST rong";
        return;
    }
    while(p!=NULL){
        cout<< p->data.MaSach<<" " << p->data.TenSach << " " << p->data.LoaiSach <<endl;
        p = p->pNext;
    }
}
#define MAX 300
int loaisach[MAX];

void ThongKeLoaiSach(LIST l){
    // vẫn chưa đúng yêu cầu lắm vì yêu cầu là in theo thứ tự nhập vào
    NODE* p = l.pHead;

    while(p!=NULL){
        loaisach[p->data.LoaiSach] += 1;
        p = p->pNext;
    }

    for(int i =0; i < MAX;i++){
        if(loaisach[i]){
            cout << char(i) << " : " << loaisach[i];
            cout<<endl;
        }
    }
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


void Fun(LIST& l){
    NODE* p = l.pHead;

    NODE* q = NULL;
    while(p!= NULL){ // không lặp phần tử cuối
        int masach = p->data.MaSach;

        if( masach < 10){
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


int StrCmp(char a, char b){
    if(a > b) return 1;
    else if( a == b) return 0;
    else return -1; // a < b

}

void checkOrder(LIST& l){

}

bool R(char a, char b){
    if(a <= b) return 1;
    else return 0;

}
//
//bool RInString(string a, string b){
//    // nếu giống nhau mà ít từ hơn thì < hơn
//    int i
//    for(i =0 ; a[i] != '\0'; i++){
//        if(!R(a[i], b[i])){
//            return false; // a > b
//        }
//    }
////    if(b[i] != '\0'){ // so luong b > a
////        return true;
////    }
//    return true;
//
//}

void toLower(string& s){
    int i =0;
    while(s[i]!='\0'){
        if(s[i]>='A' && s[i] <='Z'){
            s[i] += 32;
        }

        i++;
    }
}
void LowerAll(LIST& l){
    NODE* p = l.pHead;
    while( p != NULL){
        toLower(p->data.TenSach);
        p = p->pNext;
    }
}
// làm sao để lower rồi để so sánh mà vẫn giữ được giá trị tên
// dùng copy LIST xét trên LIST copy này nhưng thay đổi vị trí tại giá trị gốc

LIST copyLIST(LIST& l, LIST& temp){
    NODE* p = l.pHead;
    NODE* q = temp.pHead;

    while(p != NULL){
        int masach = p->data.MaSach;
        string tensach = p->data.TenSach;
        char loaisach = p->data.LoaiSach;

        NODE* pTemp = createNODE(masach,tensach,loaisach);
        addTail(temp,pTemp);

        p = p->pNext;
        q = q->pNext;
    }
}
void Sort(LIST& l){
    NODE* p, * q, *MIN;
    p= l.pHead;

    LIST temp;
    copyLIST(l,temp);
    LowerAll(temp); // lúc này thì copy toàn là chữ thường

    while( p->pNext != NULL){
        q = p->pNext;
        MIN = p;
        while(q != NULL){

        }
    }

}


int main()
{
    LIST l;
//    createBook(l);
    createEmptyList(l);
    createList(l);

    Fun(l);
    cout <<endl;
    output(l);

//    ThongKeLoaiSach(l);
    return 0;
}
