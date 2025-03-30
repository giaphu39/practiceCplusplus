#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) cout<<"  ";//viết n-1 khoảng trắng
    cout<<"**"<<endl;//viết 1 dấu *
    for(int i = 2; i < n; i++){
        for(int j=0;j<n-i;j++) cout<<"  ";//viết n-1 khoảng trắng
        cout<<"**";//viết 1 dấu *
        for(int j=0;j<2*i-3;j++); cout<<"  ";//viết 2n-3 khoảng trắng
        cout<<"**"<<endl;//viết 1 dấu *
    }
    for(int i=0;i<2*n-1;i++) cout<<"**";//viết 2n-1 dấu *
    return 0;
}
