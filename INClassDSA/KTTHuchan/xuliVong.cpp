#include<iostream>
#include <queue>

using namespace std;


void Input(queue<int>& q){
    while(true){
        int x; cin>> x;
        if(x == -1) break;
        q.push(x);

    }

}

void Output(queue<int>& q){
    int k; cin >> k;
    if(k < 0){
        cout << "invalid" ;
        return;
    }
    
    for(int i = 0; i < k; ++i){
        int front = q.front();
        q.pop();
        q.push(front);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(){


    queue<int> q;
    Input(q);
    Output(q);
    return 0;

}