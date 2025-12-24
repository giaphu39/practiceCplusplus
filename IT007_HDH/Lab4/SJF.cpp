#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3

typedef struct
{
    int iPID;
    int iArrival, iBurst;
    int iStart, iFinish, iWaiting, iResponse, iTaT;
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
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++)
    {
        printf("|  P%d  ", P[i].iPID);
    }
    printf("|\n");
    printf("%d", P[0].iStart);
    for (int i = 0; i < n; i++)
    {
        printf("      %d", P[i].iFinish);
    }
    printf("\n");
}

void pushProcess(int *n, PCB P[], PCB Q)
{
    P[*n] = Q;
    (*n)++;
}

void removeProcess(int *n, int index, PCB P[])
{
    for (int i = index; i < *n - 1; i++)
    {
        P[i] = P[i + 1];
    }
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
            (iCriteria == SORT_BY_START && P[i].iStart < pivot))
        {
            i++;
        }

        while (
            (iCriteria == SORT_BY_ARRIVAL && P[j].iArrival > pivot) ||
            (iCriteria == SORT_BY_PID && P[j].iPID > pivot) ||
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

void calculateAWT(int n, PCB P[])
{
    float total = 0;
    for (int i = 0; i < n; i++)
        total += P[i].iWaiting;
    printf("\nAverage Waiting Time: %.2f\n", total / n);
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

void randomProcess(int n, PCB P[])
{
    srand(time(NULL)); // Khởi tạo seed ngẫu nhiên 1 lần
    for (int i = 0; i < n; i++)
    {
        P[i].iPID = i + 1;
        P[i].iArrival = rand() % 21;         // [0, 20]
        P[i].iBurst = 2 + rand() % 11;       // [2, 12]
    }

    printf("\n--- Randomly Generated Processes ---\n");
    printf("%-5s%-10s%-10s\n", "PID", "Arrive", "Burst");
    for (int i = 0; i < n; i++)
        printf("%-5d%-10d%-10d\n", P[i].iPID, P[i].iArrival, P[i].iBurst);
}


int main()
{
    PCB Input[10];
    PCB ReadyQueue[10];
    PCB TerminatedArray[10];
    int iNumberOfProcess;
    printf("Please input number of Process: ");
    scanf("%d", &iNumberOfProcess);
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0; // khởi tạo các giá trị ban đầu
    // inputProcess(iNumberOfProcess, Input);
    randomProcess(iNumberOfProcess,Input);
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    int currentTime = 0; // biến theo dõi thời gian hiện tại

    while (iTerminated < iNumberOfProcess)
    {
        // Đưa các tiến trình đến thời điểm hiện tại vào hàng đợi
        for (int i = 0; i < iRemain; i++)
        {
            if (Input[i].iArrival <= currentTime)
            {
                pushProcess(&iReady, ReadyQueue, Input[i]);
                removeProcess(&iRemain, i, Input);
                i--; // cập nhật lại vì vừa xóa
            }
        }

        //Nếu hàng đợi rỗng->tăng thời gian
        if (iReady == 0)
        {
            currentTime++;
            continue;
        }

        // Sắp xếp hàng đợi Ready theo Burst Time (SJF)
        quickSort(ReadyQueue, 0, iReady - 1, SORT_BY_BURST);

        // Chọn tiến trình ngắn nhất và chạy
        PCB current = ReadyQueue[0];
        removeProcess(&iReady, 0, ReadyQueue);

        current.iStart = currentTime;
        current.iFinish = currentTime + current.iBurst;
        current.iResponse = current.iStart - current.iArrival;
        current.iWaiting = current.iResponse; // do là non-preemptive
        current.iTaT = current.iFinish - current.iArrival;

        pushProcess(&iTerminated, TerminatedArray, current);

        
        currentTime = current.iFinish;
    }

    printf("\n===== SJF (Non-preemptive) Scheduling =====\n");
    exportGanttChart(iTerminated, TerminatedArray);
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);
    printProcess(iTerminated, TerminatedArray);
    calculateRT(iTerminated, TerminatedArray);
    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);
    return 0;
}
