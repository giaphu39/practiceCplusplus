#include<iostream>
using namespace std;

int mark[3][3]={0};
int main(){
    int a[3][3];
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int n;cin>>n;
    int b[10];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int z=0;z<n;z++){
                if(a[i][j]==b[z]) mark[i][j]=1;
            }
        }
    }
    //     cout << "Mảng mark sau khi đánh dấu:\n";
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << mark[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    bool flag=false;
    // int q=0;
    // for(int i=0;i<3;i++){
    //     if(a[i][i]==1) q++;
    // }
    // if(q==3){flag=true;} else{q=0;}
    // for(int i=0;i<3;i++){
    //     if(a[i][3-i-1]==1) q++;
    // }
    // if(q==3){flag=true;} else{q=0;}

    if(mark[0][0]==1 and mark[0][1]==1 and mark[0][2]==1)flag=true;
    if(mark[1][0]==1 and mark[1][1]==1 and mark[1][2]==1)flag=true;
    if(mark[2][0]==1 and mark[2][1]==1 and mark[2][2]==1)flag=true;
    if(mark[0][0]==1 and mark[1][0]==1 and mark[2][0]==1)flag=true;
    if(mark[0][1]==1 and mark[1][1]==1 and mark[2][1]==1)flag=true;
    if(mark[0][2]==1 and mark[1][2]==1 and mark[2][2]==1)flag=true;
    if(mark[0][0]==1 and mark[1][1]==1 and mark[2][2]==1)flag=true;
    if(mark[0][2]==1 and mark[1][1]==1 and mark[2][0]==1)flag=true;

    if(flag==true){cout<<"Yes";} else{cout<<"No";}

    return 0;
}