#include <bits/stdc++.h>

using namespace std;
void ssort(int a[], int n){
    int max1=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

//    sort(a,a+n);
    ssort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    delete[] a;
    return 0;
}
