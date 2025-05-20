
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
#include<vector>
#define MAX 200
vector<int> a[MAX];

void NLR(TREE T,TREE cur)
{
    if(T)
    {   
        int level = -1;
        PrintLevel(T,cur->key, level);
        if(level != -1){
            a[level].push_back(cur->key); // chỗ cần sửa

        }
        NLR(T, cur->pLeft);
        NLR(T , cur ->pRight);

    }
}



void Find(TREE T){
    if(T == NULL) cout <<"Empty";
    else{
        NLR(T,T);
        
        for(int i = 0 ; i < MAX ; i++){
            if(! a[i].empty()){
                cout << "Level: "<< i << ": "; 
                for(int j = 0 ; j < a[i].size() ; j++){
                    cout << a[i][j] <<" ";
                }
                cout << endl;
            }
        }
    }
     
 }


int main() {
	TREE T;
    CreateTree(T);
    Find(T);
    // liet ke theo tung muc
    // ý tưởng lặp qua từng node bỏ nó vào vector tương ứng, sau đó in ra vector

	return 0;
}
