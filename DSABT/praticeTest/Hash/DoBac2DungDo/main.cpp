#include <iostream>
using namespace std;
#define MAXTABLESIZE 1000
struct NODE {
    int key;
};

typedef NODE* HASHTABLE[MAXTABLESIZE];
//###INSERT CODE HERE -
// nho chu y ki HASTABLE LA LOAI GI


int HF(int key, int M) { return key%M;}
int HF_LinearProbing(int key, int i, int M) {
    return (HF(key,M) + i * i) % M;
}

void Init(HASHTABLE& H, int& M){
    for(int i =0; i< M;i++){
        H[i] = NULL;
    }
}
NODE* createNODE(int x){
    NODE* p = new NODE;
    p->key = x;
    return p;
}

bool Insert(HASHTABLE& H, int& M, int x){
    int ind = HF(x,M);
    NODE* p = H[ind];
    int i = 1;
    while(p){
        if(p->key == x) return false;
        if(i >= M) return false;
        ind = HF_LinearProbing(x,i,M);
        i++;
        p = H[ind];
    }

    H[ind] = createNODE(x);
    return true;
}

void CreateHashTable(HASHTABLE& H, int& M){
    cin >> M;
    Init(H,M);
    while(true){
        int x; cin>> x;
        if(x == -1) break;
        Insert(H,M,x);

    }
}
int FindPre(HASHTABLE H, int M, int x){
    int ind = HF(x,M);
    NODE* p = H[ind];
    int i = 1;
    while(p){
        if(p->key == x) return ind;
        if(i >= M) return -1;
        ind = HF_LinearProbing(x,i,M);
        i++;
        p = H[ind];
    }
    return -1;
}



void Find(HASHTABLE H, int M, int x){
    int ind = HF(x,M);
    NODE* p = H[ind];
    cout << "H(" << x << ")=" << ind;
    if(p == NULL){
         cout <<"(End}"; return;
    }
    else{
        if(p->key == x) return;
        else cout <<"(collision)";
    }
    cout << endl;
    int i = 1;
    while(p){

        if(i >= M) return ;
        ind = HF_LinearProbing(x,i,M);
        i++;
        p = H[ind];
        cout <<  "H(" << x << ")=" << ind;

        if(p->key == x){
            return;
        }
        else{
            cout <<"(collision)";
        }
        cout <<endl;
    }

    return;
}

void HashFun(HASHTABLE& H, int M){
    int x; cin >> x;
    int ind = FindPre(H,M,x);
    if(ind == -1){
        cout <<x << " NOT Found";
    }
    else{
        cout << x << " FOUND IN BUCKET " << ind;
    }
    cout <<endl;
    Find(H,M,x);


}


int main(){
    HASHTABLE H;
    int M;
    CreateHashTable(H, M);
    HashFun(H, M);
    return 0;
}

