#include<iostream>
using namespace std;
//ý 1: chia ra thành 4 phần, phần 1 lặp n, phần 2 lặp n-1 in ngược, 

// 7 7 7 7 7 7 7 7 7 7 7 7 7 
// 7 6 6 6 6 6 6 6 6 6 6 6 7 
// 7 6 5 5 5 5 5 5 5 5 5 6 7 
// 7 6 5 4 4 4 4 4 4 4 5 6 7 
// 7 6 5 4 3 3 3 3 3 4 5 6 7 
// 7 6 5 4 3 2 2 2 3 4 5 6 7 
// 7 6 5 4 3 2 1 2 3 4 5 6 7 
// 7 6 5 4 3 2 2 2 3 4 5 6 7 
// 7 6 5 4 3 3 3 3 3 4 5 6 7 
// 7 6 5 4 4 4 4 4 4 4 5 6 7 
// 7 6 5 5 5 5 5 5 5 5 5 6 7 
// 7 6 6 6 6 6 6 6 6 6 6 6 7 
// 7 7 7 7 7 7 7 7 7 7 7 7 7 
void mang(int n){
    // int arr[2*n-1][2*n-1];
    // for(int i=1;i<=2*n-1;i++){
    //     for(int j=1;j<=2*n-1;j++){

    //     }
    // }


    int size = 2 * n - 1;  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = n - min(min(i, j), min(size - i - 1, size - j - 1));
            // i là hàng, j là cột, size - i - 1 là khoảng cách từ i đến cạnh dưới ma trận
            //size - j - 1 là khoảng cách từ i đến cạnh phải ma trận
            cout << value << " ";
        }
        cout << endl;
    }
}


//ý tưởng: bỏ vào mảng 2 chiều nếu i=j thì cout<<1, 2n+1, dòng 1, n cột 1,n 
int main(){
    int n;
    cin>>n;
    mang(n);
    return 0;
}