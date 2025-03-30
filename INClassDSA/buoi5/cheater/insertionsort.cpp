#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 200

int donSwap=0;
void input(int* a, int& n){ // nho chu y &n
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }

}

void output(int* a, int n,int i){
    cout<<"i="<<i<<": ";
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}

void InsertionSort(int* a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] < temp ){ // có thể thêm dấu bằng nếu tính số lần swap không đổi vị trí
                if(k == i-1){
                    donSwap++;
                }
                break;
            }
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
        output(a,n,i);
    }
}

void ReverseInsertionSort(int* a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] > temp ){
                if(k == i-1){
                    donSwap++;
                }
                break;
            } // đổi chỗ này là được
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
        output(a,n,i);
    }
}


int main(){
    int n; cin>>n;
    int a[]={2, 2, 5, 3, 0, 6, 8, 5, 1};

    // InsertionSort(a,n);
    ReverseInsertionSort(a,n);
    // output(a,n);
    // delete[] a;

    cout<<donSwap;
    return 0;
}