#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v={4,6,3,7,2};
    vector<int>::iterator contro =v.begin();
    cout<<*contro<<endl;
    // iterator giống con trỏ có thể dịch trái dịch phải +2 hoặc +3, trỏ đến có giá trị bao nhiêu thì phải giải tham chiếu
    ++contro;
    cout<<*contro<<endl; // giải tham chiếu
    contro+=2;
    cout<<*contro<<endl;
    //không được viết
    contro=contro+5; // lỗi cú pháp ra giá trị rác  
    cout<<*contro<<endl; 
 
    //duyệt qua từng phần tử bằng iterator
    for(vector<int>::iterator it1 =v.begin(); it1 !=v.end();it1++){
        cout<<*it1<<" ";
    }  
    cout<<endl;

    //tự động giá trị gán cho biến để gán dữ liệu cho biến ví dụ cho = 10.0 thì là kiểu double
    auto x=10;

    //duyệt nhanh bằng auto
    for(auto it1=v.begin();it1!=v.end();it1++){
        cout<<*it1<<" ";
    }
    cout<<endl;
    // khi dùng iterator nên dùng auto cho ngắn 
    auto a=v.begin();// cũng là 1 iterator

    //in lật ngược
    for(auto it=v.rbegin();it!=v.rend();it++){
       cout<<*it<<" ";
    } cout<<endl;
    //chèn 100 vào vị trí 3 (tính từ 0 1 2 3)

    // vector<int> v={4,6,3,7,2};
    v.insert(v.begin()+3,100);
    //xoá phần tử cuối
    v.pop_back();
    for(int x:v){
        cout<<x<<" ";
    }

    cout<<endl;
    v.clear(); // xóa các phần tử
    cout<<v.empty()<<endl; // kiểm tra phần tử có rỗng nếu đúng trả về true(=1)
    vector<float> u(10,100);
    // hàm erase(vị trí) xóa phần tử theo vị trí
    u.erase(u.begin()+1);
    

    return 0;
}