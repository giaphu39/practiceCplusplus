#include <iostream>

using namespace std;

int main()
{
    int L;// số lít đang có
    int t; // thời gian cả 2 đổ
    // đổ sang 1 lít/s

    //Số lít đã
    // giả sử thời gian 2 người cùng đổ là a
    // (42 - 2*a) = số t-a = output
    // L -t=a

    //t-a*2 = output = L - a*2

    //giả sử output là a
    // (L-a)/2


    // Hướng 3: giải hệ phương trình
    // t1+ t2=L
    // (t1-t2)+t2 = t =t1 ( nếu t1>t2)
    //=> t1=t, L-L1 = L2 ; dư = L1-L2
    cin>>L;
    cin>>t;
    int L1=t;
    int L2=L-L1;
    int ans=L1-L2;
    cout<<ans;


    return 0;
}
