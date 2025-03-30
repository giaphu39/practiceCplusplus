#include<iostream>
#include <string.h>
using namespace std;

// int f(int n){
//     static int count1=0;
//     if(n==0) return count1;
//     count1++;
//     return f(n-1);
// }
// int x=0;
// void f(int n){
//     if(n==0) return;
//     x++;
//     f(n-1);
//     x++;
// }

void replace(int a[]){
    static int u=23;
    int* b=new int[5]{3,2,4};
    a=b;
    delete[] b;
}
void replace1(int a[]){
    static int u++;
    int* b=new int[5]{3,2,4};
    a=b;
    delete[] b;
    cout<<u;
}
int main(){

    // // // int* a=new int(4);
    // // // cin>>a;
    // // // int* a=new int[7];// in ra giá trị rác
    // // int* a = new int[6]();
    // // for(int i=0;i<6;i++){
    // //     cout<<(a[i])<<" ";
    // // }
    // // cout<<a+1;
    // // delete[]a;
    // // // cout<<*a;
    // int n;
    // // cout<<f(3)<<" ";
    // // cout<<f(2)<<endl;
    // int arr[]={1,2,3};
    // cout<<*(arr+2);
    // int i=0;
    // for(;i<3;i++){
    //     cout<<arr[i];
    // }
    // cout<<endl;
    // f(3);
    // cout<<x;
    string s="Toi ten tuan";
    int cnt[300]={0};
    for(int i=0;i<s.size();i++){
        cnt[s[i]]=1;
    }
    int dem=0;
    for(int i=0;i<256;i++){
        dem+=cnt[i];
    }
    cout<<dem<<endl;

    int i;
    for(i=1;i<5;i++){
        cout<<i;
    }
    cout<<endl<<i<<endl;

    int x = 5; 
    int *a = &x;
    cout<<a<<endl;


    int c[5]={1,2,3,4,5};
    replace(c);
    for(int i=0;i<2;i++){
        cout<<c[i];
    }
    replace1(c);
    // cout<<u;// không được vì static int có vòng đời trong hàm thôi
    return 0;
}