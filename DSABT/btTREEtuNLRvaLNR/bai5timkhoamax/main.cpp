
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}





#include<math.h>
void Input(vector<int>& obj){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        obj.push_back(x);
    }
}
bool soNguyenTo(int x){
    if(x >= 0 && x<=1) return false;
    for(int i =2 ; i<= sqrt(x) ; i++){ // quên =
        if((x % i) == 0) return false;
    }
    return true;
}
bool NODELA(TREE root){
    return root->left == NULL && root->right == NULL;
}
bool NODE1ConBenTrai(TREE T){
        return T->left != NULL && T->right == NULL;
}
//void NLRDEMNODE(TREE root, int& Count){
//    if(root == NULL) return;
//    else{
////        int i =   root->key; // deug
//        if(NODE1ConBenTrai(root)) Count++;
//        NLR(root->left, Count);
//        NLR(root->right , Count);
//    }
//}

//void NLR(TREE root, int& Count){
//    if(root == NULL) return;
//    else{
////        int i =   root->key; // deug
//        if(NODE1ConBenTrai(root)) Count++;
//        NLR(root->left, Count);
//        NLR(root->right , Count);
//    }
//}
int NLR(TREE root,TREE rootexact, int& Count){
    if(root == NULL){
        return 0;
    }
    else{
        int iLEFT = NLR(root->left,rootexact,Count);
        int iRIGHT = NLR (root->right,rootexact,Count);

        if(iLEFT > iRIGHT && iLEFT != 0 && iRIGHT!= 0 && root != rootexact) Count++;

        return iLEFT+iRIGHT +1;
    }
}

void NLRTimMAX(TREE root,TREE& MAX){
    if(root == NULL){
        return;
    }
    else{
        if(root->key > MAX ->key){
            MAX = root;
        }
        NLRTimMAX(root->left,MAX);
        NLRTimMAX(root->right,MAX);
    }
}

void NLRTimMIN(TREE root,TREE& MIN){
    if(root == NULL){
        return;
    }
    else{
        if(root->key < MIN ->key){
            MIN = root;
        }
        NLRTimMIN(root->left,MIN);
        NLRTimMIN(root->right,MIN);
    }
}

void Fun(TREE root){
    if(root == NULL) cout <<"Empty Tree" <<endl;
    else{
            TREE MAX = root;
            NLRTimMIN(root,MAX);
            cout << MAX->key;
    }
}

//1 2 3 4 5 6 -1
//2 1 4 3 6 5 -1
//
//6
//
//22 4 8 12 14 15 6 10 -1
//8 12 14 15 4 6 22 10 -1
//
//22
//
//2 -1
//2 -1
//2
//
//-1
//-1
//Empty Tree


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

