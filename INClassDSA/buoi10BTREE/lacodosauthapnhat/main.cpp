#include <iostream>

using namespace std;

struct TNODE{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

TREE createNODE(int x){
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
}

bool Insert(TREE& T, TREE p){
    if(T == NULL){
        T = p;
        return 1;
    }
    else{
        if(T->key == p->key){
            return 0;
        }
        if(p->key < T->key) return Insert(T->pLeft, p);
        else return Insert(T->pRight, p);
    }
}
void CreateTree(TREE& T){
    T = NULL;

    while(true){
        int x; cin>> x;
        if(x == -1) break;
        TREE p = createNODE(x);
        Insert(T,p);
    }
}

void NLR(TREE T){
    if(T == NULL) return;
    else{
        cout << T->key <<" ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}
#include <vector>

bool FindDepth(TREE T, TREE current, int& level){
    if(T == NULL){
        level = -1;
        return 0;
    }
    else{
        if(T->key == current->key){
            level++;
            return 1;
        }
        else{
            level++;
            if(current->key < T->key) return FindDepth(T->pLeft, current, level);
            else return FindDepth(T->pRight, current, level);
        }
    }
}

void addToLIST(TREE T, TREE current ,vector<vector<TREE>>& LIST ){
    if(current == NULL){
        return;
    }
    else{
        int level = -1;
        FindDepth(T,current,level);

        if(LIST.size() <= level) LIST.resize(level+1);
        if(current->pLeft == NULL && current->pRight == NULL){
            LIST[level].push_back(current);
        }

        addToLIST(T,current->pLeft,LIST);
        addToLIST(T,current->pRight,LIST);

    }
}

void outputLIST(vector<vector<TREE>> LIST){
    bool flag = 1;
    for(int i = 0; i < LIST.size(); i++){
        if(!flag){
            break;
        }
        for(int j = 0; j < LIST[i].size(); j++){
            flag = 0;
            cout << LIST[i][j]->key <<" ";
        }
    }
}

void Find(TREE T){
    if(T== NULL) cout <<"Empty\n";
    else{
        vector<vector<TREE>> LIST;
        addToLIST(T,T,LIST);
        outputLIST(LIST);
    }
}


// ý tưởng mảng 2 chiều chứa độ sâu và từng giá trị trong đó
// 8 3 1 6 4 7 10 14 13 -1
int main()
{
    TREE T;
    CreateTree(T);
    Find(T);
//NLR(T);
    return 0;
}
