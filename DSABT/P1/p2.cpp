/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
goto
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -
bool binary_search(int a[], int l, int r, int x){
    // int mid = l + (r-l)/2;
    // bool ans=0;
    // while (a[mid] != x){
    while(l <= r){ // phải có = vì vẫn xét tại vị trí = nhau nhớ về bài quiz
        int mid = l + (r-l)/2;
        if(a[mid] == x){
            // ans=1;
            return 1;
        }
        if( x < a[mid]){
            r= mid - 1;
        }
        else l = mid + 1;

    }

    // return ans;
    return 0;
    
}
int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a=new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);; // boolalpha tra ve ten bool

    return 0;
}


