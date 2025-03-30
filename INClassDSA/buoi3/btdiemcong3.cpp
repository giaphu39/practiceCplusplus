#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 200
#include<vector>

// void input(int* a, int& n){ // nho chu y &n
//     std::cin >> n;
//     srand(time(NULL));
//     for(int i=0;i<n;i++){
//         // std::cin >> a[i];

//         a[i] = rand() % ( 100 + 1) ;
//     }

// }


void input(vector<int>& a){ // nho chu y &n
    int temp;cin>>temp;
    // int i=0;
    while(temp != 0){
        a.push_back(temp);
        cin>>temp;
    }
}

void SelectionSort(vector<int>& a){
    // if(n==0) cout<<"empty";
    // else{
        int n=a.size();
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
    // }
    
}

void ReverseSelectionSort(vector<int>& a){
    int n=a.size();
    if(n == 0) cout<<"Empty";
    else{
        for(int i=0;i<n -1;i++){ // phải là 0 -> n-2 nên chạy kiểu này không được tối ưu
            int iMax= i;
            for(int j=i+1;j<n;j++){
                if(a[iMax] <= a[ j ]){
                    iMax = j;
                }
            }
            std:: swap(a[ iMax ] , a[ i ]);
    
            cout<<"i="<<i<<": max="<<iMax<<endl;
        }
    }
    
}

void output(int* a, int n){
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
int main(){

    vector<int> A;
    input(A);

    ReverseSelectionSort(A);

    return 0;
}