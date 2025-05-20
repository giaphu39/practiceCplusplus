
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;
 
void Input(vector<int>& a){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        a.push_back(x);
    }
}

TREE CreateNode(int x){
    TNode* p = new TNode;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int FindIndex(vector<int>& a, int from, int to, int x){
    for(int i = from; i <= to; i++){
        if(a[i] == x) return i;
    }
    return -1; // nếu không tìm thấy
}

// i là chỗ bắt đầu , j là kết thúc
// TREE CreateTree(vector<int> a, vector<int> b, int bi, int bj, int ai, int aj ){ // không được gán & cho 1 số không phải biến
//     if (bi > bj) return NULL;

//     int rootValue = a[ai++];
//     TNode* root = CreateNode(rootValue);

//     if (bi == bj) return root;

//     int IndexNodeInLNR = FindIndex(b, bi, bj, rootValue);

//     root->left = CreateTree(a, b,bi, IndexNodeInLNR - 1, ai, aj);
//     root->right = CreateTree(a, b,bi, IndexNodeInLNR + 1, ai, aj);

//     return root;
// }


TREE CreateTree(vector<int>& a, vector<int>& b, int bi, int bj, int ai, int aj) {
    if (bi > bj) return NULL;

    int rootValue = a[ai];
    TNode* root = CreateNode(rootValue);

    if (bi == bj) return root;

    int IndexNodeInLNR = FindIndex(b, bi, bj, rootValue);
    int leftSize = IndexNodeInLNR - bi;
    // sửa lại chỗ phạm vi đệ quy
    root->left = CreateTree(a, b, bi, IndexNodeInLNR - 1, ai + 1, ai + leftSize);
    root->right = CreateTree(a, b, IndexNodeInLNR + 1, bj, ai + leftSize + 1, aj);

    return root;
}


void NLR(TREE a, int& Count){
    if(a == NULL) return;

    if(a->left != NULL && a->right == NULL) Count++;
    NLR(a->left,Count);
    NLR(a->right,Count);
}

void Fun(TREE a){
    if(a == NULL) cout << "Empty Tree";
    else{
        int Count = 0;
        NLR(a,Count);
        cout << Count;
    }
}









int main() {
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num=duyetNLR.size()-1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
