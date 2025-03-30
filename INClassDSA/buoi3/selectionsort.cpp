#include<iostream>
#include <cstdlib>
#include<ctime>
// using namespace std;
#define MAX 200


// void input(int* a, int& n){ // nho chu y &n
//     std::cin >> n;
//     srand(time(NULL));
//     for(int i=0;i<n;i++){
//         // std::cin >> a[i];

//         a[i] = rand() % ( 100 + 1) ;
//     }

// }


void input(int* a, int& n){ // nho chu y &n
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }

}
void SelectionSort(int* a, int n){
    
    for(int i=0;i<n;i++){
        int iMin= i;
        for(int j=i+1;j<n;j++){
            if(a[iMin] > a[ j ]){
                iMin = j;
            }
        }
        std:: swap(a[ iMin ] , a[ i ]);
    }
}

void ReverseSelectionSort(int* a, int n){
    
    for(int i=0;i<n;i++){ // phải là 0 -> n-2 nên chạy kiểu này không được tối ưu
        int iMax= i;
        for(int j=i+1;j<n;j++){
            if(a[iMax] < a[ j ]){
                iMax = j;
            }
        }
        if(iMax == i){
            std::cout<<a[i];
        }
        std:: swap(a[ iMax ] , a[ i ]);
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
    // output(a,n);

    // SelectionSort(a,n);
    // output(a,n);

    ReverseSelectionSort(a,n);
    // output(a,n);
    // delete[] a;
    return 0;
}