#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int coun=0,n,k,s;
int used[100]; // chưa dùng =0
void quaylui(int sl, int sum, int start){

    // if(sl==k && sum==s ){
    //     coun++;
    //     return;
    // }
    // // không nên bắt đầu từ số 1 vì sẽ có rất nhiều sô
    // // for(int i=1;i<=n;i++){
    // for(int i=1;i<=n;i++){
    //     if(!used[i] && sl+1<= k && sum+i<=s){
    //         used[i]=1;
    //         int sl1=sl+1;
    //         int sum1=sum+i;
    //         quaylui(sl1,sum1); // nếu truyền thắng vào thì giá trị sum và sl không đổi do đó không cần ghi vậy
    //         // nếu muốn cập nhật sum thì mới dùng cách này sau đó phải trả lại giá trị sum ban đầu sau khi quaylui


    //         used[i]=0;
    //     }
    // }

    if(sl==k && sum==s){
        coun++;
        return;
    }

    for(int i=start;i<=n;i++){
        // có thể thêm điều kiền xét trươc để giảm bớt nước đi
        if(sl+1<=k || sum+i<=s ){
            quaylui(sl+1, sum+i, i+1);
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>k>>s;    

    quaylui(0,0,1);
    cout<<coun;


    return 0;
}
