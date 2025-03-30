#include <iostream>
#include<math.h>
using namespace std;

int main()
{ //có trường hợp xe máy khởi hành cùng lúc
    float a,b,t,d;
    cin>>a>>b>>t>>d;
    if(a*t>=d){
        cout<<t<<":00";
    }
    else if(a==0 and b==0){
        cout<<"NA";
    }
    else if((d==0)){
        cout<<"NA";
    }
    else if(a==0 or b==0){
        cout<<"NA";
    }
    else if(t==0 and (a==0 and b==0)){
        cout<<"NA";
    }
    // if(a*t<d){
    else{
        float d2=a*t;
        float d3=d-d2;
        float ans=d3/(a+b);
        //cout<<ans<<endl;
        int ans1=ans;
        //cout<<ans1<<endl;
        ans=round((ans-ans1)*60);
        // cout<<ans<<endl;
        // cout<<t+ans1<<":"<<ans;

        //test case 10 10 1 300
        if(ans<10){
            cout<<t+ans1<<":0"<<ans;
        }
        else{
            cout<<t+ans1<<":"<<ans;
        }
// thiếu trường hợp 2:00
    }
    // else{
    //     cout<<"NA";
    // }
    return 0;
}