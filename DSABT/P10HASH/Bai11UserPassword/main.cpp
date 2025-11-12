
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

#define M 5000
#define numbucket 5000

struct PASSWORD_NODE{
	string pass;
	PASSWORD_NODE *pNext;
};
struct USER_NODE {
    string user;
	PASSWORD_NODE* passHead;
	USER_NODE * pNext;

};

// Khai báo kiểu con trỏ chỉ node
typedef USER_NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];


// ý tưởng là mỗi tên user là dịa chỉ nối liền theo kiểu linked list các mật khẩu addTail
int HF(string user) {
	int s=0;
	for(int i=0; i<user.size(); i++)
		s += int(user[i])*i;
	return s % numbucket;
}

USER_NODE* createNode(string name){
    USER_NODE* p = new USER_NODE;
    p->user = name;
    p->passHead = NULL;
    p->pNext = NULL;

    return p;

}

PASSWORD_NODE* createPass(string name){
    PASSWORD_NODE* p = new PASSWORD_NODE;
    p->pass = name;
    p->pNext = NULL;

    return p;

}


bool addTailPASS(USER_NODE*& user, string Password, string Name){ // hàm này add được password, không đổi user
    if(user == NULL){
        USER_NODE* p = createNode(Name);
        PASSWORD_NODE* pass = createPass(Password);
        p->passHead = pass;

        user = p;
        return true;
    }
    else{
        PASSWORD_NODE* PassP = user->passHead; // sai ở đây nếu làm vậy thì khi thay đổi PassP là thay đổi con trỏ thôi, nếu muốn truy cập vào gia trị qua trung gian
        // thì dùng pNext vì là truy cập vào địa chỉ
//        while(PassP->pNext){
//            if(PassP->pNext->pass == Password) return false;
//            PassP = PassP->pNext;
//        }
        while (PassP) { // cách viết này hay hơn vừa kt hiện tại an toàn vừa kt phía trước
            if (PassP->pass == Password) return false;
            if (PassP->pNext == NULL) break;
            PassP = PassP->pNext;
        }
        PASSWORD_NODE* p = createPass(Password);
        PassP->pNext = p;
        return true; // thiếu return gây runtime error
    }
}

//bool addTailUser(USER_NODE*& user, string Password, string Name){
////    if(user == NULL){ // trường hợp chưa có gì
////        addTailPASS(user,Password,Name);
////
////    }
//    // trường hợp có nhưng chưa có paasss mới
//    // trường hợp chưa có pass
//
//        USER_NODE* p = user;
//        USER_NODE* q = NULL;
//    while(p != NULL && p->user != Name){
//        q = p;
//        p = p->pNext;
//
//    }
//    if(q == NULL) addTailPASS(user,Password,Name);
//    else addTailPASS(q->pNext,Password,Name);
//
//    return true;
//
//}
bool addTailUser(USER_NODE*& user, string Password, string Name){
    USER_NODE* p = user;
    while (p) {
        if (p->user == Name) return addTailPASS(p, Password, Name);
        if (p->pNext == NULL) break;
        p = p->pNext;
    }
    // Nếu chưa có user, tạo mới
    if (user == NULL) return addTailPASS(user, Password, Name);
    else return addTailPASS(p->pNext, Password, Name);
}

void Init(HASHTABLE & h){
    for(int i =0;i< numbucket ; i++){
        h[i] = NULL;
    }
}
void CreateHashTable(HASHTABLE& H, int csdl){
    Init(H);
    for(int i=0;i < csdl; i++){
        string name; cin >> name;
        string pass; cin >> pass;
        int ind = HF(name);
        addTailUser(H[ind],pass,name);
    }
}


void TRUYVAN(HASHTABLE H, int truyvan){
    while(truyvan--){
        string temp; cin >> temp;
        int ind = HF(temp);
        USER_NODE* p = H[ind];

        while(p){
            if(p->user == temp) break;
            p = p->pNext;
        }

        if(p == NULL){
            cout << "Unregistered User." << endl;
            continue;
        }

        PASSWORD_NODE* pPass = p->passHead;
        while(pPass){
            cout << pPass->pass << " ";
            pPass = pPass->pNext;
        }
        cout << endl;
    }
}







int main(){
    HASHTABLE H;
    int csdl, truyvan;
    cin >> csdl >> truyvan;
    CreateHashTable(H, csdl);
    TRUYVAN(H, truyvan);

    return 0;
}
