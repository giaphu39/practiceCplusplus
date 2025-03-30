#include<iostream>
using namespace std;
#define Mod 1000000007
#define MAX 300
void input(int& n, int arr[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void output(int n, int arr[]){
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // ans+=(((arr[i]%Mod) * (arr[j]%Mod))%Mod);
            // dòng này sai do nó sẽ lấy số đó chia lấy dư 

            // lỗi tràn số do vượt quá kiểu int 
            // cách 1: nhân thêm 1 ll vào để ép nó thành kiểu long long trong phép nhân
            // cách 2: cin vào là kiểu ll
            ans+=(((1ll* arr[i]%Mod) * (arr[j]%Mod)));
            ans%=Mod;
        }
    }
    cout<<ans;
}
int main(){
    int n;
    int arr[MAX];
    input(n,arr);
    output(n,arr);


    return 0;
}
