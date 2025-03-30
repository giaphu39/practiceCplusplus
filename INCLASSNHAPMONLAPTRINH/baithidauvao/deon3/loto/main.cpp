#include <bits/stdc++.h>


using namespace std;

int main()
{
    vector<vector<int>> a(3,vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cin>>a[i][j];
    }
    int n;cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<vector<int>> mark(3,vector<int>(3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int z=0;z<n;z++){ // loi cho nay nho chu y dau la bien chay
                if(a[i][j]==b[z])
                    mark[i][j]=1;
            }//nếu chỉ được tính 1 số thì sao
        }
    }

    //kiem tra thoa chua
    int flag=0;
    //lap qua moi hang
    for(int i=0;i<3;i++){
        int flag1=1;
        for(int j=0;j<3;j++){
            if(mark[i][j]!=1) flag1=0; //chu y dieu kien xet
        }
        if(flag1){
            flag=1;
            break;
        }
    }
    //lap qua tung cot
    for(int j=0;j<3;j++){ // 3 la so cot
        int flag1=1;
        for(int i=0;i<3;i++){
            if(mark[i][j]!=1) flag1=0;
        }
        if(flag1){
            flag=1;
            break;
        }
    }
    //lap qua duong cheo chinh
    int flag1=1;//phai de o ngoai vi trong vong lap se luon dung
    for(int i=0;i<3;i++){

        if(mark[i][i]!=1) flag1=0;
    }
    if(flag1) flag=1;
    //duong cheo phu
    flag1=1;
    for(int i=0;i<3;i++){
        if(mark[i][3-i-1]!=1) flag1=0; // 3 nay la kich thuoc m cua mang

    }
    if(flag1)flag=1;
    if(flag)cout<<"Yes";
    else cout<<"No";
    return 0;
}
