/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -
bool binary_search(int a[], int n, int x){
    int l=0;
    int r = n - 1;
    while(l <= r){ // phải có = vì vẫn xét tại vị trí = nhau nhớ về bài quiz
        int mid = l + (r-l)/2;
        if(a[mid] == x){
            return 1;
        }
        if( x < a[mid]){
            l= mid + 1;
        }
        else r = mid - 1;

    }
    return 0;
    
}
int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, n, x);;

    return 0;
}

