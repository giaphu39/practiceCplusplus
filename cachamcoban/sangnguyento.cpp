#include <iostream>
using namespace std;

// tạo một 
int arr[1000001];
void sangnguyento(){
    for(int i=0;i<=1000000;i++){
        arr[i]=true;
    }
    arr[0]=arr[1]=0;
    for(int i=2;i<=1000;i++){
        if(arr[i]){
            for(int j=i*i;j<=1000;j+=i){
                arr[j]=false;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    sangnguyento();
    if(arr[n]){
        cout<<" là số nguyên tố";
    }
    else{cout<<"không phải";}
    return 0;
}