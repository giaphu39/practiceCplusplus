#include<bits/stdc++.h>


using namespace std;

bool check (vector<int> a, vector<int> b, int c){
    int cung=0;
    int cau=0;
    for(int i=0;i<a.size();i++){
        if(a[i]<=c) cung++;
    }
    for(int j=0;j<b.size();j++){
        if(b[j]>=c) cau++;
    }
    return cung>=cau;

}

int main()
{
    int n,m;cin>>n>>m;
    vector<int> a(n);
    vector <int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }

    int l=1;
    int ans=-1; // nếu ko tìm được thì trả về -1 ( đề không cho)
    int r=INT_MAX;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(a,b,mid)){
            ans=mid;
            // đã tìm được nhưng chưa phải nhỏ nhất
            // dịch sang bên trái để tìm kiếm
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
