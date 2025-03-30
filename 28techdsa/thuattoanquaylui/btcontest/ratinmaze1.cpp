#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <utility>
int n, a[100][100],check=0;
pair<int,int> ind[2] ={{1,0},{0,1}};
string S="DR";
string s;
void quaylui(int i, int j){
    // điều kiện dừng luôn được đặt trước
    if(i==n && j==n){
        check++;
        cout<<s<<endl;
        return;
    }
    // tạo nhánh với mỗi nhánh sẽ cộng vào đáp án một giá trị nào đó rồi đệ quy tới giá trị tiếp
    for(int z=0;z<2;z++){
        int i1=i+ ind[z].first;
        int j1=j+ ind[z].second;
        if(i1<=n && j1<=n && a[i1][j1]==1){
            s+=S[z];

            a[i1][j1]=0; // dòng này 
            quaylui(i1,j1);

            // phải trả lại
            s.pop_back();
            a[i1][j1]=1;// với dòng này có thể bỏ cũng được vì nó không có chạy lên hoặc qua trái nên chắc chắn không lặp lại đườn đã đi

        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];        
        }
    }
    quaylui(1,1);
    if(!check){
        cout<<-1;
    }
    return 0;
}
