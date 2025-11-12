
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

void InitHashTable(HASHTABLE &H, int numbucket) {
    for (int i = 0; i<numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i) {
    NODEPTR p = H[i];
    while (p != NULL) {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket) {
    for (int i = 0; i<numbucket; i++) {
        cout << i ;
        TraverseBucket(H, i);
        cout << endl;
    }
}


#define EMPTY -1
void Init(HASHTABLE & H , int numbucket){
    for(int i =0 ; i< numbucket; i++){
        H[i] = NULL;
    }
}

void CreateHashTable(HASHTABLE& H,int& numbucket){
    cin >> numbucket;
    Init(H,numbucket);

    while(true){
        int x; cin >> x;
        int ind = HF(numbucket, x);
        if(x== -1) break;
        AddTail(H[ind],x);

    }
}
//bool removeHead(NODE* head){ // sai ở đây
bool removeHead(NODE*& head){
    if(head == NULL) return false;
    NODE* p = head;
    head = p->pNext;
    delete p;
    return true;
}

bool removeAfter(NODE* head, NODE* q){
    if(head == NULL || q == NULL) return false;
    NODE* p = q->pNext;
    q->pNext = p ->pNext;
    delete p;
    return true;
}

bool Remove(HASHTABLE H,int& numbucket,int x){

    int ind = HF(numbucket,x);
    NODE* p = H[ind];
    NODE* q = NULL;
    while(p){
        if(p->key == x){
            if(q == NULL){
                removeHead(p);
            }
            else removeAfter(H[ind], q);

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
