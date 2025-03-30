#include <iostream>

using namespace std;


// độ cao trạm phát >= bi thì khách hàng có sóng
// số khách có sóng >= số tòa nhà đặt trạm
// độ cao trạm phải <= độ cao tòa nhà

// tương tự giao dịch
int MAX=int(1e9);

int Search(int l, int r, int* a, int* b, int n, int m){
    while(l <= r){

    }
}


int main() {
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // Viết code xử lý tại đây
    cout<<Search(0,MAX,a,b,n,m);


    return 0;
}
