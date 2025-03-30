#include<iostream>
using namespace std;
#define MAX 200000
// vị trí: Hà Ý Dương (i j k)
// ý tưởng: chọn vị trí cho hà trong lặp
int main(){
    int n;
    cin>>n;
    int* a= new int[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]==a[j]) continue;
            for(int k=j;k<n;k++){
                if(a[i]!=a[j] and a[i]!=a[k] and a[j]!=a[k]){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}