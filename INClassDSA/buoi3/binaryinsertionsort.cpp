#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 200

void input(int* a, int& n) { 
    std::cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % (100 + 1);
    }
}

int binarySearch(int* a, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid + 1;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void binaryInsertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int pos = binarySearch(a, 0, i - 1, key);
        for (int j = i; j > pos; j--) {
            a[j] = a[j - 1];
        }
        a[pos] = key;
    }
}

void output(int* a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    int a[MAX];
    input(a, n);
    
    std::cout << "Mảng ban đầu: ";
    output(a, n);

    binaryInsertionSort(a, n);
    std::cout << "Mảng sau khi sắp xếp: ";
    output(a, n);

    return 0;
}
