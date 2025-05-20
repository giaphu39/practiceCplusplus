
#include <iostream>
#include <queue>
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
			return Insert(T->pLeft, p); // cuối cùng return 1 và hết đệ quy nên không chạy tiếp T = p
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}


void CreateTree(TREE& T){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TREE p = CreateTNode(x);
        Insert(T,p);
    }
}

TREE FindParentDQ(TREE T, int x){
    if(T){
        if((T->pLeft != NULL && x == T->pLeft->key)|| (T->pRight != NULL && x == T->pRight->key)) return T;
        if(T->pLeft != NULL && x < T->key) return FindParentDQ(T->pLeft,x);
        else if(T->pRight != NULL && x > T->key) return FindParentDQ(T->pRight,x); // nhớ phải có return khi dùng đệ quy
    }

    return NULL;
}



void FindSiblingschoParent(TREE T,int x){
    if(T == NULL){
        cout << "Empty Tree.";
    }
    else{
        if(x == T->key){
            cout << x << " has no parent.";
            return;
        }
        TREE parentNODE = FindParentDQ(T,x);
        if(parentNODE) cout << parentNODE->key << " is parent of " << x << ".";
        else{
            cout << "Not found " << x << ".";
        }
    }
}

void FindSiblings(TREE T,int x){
    if(T == NULL){
        cout << "Empty Tree.";
    }
    else{
        if(x == T->key){
            cout << x << " is Root.";
            return;
        }
        TREE parentNODE = FindParentDQ(T,x);
        if(parentNODE){
            if(parentNODE->pLeft == NULL || parentNODE->pRight == NULL) cout << x << " has no siblings.";
            else cout << parentNODE->pLeft->key << " and "<< parentNODE->pRight->key << " are siblings.";
        }
        else{
            cout << "Not found " << x << ".";
        }
    }
}
TREE FindAncestorsDQ(TREE T, int x, bool& flag){
    if(T){
        if(T->key == x){
            flag = true;
            return T;
        }
        TREE p;
        // khong nen de return vi se dung vong lap do luon
        if(x < T->key) p = FindAncestorsDQ(T->pLeft,x,flag);
        else p = FindAncestorsDQ(T->pRight, x , flag);

        if(flag) cout << T->key <<" ";
        return p;
    }

    return NULL;


}

void PrintAncestors(TREE T,int x){
    if(T == NULL) cout <<"Empty Tree.";
    else{
        if(T->key == x){
            cout <<"Node is root.";
            return;
        }
        bool flag = false;
        TREE p = FindAncestorsDQ(T,x,flag);
        if(!p) cout <<-1;
    }
}

int TongSONODEDQ(TREE T){
    if(T){
        int LNODE = TongSONODEDQ(T->pLeft);
        int RNODE = TongSONODEDQ(T->pRight);
        if(LNODE - RNODE == 1) cout << T->key << " ";

        return LNODE + RNODE + 1;

    }

    return 0; // 0 NODE trước khi là lá, quan trọng nhất là số 0 này 
}



void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T){
    TongSONODEDQ(T);
}

void NODEThayThe(TREE& T, TREE& DeleteNode){
    //luôn tìm trái
    while(T->pLeft !=NULL){
        T = T->pLeft;
    }

    DeleteNode ->key = T->key;
    // p ->pRight = DeleteNode->pRight; // sai vì tại p là deleteNODE ban đầu thì đã có liên kết đã có

    // 2 dòng này quan trọng nhất
    DeleteNode = T; // cập nhật cái cần xóa
    T = T->pRight; // biển đổi


}

// void NODEThayThe(TREE& T, TREE& DeleteNode){
//     if(T->pLeft != NULL) NODEThayThe(T->pLeft,DeleteNode);
//     else{
//         DeleteNode->key = T->key;
//         DeleteNode = T;
//         T = T->pRight;
//     }

// }

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

void DeleteNode(TREE& T,int x){
    if(T){
        if(x < T->key) DeleteNode(T->pLeft,x); // nhớ luôn xét có tồn tại trước khi truy cập giá trị
        else if(x > T->key) DeleteNode(T->pRight,x); // sai chỗ này so sánh sai
        else{
            // tìm thấy thì truy vấn xóa
            TREE deleteNODE = T;
            // chú ý dùng T luôn vì các lần đệ quy trước đã khiến cho T này không phải nốt gốc nên thoải mái thay đổi con trỏ chỉ khi thay đổi liên kết
            // mới quan trọng
            if(T->pLeft == NULL && T->pRight == NULL){ // nốt lá
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
                NODEThayThe(T->pRight,deleteNODE);
                delete deleteNODE; // lúc này T sẽ là nốt cần xóa
                
                    // NODEThayThe(T->pRight, T); // T là node đang cần xóa
            
                
            }
        }
    }

    // không tìm thấy in NOTFOUND
}

void PrintTreeDQ(TREE T){
    if(T){
        cout << T->key <<" ";
        PrintTreeDQ(T->pLeft);
        PrintTreeDQ(T->pRight);

        return;
    }
}

void PrintTree(TREE T){
    if(T){
        PrintTreeDQ(T);
    }
    else{
        cout << "Empty Tree.";
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
