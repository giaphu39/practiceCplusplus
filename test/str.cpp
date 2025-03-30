#include<iostream>
#include <string.h>
using namespace std;

int main(){

    string a;
    string b;
    cin>>a>>b;
    string c=a+b;
    cout<<c<<endl;
    cout<<c.size()<<endl;
    cout<<c.find(b);
    return 0;
}