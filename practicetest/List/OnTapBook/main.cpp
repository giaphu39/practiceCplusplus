#include <iostream>

using namespace std;


#define MAX 200

struct DATA{
    int ms;
    char* str;
    char ls;
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
    l.pHead =NULL;
    l.pTail = NULL;
}
#include<cstring>

NODE* createNODE(int ms, char* str, char ls){
    NODE* p = new NODE;

    p->data.ms = ms;
    p->data.str = new char[strlen(str) + 1];
    strcpy(p->data.str,str);
    p->data.ls = ls;

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
bool addTail(LIST& l, NODE* p){
    if(p == NULL) return 0;
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }

    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }

    return true;
}

void tachChuKiTu(char* str, char& ls ){
    int n = strlen(str);
    ls = str[n - 1];
    str[n - 2] = '\0'; // bỏ luôn dấu cách
}

void createLIST(LIST& l){
    int n; cin >> n;
    int i = 0;
    while(i < n){
        int ms;
//        char* str[MAX]; // nhớ phải cấp phát vùng nhớ nếu không sẽ lỗi và nhớ khi cấp phát mà không dùng new chắc chắn crash
        char ls;

        cin >> ms;
        cin.ignore(1);
        char str[MAX];
        cin.getline(str, MAX);
        tachChuKiTu(str, ls);

//        cin.ignore();
        NODE* p = createNODE(ms,str,ls);
        addTail(l,p);

        i++;
    }
}

void printLIST(LIST l){
    NODE* p = l.pHead;
    if(p == NULL){
        cout <<"LIST RONG";
        return;
    }
    while(p != NULL){

        cout << p->data.ms << " ";
        for(int i = 0; p->data.str[i] != '\0'; i++){
            cout << p->data.str[i];
            }
        cout << " " << p->data.ls << endl;
        p = p->pNext;
        }

}
#include<unordered_map>

//void ThongKeLoai(LIST l){
//    unordered_map <char, int > loai;
//    NODE* p = l.pHead;
//
//    while(p != NULL){
//        unordered_map<char, int>::iterator it = loai.find(p->data.ls);
//        if(it == loai.end()){ // khong tim thay
//                loai.insert({p->data.ls, 1});
//        }
//
//        else{
//            (*it).second += 1;
//        }
//
//        p = p->pNext;
//    }
//
//    for(unordered_map<char, int>::iterator it = loai.begin(); it != loai.end() ; it++){
//        cout << (*it).first << " : " << (*it).second;
//
//        cout << endl;
//    }
//}
#include<vector>
#include<utility>

void ThongKeLoai(LIST l){
    vector<pair<char, int>> loai;
    NODE* p = l.pHead;

    while(p != NULL){
        bool found = false;
        for(auto& item : loai){
            if(item.first == p->data.ls){
                item.second += 1;
                found = true;
                break;
            }
        }
        if(!found){
            loai.push_back({p->data.ls, 1});
        }
        p = p->pNext;
    }

    for(auto item : loai){
        cout << item.first << " : " << item.second << endl;
    }
}

int my_strcmp(const char* a, const char* b){
    while(*a != '\0' && *b != '\0'){
        if(* a != * b){
            return *a - *b;
        }
        a++;
        b++;

    }

    return *a - *b;
}

void XetThuTu(LIST l){
    NODE* p = l.pHead;
    // ý tưởng: lặp 2 lần để biết tăng hoặc giảm, dùng cờ để kết thúc nếu khác tăng/ giảm nếu 2 cờ = 0 thì unorder

    bool Up = 1;
    bool Down = 1;

    // check tang
    while(p->pNext != NULL){
        NODE* q = p ->pNext;
        bool flag = 1;
        while(q != NULL){
            int dau = my_strcmp(p->data.str, q->data.str);
            if(dau > 0){
                Up =0;
                flag = 0;
                break;
            }
            q = q->pNext;

        }

        if(!flag) break;

        p = p->pNext;
    }

    // nhớ quan trọng nhất là phải reset biến p
    p = l.pHead;

    while(p->pNext != NULL){
        NODE* q = p ->pNext;
        bool flag = 1;
        while(q != NULL){
            int dau = my_strcmp(p->data.str, q->data.str);
            if(dau < 0){
                Down =0;
                flag = 0;
                break;
            }
            q = q->pNext;

        }

        if(!flag) break;

        p = p->pNext;
    }


    if(! Down && ! Up ){
        cout << "Unoredered" << endl;
    }
    else{
        if(Down && l.pHead->pNext != NULL) cout << "Decrease"; // chỉ xét 1 phần tử thì tính là increase
        if(Up) cout << "Increase";
    }

}
char chuyenSangThuong(char a){
    if(a >= 'A' && a <='Z') return a + 32;
    return a;
}

int my_strcmpNotUpper(const char* a, const char * b){
    while( * a != '\0' && * b != '\0'){
        if(chuyenSangThuong(*a) != chuyenSangThuong(*b)){
            return chuyenSangThuong(*a) - chuyenSangThuong(*b);
        }

        a++;
        b++;


    }

    return chuyenSangThuong(*a) - chuyenSangThuong(*b);
}

void Swap(NODE* p, NODE* q){
    swap(p->data.ls, q->data.ls);
    swap(p->data.str, q->data.str); // chú ý
    swap(p->data.ms, q->data.ms);
}

void Sort(LIST& l){
    NODE* p, *q ,* MIN;
    p = l.pHead;

    while(p ->pNext != NULL){
        MIN = p;
        q = p->pNext;

        while(q!=NULL){
            int dau = my_strcmpNotUpper(MIN->data.str,q->data.str);
            if(dau > 0){
                MIN = q;
            }


            q = q->pNext;
        }
        // chú ý là swap sau vòng lặp trong
        if(MIN != p) Swap(p,MIN);

        p = p->pNext;
    }
}

bool removeHead(LIST& l){
    NODE* deleteNODE = l.pHead;
    if(l.pHead == NULL) return false;

    else if( deleteNODE == l.pTail){
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
    }

    else{
        l.pHead = deleteNODE->pNext;
        delete deleteNODE;
    }
}

bool removeTail(LIST& l){
    NODE* deleteNODE = l.pTail;
    if(l.pHead == NULL) return false;

    else if( deleteNODE == l.pHead){
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
    }

    else{
        NODE* p = l.pHead;
        while(p->pNext->pNext != NULL){
            p = p->pNext;
        }
        p ->pNext = NULL;

        delete deleteNODE;
    }
}


bool removeAfterQ(LIST& l, NODE* q){
    if(q == NULL) return false;
    else{
        if(q->pNext == NULL) return true;
        NODE* deleteNODE = q->pNext;
        if(deleteNODE == l.pTail){
            l.pTail = q;
        }
        q ->pNext = deleteNODE->pNext;

        delete deleteNODE;

    }
}

void XoaMaSachDuoiX(LIST& l, int x){
    NODE* p = l.pHead;
    NODE* q = NULL;
    while(p != NULL){
        if(p->data.ms < x && p == l.pHead){
            removeHead(l);
            p = l.pHead;
            q = NULL;
            continue;

        }
        else if(p->data.ms < x ){
            removeAfterQ(l,q);
            p = q->pNext;
            continue;
        }

        q = p;
        p = p->pNext;


    }


}

int main()
{
    LIST l;
    createEmptyList(l);
    createLIST(l);

//    printLIST(l);
//    ThongKeLoai(l);
//    XetThuTu(l);

//    Sort(l);
//    printLIST(l);
    cout <<endl;
    XoaMaSachDuoiX(l,10);
    printLIST(l);
    return 0;
}
