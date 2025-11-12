#include <iostream>

using namespace std;
struct NODE{
    int key;
    NODE* pLeft;
    NODE* pRight;
};

typedef NODE* TREE;

void createEmptyTREE(TREE& T){
    T = NULL;
}

NODE* createNODE(int x){
    NODE* p = new NODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

bool Insert(TREE& T, int x){
    if(T){
        if(T->key == x) return false;
        else if(T->key > x) return Insert(T->pLeft, x);
        else return Insert(T->pRight, x); // thieu return la sai
    }
    T = createNODE(x);
    return true;
}

void CreateTREE(TREE& T){
    createEmptyTREE(T);
    while(true){
        int x; cin >> x;
        if(x==-1) break;
        Insert(T,x);
    }
}

void LNR(TREE T){
    if(T){
        LNR(T->pLeft);
        cout << T->key <<" ";
        LNR(T->pRight);
    }
    return;
}
// tim do sau, tim chieu cao not bat ki
NODE* Search(TREE T, int x){
    if(T){
        if(T->key == x) return T;
        else if(T->key > x) return Search(T->pLeft, x);
        else return Search(T->pRight, x); // thieu return la sai
    }
    return NULL;
}

int Height(TREE T){
    if(T){
        int LHeight = Height(T->pLeft);
        int RHeight = Height(T->pRight);

        return max(LHeight, RHeight) + 1;

    }

    return -1;
}

int Depth(TREE T, TREE Cur, int& level){
    if(T){
        level++;
        if(T->key == Cur->key){
            return level;
        }
        else if(T->key > Cur->key) return Depth(T->pLeft, Cur, level);
        else  return Depth(T->pRight, Cur, level);
    }
    level = -1;
    return level;
}

// tim NODE cha, tim Sibling
NODE* SearchParent(TREE T, int x){
    if(T){
        if((T->pLeft != NULL && T->pLeft->key == x) || (T->pRight != NULL && T->pRight->key == x)){
            return T;
        }
        else if(T->key > x) return SearchParent(T->pLeft,x);
        else return SearchParent(T->pRight,x);
    }

    return NULL;
}

void inToTien(TREE T, int x, bool& flag){
    if(T){
        if(T->key == x){
            flag = true;
            return;
        }
        else if(T->key > x) inToTien(T->pLeft,x,flag);
        else inToTien(T->pRight,x,flag);

        if(flag) cout << T->key << " ";
    }

}
// tong so NODE va delete tree

int TongSoNODE(TREE T){
    if(T){

        int leftNODE = TongSoNODE(T->pLeft);
        int rightNODE = TongSoNODE(T->pRight);

        if(leftNODE > rightNODE){
            cout << T->key <<" ";
        }

        return leftNODE + rightNODE + 1;
    }
    return 0;
}

void ThayThe(TREE& T, TREE& deleteN){
    if(T->pRight !=NULL){
        ThayThe(T->pRight, deleteN);
    }
    else{
        deleteN->key = T->key;
        deleteN = T;
        T = T->pRight;
    }
}

void deleteNODE(TREE& T, int x){
    if(T){
        if(T->key > x) deleteNODE(T->pLeft,x);
        else if(T->key < x) deleteNODE(T->pRight,x);
        else{
            NODE* deleteN = T;
            if(deleteN ->pLeft == NULL && deleteN->pRight == NULL){
                T = NULL;
            }
            else if(deleteN->pLeft == NULL){
                T = T->pRight;
            }
            else if(deleteN ->pRight == NULL){
                T = T->pLeft;
            }
            else{
                ThayThe(T->pLeft,deleteN);
            }

            delete deleteN;
        }
    }
}

void Find(TREE T){
    int x; cin >> x;
    NODE* p = Search(T,x);
    cout <<Height(p) <<endl;
    int level = -1;
    cout << Depth(T,p,level) << endl;

    NODE* parent = SearchParent(T,x);
    if(parent){
        cout << parent->key << " la node cha cua " << x << endl;
        if(parent->pLeft == NULL || parent->pRight == NULL){
            cout << x << " khong co anh em "<<endl;
        }
        else{
            cout << parent->pLeft ->key << " va "<< parent->pRight->key << " la anh em cua nhau" <<endl;
        }
    }
    else{
        cout <<"NOT FOUND " << endl;
    }
    bool flag = 0;
    inToTien(T,x,flag);
    cout << "la to tien "<<endl;

     TongSoNODE(p);
     cout << endl;

     deleteNODE(T,x);
     LNR(T);






}

int main()
{
    TREE T;
    CreateTREE(T);
    Find(T);
    return 0;
}
