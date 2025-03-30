#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int*a=new int[MAX];
    int*b=new int[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    //X la so can tim
    sort(a,a+n);
    sort(b,b+m);
    int i; int flag=1;
    int cnt;
    for(i=0;i<n;i++){
        cnt=0;
        int it= lower_bound(b,b+m,a[i])-b;//lower_bound trả về con trỏ đang cần vị trí
        if(a[i]==b[it]) flag++;
        cnt=m-it;
//        for(int j=0;j<m;j++){
//            if(a[i]<=b[j]) cnt++; // dem so sau X cua mang b
//            if(a[i]==b[j]) flag++; // dong nay de chac do la cho trung cho trung thi moi xet dap an+1
//        }
        if((i+1) >= cnt){
            cout<<a[i];
            flag=0;
            break;
        }

    }
    //thieu truong hop sau mang a
//    if(flag) cout<<a[i-1]+1; // van sai vi co truong hop ben phai X nhieu hon
    if(flag){
        if(flag==2 && i>=cnt-1){
            cout<<a[i-1]+1;
        }
        else{
            for(int j=0;j<m;j++){
                if(m-j == i+1){

                 cout<<b[j]+1;
                 break;
                }

                else if(m-j<=i){
                    cout<<b[j];
                    break;
                }
            }
        }
    }
    delete[]a;
    delete[]b;
    return 0;
}
