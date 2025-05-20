
#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    if (head == NULL) head = p;
	else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }



void init(HASHTABLE H){
    for (int i = 0; i < M; i++) H[i] = NULL;
}

void  CreateHashTable(HASHTABLE H,int& numbucket){
    init(H);
    cin >> numbucket;
    while(true){
        int key; cin >> key;
        if(key == -1 ) break;
        int ind = HF(numbucket, key);
        AddTail(H[ind], key);
    }
}

void Traverse(HASHTABLE H,int numbucket){
    for (int i = 0; i < numbucket; i++) {
        cout << i ;
        NODE* p = H[i];
        if (p != NULL) cout << " --> ";
        while (p != NULL) {
            cout << p->key;
            if (p->pNext != NULL) cout << " --> ";
            p = p->pNext;
        }
        cout << endl;
    }
}


int Search(HASHTABLE H, int numbucket, int x) {
    int ind = HF(numbucket, x);
    NODE* p = H[ind];
    while (p != NULL) {
        if (p->key == x) return ind; // index cũng được tùy cách dùng chương trình 
        p = p->pNext;
    }
    return -1; 
}

bool Remove(HASHTABLE H, int numbucket, int x) {
    int ind = HF(numbucket, x);
    NODE* p = H[ind];
    NODE* q = NULL;

    while (p != NULL) {
        if (p->key == x) {
            if (q == NULL) H[ind] = p->pNext;
            else q->pNext = p->pNext;

            delete p;
            return true;
        }
        q = p;
        p = p->pNext;
    }
    return false; 
}







int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x)) {
        cout << endl << x << ": Delete Successful."  << endl << endl;
        Traverse(H, numbucket);
    }
    else cout << endl << x << ": Delete Failed." << endl << endl;

    return 0;
}
