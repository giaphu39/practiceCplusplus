#include <iostream>
#include <cmath>
using namespace std;
// Tổng các ước với độ phức tạp O(logn)
// ta thấy một số chia hết một số ra thương thì số đó cũng chia hết cho thương nên 
//giảm thiểu vòng lặp cho mỗi lần +
int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            ans += i; 
            // nếu như i khác thương mà i chia hết thì thương cũng chia hết 
            if (i != n / i) { 
                ans += n / i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
