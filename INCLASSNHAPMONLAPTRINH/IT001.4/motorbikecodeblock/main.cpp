#include<iostream>
using namespace std;
#include<math.h>
int main(){
    float a,b,t,d,ans;
    cin>>a>>b>>t>>d;
    if((d/a)>=t){
        cout<<"NA";
       // cout<<"NA.";
    }
    else{
        float d2=a*t;
        ans=(d-d2)/(a+b);
        cout<<ans;
     }


    return 0;
}
