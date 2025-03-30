#include <iostream>
#include<string>
#include<sstream>
#include<climits>
using namespace std;
int* b= new int[10000](); //phải đặt vậy để tất cả phần tử bằng 0, vì đây ko phải mảng mà là con trỏ
int main()
{
    int* a= new int[10000];
    int n;int z=0;
//    int* b= new int[10000]; // sai vì các giá trị ko được gán sẽ là rác
    int maxv=INT_MIN;
    int minv=INT_MAX;
    while(cin>>n){
        a[z++]=n;
    }
    for(int i=0;i<z;i++){
        b[a[i]]++;
        if(a[i]>maxv) maxv=a[i];
        if(a[i]<minv) minv=a[i];
    }
    int cntmax=INT_MIN;
    int flag;
    for(int i=minv;i<=maxv;i++){
        if(b[i]>cntmax){
            cntmax=b[i];
            flag=i;
        }
    }
    cout<<flag<<":"<< b[flag]<<"lan";
    delete[]a;
    delete[] b;

    return 0;
}
