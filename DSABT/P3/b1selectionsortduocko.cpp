/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100000

void NhapMang(int *a,const int& n){
    // cin >> n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
}
void output(int* a, int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selection_sort_ascending(int* a, int n){
    // for(int i = 0; i < n-1; i++){
    //     int iMin = i;
    //     for(int j = i + 1; j < n; j++){ // sai chỗ i++ 
    //         if(a[j] < a[iMin]){
    //             iMin = j;
    //         }
    //     }
    //     swap(a[i] , a[iMin]);
    // }
    sort(a,a+n);
}

bool is_ascending(int *a, int n){
    // có thể xét n
    for(int i=1 ; i < n; i++){
        if( a[i] < a[i-1]) return false;
    }
    return true;
}

int main() {
    int a[MAXN], n;

    std::cin >> n; // nhớ đọc kĩ template

    NhapMang(a, n);

    selection_sort_ascending(a, n);
    output(a,n);
    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
