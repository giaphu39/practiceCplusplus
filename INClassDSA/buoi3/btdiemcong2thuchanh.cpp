#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 200


void input(int* a, int& n){ // nho chu y &n
    int temp;cin>>temp;
    int i=0;
    while(temp != 0){
        a[i++]=temp;
        cin>>temp;
    }
    n = i;

}
void output(int* a, int n){
    cout<<"Output: ";
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
void InsertionSort(int* a, int n){
    int b[n];
    int z=0;
    if(n == 0) cout<<"Empty";
    
    else{
        
        
        for(int i = 1; i < n ; i++){
            int temp = a[ i ]; int k;
            for( k = i - 1; k > -1 ; k--){
    
                if(a[ k ] < temp ) break;
                a[k + 1] = a[ k ];
            }
    
            a[k + 1 ]= temp;
            if(k + 1 == i){
                b[z++] = temp;
            }
        }
        









        
        if(z == 0){
            cout<<"NotFound"<<endl;
        }
        else{
            for(int i=0;i<z;i++){
                cout<<b[i]<<" ";
            }
            cout<<endl;

            
        }
        output(a,n);
    }
    
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


int main(){
    int A[MAX], N;
    input(A,N);

    InsertionSort(A,N);
    return 0;
}