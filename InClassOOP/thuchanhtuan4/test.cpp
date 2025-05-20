#include<iostream>

using namespace std;

int main(){

    int a = 2;
    // (a++) = 6; // lỗi vì là giá trị trước đó
    (++a) = 7;
    cout << a;

    return 0;
}
