#include<iostream>
#include<climits>
using namespace std;
#define MAX 1000000000
int max1=INT_MIN;
int min1=INT_MAX;

void input(int& n, int a[], int b[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        // if(a[i]>max1) max1=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]<min1) min1=b[i];
    }

    for(int i=0;i<n;i++){
        if(a[i]>max1) max1=a[i];
    }
    for(int i=0;i<n;i++){
        if(b[i]<min1) min1=b[i];
    }
}
void output(int a1[], int a2[]){
    int u=min1-max1;
    if(u>=0) cout<<u+1;
    else cout<<0;
    delete[] a1;
    delete[] a2;
}
int main(){
    int n;
    int* a1=new int[MAX];
    int* a2=new int[MAX];
    input(n,a1,a2);
    output(a1,a2);
    return 0;
}