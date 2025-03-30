#include <bits/stdc++.h>
using namespace std;
int main(){
    //set tự động loại bỏ trùng và sắp xếp từ bé đến lớn
    set<int> se;
    se.insert(5);
    se.insert(8);
    se.insert(2);
    se.insert(2);
    se.insert(9);
    se.insert('B');

    // 2 5 8 9
    cout<<se.size()<<endl;
    for(int x:se){
        cout<<x<<" ";
    }cout<<endl;

    set<char> se1;
    se1.insert('J');
    se1.insert('Y');
    se1.insert('A');
    for(char x:se1){
        cout<<x<<" ";
    }
    
    set<string> se2;
    se2.insert("c++");
    se2.insert("java");
    for(string x:se2){
        cout<<x<<" ";
    }
    cout<<endl;
    
    set<int> se3={4,6,2,6,1};
    for( auto i=se3.begin(); i!=se3.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // cách nhập vào set nhiều (BT21)
    int n;cin>>n;
    set<char> se4;
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        se4.insert(a);
    }
    // do set ko giống vector in theo index đc nên ta làm vậy
    // điều này do set có cấu trúc dữ liệu kiểu cây, còn arr hay vector có các ô nhớ kề nhau mới truy theo index đc
    vector<char> v;
    for (char x:se4){
        cout<<x<<" ";
        v.push_back(x);
    }
    cout<<endl;
    // in ngược
    for(int i=se4.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // cách 2 ko cần khai báo thêm vector
    for(auto i=se4.rbegin();i!=se4.rend();i++){
        cout<<*i<<" ";
    }
    // tìm kiếm trong set độ phức tạp o(log(n))
    if(se3.find(1)==se3.end()){
        cout<<"notfound \n";
    }
    else{
        cout<<"found"<<endl;
    }

// chỉ có thể ++ hoặc -- ko thể +=1 vì set ko phải container giống arr và vector
// find ko thấy sẽ trỏ tới end()
    auto ao=se3.find(13);
    if(ao==se3.end()){
        ao--;
        cout<<*ao;
        cout<<"f"<<endl;
    }
    else{
        cout<<*ao;
        cout<<"Found";
    }
    cout<<endl;
    // hàm count dùng để kiểm tra có xuất hiện lun ko ( thay thế hàm find)
    //count của set chỉ có 2 giá trị 1 hoặc 0
    if(se3.count(3)==0){
        cout<<"notfoundbycount";
    }
    else{
        cout<<"found";
    }cout<<endl;
    set<int> se5={1,5,7,3};
    //xoá bằng erase
    se5.erase(7);
    //xoá thông qua iterator
    auto it5=se5.begin();
    se5.erase(it5);
    for(int x:se5){
        cout<<x<<" ";
    }




    return 0;
}