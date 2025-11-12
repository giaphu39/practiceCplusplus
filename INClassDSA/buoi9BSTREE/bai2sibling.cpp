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

TNODE* PrintLevel(TREE T, int x, int& level) { // độ sâu = level
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


// ý tưởng: tìm thấy nó rồi và có được level của nó, chạy lại từ đầu, truy xuất nếu gặp nó trong left hoặc right thì truy vấn left right
// void FindSiblings(TREE T,int x){
//     int level = -1;
//     TNODE* p = PrintLevel(T,x,level);
    
// }
// bool flag = 1; // đánh dấu có phải là lần đầu
// TNODE* FindSiblings(TREE T, int x) { // độ sâu = level
//     if( T == NULL && flag){
//         cout << "Empty Tree.";
//         return NULL;
//     }
    

//     if (T != NULL) {
//         flag = 0;
//         if (T->key == x){
//             cout << x <<" is Root.";
//             return T;
//         }
//         if (T->pLeft != NULL && T->pLeft->key == x){
//             // tìm bên trái
//             if(T->pLeft->key == x){
//                 if(T->pRight == NULL){
//                     cout << x << " has no siblings.";
//                     return NULL;
//                 }
//                 cout << x << " and " << T->pRight->key <<  " are siblings.";
//                 return NULL;
//             }
           
//         }
//         // đặt return ở đây là sai
//         // tìm bên phải
//         if(T->pRight != NULL && T->pRight->key == x){ // bổ sung kiểm tra có phải NULL trước khi truy xuất 
//             if(T->pLeft == NULL){
//                 cout << x << " has no siblings.";
//                 return NULL;
//             }
//             cout <<T->pLeft->key << " and " << T->pRight->key <<  " are siblings.";
//             return NULL;
//         }

//         return FindSiblings(T->pLeft, x);
//         return FindSiblings(T->pRight, x);
//     }
//     // if(!flag){
//         cout << "Not found " << x << ".";
//         return NULL;
//     // }
    
// }
TNODE* FindParent(TREE T, int x) {
    if (T == NULL || T->key == x) return NULL; // Root hoặc không có cha.

    if ((T->pLeft && T->pLeft->key == x) || (T->pRight && T->pRight->key == x))
        return T;

    if (T->key > x) return FindParent(T->pLeft, x);
    return FindParent(T->pRight, x);
}

void FindSiblings(TREE T, int x) {
    TNODE* p = T;
    while (p != NULL) { // Tìm x có tồn tại không.
        if (p->key == x) break;
        if (p->key > x) p = p->pLeft;
        else p = p->pRight;
    }
    if (p == NULL) {
        cout << "Not found " << x << ".";
        return;
    }

    if (T->key == x) {
        cout << x << " is Root.";
        return;
    }

    TNODE* parent = FindParent(T, x);
    if (!parent) {
        cout << x << " is Root.";
        return;
    }

    if (parent->pLeft && parent->pLeft->key == x) {
        if (parent->pRight) cout << x << " and " << parent->pRight->key << " are siblings.";
        else cout << x << " has no siblings.";
    } else if (parent->pRight && parent->pRight->key == x) {
        if (parent->pLeft) cout << parent->pLeft->key << " and " << x << " are siblings.";
        else cout << x << " has no siblings.";
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
