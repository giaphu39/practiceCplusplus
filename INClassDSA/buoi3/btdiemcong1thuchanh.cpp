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


void input(int* a, int& n){ // nho chu y &n
    int temp;cin>>temp;
    int i=0;
    while(temp != 0){
        a[i++]=temp;
        cin>>temp;
    }
    n = i;
}

void SelectionSort(int* a, int n){
    if(n==0) cout<<"empty";
    else{
        for(int i=0;i< n -1;i++){
            int iMin= i;
            for(int j=i+1;j<n;j++){
                if(a[iMin] >= a[ j ]){ // có thể = hoặc không tùy vào thuật toán nếu = thì là đổi giá trị cuối cùng 
                //suy ra khi làm kiểm ra nếu sai test case thì thêm dấu bằng 
                    iMin = j;
                }
            }
            std:: swap(a[ iMin ] , a[ i ]);
            cout<<"i="<<i<<": ";
            for(int j=0;j<n;j++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
        }
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

    int A[MAX], N;
    input(A,N);

    SelectionSort(A,N);

    return 0;
}