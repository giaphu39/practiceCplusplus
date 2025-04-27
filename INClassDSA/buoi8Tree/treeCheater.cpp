#include<iostream>
using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};

typedef node* tree; // Định nghĩa tree là con trỏ tới node

void CreateEmptyTree(tree &T)
{
    T=NULL;
}

node* CreateNode(int x)
{
    node* p=new node();
    if(p==NULL)exit(1);
    p->key=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}


int Insert(tree &T, int x) {
    if (T)
    {
        if (T->key == x) return 0;
        if (T->key > x)  return Insert(T->left, x);
        return Insert(T->right, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(tree &T)
{
    int x;
    while (true){
        cin >> x; 
        if(x == 0) break;

        Insert(T,x);
    }
}


// void LNR(tree T)
// {
//     if(T)
//     {
//         LNR(T->left);
//         if(T->left!=NULL && T->right==NULL)
//             || (T->left==NULL && T->right!=NULL)
//             cout<<T->key<<"\t";
//         LNR(T->right);
//     }
// }

void NLR(tree T)
{
    if(T)
    {
        cout<<T->key<<",";
        NLR(T->left);
        NLR(T->right);
    }
}
void LNR(tree T)
{
    if(T)
    {
        LNR(T->left);
        cout<<T->key<<",";
        LNR(T->right);
        
    }
}

void LRN(tree T)
{
    if(T)
    {
        LRN(T->left);
        LRN(T->right);
        cout<<T->key<<",";
    }
}
void NRL(tree T)
{
    if(T)
    {
        cout<<T->key<<",";
        NRL(T->right);
        NRL(T->left);
        
    }
}
void RNL(tree T)
{
    if(T)
    {
        
        RNL(T->right);
        cout<<T->key<<",";
        RNL(T->left);
        
    }
}
void RLN(tree T)
{
    if(T)
    {
        
        RLN(T->right);
        RLN(T->left);
        cout<<T->key<<",";
    }
}
node* searchNode(tree T, int x) {
    if (T != NULL) {
        if (T->key == x) return T;
        if (T->key > x)  return searchNode(T->left, x);
        return searchNode(T->right, x);
    }
    return NULL;
}



int FindIndex(int a[], int n, int value) {
    for (int i = 0; i < n; ++i)
        if (a[i] == value) return i;
    return -1; // Không tìm thấy
}

node* BuildFromPreIn(int pre[], int in[], int inStart, int inEnd, int& preIndex, int n) {
    if (inStart > inEnd) return NULL;

    int rootValue = pre[preIndex++];
    node* root = CreateNode(rootValue);

    if (inStart == inEnd) return root;

    int rootIndexInInorder = FindIndex(in, n, rootValue); // tìm vị trí root mới đặt

    root->left = BuildFromPreIn(pre, in, inStart, rootIndexInInorder - 1, preIndex, n);
    root->right = BuildFromPreIn(pre, in, rootIndexInInorder + 1, inEnd, preIndex, n);

    return root;
}

#define MAX 300


void CountLa(tree T, int& COUNT)
{
    if(T)
    {
        
        CountLa(T->left, COUNT);
        CountLa(T->right , COUNT);
        // thăm kiểu nào cũng được
        if(T->left == NULL && T->right == NULL) COUNT++;
    }
}

void CountNODE1Con(tree T, int& COUNT)
{
    if(T)
    {
        
        CountNODE1Con(T->left, COUNT);
        CountNODE1Con(T->right , COUNT);
        // thăm kiểu nào cũng được
        if((T->left == NULL && T->right !=NULL ) ||  (T->right == NULL && T->left != NULL)) COUNT++;
    }
}
void CountNODE2Con(tree T, int& COUNT)
{
    if(T)
    {
        
        CountNODE2Con(T->left, COUNT);
        CountNODE2Con(T->right , COUNT);
        // thăm kiểu nào cũng được
        if((T->left != NULL && T->right !=NULL ) ||  (T->right != NULL && T->left != NULL)) COUNT++;
    }
}

int Height(node* T){
    if(!T) return -1;
    int a = Height(T->left);
    int b = Height(T->right);
    return max(a,b) + 1;
}


int HeightX(tree T, int x) {
    if (T == NULL) return -1;  // Không tìm thấy
    if (T->key == x) return Height(T);  // Tìm thấy node x

    int left = HeightX(T->left, x);
    if (left != -1) return left; // Tìm thấy ở nhánh trái

    return HeightX(T->right, x); // Tiếp tục tìm ở nhánh phải
}
int DepthX(tree T, int x, int currentDepth = 0) { // duyệt toàn bộ trường hợp nhánh thay vì chỉ 1 nhánh như cách trên
    if (T == NULL) return -1;
    if (T->key == x) return currentDepth;

    int left = DepthX(T->left, x, currentDepth + 1);
    if (left != -1) return left; // tìm thấy ở nhánh trái

    return DepthX(T->right, x, currentDepth + 1); // tiếp tục tìm ở nhánh phải
}


void SoLa(tree T){
    int CountLa1=0;
    CountLa(T,CountLa1);
    cout<< CountLa1 <<endl;
}
void So1Con(tree T){
    int CountLa1=0;
    CountNODE1Con(T,CountLa1);
    cout<< CountLa1 <<endl;
}
void So2Con(tree T){
    int CountLa1=0;
    CountNODE2Con(T,CountLa1);
    cout<< CountLa1 << endl;
}

void NodeCoChieuCaoDoSau(tree T, int depth = 0)
{
    if(T)
    {
        if(Height(T) == depth)
        {
            cout << T->key << " ";
        }
        NodeCoChieuCaoDoSau(T->left, depth + 1);
        NodeCoChieuCaoDoSau(T->right, depth + 1);
    }
}

bool LietKeToTien(tree T, int x) {
    if (T == NULL) return false;

    if (T->key == x) return true;

    // Nếu x nằm trong cây con trái hoặc phải, in node hiện tại
    if (LietKeToTien(T->left, x) || LietKeToTien(T->right, x)) {
        cout << T->key << " ";
        return true;
    }

    return false;
}
void LietKeHauDue(tree T) {
    if (T) {
        LietKeHauDue(T->left);
        LietKeHauDue(T->right);
        cout << T->key << " ";
    }
}

void LietKeHauDueCuaX(tree T, int x) {
    node* p = searchNode(T, x);
    if (p) {
        // loại bỏ chính nó
        if (p->left) LietKeHauDue(p->left);
        if (p->right) LietKeHauDue(p->right);
    }
}
void LietKeNodeMucK(tree T, int k, int currentLevel = 0) {
    if (T == NULL) return;
    if (currentLevel == k) {
        cout << T->key << " ";
        return;
    }

    LietKeNodeMucK(T->left, k, currentLevel + 1);
    LietKeNodeMucK(T->right, k, currentLevel + 1);
}
#include<iomanip> // Để dùng setw

void PrintTree(tree T, int space = 0, int indent = 6)
{
    if (T == NULL) return;

    space += indent;

    // In cây con phải trước (vì nó ở phía trên trong sơ đồ ngang)
    PrintTree(T->right, space);

    // In node hiện tại sau khi dời sang phải `space` ký tự
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << T->key << "\n";

    // In cây con trái sau (nằm dưới trong sơ đồ ngang)
    PrintTree(T->left, space);
}

int main() {
    tree T; //50 20 80 10 30 60 90 40 70
    T=NULL;
    // CreateEmptyTree(T);
    // CreateTree(T);
    int n, pre[MAX], in[MAX];
    cin >> n;

    cout << "Nhap NLR (preorder): ";
    for (int i = 0; i < n; ++i) cin >> pre[i];

    cout << "Nhap LNR (inorder): ";
    for (int i = 0; i < n; ++i) cin >> in[i];

    int preIndex = 0;

    T = BuildFromPreIn(pre, in, 0, n - 1, preIndex, n);



    NRL(T);
    // RLN(T);
    // NLR(T);
    // LNR(T);
    // cout<<endl;

    // int CountLa1=0;

    // SoLa(T);
    
    // So1Con(T);
    // cout<<endl;
    // So2Con(T);
    // cout << endl;

    // cout << Height(T);
    // cout << endl;
    // cout <<DepthX(T,80);
    // cout << endl;
    // cout << HeightX(T,50);
    // cout << endl;

    // NodeCoChieuCaoDoSau(T);
    // cout << endl;
    

return 0;
}