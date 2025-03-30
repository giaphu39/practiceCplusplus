#include <bits/stdc++.h>
// đây là khai báo thư viện tổng hợp không dùng cho các cuộc thi
#include <vector>
using namespace std;

// thư viện STL có compiler chứa vector, search,... nên c++ dùng cho lập trình thi đấu
int main(){
    vector<int> a;
    // khai báo kiểu dữ liêu vector, với là vector rỗng 
    a.push_back(7);
    a.push_back(10);
    a.push_back(3);
    // hàm để cho thêm phần tử trong ngoặc vào vetor
    cout<<a.size()<<endl;
    // vector này đc xem là mảng động nên có thể truy xuất bằng index
    cout<<a[0];
    //range base for loop - foreach với các ngôn ngữ khác
    for(int x:a){
        cout<<x<<endl;
        // đặt biến x trong vòng a 
    }
    vector<int> v={3,6,7,8,2,8};
    for(int x:v){
        x=100;
        // không đổi các phần tử vector v;
    }
    cout<<v[0]<<endl;
    for(int &x:v){
        x=100;
        // thay đổi các phần từ trong vector v
    }
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<"đổi phần tử vector "<<endl;
    

    // vector có 5 phần tử
    vector<int> k(5);
    // vector có `10 phần tử, mỗi phần tử giá trị là 100
    vector <int> j(10,100);

    int b[5]={1,5,3,2,6};
    vector<int> q(b,b+5);
    //5 là số phần tử của b, thực hiện toán từ náy thì sẽ gán b cho q
    cout<<"in q ra:"<<endl;
    for(int x:q){
        cout<<x<<" ";
    }
    // tạo vector có n phần tử 
    vector<int> s;
    int n;
    cin>>n;
    for( int i=0; i<n;i++){
        int x;
        cin>>x;
        s.push_back(x);
        // hoặc cin>>s[i]; // nhưng phải khai báo vector<int> s[n]; //giống mảng
        
    }







    return 0;
}