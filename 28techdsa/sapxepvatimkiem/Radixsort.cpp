#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define MAX 200

void input(int* a, int& n){
    std::cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % 101;
    }
}

void CountingSortByDigit(int* a, int n, int exp){
    int c[n];
    int b[10] = {0}; 
    
    for(int i = 0; i < n; i++){
        b[(a[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        b[i] += b[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        c[--b[(a[i] / exp) % 10]] = a[i];
    }

    for(int i = 0; i < n; i++){
        a[i] = c[i];
    }
}

void RadixSort(int* a, int n){
    int maxVal = *std::max_element(a, a + n);
    for(int exp = 1; maxVal / exp > 0; exp *= 10){
        CountingSortByDigit(a, n, exp);
    }
}

void output(int* a, int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    int a[MAX];
    input(a, n);
    output(a, n);

    RadixSort(a, n);
    output(a, n);
    
    return 0;
}
