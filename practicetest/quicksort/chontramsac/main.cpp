#include <iostream>

using namespace std;
//
//3 5
//100 200 300
//50 100 150 200 250



void output(int *a, int n){
    for (int i = 0; i < n; i++) cout<< a[i]<<" ";
    cout<<endl;
}

void SelectionSort(int * a, int n){

    for(int i=0 ;i < n-1 ;i++){
        int Min = i;
        for(int j = i+ 1; j<n; j++){
            if(a[j] < a[Min]){
                Min = j;
            }
        }

        swap(a[i], a[Min]);

    }


}

void InsertionSort(int *a , int n){

    for(int i= 1 ;i < n ; i++){
        int temp = a[i];
        int j;
        for(j= i-1; j> -1 ;j--){
            if(a[j] < temp){
                break; // nghĩa là chạy a[j] > temp
            }
            a[j+1] = a[j];

        }
        a[j+1] = temp;
    }

}

void QuickSort(int* a, int n, int l, int r){
    if(l >= r) return;
    int mid = l + (r-l)/2;
    int temp = a[mid];

    int i= l, j= r;
    while(i < j){

        while(a[i] > temp) i++;
        while(a[j] < temp) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if(l < j) QuickSort(a,n,l,j);
    if(i < r) QuickSort(a,n,i,r);
}

void heapify(int *a, int heapSize, int i){
    int childL= i*2 +1;
    int childR= i*2 +2;
    int Max = i;

    if(childL < heapSize && a[childL] < a[Max] ){
            Max = childL;
    }

    if(childR < heapSize && a[childR] < a[Max] ){
            Max = childR;
    }

    if(Max != i){
        swap(a[i], a[Max]);

        heapify(a,heapSize,Max);
    }
}


void buildHeap(int* a, int n){
    for(int i= (n/2)-1; i>=0;i--){
        heapify(a,n,i);
    }

}

void HeapSort(int* a, int n){

    int N= n;
    int heapSize= N;

    buildHeap(a,heapSize);

    for(int i=0 ;i< N ;i++){
        swap(a[0], a[heapSize -1]);
        heapSize -= 1;

        heapify(a,heapSize,0);

    }

}


int LinearSearch(int x, int* a, int n){
    int i=0;
    while(i < n){
        if(a[i++] >= x) return i;

    }
    return -1;

}


void sol(int* a, int* b , int n, int m){
    int COUNT=0;
    for(int i=0; i< m;i++){
        int index =LinearSearch(b[i], a, n);
        if(index != -1){
            a[index] -= b[i];

            COUNT++;
        }
    }
    cout<<COUNT;
}

// ý tưởng sắp xếp rồi tìm kiếm, tìm kiếm xong - giá trị pin sạc
int main()
{
    int n, m; // n là trạm sạc  phần tử là dung lượng pin
    cin >> n >> m; // m xe điện cần sạc với phần tử là mức pin tối thiểu

    // một trạm chỉ sạc 1 xe
    int a[n+1], b[m +1];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    InsertionSort(a,n);

    QuickSort(a,n,0,n-1);
    SelectionSort(b,m);
    HeapSort(b,m);

    output(a,n);
    output(b,m);


    sol(a,b,n,m);

    return 0;
}
