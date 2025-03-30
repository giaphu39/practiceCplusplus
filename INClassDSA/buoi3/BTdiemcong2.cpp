#include<iostream>
#include <cstdlib>
#include<ctime>
// using namespace std;
#define MAX 200


void input(int* a, int& n){ // nho chu y &n
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }

}

void InsertionSort(int* a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] < temp ) break;
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
        if(k == -1 ) std::cout<< temp<<" ";
    }
    std::cout<<std::endl;
}

void ReverseInsertionSort(int* a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] > temp ) break; // đổi chỗ này là được
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
        if(k + 1 == 0 ) std::cout<< temp<<" ";
    }
    std::cout<<std::endl;
}

void output(int* a, int n){
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
int main(){
    int n;
    // int* a=new int[MAX];
    int a[MAX];
    input(a,n);
    // output(a,n);

    // InsertionSort(a,n);
    // output(a,n);

    ReverseInsertionSort(a,n);
    output(a,n);
    // delete[] a;
    return 0;
}