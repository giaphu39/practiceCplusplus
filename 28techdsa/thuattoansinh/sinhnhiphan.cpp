#include <iostream>
using namespace std;
#include <algorithm>
int a[100],n, ok;

void cauhinhdau(){
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
}
void sinh(){

    // bắt đầu từ bit cuối trong màn hình
    int i=n;
    while(i>=1 and a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0) ok= false;
    a[i]=1;
}

int main() {
    cin>>n;
    ok=true;
    cauhinhdau();
    while(ok){
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        sinh();
    }
    return 0;
}
