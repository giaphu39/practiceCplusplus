/*######################################
# University of Information Technology #
# IT007 Operating System #
#  #
# File: produceAndConsume.cpp #
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MSSV_LAST4 1365

int products = 0;
int sells = 0;
sem_t can_produce; // kiểm soát giới hạn trên: products <= sells + MSSV_LAST4
sem_t can_sell;    // kiểm soát giới hạn dưới: sells <= products

void* Producer(void* arg) {
    while (1) {
        srand(time(NULL));
        sem_wait(&can_produce);   // chờ nếu đã sản xuất quá giới hạn
        products++;
        printf("Produced → products = %d, sells = %d\n", products, sells);
        sem_post(&can_sell);      // báo có thể bán thêm 1 sản phẩm
        sleep(rand() % 7);// cho ngẫu nhiên sleep và tính bằng giây để dễ quan sát hơn các nó chạy
    }
    
}

void* Consumer(void* arg) {
    while (1) { // nếu lần đầu là bán thì can_sell =0 nên phải chờ
        srand(time(NULL));
        sem_wait(&can_sell);      // chờ nếu chưa có sản phẩm để bán
        sells++;
        printf("Sold → products = %d, sells = %d\n", products, sells);
        sem_post(&can_produce);   // báo có thể sản xuất thêm (có chỗ trống)
        sleep(1);
        sleep(rand() % 7);// cho ngẫu nhiên sleep để dễ quan sát hơn các nó chạy

    }
}

int main() {
    pthread_t prod, cons;
    sem_init(&can_sell, 0, 0);           // chưa có sản phẩm nào để bán
    sem_init(&can_produce, 0, MSSV_LAST4); // còn chỗ trống để sản xuất

    pthread_create(&prod, NULL, Producer, NULL);
    pthread_create(&cons, NULL, Consumer, NULL);

    while (1);
    return 0;
}
