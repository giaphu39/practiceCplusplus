#include <iostream>
#include <string>
using namespace std;

#define M 100  // kích thước bảng băm
#define numbucket 100

struct PASSWORD_NODE {
    string pass;
    PASSWORD_NODE *pNext;
    PASSWORD_NODE(string p) : pass(p), pNext(nullptr) {}
};

struct USER_NODE {
    string user;
    PASSWORD_NODE* passHead;
    PASSWORD_NODE* passTail; // Để thêm mật khẩu nhanh
    USER_NODE *pNext;

    USER_NODE(string u) : user(u), passHead(nullptr), passTail(nullptr), pNext(nullptr) {}
};

typedef USER_NODE* NODEPTR;
typedef NODEPTR HASHTABLE[numbucket];

int HF(string user) {
    int s = 0;
    for (int i = 0; i < (int)user.length(); i++)
        s += int(user[i]) * i;
    return s % numbucket;
}

// Tìm user trong bảng băm
USER_NODE* findUser(HASHTABLE &ht, string user) {
    int h = HF(user);
    USER_NODE* cur = ht[h];
    while (cur != nullptr) {
        if (cur->user == user)
            return cur;
        cur = cur->pNext;
    }
    return nullptr;
}

// Thêm user mới vào bảng băm
USER_NODE* addUser(HASHTABLE &ht, string user) {
    int h = HF(user); // nếu nó NULL thì tính lại để có vị trí thêm vào
    USER_NODE* newUser = new USER_NODE(user);
    newUser->pNext = ht[h]; // add vào đầu
    ht[h] = newUser;
    return newUser;
}

// Thêm mật khẩu cho user
void addPassword(USER_NODE* userNode, string pass) {
    PASSWORD_NODE* newPass = new PASSWORD_NODE(pass);
    if (userNode->passHead == nullptr) {
        userNode->passHead = userNode->passTail = newPass;
    } else {
        userNode->passTail->pNext = newPass;
        userNode->passTail = newPass;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M_input;
    cin >> N >> M_input;

    HASHTABLE hashTable = { nullptr };

    // Nhập dữ liệu (user, pass)
    for (int i = 0; i < N; i++) {
        string user, pass;
        cin >> user >> pass;
        USER_NODE* userNode = findUser(hashTable, user);
        if (userNode == nullptr) {
            userNode = addUser(hashTable, user);
        }
        addPassword(userNode, pass);
    }

    // Xử lý truy vấn
    for (int i = 0; i < M_input; i++) {
        string queryUser;
        cin >> queryUser;

        USER_NODE* userNode = findUser(hashTable, queryUser);
        if (userNode == nullptr) {
            cout << "Unregistered User." << "\n";
        } else {
            PASSWORD_NODE* p = userNode->passHead;
            bool first = true;
            while (p != nullptr) {
                if (!first) cout << " ";
                cout << p->pass;
                first = false;
                p = p->pNext;
            }
            cout << "\n";
        }
    }

    return 0;
}
