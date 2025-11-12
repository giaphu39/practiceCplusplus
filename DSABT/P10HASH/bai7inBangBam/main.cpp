

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE {
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key) {
    return key%M;
}
int HF_LinearProbing(int key, int i) {
    return (HF(key) + i) % TableSize;
}

// khong dam bao chinh xac node nao duoc insert roi do ko dung con tro
#define EMPTY -1
// nho khong duoc ;


void Init(HASHTABLE& H){
    for(int i =0 ; i< TableSize ; i++){
//        H[i] = EMPTY;
// lõi gán ở đây
        H[i].key = EMPTY;
    }
}
void Insert(HASHTABLE& H, int x ){
    int ind = HF(x);
    int i = 1;
    while(H[ind].key != EMPTY){
        if(H[ind].key == x) return; // không lưu khóa trùng nhau

        ind = HF_LinearProbing(x,i);
        i++;
    }
    H[ind].key = x;

}
void  CreateHashTable(HASHTABLE& H,int& CurrentSize){
    cin >> M;
    cin >> TableSize;

    Init(H);
    while(true){
        int x; cin >> x;

        if(x == -1) break;
        Insert(H,x);
        CurrentSize++;
        if(CurrentSize == TableSize) break; // phải có dòng này vì nếu cứ add vào mà không quản lí số lượng giới hạn sẽ runtime

    }
}


void Traverse(HASHTABLE H,int CurrentSize){
    for(int i = 0; i< TableSize; i++){
        cout<< i <<" --> "<< H[i].key << endl;
    }
}

//7
//11
//22 1 13 11 24 33 18 42 31 -1
//



int main(){
    HASHTABLE H;
    int CurrentSize;

    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);

    return 0;
}
