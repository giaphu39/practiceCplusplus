#include <iostream>

using namespace std;
struct NODE{
    int key;
    NODE* pLeft;
    NODE* pRight;
};
typedef NODE* TREE;

NODE* createNODE(int x){
    NODE* p = new NODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight= NULL;
    return p;
}

bool Insert(TREE& t, int x){
    if(t){
        if(t->key == x) return 0;
        else if(x < t->key) return Insert(t->pLeft,x);
        else return Insert(t->pRight,x);
    }
    t =createNODE(x);
    return 1;
}

void CreateTREE(TREE& t){
    t = NULL;
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        Insert(t,x);
    }
}

NODE* Search(TREE t, int x){
    if(t){
        if(t->key == x) return t;
        else if(x < t->key) return Search(t->pLeft,x);
        else return Search(t->pRight,x);
    }
    return NULL;
}

NODE* SearchParent(TREE t, int x){
    if(t){
        if((t->pLeft && t->pLeft->key == x)|| (t->pRight && t->pRight->key == x)) return t;
        else if(x < t->key) return SearchParent(t->pLeft,x);
        else return SearchParent(t->pRight,x);
    }
    return NULL;
}

void LNR(TREE t){
    if(t){
        LNR(t->pLeft);
        cout << t->key << " ";
        LNR(t->pRight);
    }
    return;
}

void NodeAnhEm(TREE t){
    int x; cin >> x;
    NODE* p =SearchParent(t,x);
    if(p == NULL) {
        cout << "khong ton tai" << x << endl; return;
    }
    else{
        if(p->pLeft == NULL || p->pRight == NULL){
            cout << x << " khong co anh em" << endl;
            return;
        }
        else{
            if(p->pLeft->key == x){
                cout << x << " va " << p->pRight->key << " la 2 anh em"<<endl;
                return;
            }
            else{
                cout << x << " va " << p->pLeft->key << " la 2 anh em"<<endl;
                return;
            }
        }
    }
}

void DQ(TREE t, bool& flag, int x){
    if(t){
        if(t->key == x){
            flag =1;
        }
        else if(x < t->key){
            DQ(t->pLeft , flag , x);
        }
        else{
            DQ(t->pRight,flag , x);
        }

        if(flag) cout << t->key << " ";
    }
    return;
}

void NODEToTien(TREE t){
    bool flag =0;
    int x; cin >> x;
    DQ(t,flag,x);

}

int main()
{
    TREE t;
    CreateTREE(t);
    LNR(t); cout << endl;
//    NodeAnhEm(t);
    NODEToTien(t);
    return 0;
}
