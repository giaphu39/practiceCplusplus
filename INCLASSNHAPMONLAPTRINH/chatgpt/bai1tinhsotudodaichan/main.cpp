#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    getline(cin,a);
    int j=0;
    int count1=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==' '){
            if((i-j)%2==0) count1++;
            j=i+1;
        }
    }
    cout<<count1;
    return 0;
}
