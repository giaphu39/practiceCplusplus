
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;


void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p); // cuối cùng return 1 và hết đệ quy nên không chạy tiếp T = p
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}













void CreateTree(TREE& T){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TREE p = CreateTNode(x);
        Insert(T,p);
    }
}

TREE FindParentDQ(TREE T, int x){
    if(T){
        if((T->pLeft != NULL && x == T->pLeft->key)|| (T->pRight != NULL && x == T->pRight->key)) return T;
        if(T->pLeft != NULL && x < T->key) return FindParentDQ(T->pLeft,x);
        else if(T->pRight != NULL && x > T->key) return FindParentDQ(T->pRight,x); // nhớ phải có return khi dùng đệ quy
    }

    return NULL;
}



void FindSiblingschoParent(TREE T,int x){
    if(T == NULL){
        cout << "Empty Tree.";
    }
    else{
        if(x == T->key){
            cout << x << " has no parent.";
            return;
        }
        TREE parentNODE = FindParentDQ(T,x);
        if(parentNODE) cout << parentNODE->key << " is parent of " << x << ".";
        else{
            cout << "Not found " << x << ".";
        }
    }
}

void FindSiblings(TREE T,int x){
    if(T == NULL){
        cout << "Empty Tree.";
    }
    else{
        if(x == T->key){
            cout << x << " is Root.";
            return;
        }
        TREE parentNODE = FindParentDQ(T,x);
        if(parentNODE){
            if(parentNODE->pLeft == NULL || parentNODE->pRight == NULL) cout << x << " has no siblings.";
            else cout << parentNODE->pLeft->key << " and "<< parentNODE->pRight->key << " are siblings.";
        }
        else{
            cout << "Not found " << x << ".";
        }
    }
}



int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}
