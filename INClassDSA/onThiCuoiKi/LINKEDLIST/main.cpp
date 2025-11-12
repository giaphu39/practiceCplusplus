#include <iostream>
#include <string>
using namespace std;

struct Data{
    int key;
    string ten;
};

struct NODE{
    Data Key;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

NODE* createNODE(string Ten, int x){
    NODE* p = new NODE;
    p->pNext = NULL;
    p->Key.key = x;
    p->Key.ten = Ten;
    return p;
}

bool addTail(LIST& l, NODE* p){
    if(p){
        if(l.pTail == NULL){
            l.pHead = p;
            l.pTail =p;
        }
        else{
            l.pTail->pNext = p;
            l.pTail = p;
        }
        return 1;
    }
    return 0;
}
bool addHead(LIST& l, NODE* p){
    if(p){
        if(l.pHead == NULL){
            l.pHead = p;
            l.pTail =p;
        }
        else{
            p->pNext = l.pHead;
            l.pHead = p;
        }
        return 1;
    }
    return 0;
}

bool PopTail(LIST& l, int& x){
    NODE* p = l.pTail;
    if(p== NULL) return 0;
    if(p == l.pHead){
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else{
        NODE* q = l.pHead;
        while(q->pNext != NULL){
            q = q->pNext;
        }
        q->pNext = NULL;
        l.pTail = q;
    }
    x = p->Key.key;
    delete p;
    return 1;
}

bool PopHead(LIST& l, int& x){
    NODE* p = l.pHead;
    if(p == NULL) return 0;
    if(p == l.pTail){
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else{
        l.pHead = p->pNext;

    }
    x = p->Key.key;
    delete p;
    return 1;
}

bool removeAfterQ(LIST& l, NODE* q){
    if(q == NULL) return 0;
    NODE* p = q->pNext;
    if(p == l.pTail) l.pTail = q;
    q->pNext= p->pNext;
    return true;
}

bool RemoveAfterX(LIST& l, string x){
    NODE* p = l.pHead;
    NODE* q = NULL; // prev
    while(p){
        if(p->Key.ten == x){
            if(q == NULL){
                int j;
                PopHead(l,j);
                p = l.pHead;
                continue;
            }
            else{
                removeAfterQ(l,q);
                p = q->pNext;
                continue;
            }
        }
        q = p;
        p = p->pNext;
    }

}

void CreateList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;

    while(true){
        int x; cin >> x;
        if(x == -1) break;
        cin.ignore();
        string ten;
        getline(cin,ten);
        NODE* p = createNODE(ten,x);
        addTail(l,p);
    }
}

void Output(LIST l){
    NODE* p = l.pHead;
    while(p){
        cout << p->Key.key << " " << p->Key.ten <<endl;
        p = p->pNext;
    }
}

bool Cmp(Data a, Data b){
    if(a.ten != b.ten) return a.ten < b.ten;
    if(a.key != b.key) return a.key < b.key;
    return 0;
}

void Sort(LIST& l){
    NODE* i,*j , *MIN;
    i = l.pHead; // quen gan
    while(i->pNext != NULL){
        MIN = i;
        j = i->pNext;
        while(j){
            if(Cmp(j->Key,MIN->Key)){
                MIN = j;
            }
            j = j->pNext;
        }
        if(MIN != i){
            swap(i->Key.key, MIN->Key.key);
             swap(i->Key.ten, MIN->Key.ten);
        }
        i = i->pNext;
    }

}

int main()
{
    LIST l;
    CreateList(l);
    Output(l);
//    int x; PopTail(l,x); cout << x;
    cout << endl;
    Sort(l);
//    RemoveAfterX(l,"a");
    Output(l);
    return 0;
}
