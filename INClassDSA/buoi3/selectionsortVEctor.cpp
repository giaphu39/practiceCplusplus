#include<iostream>
#include <cstdlib>
#include<ctime>
// using namespace std;
#include<vector>

void input(std::vector<int>& a, int& n){
    std::cin >> n;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int temp = rand() %(99+1);
        a.push_back(temp);
    }

}

void SelectionSort(std::vector<int>& a, const int& n){
    
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

void ReverseSelectionSort (std::vector<int>& a,const int& n){
    
    for(int i=0;i<n;i++){
        int iMax= i;
        for(int j=i+1;j<n;j++){
            if(a[iMax] < a[ j ]){
                iMax = j;
            }
        }
        std:: swap(a[ iMax ] , a[ i ]);
    }
}

void output(const std::vector<int>& a, const int& n){
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
int main(){
    int n;
    std::vector<int> a;
    input(a,n);
    output(a,n);

    SelectionSort(a,n);
    output(a,n);

    ReverseSelectionSort(a,n);
    output(a,n);

    return 0;
}