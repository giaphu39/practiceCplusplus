#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#include<string>
#include<vector>
// #include<pair>
#include<utility> // thư viện chứa pair
#include<iomanip>
int main() {
    https://chatgpt.com/share/679e40c7-9ae0-800d-9f58-bff78b51e460

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    // map: key là tên người, value là vector chứa pair
    //ý tưởng: mỗi key lưu 1 người, value được cộng dồn tổng điểm và số tín chỉ
    //sắp xếp thì bỏ tất cả và vector rồi sort dùng compare

    map<string,pair<int,int>> student;
    string ten;
    int tinchi,diem;
    while(cin>>ten>>tinchi>>diem){ // mỗi lần nhập vào là reset lại biến
        student[ten].first+= tinchi;
        student[ten].second+= diem*tinchi;
    }

    vector<pair<string,double>> ans;
// không thể truy cập map bằng ind mà phải dùng it

    // for(int i=0;i<student.size();i++){
    //     ans[i].fisrt=student[i].first;
    //     ans[i].second=(1.0*student[i].second.second/student[i].second.first);
    // }
    for(const auto& s : student ){
        string name=s.first;
        double gpa=(1.0*s.second.second/s.second.first);
        ans.push_back({name,gpa});
    }
    sort(ans.begin(),ans.end(),[](const pair<string,double>& a, const pair<string,double>& b){
        return a.first>b.first;
    }
    );
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" : "<<fixed<<setprecision(2)<< ans[i].second<<endl;
    }
    return 0;
}
