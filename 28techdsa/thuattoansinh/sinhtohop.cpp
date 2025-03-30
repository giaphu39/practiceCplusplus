#include <iostream>
using namespace std;
// sinh tổ hợp, tập con C k n 
int n, x[100],k;
bool ok;
void cauhinhdau(){
    for(int i=1;i<=k;i++){
        x[i]=i; // tạo cấu hình đầu trong tổ hợp vd 1234...k
    }
}
void sinh(){
    //bắt đầu từ bit thứ k, kiểm tra xem phần tử x[i] đạt giá trị max chưa (n-k+i)
    //x[i]=n-k+i thì dịch sang trái
    // x[i]!= n-k+i thì x[i]++; tất cả phần tử từ i+1 đến k sẽ tăng dần từ x[i] một đơn vị (thằng sau lớn hơn thằng trươc 1 đơn vị)

    // mục đích thuật toán là tìm vị trí i mà chưa tăng tới max để tăng thêm giá trị
    int i=k;
    while(i>=1 and x[i]==n-k+i){
        i--; // khi mà vị trí đó đạt giá trị max thì dịch sang trái
    }
    //TH1: i vẫn nằm trong đoạn 1 đến k

    //TH2: i=0
    if(i==0){
        ok=false; // dãy là cấu hình cuối cùng thì i==0
    }
    else{
        x[i]++;
        for(int j=i+1;j<=k;j++){
            x[j]=x[j-1]+1; // cho các số sau khi +1 tại vị trí cần đổi tăng dần 1 đơn vị
        }
    }
}
int main() {
    cin>>n>>k;
    cauhinhdau();
    ok=true;
    while(ok){
        for(int i=1;i<=k;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
        sinh();
    }

    return 0;
}
