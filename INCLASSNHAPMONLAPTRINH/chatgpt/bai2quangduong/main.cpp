#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int* c= new int[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }


    int a,b,ans=0;cin>>a>>b;
    for(int i=a;i<b;i++){
        ans+= (c[i]-c[i-1]);
    }

    cout<<ans;

    delete[] c;
    return 0;
}
