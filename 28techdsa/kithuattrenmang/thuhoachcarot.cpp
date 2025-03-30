#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <cstring> //dung dc memset
int maxx;

void sol(int** pre, int x1,int x2,int y1,int y2){
    cout<< pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1]<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;cin>>n>>m;
    // int** a=new int*[n];
    // for(int i=0;i<n;i++){
    //     a[i]=new int[m];
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>a[i][j];
    //     }
    // }


    // int** pre=new int*[n+1];
    // for(int i=0;i<n+1;i++){
    //     pre[i]=new int[m+1];
    // }
    
    // // vì khai báo local nên các giá trị là rác
    // // memset(pre,0,sizeof(pre)); // sai vì chỉ áp dụng cho mảng 1 chiều
    // for(int i = 0; i < n+1; i++) {
    //     for(int j = 0; j < m+1; j++) {
    //     pre[i][j] = 0;
    //     }
    // }

    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         pre[i][j]= pre[i-1][j]+ pre[i][j-1] -pre[i-1][j-1] +a[i][j];
    //     }
    // }
    // int q;cin>>q;
    
    // for(int i=0;i<q;i++){
    //     int x1,x2,y1,y2;cin>>x1>>x2>>y1>>y2;
    //     sol(pre,x1,x2,y1,y2);
    // }
    int** a=new int*[n+1];
    int** pre=new int*[n+1];

    for(int i=0;i<n+1;i++){
        a[i]=new int[m+1]{};
        pre[i]=new int[m+1]{};
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            pre[i][j]= pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1] + a[i][j];

        }
    }

    int q;cin>>q;
    while(q--){
        // đúng vị trí luôn không cần -1 mới ra đúng vị trí index
        int x1,x2,y1,y2;cin>>x1>>x2>>y1>>y2;
        cout<<pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1]<<endl;
    }

    delete[]a;
    delete[] pre;
    return 0;
}
