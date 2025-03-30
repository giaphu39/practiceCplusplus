#include<iostream>
using namespace std;
int main(){
    int t;
    cout<<"What is the outdoor temperature?"<<endl;
    cin>>t;
    cout<<"What is your plan today?"<<endl;
    if(t>=33){
        cout<<"Good day for swimming"<<endl;
    }
    else if(t>=24){
        cout<<"Good day for golfing";
    }
    else if(t>=10){
        cout<<"Good day to play tennis";
    }
    else if(t<10){
        cout<<"Go to bed";
    }
    return 0;
}