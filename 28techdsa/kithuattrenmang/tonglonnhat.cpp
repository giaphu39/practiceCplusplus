#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<vector>

//dùng kĩ thuật mảng cộng dồn
//kĩ thuật mảng hiệu để tính tần suất xuất hiện,tại vị trí left bắt đầu lấy số thì +1 còn kết thúc thì -1 
// vị trí số 0 là không xuất hiện lần nào 
//vì cho sắp xếp bất kì sao cho số lớn nhất nên so khớp số lớn nhất với tần suất lớn nhất

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // nếu như kích thước là n thì fluency phải bắt đầu từ ind 0 thì chỉ có l và r+1 bị tác động
    vector<int> fluency(n+1);
    while(q--){
        int l,r;cin>>l>>r;
        fluency[l-1]+=1; // cố thể sai nếu l=0; nhưng đề bài cho l và r là ind+1 nên ghi vậy
        fluency[r]-=1;
    }

    for(int i=1;i<=n;i++){
        fluency[i]+=fluency[i-1];
    }
    fluency.pop_back();

    sort(a.rbegin(),a.rend());
    sort(fluency.rbegin(),fluency.rend());
    
    long long ans=0;
    for(int i=0;i<n;i++){
        if(fluency[i]){
            ans+= 1ll* fluency[i]* a[i];
        }
    }
    
    cout<<ans;
    return 0;
}
