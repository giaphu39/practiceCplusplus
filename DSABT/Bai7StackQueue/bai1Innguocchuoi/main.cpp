
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300


// ý tưởng là lưu space và khi gặp space thì tìm từ bỏ vào hết stack

struct NODE{
    string data;
    NODE* pNext;
};


struct Stack{
    NODE* pHead;
    NODE* pTail;
};


void createEmptyStack(Stack& s){
    s.pHead = NULL;
    s.pTail = NULL;
}

NODE* createNODE(string x){
    NODE* p = new NODE;
    if(p == NULL){
        exit(1);
    }
    p->data = x;
    p->pNext = NULL;

    return p;
}

void Push(Stack& s, NODE* p){

    if(s.pHead == NULL){
        s.pHead = p;
        s.pTail = p;
    }
    else{
        p->pNext = s.pHead;
        s.pHead = p;
    }

}

//bool Pop(Stack& s, string& x){ // sai pop phải là ở đầu
//    NODE* p = s.pHead;
//    NODE* deleteNODE = s.pTail;
//    if(s.pTail == NULL) return 0;
//    else if( s.pHead == s.pTail){
//        x = s.pHead ->data;
//        s.pHead = NULL;
//        s.pTail = NULL;
//
//        delete deleteNODE;
//    }
//    else{
//        while( p->pNext ->pNext !=NULL){
//            p = p->pNext;
//        }
//
//
//        p->pNext = NULL;
//        s.pTail = p;
//        delete deleteNODE;
//
//    }
//    return true;
//}

bool Pop(Stack& s, string& x){ // sai pop phải là ở đầu
    NODE* p = s.pHead;
    NODE* deleteNODE = s.pHead;
    if(p == NULL) return false;
    else{
        x = deleteNODE->data;
        p = p->pNext;
        s.pHead = p;
        delete deleteNODE;

        return true;
    }
}
bool isChu(char a){
    return (a >='A' && a <='Z') || (a >='a' && a <='z');
}
bool isspace(char a){
    return a==' ';
}
void createStack(Stack& s, string a){
    createEmptyStack(s);
//    int x;
//    while(true){
//        cin >> x;
//        if(x == 0) break;
//        NODE* p = createNODE(x);
//        Push(s,p);
//    }
    int i = 0;
    string word;
    while(a[i] != '\0'){

        if(! isspace(a[i])){
             while(! isspace(a[i]) && a[i] != '\0'){
                word += a[i];
                i++;
            }
            NODE* p = createNODE(word);
            Push(s,p);
            word = "";
        }

        else{
            i++;
            word = " ";
            NODE* p = createNODE(word);
            Push(s,p);
            word = "";
        }
    }
}


void StringReverse(string& a){
    Stack s;
    createStack(s,a);
    string b;
    NODE* p = s.pHead;
    string temp;
    while (Pop(s, temp)) {
        b += temp;
    }

    // sai do mỗi lần Pop thì số lượng nó thay đổi nên không thể dùng cách này
    // while(p!=NULL){
    //     string temp;
    //     Pop(s,temp);
    //     b += temp;

    //     p = p->pNext;
    // }
    a = b;
}



int main () {
    string s;

    getline(std::cin, s);	//Nhap chuoi s

    if(s.empty() == true)
        cout << "Chuoi rong." << endl;
    else {
        StringReverse(s);
        cout << s << endl;

    }

    return 0;
}
