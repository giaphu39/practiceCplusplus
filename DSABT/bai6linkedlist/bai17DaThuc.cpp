

#include <iostream>
using namespace std;

struct DONTHUC{
    float HeSo;
    int SoMu;
};
struct NODE {
	DONTHUC info;
	NODE* pNext;
};
struct DATHUC {
	NODE* pHead;
	NODE* pTail;
};





void CreateEmptyDATHUC(DATHUC& l){
    l.pHead = NULL;
    l.pTail = NULL;

}

NODE* CreateNode(float x, int y){
    NODE* p = new NODE;

    if(p == NULL){
        exit(1); // nếu cấp phát mà vẫn không có địa chỉ thì lỗi
    }

    p->info.HeSo = x;
    p->info.SoMu = y;

    p->pNext = NULL;

    return p;
}  

void AddTail(DATHUC& l, NODE* p){
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





int n;

// lỗi chưa tham chiếu
bool Search(DATHUC l, int x, NODE*& y){ // y dùng để lấy ra vị trí cần add vào
    NODE* p = l.pHead;

    while(p!= NULL){
        if(p->info.SoMu == x){
            y = p; // quên dòng nay thì sai
            return true;
        }

        p=p->pNext;
    }
    return false;

}

void Sort(DATHUC& l){
    NODE* p = l.pHead;
    NODE* q;
    NODE* MIN;

    while(p!= NULL){
        q = p->pNext;
        MIN = p;
        while(q!=NULL){
            if(q->info.SoMu < MIN->info.SoMu){ // lỗi ghi sai MIN thành p
                MIN = q;
            }
            q = q->pNext;
        }
        
        swap(p->info.HeSo, MIN->info.HeSo);
        swap(p->info.SoMu, MIN->info.SoMu);

        p=p->pNext;
    }

}


bool RemoveHead(DATHUC& l){ // có thể tích hợp lấy ra giá trị x bị xóa
    // có thể dùng hàm bool để là hàm xác định có xóa được không
    if(l.pHead == NULL) return false;

    NODE* deleteNODE = l.pHead;
    
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) l.pTail = NULL; // quên mất dòng này thì không ảnh hưởng kết quả nhưng rất quan trọng vì nó là bản chất nếu không có thì Tail vẫn sai

    delete deleteNODE;
    return true;
}

bool RemoveTail(DATHUC& l){
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
bool RemoveAfterQ(DATHUC& l, NODE* q, int& x ){ // phần tử x nếu muốn lấy ra giá trị cần xóa
    NODE* p = NULL;

    if(q == NULL) return false;
    else{
        p = q->pNext;

        if(p == NULL) return true; // Q là nốt cuối
        if(p == l.pTail){
            l.pTail = q;
        }
        x = p->info.HeSo; // lấy ra giá trị bị xóa
        q->pNext = p->pNext; // nốt prev (q) sẽ liên kết nốt sau p( bị xóa )
        
        delete p;
    }
    return true;
}


bool RemoveX(DATHUC& l, int x){ // nên làm 1 cái remove after để có thể liên kết phần tử trước với phần tử sau x
    NODE* p = l.pHead;
    NODE* prev = NULL;

    bool flag = 0 ;// đã xóa chưa
    while(true){
        if(p == NULL){ // không tìm thấy nữa
            break;
        }

        if(p->info.HeSo == x){
            if(prev == NULL){
                RemoveHead(l);
                p = l.pHead; // cập nhật lại để nó quay lại check đầu list
                continue;
            }
            else if( prev != NULL){
                RemoveAfterQ(l,prev,x);
                p = prev->pNext; // quan trọng nhất là các dòng cặp nhật con trỏ sau khi đã xóa
                continue;
            }
            flag = 1;

            // break; // tìm thấy phần tử đầu thì break;
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

// nên tạo một hàm tìm kiếm số mũ đã có trong DATHUC chưa
// chưa có thì add vào đuôi có rồi thì chỉ + thêm hệ số
// sau đó sắp xếp lại theo thứ tự 
// sau đó xóa hết tất cả hệ số 0

void CreatePolynomial(DATHUC& l){ // create da thuc
    cin >> n;
    int i = 0;
    NODE* index = NULL;
    while(i < n){
        float temp1; cin >> temp1; // lưu hệ số
        int temp2; cin >> temp2; // lưu số mũ

       

        if(Search(l,temp2,index)){
            index->info.HeSo += temp1; 
        }
        else{
            NODE* p = CreateNode(temp1,temp2);
            AddTail(l , p);
        }
        

        i++;
    }

    Sort(l);
    RemoveX(l,0);
}






void Output(DONTHUC a){
    if(a.HeSo==-1) cout << "-";
	else if(a.HeSo==1) cout << "";
	else cout << a.HeSo;
    // in ra hệ số trước tách riêng có dấu và khong

    // số mũ =0 thì không in
    if(a.SoMu==0) cout << "";
	else if(a.SoMu==1) cout << "x";
	else if(a.SoMu<1) cout << "-x";
    else // s.SoMu>1
		cout << "x^" << a.SoMu;
}

void Output(DATHUC L) {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty DATHUC.";
	else {
		p = L.pHead;
		Output(p->info);
		p=p->pNext;
		while (p) {
			cout << " + "; Output(p->info);
			p = p->pNext;
		}
	}
}


int main() {
    DATHUC poly;
	CreateEmptyDATHUC(poly);
    CreatePolynomial(poly);
	Output(poly);
	return 0;
}
