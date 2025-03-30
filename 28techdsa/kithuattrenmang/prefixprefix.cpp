#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<vector>

#define int long long
// vì cộng dồn rồi nhân lại cho freq rồi lại cộng lại cho a[i] thì số rât rất lớn nên dùng kiểu int là sai
// thay thế kiểu int nhanh như trên chú ý phải khai báo lại main


// giải quyết M: mảng hiệu và mảng cộng dồn
//mảng hiệu lưu vị trí cập nhật

// giải quyết K truy vấn: lặp lại các thao tác M trong khoảng index 
//=> đếm số lần truy vấn M[i] bằng mảng hiệu rồi cộng dồn 
// ví dụ: 0 0 1 2 2 1 0

// ta được mảng tần suất truy vấn theo index 
//sau đó ta mới nhân tần suất với với mảng hiệu của từng truy vấn

//lưu ý l r >=1


// với dạng bài phức tạp hoặc dùng mảng hiệu, mảng cộng dồn các chỉ số nên bắt đầu từ 1
// int main() {


// bắt buộc là int32_t vì tương đương int khi không nói gì
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n+2);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<vector<int>> temp(m+2,vector<int>(4));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>temp[i][j];
        }
    }

    vector<int> freq(m+2);

    while(k--){
        int l,r;cin>>l>>r;
        freq[l]+=1;
        freq[r+1]-=1;
    }

    for(int i=1;i<=m;i++){ // mảng freq bắt đầu từ 1 nên phải +1 thêm nữa mà cho truy xuất r+1 nên phải cộng thêm 1 nữa
        freq[i]+=freq[i-1];
    }
    freq.pop_back();

    vector<int> delta(n+2,0);

    for(int i=1;i<=m;i++){
        delta[temp[i][1]] += temp[i][3]* freq[i]; // truy vấn thứ i mà freq đang chênh 1 số
        delta[temp[i][2]+1] -= temp[i][3]* freq[i];
    }

    for(int i=1;i<=n;i++){
        delta[i] += delta[i-1];
        a[i] +=delta[i];
    }


    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }

    
    
    return 0;
}
