

// ĐỂ TRÁNH TRƯỜNG HỢP TRÀN BỘ NHỚ DO SỐ LƯỢNG PASSWORD CỦA 1 USER CẦN LƯU TRỮ QUÁ NHIỀU.
//CÓ TEST CASE CÓ NHIỀU USER THAY ĐỔI SỐ LƯỢNG PASS RẤT LỚN, LÊN ĐẾN 4000-5000 NGÀN PASS CHO 1 USER.
//
//TRƯỜNG HỢP SINH VIÊN VẪN DÙNG MẢNG 1 CHIỀU LƯU DS PASSWORD THÌ SỐ LƯỢNG PHẦN TỬ MẢNG PASS SẼ RẤT LỚN.
//=> CÓ MỘT TEST BỊ "Memory Limit Exceeded": TEST 9, 10 12, 13, ... => TUY NHIÊN GV VẪN CHẤM ĐÚNG CHO TRƯỜNG HỢP NÀY.
//
//=> ĐỀ NGHỊ SINH VIÊN CHUYỂN SANG DÙNG LIST PASSWORD THAY VÌ DÙNG MẢNG 1 CHIỀU PASSWORD.
//VD NHƯ BÊN DƯỚI, HOẠC CÓ THỂ DÙNG LIST SẴN CÓ TRONG STD C++.


#include <iostream>
#include <string>
using namespace std;

#define M 100
#define numbucket 100

struct PASSWORD_NODE{
	string pass;
	PASSWORD_NODE *pNext;
};
struct USER_NODE {
    string user;
	PASSWORD_NODE* passHead;
	USER_NODE * pNext;

	PASSWORD_NODE* passTail;

};

// Khai báo kiểu con trỏ chỉ node
typedef USER_NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

int HF(string user) {
	int s=0;
	for(size_t i=0; i<user.length(); i++)
		s += int(user[i])*i;
	return s % numbucket;
}

void Init(HASHTABLE& H){
    for(int i = 0 ; i < M; i++){
        H[i] = NULL;
    }
}
// ý tưởng là tìm chỗ cần add vào nếu NULL thì add mới user, còn không thì addpass

USER_NODE* SearchNode(HASHTABLE H, string Name){
    int ind = HF(Name);
    USER_NODE* p = H[ind];
    while(p){
        if(p->user == Name) break;
        p = p->pNext;
    }
    return p;
}

USER_NODE* createUser( string Name ){
    USER_NODE* newU = new USER_NODE;
    newU-> user = Name;
    newU->passHead = NULL;
    newU->passTail = NULL;
    newU->pNext = NULL;

    return newU;
}

bool addUser(HASHTABLE& H, string Name){
    int ind = HF(Name);
    USER_NODE* p = createUser(Name);
    p->pNext = H[ind];
    H[ind] = p;
    return true;
}
PASSWORD_NODE* createPass(string Pass){
    PASSWORD_NODE *temp = new PASSWORD_NODE;
    temp->pass = Pass;
    temp->pNext = NULL;
    return temp;
}

bool addPassword (USER_NODE*& p, string Pass){
    PASSWORD_NODE* temp = createPass(Pass);
    if(p->passHead == NULL){
        p->passHead = temp;
        p->passTail = temp;
        return true;

    }
    else{
        p->passTail->pNext = temp;
        p->passTail = temp;
        return true;
    }
}

void createHashTable(HASHTABLE& H, int csdl){
    Init(H);

    for(int i = 0 ;i < csdl ; i++){
        string x; cin >> x;
        USER_NODE* p = SearchNode(H,x);
        string pass ; cin >> pass;

        if(p == NULL){
            addUser(H, x); // dòng này khiến bỏ qua đoạn pass ddaauf

        }
        p = SearchNode(H,x);

        addPassword(p,pass);


    }

}

void TRUYVAN(HASHTABLE H, int truyvan){
    while(truyvan--){
        string name; cin >> name;
        USER_NODE* temp = SearchNode(H,name);
        if(temp == NULL){
            cout <<"Unregistered User." <<endl;// ko endl?
        }
        else{
            PASSWORD_NODE* p = temp->passHead;
            while(p->pNext){

                p = p->pNext;
            }
            cout << p->pass <<" ";
            cout << endl;
        }
    }
}









int main(){
    int csdl, truyvan;
    cin >> csdl >> truyvan;
    HASHTABLE H;
    createHashTable(H,csdl);
    TRUYVAN(H, truyvan);
    return 0;
}

