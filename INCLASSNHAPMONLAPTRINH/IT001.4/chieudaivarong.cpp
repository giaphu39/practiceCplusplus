#include <iostream>
#include<math.h>
using namespace std;
float giai(float s,float p){
    float a,b,c;
    a=-1;
    b=p/2.0;
    c=-s;
    float delta;
    delta=b*b -4*a*c;
    if(a==0){
        return -c/b;
    }
    else if(delta>0){
        float x1,x2;
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        return max(x1,x2);
    }
    else if(delta==0){
        return -b/(2*a);
    }
    else if(delta<0){
        return -100;
    }
}
int main()
{
    float s,p,x1,x2;
    cin>>s>>p;
    x2=giai(s,p);
    x1=p/2.0 -x2;
    // if(x1<=0 or x2<=0){
    //     cout<<"NA";
    // }
    if(x1>0 and x2>0){
        cout<<max(x1,x2)<<" ";
        cout<<min(x1,x2)<<endl;
    }
    //trường hợp 0 0 vẫn cho ra 0 0
    else if(s==0 and p==0){
        cout<<0<<" "<<0;
    }
    else{
        cout<<"NA";
    }
    return 0;
}