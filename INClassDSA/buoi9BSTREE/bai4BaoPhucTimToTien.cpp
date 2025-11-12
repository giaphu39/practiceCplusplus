
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; 
	p->key = x; 
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}


void CreateTree(TREE &T)
{
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TNODE* p = CreateTNode(x);
        Insert(T,p);
    }
}

void Function(TREE &T, int x, bool &flag) {
    if(T) {
        if(T->key > x) {
            Function(T->pLeft, x, flag);
        }
        else if(T->key < x) {
            Function(T->pRight, x, flag);
        }
        else {
            flag = true; // nghĩa là đã tìm thấy x rồi lúc này trả về theo quy luật stack
            return;
        }
        if(flag) cout << T->key << " ";
    }
    else cout << -1; 

}

void PrintAncestors(TREE &T, int x) {
    bool flag = false;
    if(T) {
        if(T->key == x) cout << "Node is root.";
        else Function(T, x, flag);
    }
    else cout << "Empty Tree.";
}












int main() {
	TNODE* T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	PrintAncestors(T, x);

	return 0;
}
