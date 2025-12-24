#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3
#define SORT_BY_REMAININGBURST 4
#define MAX 100

using namespace std;

typedef struct
{
    int iPID;
    int iArrival, iBurst;
    int iRemainingBurst;
    int iStart, iFinish, iWaiting, iResponse, iTaT;
    int started;
} PCB;

void inputProcess(int n, PCB P[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        P[i].iPID = i + 1;
        printf("Arrival time: ");
        scanf("%d", &P[i].iArrival);
        printf("Burst time: ");
        scanf("%d", &P[i].iBurst);
        P[i].iRemainingBurst = P[i].iBurst;
        P[i].started = 0;
        P[i].iStart = -1;
        P[i].iFinish = -1;
        P[i].iWaiting = 0;
        P[i].iResponse = 0;
        P[i].iTaT = 0;
    }
}

void randomProcess(int n, PCB P[])
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        P[i].iPID = i + 1;
        P[i].iArrival = rand() % 21;        // [0, 20]
        P[i].iBurst = 2 + rand() % 11;      // [2, 12]
        P[i].iRemainingBurst = P[i].iBurst;
        P[i].started = 0;
        P[i].iStart = -1;
        P[i].iFinish = -1;
        P[i].iWaiting = 0;
        P[i].iResponse = 0;
        P[i].iTaT = 0;
    }

    printf("\n--- Randomly Generated Processes ---\n");
    printf("%-5s%-10s%-10s\n", "PID", "Arrive", "Burst");
    for (int i = 0; i < n; i++)
        printf("%-5d%-10d%-10d\n", P[i].iPID, P[i].iArrival, P[i].iBurst);
}

void pushProcess(int *n, PCB P[], PCB Q)
{
    P[*n] = Q;
    (*n)++;
}

void removeProcess(int *n, int index, PCB P[])
{
    for (int i = index; i < *n - 1; i++)
        P[i] = P[i + 1];
    (*n)--;
}

int swapProcess(PCB *P, PCB *Q)
{
    PCB temp = *P;
    *P = *Q;
    *Q = temp;
    return 1;
}

