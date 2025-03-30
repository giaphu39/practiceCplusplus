#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX = 200;

void input(int a[], int& n) {
    cin >> n;
    srand(time(0));

    int len = 0; // Số phần tử hiện có trong mảng
    for (int i = 0; i < n; i++) {
        int val = rand() % 100; // Sinh số ngẫu nhiên từ 0 đến 99
        
        // Tìm vị trí chèn bằng tìm kiếm nhị phân
        int pos = lower_bound(a, a + len, val) - a;

        // Dịch các phần tử để chèn vào đúng vị trí
        for (int j = len; j > pos; j--) {
            a[j] = a[j - 1];
        }
        a[pos] = val;
        len++;
    }
}

void output(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Find01(const int a[], int n, int x) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            cout << mid << endl;
            return;
        }
        if (x < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "NotFound" << endl;
}

int main() {
    int a[MAX], n;
    input(a, n);
    output(a, n);

    int x;
    cin >> x;
    Find01(a, n, x);

    return 0;
}
