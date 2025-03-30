#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm xuất mảng C sau mỗi lần lặp
void output(int* a, int n, int i) {
    cout << "i=" << i << ": ";
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
}

// Counting Sort tăng dần
void countingSortAscending(vector<int> &arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> C(range, 0);  // Mảng đếm
    vector<int> outputArr(arr.size());

    // Đếm số lần xuất hiện của từng phần tử
    for (int num : arr) {
        C[num - min_val]++;
    }
    
    // In mảng C sau khi đếm
    output(C.data(), range, 0);

    // Tính tổng tích lũy để có vị trí sắp xếp chính xác
    for (int i = 1; i < range; i++) {
        C[i] += C[i - 1];
    }

    // In mảng C sau khi tích lũy
    output(C.data(), range, 1);

    // Sắp xếp vào outputArr theo thứ tự tăng dần
    for (int i = arr.size() - 1; i >= 0; i--) {
        outputArr[C[arr[i] - min_val] - 1] = arr[i];
        C[arr[i] - min_val]--;
    }

    arr = outputArr;
}

// Counting Sort giảm dần
void countingSortDescending(vector<int> &arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> C(range, 0);  // Mảng đếm
    vector<int> outputArr(arr.size());

    // Đếm số lần xuất hiện của từng phần tử
    for (int num : arr) {
        C[num - min_val]++;
    }

    // In mảng C sau khi đếm
    output(C.data(), range, 0);

    // Tính tổng tích lũy giảm dần
    for (int i = range - 2; i >= 0; i--) {
        C[i] += C[i + 1];
    }

    // In mảng C sau khi tích lũy giảm dần
    output(C.data(), range, 1);

    // Sắp xếp vào outputArr theo thứ tự giảm dần
    for (int i = arr.size() - 1; i >= 0; i--) {
        outputArr[C[arr[i] - min_val] - 1] = arr[i];
        C[arr[i] - min_val]--;
    }

    arr = outputArr;
}

int main() {
    vector<int> arr = {5, 12, 25, 4, 92, 61, 86, 123};

    cout << "Sắp xếp tăng dần:\n";
    countingSortAscending(arr);
    for (int num : arr) cout << num << " ";
    cout << "\n\n";

    vector<int> arr2 = {5, 12, 25, 4, 92, 61, 86, 123};

    cout << "Sắp xếp giảm dần:\n";
    countingSortDescending(arr2);
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}
