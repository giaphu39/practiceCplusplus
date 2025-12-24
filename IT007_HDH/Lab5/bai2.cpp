/*######################################
# University of Information Technology #
# IT007 Operating System #
# Ten,mssv #
# File: ProduceAndConsumeInArray.cpp #
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 100

int a[N];
int count = 0;

void* producer(void* arg) {
    while (1) {
        int x = rand();
        if (count < N) {
            a[count++] = x;
            printf("Produced %d → count = %d\n", x, count);
        } else {
            printf("Array is full, we can't produce more\n");
        }
        // sleep(rand() % 7);
    }
    return NULL; // tránh lỗi khi biên dịch tuy nhiên không có vẫn chạy được
}

void* consumer(void* arg) {
    while (1) {
        if (count > 0) {
            int x = a[--count];
            printf("Consumed %d → count = %d\n", x, count);
        } else {
            printf("Nothing in array a\n");
        }
        // sleep(rand() % 7);
    }
    return NULL; 
}

int main() {
    srand(time(NULL));
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL); // luồng main đợi threads thay vì dùng while(true)
    return 0;
}
