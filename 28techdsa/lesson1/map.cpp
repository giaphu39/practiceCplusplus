#include<iostream>
#include<map>
//nhớ phải khai báo thư viện map đã
using namespace std;

// map<int,int> dem(int n){
void dem(int n, map<int,int> b){
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        b.insert({a,1});
    }
    cout<<b.size()<<endl;
}

int main(){
    map<int,int> a; // giống pair<int,int>
    a.insert(make_pair(1,9));
    // hoặc cách khác là
    a.insert({1,7}); // độ phức tạp O(logn)
    //do trùng giá trị key nên insert sau sẽ không được update
    a.insert({2,10}); 
    a.insert({8,111});
    cout<<a.size()<<endl;
    //truyền vào key sẽ ra value
    cout<<a[8]<<endl;
    //thay đổi value qua key
    a[2]=1052;
    //key có thể là số âm hoặc chỉ số rất lớn 10^12 hoặc 15,16


    // đếm số phần tử khác nhau qua map thì đưa các phần tử trở thành key, value để bất kì
    int n;cin>>n;
    map<int,int> b;
    dem(n,b);
    cout<<b.size()<<endl; // do hàm void không được truyền địa chỉ( truyền tham chiếu) 
    // nên b không bị tác động khi ra khỏi hàm

    b[7]=134; // nếu map chưa có key nào mà được truyền vào key đó sẽ thêm key và giá trị mới
    cout<<b[7]<<endl<<"mảng a:"<<endl;

    // duyệt map = range for loop
    for(pair<int,int> x: a){
        cout<<x.first<<" "<<x.second<<endl;
    }
    //duyệt bằng iterator
    cout<<endl;
    map<int,int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        //cái it là trỏ tới pair nên muốn truy xuất vào giá trị phải giải tham chiếu
        cout<<(*it).first<<" "<<(*it).second<<endl;
        //hoặc cách khác là
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}