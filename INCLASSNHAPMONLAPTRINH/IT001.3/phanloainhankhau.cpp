#include <iostream>
using namespace std;
int main(){
    int t;
    char s;
    cin>>t>>s;
    if(t>=21 and (s=='M'|| s=='m')){
        cout<<1;
    }
    else if(t>=21 and (s=='F'|| s=='f')){
        cout<<2;
    }
    else if (t<21 and (s=='M'|| s=='m')){
        cout<<3;
    }
    else if (t<21 and (s=='F'|| s=='f')) {
        cout<<4;
    }
    else{
        cout<<"I do not know why";
    }

    return 0;
}