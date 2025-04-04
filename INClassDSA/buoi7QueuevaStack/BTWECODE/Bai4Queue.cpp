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

void createQueue(queue& q){
    CreateEmptyqueue(q);
    

    cout<<"output: ";

    while(true){
        int temp; cin>>temp;
        if( temp == -1 ){
            cout<<endl;
            cout<<"front: ";
            // sau đó lấy top ra
            int x;
            if(front(q,x)){
                cout << x <<" ";
            }
            cout<<endl;
            cout<<"back: ";
            if(back(q,x)){
                cout << x <<" ";
            }
            break;

        }
        
        if( temp == 0){
            int x;
            if( Dequeue(q,x)){
                cout<< x << " ";
            }
            
        }
        else{
            NODE* p = CreatNode(temp);
            Enqueue(q,p);
        }
    }
}





int main() {
    queue q;
	createQueue(q);
    return 0;
}
