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
    p->pRight = NULL;
    return p;
}

bool Insert(TREE& t, int x){
    if(t){
        if(t->key == x) return 0;
        else if(x < t->key) return Insert(t->pLeft , x);
        else return Insert(t->pRight , x);
    }
    t = createNODE(x);
    return 1;

}

void CreateTree(TREE& t){
    t = NULL;

    while(true){
        int x; cin >> x;
        if(x == -1) break;
        Insert(t,x);
    }
}

void LNR(TREE t){
    if(t){
        LNR(t->pLeft);
        cout << t->key << " ";
        LNR(t->pRight);
    }
    return ;
}

void DemNode(TREE t,int l,int r,int& Count){
    if(t){
        DemNode(t->pLeft,l,r,Count);
        if(t->key <= r && t->key >= l) Count++;
        DemNode(t->pRight,l,r,Count);
    }
    return ;
}

int DemNode1(TREE t,int l,int r){
    if(t){
        int lNode = DemNode1(t->pLeft,l,r);

        int rNode = DemNode1(t->pRight,l,r);

        int i = (t->key <= r && t->key >= l); // đây là NODE do đó không phụ thuộc 2 ý trên nên duyệt kiểu NLR vẫn được
        return lNode + rNode + i;
    }
    return 0;
}

int Height(TREE t){
    if(t){
        int lNode = Height(t->pLeft);
        int rNode = Height(t->pRight);

        return max(lNode,rNode) + 1;
    }
    return -1;
}
int SoNodeBenTraiVaPhai(TREE t){
    if(t){

        int lNode = SoNodeBenTraiVaPhai(t->pLeft);
        int rNode = SoNodeBenTraiVaPhai(t->pRight);
//        if(lNode - rNode == 1) cout << t->key << " ";
        return lNode + rNode + 1;
    }
    return 0;
}

void NLR(TREE t){
    if(t){

        int l = SoNodeBenTraiVaPhai(t->pLeft);
        int r = SoNodeBenTraiVaPhai(t->pRight);
        if(l - r == 1) cout << t->key << " ";

        NLR(t->pLeft);
        NLR(t->pRight);
    }
    return ;
}

// con phan node to tien,. cha ,anh em
int main()
{
    TREE t;
    CreateTree(t);
    LNR(t); cout << endl;
    int Count = 0; int l , r;
    cin >> l >> r;
    DemNode(t,l,r,Count);
    cout << Count;
    cout << endl;
    cout << DemNode1(t,l,r);

    cout << Height(t) << endl;

    cout << endl;
    SoNodeBenTraiVaPhai(t);
    NLR(t);
    return 0;
}
