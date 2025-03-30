#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    long long ans = 1;  
    cin >> n;
    // dùng căn vì ở đây ta tách các ước số thành 2 vế 1 vế là số chia hết 1 vế là ước của số chia hết đó
    // ví dụ ước 36 là 1,2,3,4,6,9,12,18,36.
    // 36=1*36=2*18=....
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans *= i; 
            if (i != n / i) {
                ans *= (n / i); // không nhân hai lần mà phải là if lồng vì 6*6=36
            }
        }
    }
    
    cout << ans;
    return 0;
}
