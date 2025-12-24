#include <stdio.h>
#include <stdlib.h>
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

// int partition(PCB P[], int low, int high, int iCriteria)
// {
//     int mid = (low + high) / 2;
//     int pivot;

//     // chọn pivot theo tiêu chí
//     if (iCriteria == SORT_BY_ARRIVAL)
//         pivot = P[mid].iArrival;
//     else if (iCriteria == SORT_BY_PID)
//         pivot = P[mid].iPID;
//     else if (iCriteria == SORT_BY_BURST)
//         pivot = P[mid].iBurst;
//     else
//         pivot = P[mid].iStart;

//     int i = low;
//     int j = high;

//     while (i <= j)
//     {
//         int leftCond, rightCond;

//         // dịch con trỏ i sang phải
//         if (iCriteria == SORT_BY_ARRIVAL)
//             leftCond = P[i].iArrival < pivot;
//         else if (iCriteria == SORT_BY_PID)
//             leftCond = P[i].iPID < pivot;
//         else if (iCriteria == SORT_BY_BURST)
//             leftCond = P[i].iBurst < pivot;
//         else
//             leftCond = P[i].iStart < pivot;

//         // dịch con trỏ j sang trái
//         if (iCriteria == SORT_BY_ARRIVAL)
//             rightCond = P[j].iArrival > pivot;
//         else if (iCriteria == SORT_BY_PID)
//             rightCond = P[j].iPID > pivot;
//         else if (iCriteria == SORT_BY_BURST)
//             rightCond = P[j].iBurst > pivot;
//         else
//             rightCond = P[j].iStart > pivot;

//         if (leftCond)
//             i++;
//         else if (rightCond)
//             j--;
//         else
//         {
//             swapProcess(&P[i], &P[j]);
//             i++;
//             j--;
//         }
//     }

//     return i;
// }

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
        // Dịch con trỏ trái
        while (
            (iCriteria == SORT_BY_ARRIVAL && P[i].iArrival < pivot) ||
            (iCriteria == SORT_BY_PID && P[i].iPID < pivot) ||
            (iCriteria == SORT_BY_BURST && P[i].iBurst < pivot) ||
            (iCriteria == SORT_BY_START && P[i].iStart < pivot))
        {
            i++;
        }

        // Dịch con trỏ phải
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

    return i; // trả về vị trí chia mảng với trước i là nửa trái, từ i đến hết là nửa phải
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



// int partition(PCB P[], int low, int high, int iCriteria)
// {
//     int pivot;
//     if (iCriteria == SORT_BY_ARRIVAL)
//         pivot = P[high].iArrival;
//     else if (iCriteria == SORT_BY_PID)
//         pivot = P[high].iPID;
//     else if (iCriteria == SORT_BY_BURST)
//         pivot = P[high].iBurst;
//     else
//         pivot = P[high].iStart;
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         int cond = 0;
//         if (iCriteria == SORT_BY_ARRIVAL)
//             cond = P[j].iArrival < pivot;
//         else if (iCriteria == SORT_BY_PID)
//             cond = P[j].iPID < pivot;
//         else if (iCriteria == SORT_BY_BURST)
//             cond = P[j].iBurst < pivot;
//         else
//             cond = P[j].iStart < pivot;
//         if (cond)
//         {
//             i++;
//             swapProcess(&P[i], &P[j]);
//         }
//     }
//     swapProcess(&P[i + 1], &P[high]);
//     return i + 1;
// }

// void quickSort(PCB P[], int low, int high, int iCriteria)
// {
//     if (low < high)
//     {
//         int pi = partition(P, low, high, iCriteria);
//         quickSort(P, low, pi - 1, iCriteria);
//         quickSort(P, pi + 1, high, iCriteria);
//     }
// }

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
int main()
{
    PCB Input[10];
    PCB ReadyQueue[10];
    PCB TerminatedArray[10];
    int iNumberOfProcess;
    printf("Please input number of Process: ");
    scanf("%d", &iNumberOfProcess);
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0;
    inputProcess(iNumberOfProcess, Input);
    quickSort(Input, 0, iNumberOfProcess - 1,
              SORT_BY_ARRIVAL);
    pushProcess(&iReady, ReadyQueue, Input[0]);
    removeProcess(&iRemain, 0, Input);
    ReadyQueue[0].iStart = ReadyQueue[0].iArrival;
    ReadyQueue[0].iFinish = ReadyQueue[0].iStart +
                            ReadyQueue[0].iBurst;
    ReadyQueue[0].iResponse = ReadyQueue[0].iStart -
                              ReadyQueue[0].iArrival;
    ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
    ReadyQueue[0].iTaT = ReadyQueue[0].iFinish -
                         ReadyQueue[0].iArrival;
    printf("\nReady Queue: ");
    printProcess(1, ReadyQueue);
    while (iTerminated < iNumberOfProcess)
    {
        while (iRemain > 0)
        {
            if (Input[0].iArrival <= ReadyQueue[0].iFinish)
            {
                pushProcess(&iReady, ReadyQueue, Input[0]);
                removeProcess(&iRemain, 0, Input);
                continue;
            }
            else
                break; // chỗ này có vẻ sai vì có thể cái đầu hoàn thành rồi nhưng cái sau chưa đến nên cho vòng lặp ở đây ++ lên
        }
        if (iReady > 0)
        {
            pushProcess(&iTerminated, TerminatedArray,
                        ReadyQueue[0]);
            removeProcess(&iReady, 0, ReadyQueue);
            ReadyQueue[0].iStart = TerminatedArray[iTerminated - 1].iFinish;
            ReadyQueue[0].iFinish = ReadyQueue[0].iStart +
                                    ReadyQueue[0].iBurst;
            ReadyQueue[0].iResponse = ReadyQueue[0].iStart -
                                      ReadyQueue[0].iArrival;
            ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
            ReadyQueue[0].iTaT = ReadyQueue[0].iFinish -
                                 ReadyQueue[0].iArrival;
        }
    }
    printf("\n===== FCFS Scheduling =====\n");
    exportGanttChart(iTerminated, TerminatedArray);
    quickSort(TerminatedArray, 0, iTerminated - 1,
              SORT_BY_PID);
    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);
    return 0;
}
