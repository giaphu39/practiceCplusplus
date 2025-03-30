#include <iostream>
#include<vector>
using namespace std;
// in ra số lượng dãy con tăng dài nhất
int main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt++;
        while(i<n && a[i]<a[i+1]){
            i++;
        }
    }
    cout<<cnt;
    return 0;
}
