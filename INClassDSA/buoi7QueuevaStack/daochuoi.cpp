#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
#include<string>
struct NODE {
    char info;
    NODE* pNext;
};

struct Stack {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyStack(Stack &s) {
    s.pHead = NULL;
    s.pTail = NULL;
}

int isEmpty(Stack &s) {
    if (s.pHead == NULL) //Stack rong
            return 1;
    return 0;
}

NODE* CreateNode(char x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void Push(Stack &s, NODE* p) { // push vào đầu 
    if (s.pHead == NULL) {
        s.pHead = p;
        s.pTail = s.pHead;
    }
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

int Pop(Stack &s, char &x) {
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


void CreateStack(Stack &s)
{
    CreateEmptyStack(s);
    string word;
    getline(cin,word);

    for(int i=0 ;i< word.size();i++){
        NODE* p = CreateNode(word[i]);
        Push(s,p);
    }
}

// void PrintStack(Stack s)
// {

//     if(isEmpty(s)){
//         cout<<"danh sach rong";
//         return;
//     }
//     else{

//         NODE* p = s.pHead;
//         while( p != NULL){
//             cout<< p->info<< " ";
//             p= p->pNext;
//         }
//     }
// }
void printrevese(NODE* p){
    if( p == NULL)  return;

    printrevese(p->pNext);
    // cout<< p->info <<" ";
    cout<< p->info;
}

void ReversePrintStack(Stack s)
{

    if(isEmpty(s)){
        cout<<"danh sach rong";
        return;
    }
    else{
        NODE* p = s.pHead;

        printrevese(p);
        
    }
}

void PrintStack(Stack& s)
{
    if(isEmpty(s)){
        cout<<"Mang Rong";
        return;
    }
    else{
        NODE* p = s.pHead;
        while( true ){
            if(isEmpty(s)){ // quan trọng nhất là điểm dừng 
                break;
            }
            char x;
            Pop(s,x);
            cout << x <<" ";
            
        }
        

    }
}
int main() {
    Stack s;
    CreateStack(s);
    PrintStack(s);
    return 0;
}