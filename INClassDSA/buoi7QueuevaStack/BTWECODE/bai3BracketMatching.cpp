// thêm đầu cho stack
// thêm cuối cho queue 
// còn lấy ra là removeHead

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

void Createstack(stack &s)
{
    CreateEmptystack(s);
    while(true){
        int temp; cin>> temp;
        if(temp == -1 ) break;
        NODE* p = CreateNode(temp);
        Push(s,p);
    }
}

// void Printstack(stack s)
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
void Printstack(stack s)
{
    // if(isEmpty(s)){
    //     cout<<"Mang Rong";
    //     return;
    // }
    // else{
        // NODE* p = s.pHead;
        while (true) {
            int x;
            if(Pop(s,x)){
                cout << x ;
            }
            else{
                break;
            }
        }
        

    // }
}
void printrevese(NODE* p){
    if( p == NULL)  return;

    printrevese(p->pNext);
    cout<< p->info <<" ";
}

void ReversePrintstack(stack s)
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


void Testing_Push_Pop_Top_Stack(stack& s){
    CreateEmptystack(s);
    

    // int a[100]; // mảng lưu output
    // int b[100] ; // mảng lưu top
    cout<<"output: ";

    while(true){
        int temp; cin>>temp;
        if( temp == -1 ){
            cout<<endl;
            cout<<"top: ";
            // sau đó lấy top ra
            int x;
            if(Top(s,x)){
                cout << x <<" ";
            }

            break;

        }
        
        if( temp == 0){
            int x;
            if( Pop(s,x)){
                cout<< x << " ";
            }
            
        }
        else{
            NODE* p = CreateNode(temp);
            Push(s,p);
        }
    }
}



void decimal_to_binary(int n){
    stack s;
    CreateEmptystack(s);
    if(n == 0){
        cout<<0;
        return;
    }
    while(n !=0){
        int x;
        x = n%2;
        n /= 2;
        NODE* p = CreateNode(x);
        Push(s,p);
    }
    
    Printstack(s);
}

void BracketMatching(stack s,char* st){
    CreateEmptystack(s);
    cin.getline(st,MAX);
    int i =0;
    // bool flag = 0;
    while(st[i] != '\0'){
        
        if(st[i] == '('){
            NODE* p = CreateNode(1);
            Push(s,p);

        }

        if( st[i] == ')'){
            if(isEmpty(s)){
                cout<<"False";
                return;
            }
            else{
                int x;
                Pop(s,x);
            }
        }


        i++;
    }

    if(isEmpty(s)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }


}



int main() {
    stack s;
    char st[100];
    BracketMatching(s,st);
    return 0;
}

