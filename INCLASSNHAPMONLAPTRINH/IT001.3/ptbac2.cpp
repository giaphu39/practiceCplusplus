// // Write your code here
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     float a, b ,c;
//     cin>>a>>b>>c;
//     float delta;
//     delta=b*b -4*a*c;
//     if(delta>0){
//         float x1,x2;
//         x1=(-b+sqrt(delta))/(2*a);
//         x2=(-b-sqrt(delta))/(2*a);
//         cout<<"PT co hai nghiem phan biet:"<<endl;
//         cout<<"x1 = "<<x1<<endl;
//         cout<<"x2 = "<<x2<<endl;
//     }
//     else if(delta==0){
//         cout<<"PT co nghiem kep: x1 = x2 = "<<-b/(2*a);
//     }
//     else{
//         cout<<"PTVN";
//     }
//     return 0;
// }
// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main(){
    float a, b ,c;
    cin>>a>>b>>c;
    float delta;
    delta=b*b -4*a*c;
    if(a==0 and c==0 and b==0){
        cout<<"Infinitely many solutions";
    }
    else if(a==0){
        cout<<-c/b;
    }
    else if(delta>0){
        float x1,x2;
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        
        cout<<x2<<endl;
        cout<<x1<<endl;
    }
    else if(delta==0){
        cout<<-b/(2*a);
    }
    else{
        cout<<"No solution";
    }
    return 0;
}