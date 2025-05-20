
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



TREE FindMin(TREE t){
    if(t == NULL) return NULL;
    else{
        while(t->pLeft != NULL){
            t = t->pLeft;
        }
        return t;
    }
    
}

void PrintLevel(TREE t, int x, int& level){
    if(t == NULL){
        level = -1;
        return; // nhớ có dòng này khi tới điểm dừng
    }
    else{
        if(t->key == x){
            level++; // + lại cái -1 ngay đầu vì nốt đầu là level 0
            return;
        }
        level++;// nên dùng vậy thay vì level+=1 trong hàm lun vì nếu nhánh  cận sai thì có thể quay lui
        if(x < t->key) PrintLevel(t->pLeft,x,level);
        else PrintLevel(t->pRight,x,level);
    }
}

void PrintLevel(TREE t, int x, int& level){
    if(t == NULL){
        level = -1;
        return; // nhớ có dòng này khi tới điểm dừng
    }
    else{
        if(t->key == x){
            level++; // + lại cái -1 ngay đầu vì nốt đầu là level 0
            return;
        }
        level++;// nên dùng vậy thay vì level+=1 trong hàm lun vì nếu nhánh  cận sai thì có thể quay lui
        if(x < t->key) PrintLevel(t->pLeft,x,level);
        else PrintLevel(t->pRight,x,level);
    }
}

int MaxDepth(TREE t) {
    if (t == NULL) return 0;
    int leftDepth = MaxDepth(t->pLeft);
    int rightDepth = MaxDepth(t->pRight);
    return 1 + max(leftDepth, rightDepth);
}

// void NLR(tree T)
// {
//     if(T)
//     {
//         cout<<T->key<<",";
//         NLR(T->left);
//         NLR(T->right);
//     }
// }

void NLR(tree T, int&)
{
    if(T)
    {
        cout<<T->key<<",";
        NLR(T->left);
        NLR(T->right);
    }
}


// ý tưởng tìm lặp tất và cho biến max tìm độ sâu

// ý tưởng tìm độ sâu sâu nhất rồi lặp 
void Find(TREE T){
    if(T == NULL) cout <<"Empty";
    else{
        int level = MaxDepth(t);
        NLR(T,level);
        // cout << level;
    }
     
 }



int main() {
	TREE T;
    CreateTree(T);
    Find(T);
    // tìm tất cả node lá sâu nhất

	return 0;
}
