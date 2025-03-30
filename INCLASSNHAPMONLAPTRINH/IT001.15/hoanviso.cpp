#include <iostream>
#include<string>
#include <algorithm>
#include<cmath> // để khai báo đc pow
using namespace std;
#define MAX 500
//ý tưởng nhớ các con số đó vào mảng đánh dấu, đếm số lượng số
//lưu số này vào 1 mảng sau đó in mảng này vào str rồi hoán vị

//phải làm bằng tay trước khi nghĩ thuật toán
//cách 2 lấy tất cả chữ số bằng cách đưa về chuỗi, 
// khi đã lấy ra phần tử thì sort lớn đến bé
// nếu làm nhiều vòng for mà không biết trước số lượng thì dùng đệ quy

int *a=new int[MAX];
int num[300]; // lưu các só
int coun=0;
bool ok;
int demsochu(int n){
    int c=0;
    while(n!=0){
       c++;
       n/=10; 
    }
    return c;
}
// void khoitao(int n){
//     int c=demsochu(n);
//     int u=pow(10,(c-1));
//     for(int i=0;i<c;i++){
//         int b=n/u;
//         n-=u*b;
//         a[i]=b;
//         u/=10;
//     }
// }
void khoitao(int n){
    // ok=true;
    int c=demsochu(n);
    int i=0;
    while(n!=0){
        
        a[i++]=(n%10);
        n/=10;
    }
}
// void sinh(int n){
//     // int i=n-1;
//     // while(i>=1 and a[i]<a[i+1]){ // a[i]<a[i+1] thì dịch trái
//     //     i--;
//     // }
//     // if(i==0){
//     //     ok=false;
//     // }
//     // else{//đã tìm được vị trí mà i có giá trị > hơn số bên phải
//     // // a[i]<a[i+1]
//     // // đi tìm số đứng sau i (bên phải) >a[i] và nhỏ nhất đổi số đó sang vị trí i
//     // // các số còn lại xếp theo thứ tự tăng dần
//     // int j=n; // bắt đầu từ vị trí cuối bỏ qua các vị trí mà a[j]>a[i]
//     // while (a[i]<a[j]){
//     //     j--;
//     // }
//     // swap(a[i],a[j]);
//     // // sau đó sắp xếp các phần tử từ i+1 đến n;
//     // // sort(a+i+1,a+n+1);  // độ phức tạp o(nlogn)
//     // // cách 2 dùng reverse thì sẽ có độ phức tạp o(n)
//     // reverse(a+i+1,a+n+1);

//     // }
//     ok=true;
// }
void sinh(int n){
    ok=true;
}
void in(int n){
    int c=demsochu(n);
    for(int i=0;i<c;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    unsigned long long n;
    cin>>n;
    if(n==0){
        cout<<0;
    }
    else{
        // cout<<demsochu(n);
        // string ans;
        khoitao(n);
        // sinh(n);
        while(!ok){
            sinh(n);
            // ok=false;
            in(n);
        }
        // in(n);

    }
    return 0;
}