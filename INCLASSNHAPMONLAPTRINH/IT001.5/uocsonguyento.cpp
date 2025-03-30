
#include <iostream>
#include <cmath>
using namespace std;


bool sol(int n){
    if(n<2){
        return 0;
    }
    int u=sqrt(n);
    for(int i=2;i<=u;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

// // vì không tôi ưu nên dùng sàng nguyên tố thay thế
// bool mark[1000];
// bool sol(int n){
//     if(n<=1){
//         return false;
//     }
//     else{
//         int a=2;
//         while(true){
//             if (a*a>=n) break;
//             unsigned int p=a*a;
//             while(p<=n) {
//                 mark[p]=true;
//                 p+=a;
//         }
//         a++; // thêm bước cho vòng lặp nếu đã đánh dấu thì bỏ qua còn chưa được đánh dấu thì kt tiếp
//         while(a<=n and mark[a]==true) a++;
//         if(a>n) break;
//     }}
//     return (mark[n]) ?false : true; 
// }
int sum_common_prime(int a, int b){
    if(sol(a)==true and sol(b)==true){
        return -1;
    }
    int min= std::min(a,b);
    int ans=0;
    for(int i=2;i<=min;i++){
        if(a%i==0 and b%i==0 and sol(i)==true){
            ans+=i;
        }
    }
    if(ans==0) return -1;
    else return ans;
}



int main() {
	int m, n;
	cin >> m >> n;
	cout << sum_common_prime(m, n);
}