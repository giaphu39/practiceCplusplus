
#include <iostream>
using namespace std;




struct NODE{
    int info;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};


void CreateEmptyList(LIST& l){
    l.pHead = NULL;
    l.pTail = NULL;

}

NODE* CreateNode(int x){
    NODE* p = new NODE;

    if(p == NULL){
        exit(1); // nếu cấp phát mà vẫn không có địa chỉ thì lỗi
    }

    p->info = x;
    p->pNext = NULL;

    return p;
}  

void AddHead(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{

        // tạo liên kết
        p -> pNext = l.pHead;
        l.pHead = p;

    }
} 
void AddTail(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    }
    else{

        // tạo liên kết
        l.pTail ->pNext = p;

        l.pTail = p;

    }
}


void CreateList(LIST& l){
    while(true){
        int temp; cin >> temp;
        if(temp == -1) break;
        else{
            NODE* p = CreateNode(temp);
            AddTail(l , p);
        }
    }
}

bool RemoveHead(LIST& l){ // có thể tích hợp lấy ra giá trị x bị xóa
    // có thể dùng hàm bool để là hàm xác định có xóa được không
    if(l.pHead == NULL) return false;

    NODE* deleteNODE = l.pHead;
    
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) l.pTail = NULL; // quên mất dòng này thì không ảnh hưởng kết quả nhưng rất quan trọng vì nó là bản chất nếu không có thì Tail vẫn sai

    delete deleteNODE;
    return true;
}

bool RemoveTail(LIST& l){
    NODE* p = l.pHead;
    NODE* deleteNODE = l.pTail;

    if(p == NULL ) return false; // trường hợp 1: không có gì để xóa
    else if(p == deleteNODE){ // trường hợp 2: chỉ có 1 phần tử để xóa
        // cắt đứt liên kết rồi mới xóa
        l.pHead = NULL;
        l.pTail = NULL;
        delete deleteNODE;
        
    }
    // trường hợp 3: bình thường
    else{
        while(p->pNext -> pNext != NULL){ // lẩy thằng tiếp theo mà trỏ tới địa chỉ NULL ( cuối cùng )
            p = p->pNext;
        }
    
        
    
        p->pNext = NULL;
        l.pTail = p;
        delete deleteNODE;
    }
    return true;

}
// hàm remove after Q 
// TH1: Q là null không xóa được, TH2: Q là nút cuối không xóa gì nhưng vẫn xem là xóa được
// TH3: p (nốt cần xóa != NULL) thì đầu tiên xét nó phải nốt cuối nếu nó là nốt cuối thì cho Q làm nốt cuối, sau cùng thì cho Q liên kết p->pNext
bool RemoveAfterQ(LIST& l, NODE* q, int& x ){ // phần tử x nếu muốn lấy ra giá trị cần xóa
    NODE* p = NULL;

    if(q == NULL) return false;
    else{
        p = q->pNext;

        if(p == NULL) return true; // Q là nốt cuối
        if(p == l.pTail){
            l.pTail = q;
        }
        x = p->info; // lấy ra giá trị bị xóa
        q->pNext = p->pNext; // nốt prev (q) sẽ liên kết nốt sau p( bị xóa )
        
        delete p;
    }
    return true;
}



// Th1:ds rỗng -> không xóa
//TH2: tìm thấy x bình thường(bao gồm cả x là phần tử cuối) dùng removeafter
//TH3: tìm thấy x nhưng ở đầu dãy  thì removeHead
// đây chỉ mới hủy 1 phần tử đầu tiên được gặp
bool RemoveX(LIST& l, int x){ // nên làm 1 cái remove after để có thể liên kết phần tử trước với phần tử sau x
    NODE* p = l.pHead;
    NODE* prev = NULL;

    bool flag = 0 ;// đã xóa chưa
    while(true){
        if(p == NULL){ // không tìm thấy nữa
            break;
        }

        if(p->info == x){
            if(prev == NULL){
                RemoveHead(l);
            }
            else if( prev != NULL){
                RemoveAfterQ(l,prev,x);
            }
            flag = 1;

            break; // tìm thấy phần tử đầu thì break;
        }

        prev = p;
        p = p->pNext;

    }

    if(! flag){
        // có thể ghi ra không tìm thấy
        return false; 
    }
    return true;
}


void PrintList(LIST l){
    NODE* p = l.pHead;
    if(p == NULL){
        cout<<"Empty List."<<endl;
        return;
    }

    while(p!= NULL){
        cout << p->info<<" ";
        p = p->pNext;
        
    }
    cout<<endl;
}

// add vào chính giữa nếu
// số phần tử là chẵn thì index = n/2; với i=1
// số phần tử lẻ thì index = n/2 + 1; với i=1
int DemPhanTu(LIST l){
    NODE* p = l.pHead;
    int COUNT=0;
    while(p!=NULL){
        COUNT++;
        p=p->pNext;
    }
    return COUNT;
}

bool AddAfterQ(LIST& l, NODE* current, NODE* newNODE){
    if(current == l.pTail){
        AddTail(l,newNODE);
    }
    else{
        newNODE->pNext = current->pNext;
        current->pNext = newNODE;
    }

    return true;
}

bool add_after_middle(LIST& l, int y){
    int n = DemPhanTu(l);
    NODE* newNODE = CreateNode(y);

    // dòng này không phù hợp test case add đầu nếu không có phần tử
    // if(n==0){
    //     AddHead(l,newNODE);
    //     return true;
    // }
    NODE*p = l.pHead;
    // NODE* q = NULL;
    int i = 1;
    int location; // vị trí dừng

    if( !(n&1)){ // số chẵn thì
        location = n/2;
    }
    else location = n/2+1;

    while(p != NULL){
        if(i == location){
            AddAfterQ(l,p,newNODE);
            return true;
        }
        
        // 2 dòng dưới đây là quan trọng nhất trong while
        i++; 
        p = p->pNext;
    }

    return false;
}

int main() {
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_middle(L, Y);

	PrintList(L);

    return 0;
}
