#include <iostream>
using namespace std;

struct NODE{
    int info;
    NODE *pNext;
};
struct queue{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;

}



void CreateEmptyqueue(queue &q) {
    q.front = NULL;
    q.back = NULL;
}

int isEmpty(queue &q) {
    if (q.front == NULL) //queue rong
            return 1;
    return 0;
}



void Enqueue(queue &q, NODE* p) {
    if (q.front == NULL) {
        q.front = p;
        q.back = q.front;
    }
    else {
        q.back->pNext = p;
        q.back = p;
    }
}

int Dequeue(queue &Q, int &x) {
    NODE *p;
        if (isEmpty(Q) != 1) {
        if (Q.front != NULL) {
            p = Q.front;
            x = p->info;
            Q.front = Q.front->pNext;
            if (Q.front == NULL) Q.back = NULL;
            return 1;
        }
    }
    return 0;
}


void Createqueue(queue &q)
{
    CreateEmptyqueue(q);
    while(true){
        int temp; cin>> temp;
        if( temp == -1 ) break;
        NODE* p= CreatNode(temp);
        Enqueue(q,p);

    }
}

void Printqueue(queue q)
{
     if(isEmpty(q)){
        cout<<"danh sach rong";
        return;
    }
    else{

        NODE* p = q.front;
        while( p != NULL){
            cout<< p->info<< " ";
            p= p->pNext;
        }
    }
}

void printrevese(NODE* p){
    if( p == NULL)  return;

    printrevese(p->pNext);
    cout<< p->info <<" ";
}

void ReversePrintqueue(queue q)
{

    if(isEmpty(q)){
        cout<<"danh sach rong";
        return;
    }
    else{
        NODE* p = q.front;

        printrevese(p);
        
    }
}

bool front(queue& s,int& x){
    NODE *p;
    if (isEmpty(s) != 1) {
        // if (s.pHead != NULL){  // điều kiện này thừa do ở trên đã thỏa 
            p = s.front;
            x= p->info;
            return true; 
        // }
    }
    return false; // không có giá trị trả về
} 
bool back(queue& s,int& x){
    NODE *p;
    if (isEmpty(s) != 1) {
        // if (s.front != NULL){  // điều kiện này thừa do ở trên đã thỏa 
            p = s.back;
            x= p->info;
            return true; 
        // }
    }
    return false; // không có giá trị trả về
} 



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


#include <cctype> // Thư viện cho tolower()
#include <cstring> // Thư viện cho strlen()
// học cách tự viết lại hàm này
void toLowerCase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}


void ToLowerCase(char* str){
    int i =0;
    while(str[i] !='\0'){
        if(str[i]>='A' && str[i] <='Z'){
            str[i] +=32;
        }
        i++;
    }
}
#define MAX 300

void createQueue(queue& q){
    CreateEmptyqueue(q);
    stack s;
    CreateEmptystack(s);
    char st[MAX];
    cin.getline(st,MAX);
    int i =0;
    if(st[i] == '\0'){
        cout<<"Empty";
        return;
    }
    ToLowerCase(st);

    while(st[i] != '\0'){
        
        NODE* p1 = CreateNode(st[i]);
        NODE* p2 = CreateNode(st[i]); 
        Push(s, p1);
        Enqueue(q, p2);

        // Push(s,p);
        // Enqueue(q,p);


        i++;
    }

    i = 0;
    while(st[i] != '\0'){
        int x, y;

        Dequeue(q,x);
        Pop(s,y);

        if(x!=y){
            cout<<"False";
            return;
        }
        
        i++;
    }

    cout<<"True";


}




int main() {
    queue q;
	createQueue(q);
    return 0;
}
