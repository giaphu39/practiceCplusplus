/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
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


int TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE &T) {
    if(!T) return 0;
    else {
        int left = TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pLeft);
        int right = TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pRight);

        if(left - right == 1) cout << T->key << " ";
        return left + right + 1;
    }
}




int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

	return 0;
}
