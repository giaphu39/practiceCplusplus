//#include <bits/stdc++.h>
//
//using namespace std;
//// không vượt quá X và chứa ít nhất M cửa hàng.
////
////Đề bài:
////An là người quản lý kho hàng và cần lập kế hoạch vận chuyển hàng hóa từ một kho lớn (mảng weights[]) đến các cửa hàng (có số lượng cửa hàng M) bằng xe tải. Mỗi xe tải có thể chở được tối đa X kg hàng hóa, và mỗi cửa hàng có một yêu cầu số lượng hàng hóa nhất định. An muốn biết có thể vận chuyển tất cả hàng hóa một cách hợp lý và tối ưu không, tức là có thể chọn dãy con của mảng weights[] sao cho tổng trọng lượng của nó không vượt quá X kg và dãy con này phải chứa ít nhất M cửa hàng.
////
////Input:
////
////Dòng đầu tiên chứa hai số nguyên N và M (1 ≤ N ≤ 10^5, 1 ≤ M ≤ N), là số lượng cửa hàng và số lượng hàng hóa.
////Dòng tiếp theo chứa N số nguyên weights[], trong đó weights[i] là trọng lượng hàng hóa tại cửa hàng i (1 ≤ weights[i] ≤ 10^9).
////Dòng cuối cùng chứa số nguyên X, là trọng tải tối đa mà xe tải có thể chở.
////Output:
////
////Nếu có thể vận chuyển tất cả hàng hóa một cách hợp lý với điều kiện nêu trên, in ra số lượng dãy con của weights[] mà có tổng trọng lượng không vượt quá X và chứa ít nhất M cửa hàng.
////Nếu không thể, in ra "Không thể vận chuyển".
////Ví dụ:
////Input:
////
////Copy code
////6 3
////5 3 2 8 1 4
////10
////Output:
////
////Copy code
////4
//
//
//// nhớ chú ý các kĩ thuật hai con trỏ có thể chỉ áp dụng sau khi đã sort
//int main()
//{
//    int n,m;cin>>n>>m;
//    vector<int> w(n);
//    for(int i=0;i<n;i++){
//        cin>>w[i];
//    }
//    int x;cin>>x;
//    sort(w.begin(),w.end))
//    int ans=0; // đây phải là số lượng dãy con chứ không phải độ dài dãy max
//    for(int i=0;i<=n-m;i++){
//        int tong=w[i];
//        int j=i+1;int u=j;
//        while(j<=n){
//
//
//            if(tong==x){
////                if(j-i+1>=m) ans=max(ans,j-i+1);
//                if(j-i+1>=m){
//                    ans++;
//                    tong+=w[j++];
//                }
//                else tong-=w[u++];
//            }
//            if(tong<x) tong+=w[j++];
//            else if( tong>x){
//                tong-=w[u++];
//            }
//        }
//    }
//    if(ans!=0) cout<<ans;
//    else cout<<"khong the van chuyen";
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;

int countValidSubsequences(vector<int>& w, int n, int m, int x) {
    sort(w.begin(), w.end());
    int count = 0;

    // Duyệt qua tất cả các dãy con có thể
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int len = 0;
        for(int j = i; j < n; j++) {
            if(sum + w[j] <= x) {
                sum += w[j];
                len++;
                if(len >= m) {
                    count++;
                }
            } else {
                break;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int x;
    cin >> x;

    int result = countValidSubsequences(weights, n, m, x);

    if(result > 0) {
        cout << result << "\n";
    } else {
        cout << "Khong the van chuyen\n";
    }

    return 0;
}
