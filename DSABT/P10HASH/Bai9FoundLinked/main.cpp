
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


void Init(HASHTABLE H, int numbucket){
    for(int i=0;i<numbucket ;i++){
        H[i] = NULL;
    }
}

void CreateHashTable(HASHTABLE& H,int& numbucket){
    cin >> numbucket;
    Init(H,numbucket);
    while(true){
        int x; cin >> x;
        if(x==-1) break;
        int ind = HF(numbucket,x);
        AddTail(H[ind], x);

    }
}

void Traverse(HASHTABLE H,int numbucket){
    for(int i =0;i<numbucket ; i++){
        cout << i ;
        NODE* p = H[i];
        while(p){
            cout << " --> " <<p->key;
            p = p->pNext;
        }
        cout <<endl;
    }


}

int Search(HASHTABLE H,int numbucket,int x){
    int ind = HF(numbucket,x);
    NODE* p = H[ind];
    while(p){
        if(p->key == x){
            return ind;
        }
        p = p->pNext;
    }

    return -1;
}



//7
//50 700 76 85 92 73 101 -1
//85

//
//7
//50 700 76 85 92 73 101 -1
//86

int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    cin >> x;
    int i=Search(H, numbucket, x);
    cout << endl;
    if(i==-1)
        cout << x << " not found.";
    else
        cout << x << " found in bucket " << i << ".";
    return 0;
}

