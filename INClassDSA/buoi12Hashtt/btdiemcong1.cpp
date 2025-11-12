#include <iostream>
using namespace std;
#define M 100
struct NODE{
    int key;
    NODE* pNext;
};

typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];


int HF(int numbucket, int key){
    return key % numbucket;
}









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

void init(HASHTABLE H){
    for (int i = 0; i < M; i++) H[i] = NULL;
}

bool Empty = 0;

void  CreateHashTable(HASHTABLE H,int& numbucket){
    init(H);
    cin >> numbucket;
    while(true){
        int key; cin >> key;
        if(key == -1 ) break;
        int ind = HF(numbucket, key);
        AddTail(H[ind], key);
        Empty = 1; // đánh dấu đã có giá trị chưa
    }
}

void Traverse(HASHTABLE H,int numbucket){
    if(!Empty){
        cout <<"Empty" <<endl;
        return;
    }
    for (int i = 0; i < numbucket; i++) {
        cout << i <<"| ";
        NODE* p = H[i];
        // if (p != NULL) cout << " --> ";
        if(p == NULL) cout <<"NULL";
        while (p != NULL) {
            cout << p->key;
            if (p->pNext != NULL) cout << " --> ";
            p = p->pNext;
        }
        cout << endl;
    }
}

void HashSearch(HASHTABLE H,int numbucket){
    if(!Empty){
        return;
    }
    NODE* MAX = H[0];
    NODE* MIN = H[0];
    for (int i = 0; i < numbucket; i++) {
        NODE* p = H[i];
        while (p != NULL) {
            if(p->key > MAX->key) MAX = p;
            if(p->key < MIN->key) MIN = p;
            p = p->pNext;
        }
    }


    cout << "MAX: "<< MAX->key<<endl;
    cout <<"MIN: " << MIN ->key <<endl;
}








int main(){
    HASHTABLE H;
    int numbucket;
    CreateHashTable(H,numbucket);
    Traverse(H,numbucket);

    HashSearch(H,numbucket);

    return 0;
}