#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int n;cin>>n;
//    int a[100][100];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++) cin>>a[i][j];
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<a[i][j];
//    }
//    int** a=new int*[100];
//    for(int i=0;i<n;i++){
//        a[i]=new int[100];
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++) cin>>a[i][j];
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<a[i][j];
//    }
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j];
    }
    return 0;
}
