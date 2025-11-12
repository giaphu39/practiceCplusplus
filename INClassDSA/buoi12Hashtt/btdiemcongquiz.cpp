#include <iostream>
using namespace std;
#define MAXTABLESIZE 1000
struct NODE {
    int key;
};
int TableSize;
typedef NODE HASHTABLE[MAXTABLESIZE];
int HF(int key) { return key%TableSize;}
int HF_LinearProbing(int key, int i) {
    return (HF(key) + i) % TableSize;
}




//###INSERT CODE HERE -

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}


void init(HASHTABLE H){
    for (int i = 0; i < M; i++) H[i] = NULL;
}

void AddHASH(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    head = p;
}



bool Empty = 0;

void  CreateHashTable(HASHTABLE H,int& numbucket, int m){
    init(H);
    cin >> numbucket;
    TableSize = numbucket;
    
    while(true){
        int key; cin >> key;
        if(key == -1 ) break;
        int ind = HF(key);
        int i =0;
        while(H[ind] != NULL){
            ind = HF_LinearProbing(key,i);
            i++;
        }
        AddHASH(H[ind], key);

        Empty = 1; // đánh dấu đã có giá trị chưa
    }
}

void HashFun(HASHTABLE H,int numbucket, int m){
    if(!Empty){
        cout <<"Empty" <<endl;
        return;
    }
    for (int i = 0; i < numbucket; i++) {
        cout << i <<"| ";
        NODE* p = H[i];
        // if (p != NULL) cout << " --> ";
        if(p == NULL) cout <<"NULL";
        else{
            cout << p->key;
        }
        cout << endl;
    }
}

// void HashSearch(HASHTABLE H,int numbucket){
//     if(!Empty){
//         return;
//     }
//     NODE* MAX = H[0];
//     NODE* MIN = H[0];
//     for (int i = 0; i < numbucket; i++) {
//         NODE* p = H[i];
//         while (p != NULL) {
//             if(p->key > MAX->key) MAX = p;
//             if(p->key < MIN->key) MIN = p;
//             p = p->pNext;
//         }
//     }


//     cout << "MAX: "<< MAX->key<<endl;
//     cout <<"MIN: " << MIN ->key <<endl;
// }




int main(){
    HASHTABLE H;
    int CurrentSize;
    int M;
    CreateHashTable(H, M, CurrentSize);
    HashFun(H, M, CurrentSize);
    return 0;
}