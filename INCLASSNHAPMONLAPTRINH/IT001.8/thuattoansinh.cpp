// #include <iostream>
// using namespace std;
// #include <algorithm>
// int a[100],n, ok;
// // permutation
// // next_permutation
// // prev_permutation

// void cauhinhdau(){
//     for(int i=1;i<=n;i++){
//         a[i]=i;
//     }
// }
// void sinh (){
//     //bắt đầu từ vị trí i= n-1
//     //chừng nào a[i]>a[i+1] thì dịch sang trái
//     int i=n-1;
//     while(i>=1 and a[i]>a[i+1]){
//         i--;
//     }
//     if(i==0){
//         ok=false;
//     }
//     else{//đã tìm được vị trí mà i có giá trị < hơn số bên phải
//     // a[i]<a[i+1]
//     // đi tìm số đứng sau i (bên phải) >a[i] và nhỏ nhất đổi số đó sang vị trí i
//     // các số còn lại xếp theo thứ tự tăng dần
//     int j=n; // bắt đầu từ vị trí cuối bỏ qua các vị trí mà a[j]<a[i]
//     while (a[i]>a[j]){
//         j--;
//     }
//     swap(a[i],a[j]);
//     // sau đó sắp xếp các phần tử từ i+1 đến n;
//     // sort(a+i+1,a+n+1);  // độ phức tạp o(nlogn)
//     // cách 2 dùng reverse thì sẽ có độ phức tạp o(n)
//     reverse(a+i+1,a+n+1);

//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     cin>>n;
//     if(n==0){cout<<0;}
//     else{
//         ok=true;
//         cauhinhdau();
//         while(ok){
//             for(int i=1;i<=n;i++){
//                 cout<<a[i]<<" ";
//             }
//             cout<<endl;
//             sinh();
//         }
//     }
//     // do{
//     //     for(int i=1;i<=n;i++){
//     //         cout<<a[i]<<" ";
//     //     }
//     //     cout<<endl;
//     // } while(next_permutation(a+1,a+n+1));
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[100], n;
bool ok;
void cauhinhdau(){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
void sinh (){
    //bắt đầu từ vị trí i= n-1
    //chừng nào a[i]>a[i+1] thì dịch sang trái
    int i=n-1;
    while(i>=1 and a[i]>a[i+1]){
        i--;
    }
    if(i==0){
        ok=false;
    }
    else{//đã tìm được vị trí mà i có giá trị < hơn số bên phải
    // a[i]<a[i+1]
    // đi tìm số đứng sau i (bên phải) >a[i] và nhỏ nhất đổi số đó sang vị trí i
    // các số còn lại xếp theo thứ tự tăng dần
    int j=n; // bắt đầu từ vị trí cuối bỏ qua các vị trí mà a[j]<a[i]
    while (a[i]>a[j]){
        j--;
    }
    swap(a[i],a[j]);
    // sau đó sắp xếp các phần tử từ i+1 đến n;
    // sort(a+i+1,a+n+1);  // độ phức tạp o(nlogn)
    // cách 2 dùng reverse thì sẽ có độ phức tạp o(n)
    reverse(a+i+1,a+n+1);

    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    if(n==0){cout<<0;}
    else{
        string result;
        ok=true;
        cauhinhdau();
        while(ok){
            for(int i=1;i<=n;i++){
                result += to_string(a[i])+" ";
            }
            result +="\n";
            sinh();
        }
        cout<<result;
    }
}