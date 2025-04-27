#include <iostream>
using namespace std;






#define MAX 100
struct NODE {
    int info;
    NODE* pNext;
};

struct stack {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptystack(stack &s) {
    s.pHead = NULL;
    s.pTail = NULL;
}

int isEmpty(stack &s) {
    if (s.pHead == NULL) //stack rong
            return 1;
    return 0;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void Push(stack &s, NODE* p) { // push vào đầu
    if (s.pHead == NULL) {
        s.pHead = p;
        s.pTail = s.pHead;
    }
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

int Pop(stack &s, int &x) {
    NODE *p;
    if (isEmpty(s) != 1) {
        if (s.pHead != NULL){  // điều kiện này thừa do ở trên đã thỏa
            p = s.pHead;
            x = p->info;
            s.pHead = s.pHead->pNext;
            if (s.pHead == NULL) // trường hợp chỉ có 1 phần tử mà lấy nó ra luôn
                s.pTail = NULL;
            return 1;
        }
    }
    return 0;
}

bool Top(stack& s,int& x){
    NODE *p;
    if (isEmpty(s) != 1) {
        if (s.pHead != NULL){  // điều kiện này thừa do ở trên đã thỏa
            p = s.pHead;
            x= p->info;
            return true;
        }
    }
    return false; // không có giá trị trả về
}

void input(int* a, int& n){
    cin >> n;
    for(int i= 0; i< n;i++){
            cin >> a[i];
        }
}
void output(int* a, int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
void array_reverse(stack& s,int* a,int n){
    input(a,n);
    CreateEmptystack(s);

    for(int i = 0 ; i< n;i++){
        NODE* p =CreateNode(a[i]);
        Push(s,p);
    }

    for(int i = 0 ; i < n;i++){
        int x;
        Pop(s,x);
        a[i] = x;
    }

    output(a,n);




}






int main() {
    stack s;
    int a[100], n;
    array_reverse(s,a,n);
    return 0;
}
