#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    // lặp ví trí hà rồi ý rồi dương
    for(int i=0;i<n-2;i++){

        for(int j=i+1;j<n-1;j++){
            if(a[i]==a[j]) continue;
            for(int z=j+1;z<n;z++){
                if(a[i]!=a[j] and a[i]!=a[z] and a[j]!=a[z]){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
