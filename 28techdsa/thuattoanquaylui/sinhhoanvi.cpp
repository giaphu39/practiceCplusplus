#include<iostream>
#include <cstring> //để dùng được menset
using namespace std;

int n,arr[100],used[100];
void ketqua(){
    for(int i=1;i<=n;i++){ 
        cout<<arr[i];
    }
    cout<<endl;
}

// có bài toán là + giá trị trong used sử dụng xong thì trừ ra
void _try(int i){
    // duyệt các khả năng của arr[i] có thể nhận được 
    for(int j=1;j<=n;j++){
        // xét xem có thể gán arr[i]=j không
        if(used[i]==0){
            arr[i]=j;
            used[j]=1; // đánh dấu không được dùng lại j nữa
        
            if(i==n) {ketqua();}
            else {
                _try(i+1);
            }
            //backtrack
            used[j]=0;
        }
    }
}
int main(){
    cin>>n;
    memset(used,0,sizeof(used)); // khởi tạo các giá trị ban đầu của used =0 hết
    _try(1);
    return 0;
}