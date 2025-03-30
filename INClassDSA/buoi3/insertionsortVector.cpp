#include<iostream>
#include <cstdlib>
#include<ctime>
// using namespace std;
#define MAX 200
#include<vector>

void input(std:: vector<int>&  a, int& n){ 
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int temp = rand() % ( 100 + 1) ;
        a.push_back(temp);
    }
}


void InsertionSort(std:: vector<int>&  a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] < temp ) break;
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
    }
}

void ReverseInsertionSort(std:: vector<int>&  a, int n){
    
    for(int i = 1; i < n ; i++){
        int temp = a[ i ]; int k;
        for( k = i - 1; k > -1 ; k--){

            if(a[ k ] > temp ) break; // đổi chỗ này là được
            a[k + 1] = a[ k ];
        }

        a[k + 1 ]= temp;
    }
}


void output( const std:: vector<int>&  a, int n){
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
int main(){
    int n;
    // int* a=new int[MAX];
    // int a[MAX];

    std:: vector <int> a;
    input(a,n);
    output(a,n);

    InsertionSort(a,n);
    output(a,n);

    ReverseInsertionSort(a,n);
    output(a,n);
    // delete[] a;
    return 0;
}