/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -
bool binary_search(int a[], int l, int r, int x){
    if(l > r) return 0;
    int mid = l + (r-l)/2;
    if(a[mid] == x){
        return 1;
    }
    if( x < a[mid]){
        return binary_search(a,mid+1,r,x); 
    }
    else return binary_search(a,l,mid-1,x);

}
int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}

