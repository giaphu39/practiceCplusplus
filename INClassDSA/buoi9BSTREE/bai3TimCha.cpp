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
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
//###INSERT CODE HERE -


void CreateTree(TREE &T)
{
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TNODE* p = CreateTNode(x);
        Insert(T,p);
    }
}

TNODE* searchNode(TREE T, int x,int &level) {
    if (T != NULL) {
        if (T->key == x) return T;
        if (T->key > x)  return searchNode(T->pLeft, x,level+=1);
        return searchNode(T->pRight, x,level+=1);
    }
    return NULL;
}

TNODE* searchNode(TREE T, int x) {
    if (T != NULL) {
         if ((T->pLeft != NULL && T->pLeft->key == x) ||
        (T->pRight != NULL && T->pRight->key == x))
        return T;
        if (T->key > x)  return searchNode(T->pLeft, x);
        return searchNode(T->pRight, x);
    }
    return NULL;
}
void FindSiblings(TREE T,int x)
{
    if(T==NULL)
    {
        cout<<"Empty Tree.";
        return ;
    }
    int level=0;
    TNODE* t=searchNode(T,x,level); // tìm nốt cần tìm
    if(t==NULL)
    {
        cout<<"Not found "<<x<<".";
        return ;
    }
    if(level==0){
        cout<<T->key<<" has no parent.";
        return ;
    }
    TNODE*a=searchNode(T,x);
    cout << a->key <<" is parent of "<< t->key << ".";
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
