/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template 
class 
typedef
pair
set
map
###End banned keyword*/ 


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE {
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;

int HF(int key) {
    return key%TableSize;
}
 
//###INSERT CODE HERE -

const int EMPTY = -1;

int HF2(int key){
    return 7 - key % 7;
}

void Init(HASHTABLE& H,int& CurrentSize){
    for(int i = 0; i < CurrentSize ; i++){
        H[i]->key = EMPTY;
    }
}

bool Insert(HASHTABLE& H,int& CurrentSize, int x){
    int ind = HF(x);
    
    while(H[ind]->key != EMPTY){
        
    }

    H[i] = x;
}

void CreateHashTable(HASHTABLE& H,int& CurrentSize){
    Init(H,CurrentSize);

    while(true){
        int x ; cin >> x;
        if(x ==-1)break;

    }
}


int main(){
    HASHTABLE H;
    int CurrentSize;
    CreateHashTable(H, CurrentSize);
    Fun(H, CurrentSize);
    return 0;
}