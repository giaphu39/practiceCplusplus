#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 200


// void input(int* a, int& n){ // nho chu y &n
//     std::cin >> n;
//     srand(time(NULL));
//     for(int i=0;i<n;i++){
//         // std::cin >> a[i];

//         a[i] = rand() % ( 100 + 1) ;
//     }

// }
int donSwap=0;
void output(int* a, int n,int i){
    cout<<"i="<<i<<": ";
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
void input(int* a, int& n){ // nho chu y &n
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }

}
void SelectionSort(int* a, int n){
    
    for(int i=0;i<n-1;i++){
        int iMin= i;
        for(int j=i+1;j<n;j++){
            if(a[iMin] > a[ j ]){ // có thể có dấu = nếu cho 
                iMin = j;
            }
            
        }
        if(iMin == i) donSwap++;
        std:: swap(a[ iMin ] , a[ i ]);
        output(a,n,i);

    }
}

void ReverseSelectionSort(int* a, int n){
    
    for(int i=0;i<n-1;i++){ // phải là 0 -> n-2 nên chạy kiểu này không được tối ưu
        int iMax= i;
        for(int j=i+1;j<n;j++){
            if(a[iMax] < a[ j ]){
                iMax = j;
            }
        }
        if(iMax == i) donSwap++;
        std:: swap(a[ iMax ] , a[ i ]);
        output(a,n,i);
    }
}


int main(){
    int n; cin>>n;

    int a[]={2, 5, 3, 0, 8, 6, 1};
    // int* a=new int[MAX];
    // int a[MAX];
    // input(a,n);
    // output(a,n);

    SelectionSort(a,n);
    // ReverseSelectionSort(a,n);
    // output(a,n);
    // delete[] a;

    cout<<donSwap;
    return 0;
}