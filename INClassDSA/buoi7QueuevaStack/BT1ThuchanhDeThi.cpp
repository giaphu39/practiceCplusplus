
#include <iostream>
using namespace std;


struct Data{
    int SoPhong;
    char LoaiPhong;
    int TinhTrang;
};

struct NODE{
    Data info;
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

NODE* CreateNode(int soPhong, char loaiPhong, int tinhTrang){
    NODE* p = new NODE;

    if(p == NULL){
        exit(1); // nếu cấp phát mà vẫn không có địa chỉ thì lỗi
    }

    p->info.SoPhong = soPhong;
    p->info.LoaiPhong = loaiPhong;
    p->info.TinhTrang =tinhTrang;
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




int DemPhanTu(LIST l){
    NODE* p = l.pHead;
    int COUNT=0;
    while(p!=NULL){
        COUNT++;
        p=p->pNext;
    }
    return COUNT;
}

void CreateList(LIST& l){
    int n; cin>> n;
    int i=0;
    CreateEmptyList(l);
    while(i < n){
        int soPhong; char loaiPhong ; int tinhTrang;
        cin>> soPhong;
        cin>>loaiPhong;
        cin>>tinhTrang;
        NODE* p = CreateNode(soPhong,loaiPhong,tinhTrang);
        AddTail(l , p);
        
        i++;
    }
}
void PrintPhong(LIST& l){
    NODE* p = l.pHead;
    cout<<"---------------Output------------------"<<endl;
    if(p == NULL){
        cout<<"chua co danh sach phong";
        return;
    }
   
    while(p!=NULL){
        cout<<p->info.SoPhong<<" "<< p->info.LoaiPhong<<" "<<p->info.TinhTrang<<endl;
        p=p->pNext;
    }
    cout<<endl;
}

int COUNTTinhTrang(int x, LIST l){
    NODE* p = l.pHead;
    int COUNT=0;
    while(p!= NULL){
        if(p->info.TinhTrang == x){
            COUNT++;
        }
        p=p->pNext;
    }
    return COUNT;
}
int COUNTLoaiPhong(char x, LIST l){
    NODE* p = l.pHead;
    int COUNT=0;
    while(p!= NULL){
        if(p->info.LoaiPhong == x){
            COUNT++;
        }
        p=p->pNext;
    }
    return COUNT;
}
void BangTinhTrang(LIST& l, int x, int COUNT1, int y, int COUNT2){
    cout<<"Tinh Trang" <<"\t" << "So phong"<<endl;
    cout<< x << "\t" << COUNT1;
    cout<<endl;
    cout<< y << "\t" << COUNT2;
    cout<<endl;
}
void BangSoPhong(LIST& l, char x, int COUNT1, char y, int COUNT2){
    cout<<"LoaiPhong" <<"\t" << "So phong"<<endl;
    cout<< x << "\t" << COUNT1;
    cout<<endl;
    cout<< y << "\t" << COUNT2;
    cout<<endl;
}
void ThongKePhong(LIST& l){
    NODE* p = l.pHead;
    if(p == NULL){
        cout<<"chua co danh sach phong";
        return;
    }

    int COUNTtinhTrang0 = COUNTTinhTrang(0,l);
    int COUNTtinhTrang1 = COUNTTinhTrang(1,l);
    int COUNTloaiPhongA = COUNTLoaiPhong('A',l);
    int COUNTloaiPhongB = COUNTLoaiPhong('B',l);
    
    BangTinhTrang(l,0, COUNTtinhTrang0,1,COUNTtinhTrang1);
    BangSoPhong(l,'A',COUNTloaiPhongA,'B',COUNTloaiPhongB);
}
int giaPhong(char x){
    if(x=='A') return 200;
    else if(x=='B') return 350;
    else return 0;
}

int DoanhThu(LIST l){
    NODE* p = l.pHead;
    if(p == NULL){
        cout<<"chua co danh sach phong";
        return 0;
    }
    int Tong=0;

    while(p!=NULL){
        if(p->info.TinhTrang == 1){
            Tong += giaPhong(p->info.LoaiPhong);
        }
        p=p->pNext;
    }
    return Tong;
}

void Swap(NODE*& i, NODE*& j){
    swap(i->info.LoaiPhong, j->info.LoaiPhong);
    swap(i->info.SoPhong, j->info.SoPhong);
    swap(i->info.TinhTrang, j->info.TinhTrang);
}
void Sort(LIST &l) {
    NODE* i,* j ,* MIN; // nhớ cách ghi này

    i = l.pHead; // quan trọng nhất

    while(i != l.pTail){
        MIN = i;
        j = i->pNext;
        while( j != NULL){
            if(MIN->info.LoaiPhong == j->info.LoaiPhong){
                if(MIN->info.SoPhong > j->info.SoPhong){
                    MIN = j;
                }
            }
            else if(MIN->info.LoaiPhong > j->info.LoaiPhong){
                MIN = j;
            }   

            j=j->pNext;
            
        }
        if(i != MIN){
            Swap(i,MIN);
        }
        i = i->pNext;
    }

}

int main() {
    LIST L;
	CreateList(L);
    // PrintPhong(L);
    // ThongKePhong(L);

    // cout<<endl;
    // cout<<DoanhThu(L);

    Sort(L);
    PrintPhong(L);

    return 0;
}
