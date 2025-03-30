#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
const int MOD = int(1e9)+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, k;
    cin>> n>> m>> k;
    ll powerof10 =1;
    for(int i=0;i<k;i++)
        powerof10*=10;
    ll ans=1;
    for(int i=0;i<m;i++){
        // ans*= n  % powerof10;
        ans*=n; // vậy cũng được vì n không vượt quá số power
        ans %= powerof10;
    }
    cout<<ans;
    return 0;
}


// #include <iostream>
// using namespace std;
// using ll = long long;

//đây là cách lũy thừa nhanh độ phức tạp log(n)

// ll powerMod(ll base, ll exp, ll mod) {
//     ll result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }

// int main() {
//     ll N, M, K;
//     cin >> N >> M >> K;

//     ll modVal = 1;
//     for (int i = 0; i < K; i++) modVal *= 10;  // modVal = 10^K

//     cout << powerMod(N, M, modVal) << endl;
//     return 0;
// }
