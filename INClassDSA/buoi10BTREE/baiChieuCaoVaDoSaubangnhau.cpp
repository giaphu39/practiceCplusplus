
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;







TREE createNODE(int x){
    TREE p = new TNODE;
    if(p == NULL) exit(1);
    else{
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        return p;
    }
}

bool Insert(TREE& t, TREE p){ // t là con trỏ của tree gốc, p là con trỏ cần thêm vào
    if(t != NULL){ // phải là kiểm tra NODE đang chạy
        if(t->key == p->key) return 0;
        if(t->key > p->key) return Insert(t->pLeft, p);
        return Insert(t->pRight,p);
    }

    t = p;
    return 1;
}

void CreateTree(TREE& T){
    T = NULL;
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TREE p = createNODE(x);
        Insert(T,p);
    }
}

int Height(TREE t){
    if(t == NULL) return -1; // do lá là 0
    else{
        int LNODE = Height(t->pLeft);
        int RNODE = Height(t->pRight);

        return max(LNODE, RNODE) + 1;
    }
} 

// int HeightOfNode(TREE t,int x){
//     int count;
//     TREE p;
//     p = searchNode(t,x);
//     count = Height(p);
//     return count;

// }

// TNODE* PrintLevel(TREE T, TREE current, int& level) {
//     if (T != NULL) {
//         if (T == current){
//             level++;
//             return T;
//         }
//         if (T->key > current->key){
//             level++;
//             return PrintLevel(T->pLeft, current,level);
//         }
//         level++;
//         return PrintLevel(T->pRight,current, level);
//     }
//     level = -1;
//     return NULL;
// }



// TREE FindDQ(TREE T, TREE current){
//     if(current == NULL) return NULL;

//     int chieuSau = -1;
//     PrintLevel(T,current,chieuSau);
//     int ChieuCao = Height(T);

//     if(ChieuCao == chieuSau) return current;

//     TREE left = FindDQ(T, current->pLeft);
//     if(left != NULL) return left;

//     TREE right = FindDQ(T, current->pRight);
//     return right;
// }


// void Find(TREE T){
//    if(T == NULL) cout <<"Empty";
//    else{
//         TREE p = FindDQ(T,T);
//         if(p) cout << p->key;
//         else cout << "NotFound";
//    }
    
// }

// // ý tưởng: duyệt qua toàn bộ cây, xét tại mỗi nốt, cái nào thỏa thì add vào vector
#define MAX 100
#include<vector>
void PrintLevel(TREE T, TREE Current, int& level){
    if(Current == NULL){
        level = -1; return;
    }
    else{
        if(T->key == Current->key){
            level++;
        }
        else if(T->key < Current->key){
            level++;
            PrintLevel(T->pRight, Current, level);
        }
        else{
            level++;
            PrintLevel(T->pLeft, Current, level);
        }
    }
}

void KTDoSauCoBangDoCao(TREE T,TREE Current ,vector<TREE>& v){
    int level = -1; // luu do sau
    PrintLevel(T,Current, level);
    int height = Height(Current);
    if(level == height) v.push_back(Current);
}

void FindDQ(TREE T,TREE Current, vector<TREE>& v){
    if(Current == NULL) return;
    else{
        FindDQ(T,Current->pLeft,v);
        KTDoSauCoBangDoCao(T,Current, v);
        FindDQ(T,Current->pRight,v);
    }
}

void Find(TREE T){
    if(T == NULL) cout << "Empty";
    else{
        // TREE v[100];
        // int i = 0;
        vector<TREE> v;
        FindDQ(T,T,v);
        if(v.empty()){
            cout <<"NotFound";
        }
        else{
            for(int i = 0 ; i < v.size() -1; i++){
                cout << v[i]->key << ", ";
            }
            cout << v[v.size()-1]->key;
        }
        
    }
}
int main() {
	TREE T;
    CreateTree(T);
    Find(T);

	return 0;
}
