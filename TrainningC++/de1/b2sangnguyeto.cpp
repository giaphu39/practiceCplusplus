#include<iostream>
using namespace std;
#define MAX 100000
int *arr= new int[MAX];

void sangnguyento(int n){
    for(int i=0;i<n;i++){
        arr[i]=1;
    }

    arr[0]=0;// 0 là false
    arr[1]=0;
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            arr[j]=0;
        }
    }
}

void sol(int n){
    if(arr[n]==0) cout<<false;
    else cout<<true;
}

int main(){

    int n;
    cin>>n;
    sangnguyento(n);
    sol(n);
    delete[] arr;
    return 0;
}