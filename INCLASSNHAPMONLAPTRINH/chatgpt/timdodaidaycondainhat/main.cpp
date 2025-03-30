#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
//    vector<int>max1;
    int max1=0;
    for(int i=0;i<n;i++){
        int cnt=1;
        while(i<n && a[i]<a[i+1]){
            cnt++;
            i++;
        }
        max1=max(max1,cnt);
    }
    cout<<max1;
    return 0;
}
