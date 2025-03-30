#include<iostream>
using namespace std;

int n,arr[100],k;

void func1(int=0);
void ketqua(){
    for(int i=1;i<=n;i++){ // in đến k phần tử
        cout<<arr[i];
    }
    cout<<endl;
}
// phần tử max tại i là n-k+i
// phần tử nhỏ nhất tại i là arr[i-1]+1

void _try(int i){
    // duyệt các khả năng của arr[i] có thể nhận được 
    for(int j=arr[i-1]+1;j<=n-k+i;j++){
        arr[i]=j; // điều này sẽ tạo ra các số khác nhau trong tổ hợp trong đệ quy nhiều lần
        if(i==k){
            ketqua();
        }
        else {
            _try(i+1);
        }
    }
}
int main(){
    cin>>n>>k;
    arr[0]=0;
    _try(1);
    return 0;
}