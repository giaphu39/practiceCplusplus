#include <iostream>

using namespace std;


struct NODE{
    int data;
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

NODE* createNODE(int x){
    NODE * p = new NODE;

    if(p == NULL){
        exit(1);
    }

    p->data = x;
    p->pNext = NULL;
}

bool addHead(LIST& l, NODE* p){
    if(p == NULL) return false;

    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
        return true;
    }

    else{
        p->pNext = l.pHead;
        l.pHead = p;

        return true;
    }
}

bool addTail(LIST& l, NODE* p){
    if(p == NULL) return false;

    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
        return true;
    }

    else{
        l.pTail ->pNext = p;
        l.pTail = p;

        return true;
    }
}



bool removeHead(LIST& l, int& x){
    NODE* deleteNODE = l.pHead;

    if(deleteNODE == NULL) return false;
    if(deleteNODE == l.pTail){
        x = deleteNODE->data;
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
    }

    else{
        l.pHead = deleteNODE->pNext;
        x = deleteNODE->data;
        delete deleteNODE;
    }
}

bool removeTail(LIST& l , int& x){
    NODE* deleteNODE = l.pTail;
    if(deleteNODE == NULL) return false;

    if(deleteNODE == l.pHead){
        x = deleteNODE->data;
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
    }

    else{
        NODE* p = l.pHead;
        while(p->pNext->pNext != NULL){
            p = p->pNext;
        }

        p->pNext = NULL;
        x = deleteNODE->data;
        delete deleteNODE;

    }
}


bool removeAfterQ(LIST& l , NODE* q, int& x){
    if(q == NULL) return 0;
    else{
        if(q == l.pTail) return true;

        NODE* deleteNODE = q->pNext;
        if(deleteNODE == l.pTail){
            l.pTail = q;

        }
        x = deleteNODE->data;
        q->pNext = deleteNODE->pNext;
        delete deleteNODE;

        return true;
    }
}

bool removeALLX(LIST& l, int x){
    NODE* p, * prev;
    p = l.pHead;
    prev = NULL;

    while(p != NULL){
        if(p->data == x){
            if(p == l.pHead){
                removeHead(l,x);

                p = l.pHead;
                prev = NULL;
                continue; // quan trọng nhất là bước cập nhật lại
            }
            else{
                removeAfterQ(l,prev,x);

                p = prev->pNext;
                continue;
            }
        }

        prev = p;
        p = p->pNext;
    }

    return true;
}

bool SearchX(LIST l, NODE*& p, int x){
    p = l.pHead;
    while(p != NULL){

        if(p->data == x){
            return true;
        }


        p = p->pNext;
    }

    return false;
}

void SortLIST(LIST& l){
    NODE* p, * q, * MIN;

    p = l.pHead;
    q = NULL;
    MIN = NULL;


    while(p->pNext != NULL){
        MIN = p;
        q = p ->pNext;

        while( q != NULL){
            if(q ->data < MIN->data){
                MIN = q;
            }

            q = q->pNext;

        }
        if(p != MIN){
            swap(p->data, MIN->data);
        }
        p = p->pNext;
    }

}

bool TopFront(LIST& l, int& x){
    if(l.pHead == NULL) return false;
    x = l.pHead->data;
    return true;
}


bool Back(LIST& l, int& x){
    if(l.pTail == NULL) return false;
    x = l.pTail->data;
    return true;
}

bool addAfterQ(LIST& l, NODE* q, NODE* p){
    if(q == NULL || p == NULL) return false;
    else{
        p->pNext = q->pNext;
        q->pNext = p;
        if(q == l.pTail){
            l.pTail= p;
        }
    }

    return true;
}

void createLIST(LIST& l){
    createEmptyList(l);

    while(true){

        int thaoTac; cin >> thaoTac;
        if(thaoTac <= -1 ) break;

        else if(thaoTac == 0 || thaoTac == 1){
            int x; cin >> x;
            NODE* p = createNODE(x);
            if(thaoTac == 0){
                addHead(l,p);
            }
            else if(thaoTac == 1){
                addTail(l,p);
            }

        }
        else{
            if(thaoTac == 2){
                int x;
                removeHead(l,x);
            }
            if(thaoTac == 3){
                int x;
                removeTail(l,x);
            }

            if(thaoTac == 4){
                int x; cin >> x;
                int i =1;
                NODE* p = l.pHead;
                while(i != x){
                    i++;
                    p = p->pNext;
                }

                int y;
                removeAfterQ(l,p,y);
            }

            if(thaoTac == 5){
                int x; cin >> x;

                removeALLX(l,x);
            }

            if(thaoTac == 6){
                int x; cin >> x;
                NODE* p = NULL;

                SearchX(l,p,x);

                // đổi data tìm thấy đầu tiên thành 100
                p->data = 100;
            }

            if(thaoTac == 7){
                SortLIST(l);
            }

            if(thaoTac == 8){
                int x;
                cin >> x;
                NODE* p = NULL;
                SearchX(l,p,x);
                NODE* q = createNODE(x+100);
                addAfterQ(l,p,q);
            }
        }


    }

}
void printLIST(LIST& l){
    NODE* p = l.pHead;
    while(p != NULL){
        cout << p->data << " ";

        p = p->pNext;
    }


}
int main()
{
        LIST l;
        createLIST(l);
        printLIST(l);

        return 0;
}
