#include<iostream>
#include<vector>
#include <algorithm> // để dùng được max_element
using namespace std;
// độ phức tạp o(n^2)

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> L(n,1);
    // L[i] độ dài dãy con tăng dài nhất kết thúc tại vị trí i
    // L[i]=max(L[i],L[j+1]) nếu a[i]>a[j];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                L[i]=max(L[i],L[j]+1); // để max vì nếu để L[i]=L[j]+1 thì nó chỉ xét cái cuối
                // còn ghi theo kiểu này thì L[i]đc gán liên tục và xét với các L[j] tiếp theo

            }
        }
    }
    cout<<*max_element(L.begin(),L.end());
    return 0;
}