#include <iostream>
using namespace std;
#define Max 100
void nhap(int n, int a[]){
    for(int i=0;i<n;i++){
        cin>>a[i]; //scanf("%d",&a[i])
    }

}
void doinguoc(int n, int a[] ){
    int j=0;
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[j]=a[i];
        j++;
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
void xoa(int n, int a[]){
    int j;
    cin>>j;
    for(int i=j;i<n-1;i++){
        a[i]=a[i+1];
    }
}
void xuat(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    nhap(n,a);
    doinguoc(n,a);
    xuat(n,a);
    xoa(n,a);
    xuat(n,a);
    return 0;
}

