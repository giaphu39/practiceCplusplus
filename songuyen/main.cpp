#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    freopen("songuyen.inp","r",stdin);
    freopen("songuyen.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for( int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int g=a[i]/2;
        if(a[i]<2){
            cout<<-1<<endl;
        }
        else if(a[i]==2){
            cout<<2<<endl;
        }
        else if(a[i]%2==0){
            for(int j=0;j<g;j++){
                cout<<2<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j=0;j<g-1;j++){
                cout<<2<<" ";
            }
            cout<<3<<endl;

        }
    }
    return 0;
}
