#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<i;j++){
            cout<<"  ";
        }
        for(int j=i;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for (int i =1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
