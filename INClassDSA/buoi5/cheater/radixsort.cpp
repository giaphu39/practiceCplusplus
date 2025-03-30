#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm lấy chữ số tại vị trí digit_pos (1: đơn vị, 10: chục, 100: trăm,...)
int getDigit(int num, int digit_pos) {
    return (num / digit_pos) % 10;
}

// Counting Sort theo hàng digit_pos, được sửa để sắp xếp GIẢM dần
void countingSort(vector<int> &arr, int digit_pos) {
    vector<int> output(arr.size());
    int count[10] = {0};

    // Đếm số lần xuất hiện của từng chữ số
    for (int num : arr) {
        count[getDigit(num, digit_pos)]++;
    }

    // Chuyển thành tổng tích lũy để sắp xếp giảm dần
    for (int i = 8; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    // Sắp xếp theo hàng digit_pos (giảm dần)
    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], digit_pos);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Gán lại mảng gốc
    arr = output;
}

// Hàm Radix Sort giảm dần
void radixSortDescending(vector<int> &arr) {
    int max_val = *max_element(arr.begin(), arr.end());

    // Lần lượt sắp xếp theo từng chữ số (đơn vị, chục, trăm,...)
    for (int digit_pos = 1; max_val / digit_pos > 0; digit_pos *= 10) {
        countingSort(arr, digit_pos);
        
        // In trạng thái sau mỗi lần sắp xếp
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i == arr.size() - 1 ? "\n" : "-");
        }
    }
}
// Counting Sort theo hàng digit_pos, sắp xếp TĂNG dần
void countingSortAscending(vector<int> &arr, int digit_pos) {
    vector<int> output(arr.size());
    int count[10] = {0};

    // Đếm số lần xuất hiện của từng chữ số
    for (int num : arr) {
        count[getDigit(num, digit_pos)]++;
    }

    // Chuyển thành tổng tích lũy để sắp xếp tăng dần
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Sắp xếp theo hàng digit_pos (tăng dần)
    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], digit_pos);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Gán lại mảng gốc
    arr = output;
}

// Radix Sort tăng dần
void radixSortAscending(vector<int> &arr) {
    int max_val = *max_element(arr.begin(), arr.end());

    // Lần lượt sắp xếp theo từng chữ số (đơn vị, chục, trăm,...)
    for (int digit_pos = 1; max_val / digit_pos > 0; digit_pos *= 10) {
        countingSortAscending(arr, digit_pos);
        
        // In trạng thái sau mỗi lần sắp xếp
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i == arr.size() - 1 ? "\n" : "-");
        }
    }
}

// Main function
int main() {
    vector<int> arr = {92, 12, 25, 5, 86, 4, 61, 123};
    radixSortAscending(arr);
    // radixSortDescending(arr);
    
    return 0;
}
