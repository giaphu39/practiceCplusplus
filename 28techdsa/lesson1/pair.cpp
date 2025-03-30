#include<iostream>
using namespace std;

int main(){
    //kiểu auto chỉ nên thay cho pair hoặc iterator
    
    //kiểu pair cho 2 kiểu dữ liệu giống hoặc khác nhau
    pair<int,double> a;
    a.first=5;
    a.second=7.9;
    cout<<a.first<<" "<<a.second<<endl;

    pair<bool, int> b =make_pair(true,7);
    cout<<b.first<<" "<<b.second<<endl;

    // tạo giống x,y
    int n;
    cin>>n;
    pair<int , int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }

    //pair lồng nhau
    pair<char, pair<bool, double>> u;
    u.first='@';
    u.second.first=false;
    u.second.second=9.3;

    // khi so sánh pair thì sẽ so sánh first trước nếu bằng thì mới so sánh second
    return 0;
}