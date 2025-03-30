#include <bits/stdc++.h>

using namespace std;
// các thành phần quan trọng của bit mask
// bitset<32> b;
//duyệt qua từng tổ hợp bằng số nhưng chuyển sang hệ nhị phân
// cho b=mask ( mask là số đại diện tổ hợp) để đưa về nhị phân
// lặp cho từng vị trí của mask 1 thì tính là có tổ hợp vị trí này sẽ tương đương vị trí của mảng xét

// xét điều kiện sau khi đã trích ra từng tổ hợp nên nhét nó vào 1 mảng khác để dễ thao tác

int main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int k;cin>>k;
    int p;cin>>p;
    bitset<32> b;
    int total=1<<a.size();
    for(int mask=0;mask<total;mask++){
        b=mask;
        int sum=0;
        int count1=0;
        vector<int>tohop;
        int max1=INT_MIN;
        for(int i=0;i<n;i++){// đây là vị trí các bit
            if(b[i]){ // nghĩa là có giá trị ở vị trí i
                tohop.push_back(a[i]); // bỏ vào tohop để có thể lấy ra hoặc check rỗng
                sum+=a[i];
                count1++;
                max1=max(max1,a[i]);
            }
        }
        // đã xử lí xong tổ hợp lần mask
        //xử lí tiếp điều kiện
//        Tổng các phần tử của tổ hợp chia hết cho k
//
//tổng số phần tử là số phần tử
        //Tổng số phần tử trong tổ hợp là một số lẻ.
        //Giá trị lớn nhất trong tổ hợp chia hết cho
        //𝑝
        //p.
        if(sum%k==0 && count1%2!=0 && max1%p==0 && !tohop.empty()){ // nên check tổ hợp rỗng
            cout<<" to hop thoa:";
            for(int x : tohop)cout<<x<<" ";
            cout<<endl;
        }

    }

    return 0;
}
