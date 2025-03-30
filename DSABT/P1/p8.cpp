/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -

int binary_search_last_occurrence(int a[],int n,int x){
    int l=0;
    int r=n-1;
    int index=-1;
    
    while(l <= r){

        int mid= l + (r-l)/2; // nhớ để trong while
        if(x == a[mid]){
            index=mid;
            l= mid +1;
            continue;
        }
        // if(x < a[mid]){
        //     r = mid + 1;
        // }
        if(x > a[mid]){
            l= mid +1; // lỗi time limit thường do chạy vô hạn
        }
        else{
            r= mid -1;
        }
    }
    return index;
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


