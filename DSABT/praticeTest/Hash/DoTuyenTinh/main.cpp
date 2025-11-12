#include<iostream>
using namespace std;
#define MAXTABLESIZE 1000
struct NODE{
    int key;
};
typedef NODE* NODEPTR;
typedef NODEPTR HASHTABLE[MAXTABLESIZE];




//###INSERT CODE HERE -
int HF(int key , int M){
    return key% M;
}

int HF_LinearProbing(int key, int i, int M){
    return (key + i) % M;
}

bool EMPTY = 1;

void Init(HASHTABLE& H, int& M){
    for(int i = 0 ;i < M; i++){
        H[i] = NULL;
    }
}
NODE* createNODE(int x){
    NODE* p = new NODE;
    p->key = x;
    return p;
}
bool Insert(HASHTABLE& H, int M, int x){
    int ind = HF(x,M);
    NODE* p = H[ind];
    int i = 1;
    while(p){
        if(i >= M -1) return false;
        if(p->key == x) return false;
        ind = HF_LinearProbing(x,i,M);
        i++;
        p = H[ind];
    }

    H[ind] = createNODE(x);
    return true;

}

void CreateHashTable(HASHTABLE& H, int& M){
    cin >> M;
    Init(H, M);

    while(true){
        int x; cin >> x;
        if(x == -1) break;
        Insert(H,M,x);
        EMPTY = 0;

    }

}

void HashFun(HASHTABLE& H, int M){
    if(EMPTY){
        cout << "Empty"; return ;
    }
    for(int i = 0 ; i< M; i++){
        cout << i <<"| ";
        NODE* p = H[i];
        if(p){
            cout << p->key;
        }
        else cout << "NULL";
        cout << endl;
    }
}


int main(){
    HASHTABLE H;
    int M;
    CreateHashTable(H, M);
    HashFun(H, M);
    return 0;
}
