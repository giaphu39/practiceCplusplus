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
//vị trí đầu tiên lớn hơn x
// nếu lớn hơn x -> sau đó tìm trái
// nếu bé hơn x -> tìm bên phải
int binary_search_leastGreater_firstOccurrence(int a[],int n,int x){
    int l=0;
    int r=n-1;
    int index=-1;
    
    while(l <= r){

        int mid= l + (r-l)/2; // nhớ để trong while
        if(a[mid] > x){ // mẹo suy nghĩ: dòng if đầu là yêu cầu bài toán, các dòng if sau là để tìm kiếm dựa trên yêu cầu 
            index=mid;
            r= mid -1;
            // continue;
        }
        // dùng else if thay continue
        // else if(x > a[mid]){
        //     l= mid +1;
        // }
        else{
            l= mid + 1; // giá trị lớn hơn thì cũng tìm cái bé hơn
        }
    }
    return index;
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_leastGreater_firstOccurrence(a, n, x);

    return 0;
}


