/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
bool binary_search(int a[], int l, int r, int x){
    if(l > r) return 0;
    int mid = l + (r-l)/2;
    if(a[mid] == x){
        return 1;
    }
    if( x < a[mid]){
        return binary_search(a,l,mid-1,x); // nhớ kiểu khác void thì phải return trước khi gọi đệ quy
    }
    else return binary_search(a,mid+1,r,x);
    
    //tại sao không đặt gán l hoặc r rồi mới chạy đệ quy
    // tại sao không để cuối cùng return 0
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}
