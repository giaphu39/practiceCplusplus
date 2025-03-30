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
int binary_search_first_occurrence(int a[], int n, int x){
    int l=0;
    int r=n-1;
    //dùng index =-1 để đánh dấu luôn không gặp
    // bool flag=0; //đánh dấu đã gặp x chưa
    int index = -1; // lưu index cần tìm
    while(l <= r){ 
        int mid = l + (r-l)/2;
        if(a[mid] == x){
            // // flag=1;
            // index = mid--;
            // // r= mid -1; // tìm tiếp bên phải
            // // không nên và sai vì các phần tử được sắp xếp rồi chỉ cần giảm
            // // while(a[--mid] == x && mid>0){ // vậy vẫn sai vì truy cập ngoài mảng rồi mới xét
            // while(mid>0 && a[mid] == x){
            //     index= mid--;
            // }

            // // nhớ quan trọng nhất là phải dừng 
            // break;
            index=mid;
            r = mid -1;
            //sau đó nó chạy tiếp if dưới nên sẽ sai
            continue; // hoặc if dưới dùng else if
        }
        if( x < a[mid]){ // do điều kiện này mà không có contine sẽ sai vì sẽ chạy dòng else
            r= mid - 1;
        }
        else l = mid + 1;

    }

    return index;
    
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_first_occurrence(a, n, x);

    return 0;
}


