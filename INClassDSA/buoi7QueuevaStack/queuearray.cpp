#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

typedef struct tagQueue {
    int a[MAX];
    int Front; //chỉ số của phần tử đầu trong Queue
    int Rear; //chỉ số của phần tử cuối trong Queue
} Queue;

void CreateEmptyQueue(Queue &q) {
    q.Front = -1;
    q.Rear = -1;
}

bool isEmpty(Queue q) { // Queue có rỗng?
    if (q.Front == -1)
        return 1;
    return 0;
}

bool isFull(Queue q) { // Kiểm tra Queue có đầy?
    if (q.Rear - q.Front + 1 == MAX)
        return 1;
    return 0;
}

void EnQueue(Queue &q, int x) {
    int f, r;
    if (isFull(q)) //queue bị đầy => không thêm được nữa
           cout<<"queue day roi khong the them vao duoc nua";
    else {
        if (q.Front == -1) {
            q.Front = 0;
            q.Rear = -1; // thêm phần tử đầu nhưng phần cuối chưa tính
        }
        if (q.Rear == MAX - 1) { //Queue đầy ảo 
            // nhưng mà vẫn có ô trống ở đầu
            f = q.Front;
            r = q.Rear;
            for (int i = f; i <= r; i++)
                q.a[i - f] = q.a[i];
            q.Front = 0;
            q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x; // add vào cuối
    }
}

bool DeQueue(Queue &q, int &x) {
    if (isEmpty(q)==0) { //queue khong rong
        x = q.a[q.Front];
        q.Front++;
        if (q.Front>q.Rear) { //truong hop co mot phan tu
            q.Front = -1;
            q.Rear = -1;
        }
        return 1;
    }
    cout<<"Queue rong";
    return 0;
}


void CreateQueue(Queue &q)
{
    CreateEmptyQueue(q);
    
    while(true){
        int temp;
        cin >> temp;
        if(temp == -1){
            break;
        }

        EnQueue(q,temp);
    }
}

// void PrintQueue(Queue q)
// {
//     if(isEmpty(q)){
//         cout<<"Mang Rong";
//         return;
//     }
//     else{
//         for(int i=front ; i < q.Rear + 1;i++){
//             cout<< q.a[i] << " ";
//         }
//     }
// }
void PrintQueue(Queue q)
{
    if(isEmpty(q)){
        cout<<"Mang Rong";
        return;
    }
    else{
        int i=0;
        while( true ){
            if(i == q.Rear + 1){
                break;
            }
            int x;
            DeQueue(q,x);
            cout << x <<" ";
            
        }
        
    }
}
int main() {
    Queue s;
    CreateQueue(s);
    PrintQueue(s);
    return 0;
}