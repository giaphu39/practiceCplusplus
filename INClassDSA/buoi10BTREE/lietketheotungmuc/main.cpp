#include <iostream>

using namespace std;
struct TNODE{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

TREE createNODE(int x){
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

//bool Insert(TREE& T, TREE p){
//    if(T != NULL){
//        if(T->key == p->key) return 0;
//        else if(p->key < T->key)return Insert(T->pLeft,p); // nho return neu la kieu tra ve
//        else return Insert(T->pRight, p);
//    } // phải return mới đúng điểm dừng nếu không thì có thể nó chạy từ lúc đầu đệ quy đầu gặp NULL là add vào lun
//    // hoặc không return thì nó add giá trị nhiều lần gây lỗi hình dạng cây do mỗi lần đệ quy là vị trí khác của cây
//    T = p;
//    return 1;
//}

void Insert(TREE& T, TREE p){
    if(T != NULL){
        if(T->key == p->key) return ;
        else if(p->key < T->key) // nho return neu la kieu tra ve
        {
             Insert(T->pLeft,p); return;
        }
        else{
             Insert(T->pRight, p); return;
        }
    } // phải return mới đúng điểm dừng nếu không thì có thể nó chạy từ lúc đầu đệ quy đầu gặp NULL là add vào lun
    // hoặc không return thì nó add giá trị nhiều lần gây lỗi hình dạng cây do mỗi lần đệ quy là vị trí khác của cây
    T = p;
    return;
}
void createEmptyTREE(TREE& T){
    T = NULL;
}

void CreateTree(TREE& T){
    // luon phai khoi toa truoc loi ngay tu dau
    createEmptyTREE(T);
    while(true){
        int x; cin >> x;
        if(x==-1) break;
        TREE p = createNODE(x);
        Insert(T,p);
    }
}

void NLR(TREE& T){
    if(T != NULL){
        cout << T->key << " ";
        NLR(T->pLeft);
        NLR(T->pRight);

    }
    return;
}
#include<vector>
bool checkDepth(TREE T, TREE current, int& level ){
    if(current != NULL){
        if(T->key == current->key){
            level++;
            return 1;
        }
        else{
            level++;
            if(current->key < T->key){
                return checkDepth(T->pLeft,current, level);
            }
            return checkDepth(T->pRight, current, level);
        }
    }
    level = -1;
    return 0;
} // bị dấm chấm
void addToList(TREE T,TREE current ,vector<vector<int>>& LIST){
//    if(T != NULL){ // sai ở đây
    if(current != NULL){
        int level = -1;
        checkDepth(T, current, level);

        if (LIST.size() <= level) LIST.resize(level + 1); // cai nay có thẻ thay thể bằng dùng mảng vector nhưng
        // khó trong việc in ra

        LIST[level].push_back(current->key);

        addToList(T,current->pLeft,LIST);
        addToList(T,current->pRight,LIST);
    }
    return;
}
void outputLIST(vector<vector<int>> temp){
    for(int i = 0; i < temp.size() ; i++){
        cout << "Level " << i << ":";
        for(int j = 0 ; j < temp[i].size(); j++){
        cout << " " << temp[i][j];
        }
        cout << endl;
    }
}

void Find(TREE T){
    if(T == NULL) cout <<"EMPTY";
    else{
        vector<vector<int>> LIST;
        addToList(T,T,LIST);
        outputLIST(LIST);
    }
}

int main()
{
    TREE T;
    CreateTree(T);
    Find(T);
//    NLR(T);
    return 0;
}
