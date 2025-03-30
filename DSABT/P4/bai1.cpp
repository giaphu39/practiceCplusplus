/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 200000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

//###INSERT CODE HERE -
void Heapify(int *a,int heapSize, int index){ // dùng để giao hoán vị trí và vị trí lan truyền, index là của parent
    int indexChildLeft = index*2 + 1;
    int indexChildRight = index *2 +2;
    int Max=index;
    // if(indexChildLeft > Max) Max = indexChildLeft; // sai chõ này so sánh giá trị
    if(indexChildLeft < heapSize && a[indexChildLeft] > a[Max]) Max = indexChildLeft;
    // if(indexChildRight > Max) Max = indexChildRight;
    if(indexChildRight < heapSize && a[indexChildRight] > a[Max]) Max = indexChildRight;

    if(Max != index){
        std::swap(a[index] , a[Max]);
        Heapify(a,heapSize,Max); // Max lưu vị trí được đổi
    }
}

void buildHeap(int * a, int heapSize){

    for(int i = heapSize/2 - 1; i >= 0 ; i--){
        Heapify(a, heapSize, i);
    }
}




void HeapSort(int a[], int n) {
	int heapSize;
	heapSize = n;
	buildHeap(a, heapSize);
	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]);
		heapSize -= 1;
		Heapify(a, heapSize, 0);
	}
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}
