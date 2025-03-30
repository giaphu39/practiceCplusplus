#include <iostream>
using namespace std;
int main(){
    float a,b,c;
    cin>>a>>b>>c;
    if(a==0){
        if(b==c){
            cout<<"Infinitely many solutions";
        }
        else{
            cout<<"No solution";
        }

    }
    else{
        cout<<(c-b)/a;
    }
    return 0;
}