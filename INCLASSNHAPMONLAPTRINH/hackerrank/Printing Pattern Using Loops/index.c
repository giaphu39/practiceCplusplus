#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int min(int a, int b){
    if(a>b){
        return b;
    }
    else return a;
}
void mang(int n){
    int size = 2 * n - 1;  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          
            int value = n -min(min(i, j),min(size-i- 1, size- j- 1));
            printf("%d ", value); 
        }
        printf("\n");  
    }
}

int main(){
    int n;
    scanf("%d", &n);  
    mang(n);  
    return 0;
}