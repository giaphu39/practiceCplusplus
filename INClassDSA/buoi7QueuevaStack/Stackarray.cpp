#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
struct Stack {
    int a[MAX];
    int t;
};

void CreateEmptyStack(Stack &s) {
	s.t = -1;
}

bool isEmpty(Stack s)
{
    if (s.t == -1)
		return 1;
    return 0;
}

bool isFull(Stack s) {
    if (s.t >= MAX)
		return 1;
    return 0;
}

bool Push(Stack &s, int x) {
    if (isFull(s) == 0){
        s.a[++s.t] = x;
        return 1;
    }
    return 0;
}

int Pop(Stack &s, int &x) {
    if (isEmpty(s) == 0) {
        x = s.a[s.t--];
        return 1;
    }
    return 0;
}

void CreateStack(Stack &s)
{
    CreateEmptyStack(s);
    
    while(true){
        int temp;
        cin >> temp;
        if(temp == -1){
            break;
        }

        Push(s,temp);
    }
}

// void PrintStack(Stack s)
// {
//     if(isEmpty(s)){
//         cout<<"Mang Rong";
//         return;
//     }
//     else{
//         for(int i=0 ; i < s.t + 1;i++){
//             cout<< s.a[i] << " ";
//         }
//     }
// }

void PrintStack(Stack s)
{
    if(isEmpty(s)){
        cout<<"Mang Rong";
        return;
    }
    else{
        int i=0;
        while( true ){
            if(i == s.t + 1){
                break;
            }
            int x;
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