/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

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
    TNODE *p;
    p = new TNODE; //cấp phát vùng nhớ động
    if (p == NULL) exit(1); // thoát
    p->key = x;     //gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE &T, int x) {
    if (T) {
        if (T->key == x) return 0;
        if (T->key > x)  return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateTNode(x);
    return 1;
}

TNODE* searchNode(TREE T, int x) {
    if (T != NULL) {
        if (T->key == x) return T;
        if (T->key > x)  return searchNode(T->pLeft, x);
        return searchNode(T->pRight, x);
    }
    return NULL;
}

void CreateTree(TREE &T)
{
    
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        Insert(T,x);

        
    }
}

TNODE* PrintLevel(TREE T, int x, int& level) {
    if (T != NULL) {
        if (T->key == x){
            level++;
            return T;
        }
        if (T->key > x){
            level++;
            return PrintLevel(T->pLeft, x,level);
        }
        level++;
        return PrintLevel(T->pRight, x, level);
    }
    level = -1;
    return NULL;
}


int main() {
	TNODE* T;
	int x, level=-1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}

