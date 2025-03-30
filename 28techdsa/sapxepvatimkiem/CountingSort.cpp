#include<iostream>
#include <cstdlib>
#include<ctime>
// using namespace std;
#define MAX 200


void input(int* a, int& n){ // nho chu y &n
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        // std::cin >> a[i];

        a[i] = rand() % ( 100 + 1) ;
    }

}

void CountingSort(int* a, int n){
    int c[n];
    int b[MAX] ={0};
    for(int i = 0; i < n; i++){
        b[a[i]]++;
    }

    for(int i = 1; i < MAX; i++){ // phải lặp tới MAX
        b[i] += b[i-1];
    }

    for(int i = n - 1; i > -1 ; i--){
        b[a[i]]--;
        c[b[a[i]]] = a[i];
    }
    // a=c; // không được vì chỉ gán địa chỉ copy
    for(int i = 0 ; i < n ; i++){
        a[i] = c[i];
    }
}

void ReverseCountingSort(int* a, int n){
    int b[MAX] = {0}; 
    int c[n];

    for(int i = 0; i < n; i++){
        b[a[i]]++;
    }

    for(int i = 1; i < MAX; i++){
        b[i] += b[i - 1];
    }

    for(int i = n - 1; i > -1; i--){
        c[n - b[a[i]]] = a[i];  // Đảo vị trí để sắp xếp giảm dần
        b[a[i]]--;
    }

    for(int i = 0; i < n; i++){
        a[i] = c[i];
    }
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
    output(a,n);

    CountingSort(a,n);
    output(a,n);

    ReverseCountingSort(a,n);
    output(a,n);
    // delete[] a;
    return 0;
}