
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
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        TREE p = createNODE(x);
        Insert(T,p);
    }
}

void PrintTreeTheoCay(TREE T){ // LNR
    if(T != NULL){
        PrintTreeTheoCay(T->pLeft);
        cout << T->key << " "; // phải là kiểu LNR vì đó là theo thứ tự tăng đần của cây tìm kiếm
        PrintTreeTheoCay(T->pRight);
        
    }
}

void PrintTREETheoRNL(TREE T){ // LNR
    if(T != NULL){
        PrintTREETheoRNL(T->pRight);
        cout << T->key << " ";
        PrintTREETheoRNL(T->pLeft);
        
    }
}

void PrintTree(TREE T){
    if(T != NULL){
        PrintTREETheoRNL(T);
    }
    else{
        cout <<"Empty Tree.";
    }
}

TREE searchNode(TREE& T, int x){ // luôn đúng không chạy đuognừ khác 
    if(T !=NULL){
        if(T ->key == x){
            return T;
        }
        if(T->key > x){
            return searchNode(T->pLeft, x); // phải có chữ return vì
            //
        }
        else{
            return searchNode(T->pRight, x);
        }
    }

    return NULL;
}
int countNodeDeQuy(TREE t, int& count){
    if(t == NULL) return 0;
    else{
        count++; // NLR

        countNodeDeQuy(t->pLeft, count);
        countNodeDeQuy(t->pRight, count);
    }

    return 1;
}

int CountNode(TREE t){
    int count = 0;
    if(t == NULL) return count;
    if(t->pLeft ==NULL && t->pRight == NULL){
        return count + 1;
    }
    else{
        countNodeDeQuy(t, count);
        return count;
    }
}



int count1ConDeQuy(TREE t, int& count){
    if(t == NULL) return 0;
    else{
        // NLR
        if((t->pLeft == NULL && t->pRight !=NULL)
        ||(t->pRight == NULL && t->pLeft !=NULL)){
            count++;
        }
        count1ConDeQuy(t->pLeft, count);
        count1ConDeQuy(t->pRight, count);
    }

    return 1;
}

int CountNode_Have1Child(TREE t){
    int count = 0;
    if(t == NULL) return count;
    else{
        count1ConDeQuy(t,count);
        return count;
    }
}

int count2ConDeQuy(TREE t, int& count){
    if(t == NULL) return 0;
    else{
        // NLR
        if(t->pLeft != NULL && t->pRight !=NULL){
            count++;
        }
        count2ConDeQuy(t->pLeft, count);
        count2ConDeQuy(t->pRight, count);
    }

    return 1;
}

int CountNode_Have2Child(TREE t, int & count){
    if(t == NULL) return count;
    else{
        count2ConDeQuy(t,count);
        return count;
    }
}

int countLaDeQuy(TREE t, int& count){
    if(t == NULL) return 0;
    else{
        // NLR
        if(t->pLeft == NULL && t->pRight ==NULL){
            count++;
        }
        countLaDeQuy(t->pLeft, count);
        countLaDeQuy(t->pRight, count);
    }

    return 1;
}

int CountLeaf(TREE t, int & count){
    if(t == NULL) return count;
    else{
        countLaDeQuy(t,count);
        return count;
    }
}

int TinhTongNode(TREE t, int& sum){
    if(t == NULL) return 0;
    else{
        // NLR
        sum += t->key;
        TinhTongNode(t->pLeft, sum);
        TinhTongNode(t->pRight, sum);
    }

    return 1;
}

int SumNode(TREE t){
    int sum = 0;
    TinhTongNode(t,sum);
    return sum;
}

// Tạo một cây nhị phân tìm kiếm T lưu trữ các số nguyên ( giá trị số nguyên < 1000, cây T có thể rỗng). Sau đó tính tổng giá trị các internal node trong cây.

// Định nghĩa: Internal node: A node with at least one child. Ví dụ:

//              9
//      6              16
//  2       7      12       25
//      4      11
// Tổng Internal node là: 2+6+9+12+16= 45

int TinhTongInternalNode(TREE t, int& sum){
    if(t == NULL) return 0;
    else{
        // NLR
        if(t->pLeft != NULL || t->pRight != NULL){
            sum += t->key;
        }
        TinhTongInternalNode(t->pLeft, sum);
        TinhTongInternalNode(t->pRight, sum);
    }

    return 1;
}

int SumInternalNode(TREE t){
    int sum = 0;
    TinhTongInternalNode(t,sum);
    return sum;
}

int SumOddNodeDQ(TREE t, int& sum){
    if(t == NULL) return 0;
    else{
        // NLR
        if((t->key & 1 ) == 1){
            sum += t->key;
        }
        SumOddNodeDQ(t->pLeft, sum);
        SumOddNodeDQ(t->pRight, sum);
    }

    return 1;
}

int SumOddNode(TREE t){
    int sum = 0;
    SumOddNodeDQ(t,sum);
    return sum;
}

// ý tưởng làm chiều cao: NLR đến khi gặp lá thì xét tìm MAX ( biến toàn cục mỗi lần chạy hàm ngoài thì cho = MIN_INT)

int Height(TREE t){
    if(t == NULL) return -1; // do lá là 0
    else{
        int LNODE = Height(t->pLeft);
        int RNODE = Height(t->pRight);

        return max(LNODE, RNODE) + 1;
    }
} 

int HeightOfNode(TREE t,int x){
    int count;
    TREE p;
    p = searchNode(t,x);
    count = Height(p);
    return count;

}

// TREE FindMax(TREE t){ // dùng đệ quy bị runtime error
//     if( t == NULL) return NULL;
//     else{
//         if(t->pRight == NULL){
//             return t;
            
//         }
//         else{// có cả 
//             FindMax(t->pRight);
//         }
//     }
// }
TREE FindMax(TREE t){
    if( t == NULL) return NULL;
    else{
        while(t->pRight != NULL){
            t = t->pRight;
        }
        return t;
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


int main() {
	TNODE* T;
	int x, level=-1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}


