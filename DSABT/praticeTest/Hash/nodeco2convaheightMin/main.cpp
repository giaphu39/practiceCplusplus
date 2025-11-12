#include <iostream>

using namespace std;
// y tuong: lap tung node roi add vao neu co 2 node sau do xet tu cuoi len dau

struct NODE{
    int key;
    NODE* pLeft;
    NODE* pRight;

};
typedef NODE* TREE;

void Init(TREE& T){
    T = NULL;
}

NODE* createNODE(int x){ // nhớ phải tạo NODE mới insert được
    NODE* p = new NODE;
    p->key = x;
    p->pLeft= NULL;
    p->pRight = NULL;
    return p;
}

bool Insert(TREE& T, int x){
    if(T){
        if(T->key == x) return false;
        else if(T->key > x) return Insert(T->pLeft,x);
        return Insert(T->pRight,x);
    }
    T = createNODE(x);
    return true;
}

void createTREE(TREE& T){
    Init(T);
    while(true){
        int x; cin>> x;
        if(x==-1) break;
        Insert(T,x);
    }
}
#include<vector>

//void LNR(TREE T){
//    if(T){
//        LNR(T->pLeft);
//        cout <<T->key <<" ";
//        LNR(T->pRight);
//    }
//    return;
//}
int Depth(TREE T,TREE cur, int& level){
    if(T){
        if(T->key == cur->key){
            level++;
            return level;
        }
        else{
            level++;
            if(T->key > cur->key) return Depth(T->pLeft,cur,level) ;
            else  return Depth(T->pRight,cur,level) ;
            level--; // quay lui trong truong hop khong reteturn;
        }
    }
    level = -1;
    return -1;
}

void LNR(TREE T, TREE cur, vector<vector<TREE>> & temp){
    if(cur){
        LNR(T,cur->pLeft,temp);

        int level = -1;
        Depth(T,cur, level);

        if(cur->pLeft != NULL && cur->pRight != NULL && level!= -1){
            if(temp.size() <= level ) temp.resize(level+1);
            temp[level].push_back(cur);
        }

        LNR(T,cur->pRight, temp);

    }
    return;
}

void FIND(TREE T){
    vector<vector<TREE>> temp;
    LNR(T,T,temp);
    if(temp.empty()) cout <<"NOT FOUND";
    else{
        bool daIn = 0;
        for(int i = temp.size() -1; i >= 0; i--){ // qua chi so out range
            if(daIn) break;
            for(int j = 0; j < temp[i].size(); j++){
                cout << temp[i][j]->key << " ";
                daIn = 1;
            }

        }
    }
    return;
}
int main()
{
    TREE T;
    createTREE(T);
    FIND(T);
//    LNR(T);
    return 0;
}
