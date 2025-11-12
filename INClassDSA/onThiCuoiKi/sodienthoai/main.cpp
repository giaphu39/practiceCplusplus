#include <iostream>
#include<stack>

using namespace std;

void Init(int* a){
    for(int i= 0;i < 1000;i++){
        a[i] =0;
    }
}

void input(){
   int k , n ;
   cin >> k >> n;
   stack<int> tn;
   int mark[1000];
   Init(mark);
   for(int i =0; i < n; i++){
    int temp; cin >> temp;
    tn.push(temp);
    mark[temp]++;
   }
   int daIn[1000];
   Init(daIn);
   int j = 0;
    while(j != k){
        int so = tn.top();
        tn.pop();
        if(daIn[so]) continue;
        else{
            daIn[so]++;
            j++;
        }

        if(mark[so] ==1){
            cout << so << " ";
        }
        else
            cout << so << "(" << mark[so] << "}"<< " ";
    }

}

int main()
{
    input();
    return 0;
}
