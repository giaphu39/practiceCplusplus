#include <iostream>
using namespace std;
#define MAXTABLESIZE 1000
struct NODE {
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];
int HF(int key, int M) { return key%M;}
int HF_LinearProbing(int key, int i, int M) {
    return (HF(key,M) + i*(7-key%7)) % M;
}




//###INSERT CODE HERE -
const int EMPTY = -1;

void Init(HASHTABLE& H, int& M){
    for(int i = 0 ;i<M;i++){
        H[i].key = EMPTY;
    }
}

bool Insert(HASHTABLE& H, int& M, int x){
    int ind = HF(x,M);

    int i =1;
    while(H[ind].key != EMPTY){

        if(i>=M) return false;
        if(H[ind].key == x) return false;
        ind = HF_LinearProbing(x,i,M);

        i++;
    }

    H[ind].key = x;
    return true;
}

void CreateHashTable(HASHTABLE& H, int& M){
    cin >> M;
    Init(H,M);
    int daIn = 0;
    while(true){
        int x; cin>>x;
        if(x==-1)break;

        if(!Insert(H,M,x)){
            daIn = 1;
            cout << x <<" ";
        }

    }

    if(!daIn) cout <<"NotFound";
}


int main(){
    HASHTABLE H;
    int M;
    CreateHashTable(H, M);
//    HashFun(H, M);
    return 0;
}
