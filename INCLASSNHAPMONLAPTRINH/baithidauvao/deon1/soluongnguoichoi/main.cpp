//#include <bits/stdc++.h>
//
//using namespace std;
////ý tưởng: sô đầu là ngày bát đầu, số sau là ngày tăng 1 trong for
////tạo một mảng lưu số ngày trùng +1 lên mỗi tại ngày đó
//#define ull unsigned long long
//int main()
//{
//    int n;cin>>n;
//    vector<vector<int>> a(n,vector<int>(2));
//    int max1=INT_MIN;
//    int min1=INT_MAX;
//    for(int i=0;i<n;i++){
//        cin>>a[i][0];
//        cin>>a[i][1];
//        max1=max(max1,a[i][0]+a[i][1]);
//        min1=min(min1,a[i][0]);
//    }
//    vector<int> b(max1+1,0); // mảng lưu số ngày, +1 cho chắc
//    for(int i=0;i<n;i++){
//        for(int j=a[i][0];j<a[i][0]+a[i][1];j++){
//            b[j-min1]++; // đây sẽ cho biết ngày nào có bao nhiêu người
//        }
//    }
//    //đếm số người mỗi ngày
//    for(int i=1;i<=n;i++){
//        int count1=0;
//        for(int j=min1;j<max1;j++){
//            if(b[j-min1]==i)count1++;
//        }
//        cout<<count1<<" ";
//    }
//    return 0;
//}
#include <iostream>
#include <algorithm>
#include<vector>
struct sukien{
    int time;
    int login;
};
using namespace std;

bool cmp(sukien A,sukien B)
{
    if(A.time==B.time)
    {
        return A.login>B.login;
    }
    return A.time<B.time;
}
int main(){
    int n;
    cin>>n;
    vector<sukien> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,1}); // 1 là login bắt đầu
        v.push_back({x+y,-1}); // -1 là login kết thúc
    }
    sort(v.begin(),v.end(),cmp);
    int truocdo=-1;
    int online=0;
    int a[n+1]={0};
    for(int i=0;i<v.size();i++)
    {
        if(truocdo !=-1 and v[i].time != truocdo)
        {
            a[online]+=v[i].time-truocdo;
        }
        truocdo=v[i].time;
        online+=v[i].login;
    }
    // for(int i=1;i<n+1;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<v.size();i++){
    //         cout<<v[i].login<<" "<< v[i].time<<endl;

    // }


}
