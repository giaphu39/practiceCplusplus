#include <bits/stdc++.h>

using namespace std;
double dodai(int a, int b){
    return sqrt(a*a + b*b);


}
int main()
{
    int n;

    cin>>n;
    int*a = new int[n];
    int *b= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    double ans=0;
    for(int i=0;i<n;i++){

        ans+=dodai(a[i],b[i]);
    }
    cout<<round(ans*100)/100; // round chỉ cho 1 giá trị là về số nguyên
    // ghi dòng này sẽ lấy đc 2 chữ số sau thập phân
    delete[] a;
    delete[] b;
    return 0;
}
