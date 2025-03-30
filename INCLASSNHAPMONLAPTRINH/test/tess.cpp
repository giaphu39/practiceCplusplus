#include <iostream>
using namespace std;
int a=3;
int main(){   
    int a=5;
    {
        cout<<a;
        int a=7;
        cout<<a;
        cout<<::a;
        //làm sao để in ra 5 ở trong?
    }
    cout<<::a;

    return 0;

}
// Câu hỏi 5Trả lời

// a.
// int a(9);


// b.
// int a{9};


// c.
// int a[9];


// d.
// int a<9>