int partition(PCB P[], int low, int high, int iCriteria)
{
    int mid = (low + high) / 2;
    int pivot;

    if (iCriteria == SORT_BY_ARRIVAL)
        pivot = P[mid].iArrival;
    else if (iCriteria == SORT_BY_PID)
        pivot = P[mid].iPID;
    else if (iCriteria == SORT_BY_BURST)
        pivot = P[mid].iBurst;
    else if (iCriteria == SORT_BY_REMAININGBURST)
        pivot = P[mid].iRemainingBurst;
    else
        pivot = P[mid].iStart;

    int i = low;
    int j = high;

    while (i <= j)
    {
        while (
            (iCriteria == SORT_BY_ARRIVAL && P[i].iArrival < pivot) ||
            (iCriteria == SORT_BY_PID && P[i].iPID < pivot) ||
            (iCriteria == SORT_BY_BURST && P[i].iBurst < pivot) ||
            (iCriteria == SORT_BY_START && P[i].iStart < pivot) ||
            (iCriteria == SORT_BY_REMAININGBURST && P[i].iRemainingBurst < pivot))
        {
            i++;
        }

        while (
            (iCriteria == SORT_BY_ARRIVAL && P[j].iArrival > pivot) ||
            (iCriteria == SORT_BY_PID && P[j].iPID > pivot) ||
            (iCriteria == SORT_BY_REMAININGBURST && P[j].iRemainingBurst > pivot) ||
            (iCriteria == SORT_BY_BURST && P[j].iBurst > pivot) ||
            (iCriteria == SORT_BY_START && P[j].iStart > pivot))
        {
            j--;
        }

        if (i <= j)
        {
            swapProcess(&P[i], &P[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quickSort(PCB P[], int low, int high, int iCriteria)
{
    if (low < high)
    {
        int index = partition(P, low, high, iCriteria);
        if (low < index - 1)
            quickSort(P, low, index - 1, iCriteria);
        if (index < high)
            quickSort(P, index, high, iCriteria);
    }
}

void printProcess(int n, PCB P[])
{
    printf("\n%-5s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "PID", "Arrive", "Burst", "Start", "Finish", "Wait", "Resp", "TaT");
    for (int i = 0; i < n; i++)
    {
        printf("%-5d%-10d%-10d%-10d%-10d%-10d%-10d%-10d\n",
               P[i].iPID, P[i].iArrival, P[i].iBurst, P[i].iStart,
               P[i].iFinish, P[i].iWaiting, P[i].iResponse, P[i].iTaT);
    }
}

void exportGanttChart(int n, PCB P[])
{
    if (n == 0) return;
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++)
        printf("|  P%d  ", P[i].iPID);
    printf("|\n");
    printf("%d", P[0].iStart);
    for (int i = 0; i < n; i++)
        printf("      %d", P[i].iFinish);
    printf("\n");
}

void calculateAWT(int n, PCB P[])
{
    float total = 0;
    for (int i = 0; i < n; i++)
        total += P[i].iWaiting;
    printf("Average Waiting Time: %.2f\n", total / n);
}

void calculateATaT(int n, PCB P[])
{
    float total = 0;
    for (int i = 0; i < n; i++)
        total += P[i].iTaT;
    printf("Average Turnaround Time: %.2f\n", total / n);
}

void calculateRT(int n, PCB P[])
{
    float total = 0;
    for (int i = 0; i < n; i++)
        total += P[i].iResponse;
    printf("Average Response Time: %.2f\n", total / n);
}


int main()
{
    PCB Gantt[1000];
    int iGantt = 0;

    PCB Input[MAX];
    PCB ReadyQueue[MAX];
    PCB TerminatedArray[MAX];
    int iNumberOfProcess;
    printf("Please input number of Process: ");
    if (scanf("%d", &iNumberOfProcess) != 1 || iNumberOfProcess <= 0 || iNumberOfProcess > MAX)
    {
        printf("Invalid number of processes (1-%d).\n", MAX);
        return 0;
    }

    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0;
    // inputProcess(iNumberOfProcess, Input);
    randomProcess(iNumberOfProcess,Input);
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    int currentTime = 0;

    while (iTerminated < iNumberOfProcess)
    {
        for (int i = 0; i < iRemain; i++)
        {
            if (Input[i].iArrival <= currentTime)
            {
                pushProcess(&iReady, ReadyQueue, Input[i]);
                removeProcess(&iRemain, i, Input);
                i--;
            }
        }

        if (iReady == 0)
        {
            if (iRemain > 0)
                currentTime = Input[0].iArrival; // nhảy tới tiến trình sắp đến
            else if (iTerminated == iNumberOfProcess)
                break; // chỉ break khi thật sự xong tất cả
            else
                currentTime++; // chờ thêm một tick thời gian (phòng trường hợp còn process đang chạy)
        }

        quickSort(ReadyQueue, 0, iReady - 1, SORT_BY_REMAININGBURST);
        PCB *current = &ReadyQueue[0];

        if (!current->started) // lần đầu được in thì chạy
        {
            current->iStart = currentTime;
            current->iResponse = current->iStart - current->iArrival;
            current->started = 1;
        }

        int segmentStart = currentTime;
        int timeToNextArrival;
        if (iRemain > 0)
        {
            int diff = Input[0].iArrival - currentTime;
            if (diff <= 0) timeToNextArrival = 1; // xét thời gian tới của process đầu hàng đợi chưa được bỏ vào ready, trường hợp nó còn bé hơn thời gian hiện tại thì tăng 1 đơn vị
            else timeToNextArrival = diff;
        }
        else
        {
            timeToNextArrival = current->iRemainingBurst;
        }

        int executed = min(current->iRemainingBurst, timeToNextArrival); // min giữa remaining burst và thời điểm tiến trình vào readyQueue
        if (executed <= 0) executed = 1; // trường hợp timeToNextArrival <=0 nghĩa là chỉ xét thời điểm 1 tiến trình được bỏ vào

        current->iRemainingBurst -= executed;
        currentTime += executed;

        //Bỏ vào Gantt để vẽ giản đồ
        PCB temp = *current;
        temp.iStart = segmentStart;
        temp.iFinish = currentTime;
        Gantt[iGantt++] = temp;

        //Trường hợp đã hoàn tất 1 tiến trình 
        if (current->iRemainingBurst == 0)
        {
            current->iFinish = currentTime;
            current->iTaT = current->iFinish - current->iArrival;
            current->iWaiting = current->iTaT - current->iBurst;
            pushProcess(&iTerminated, TerminatedArray, *current);
            removeProcess(&iReady, 0, ReadyQueue);
        }
    }

    printf("\n===== SRTF (Preemptive) Scheduling =====\n");
    exportGanttChart(iGantt, Gantt);
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);
    printProcess(iTerminated, TerminatedArray);
    calculateRT(iTerminated, TerminatedArray);
    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);

    return 0;
}
