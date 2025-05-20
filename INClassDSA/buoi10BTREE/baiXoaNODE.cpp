
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



int MaxDepth(TREE t) {
    if (t == NULL) return 0;
    int leftDepth = MaxDepth(t->pLeft);
    int rightDepth = MaxDepth(t->pRight);
    return 1 + max(leftDepth, rightDepth);
}

void NLRDQ(TREE T)
{
    if(T)
    {
        cout<<T->key<<" ";
        NLRDQ(T->pLeft);
        NLRDQ(T->pRight);
    }
}
void NLR(TREE T){
    if(T == NULL) cout << "Empty";
    else{
        NLRDQ(T);
    }
}

// #include<vector>
// #define MAX 200
// int a[MAX];

// void NLR(TREE T,TREE cur)
// {
//     if(T)
//     {   
//         int level = -1;
//         PrintLevel(T,cur->key, level);
//         if(level != -1){
//             a[level] = cur->key; // chỗ cần sửa

//         }
//         NLR(T, cur->pLeft);
//         NLR(T , cur ->pRight);

//     }
// }


void NODEThayThe(TREE& T, TREE& DeleteNode){
    if(T->pRight != NULL) NODEThayThe(T->pRight,DeleteNode);
    else{
        DeleteNode->key = T->key;
        DeleteNode = T;
        T = T->pLeft;
    }

}

// void NODEThayThe(TREE& p, TREE& q) {
//     if (p->pLeft) {
//         NODEThayThe(p->pLeft, q);
//     } else {
//         q->key = p->key; // Gán giá trị node thay thế
//         TREE temp = p;
//         p = p->pRight;   // Kết nối lại cây con
//         delete temp;     // Xoá node thay thế
//     }
// }

void DeleteNode(TREE& T,int x){ // thay thế băng node MaxLeft
    if(T){
        if(x < T->key) DeleteNode(T->pLeft,x); // nhớ luôn xét có tồn tại trước khi truy cập giá trị
        else if(x > T->key) DeleteNode(T->pRight,x); // sai chỗ này so sánh sai
        else{
            TREE deleteNODE = T;
            if(T->pLeft == NULL && T->pRight == NULL){ 
                T = NULL; // dòng này không có thì lặp vô tận
                delete deleteNODE;
            }
            // trường hợp 1 cây
            else if(T->pLeft == NULL){
                T = T->pRight;
                delete deleteNODE;
            }
            else if(T->pRight == NULL){
                T = T->pLeft;
                delete deleteNODE;
            }
            else{ // 2 cây thì cho vị trí delete là nốt thay thế
                // NODEThayThe(T,deleteNODE->pRight); // chổ này sai vì phải so sánh bằng T
                NODEThayThe(T->pLeft,deleteNODE);
                delete deleteNODE; // lúc này T sẽ là nốt cần xóa

            }
        }
    }

    // không tìm thấy in NOTFOUND
}
void Delete(TREE T){
    int x; cin >> x;
    DeleteNode(T,x);
}

int main() {
	TREE T;
    CreateTree(T);
    Delete(T);
    NLR(T);

	return 0;
}
