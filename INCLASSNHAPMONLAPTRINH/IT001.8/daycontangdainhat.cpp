// //dãy tăng dần không chứa giá trị trùng
// //bỏ vào mảng cho vào vòng lặp, bỏ vào set nếu đặt một biến là max nếu lớn hơn thì dừng
// // bỏ các giá trị size vào set rồi in ra cái cuối
// //ý tưởng bỏ tất cả vào set rồi đếm số phần tử của set
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     set<int> a;
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }    
//     // for(int i=0;i<n;i++){
//     //     a.insert(arr[i]);
//     // }

//     // cout<<a.size();

//     // chạy tất cả trường hợp 

//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;
#include<iostream>
#include <algorithm> 
using namespace std;
int longestIncreasingSubsequence(int a[], int n) {
    int dp[1000]; // Mảng tĩnh dp để lưu LIS tại mỗi vị trí
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Ban đầu LIS tại mỗi vị trí là 1
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}
int l[1000000];
void khoitaodau(int arr[], int n){
    for(int i=0;i<=n;i++){
        arr[i]=1;
    }
}
void daycontangdainhat(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                l[i]=max(l[i],l[j]+1);
            }
        }
    }
}
int demmax(int l[], int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(l[i]>max) max=l[i];
    }
    return max;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    khoitaodau(l,n);
    daycontangdainhat(arr,n);
    cout<<demmax(l,n);
    return 0;
}



// độ phức tạp o(n^2)

// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     vector<int> L(n,1);
//     // L[i] độ dài dãy con tăng dài nhất kết thúc tại vị trí i
//     // L[i]=max(L[i],L[j+1]) nếu a[i]>a[j];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(a[i]>a[j]){
//                 L[i]=max(L[i],L[j]+1); // để max vì nếu để L[i]=L[j]+1 thì nó chỉ xét cái cuối
//                 // còn ghi theo kiểu này thì L[i]đc gán liên tục và xét với các L[j] tiếp theo

//             }
//         }
//     }
//     cout<<*max_element(L.begin(),L.end());
//     return 0;
// }