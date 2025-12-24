#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int x = 0; 

void * processA(){

    while(1){
        x = x+ 1;
        if(x==20){
            x = 0;
        }
        print(x);
    }

}

void * processB(){

    while(1){
        x = x+ 1;
        if(x==20){
            x = 0;
        }
        print(x);
    }

}



int main(){

    pthread_t tA, tB;
    // x = 0;
    pthread_create(&tA, NULL, processA, NULL);
    pthread_create(&tB, NULL, processB, NULL);
    
    pthread_join(&tA, NULL);
    pthread_join(&tB, NULL);
    
    return 0;
}