#include<iostream>
using namespace std;

int main(){
    char a,b;
    int x;
    cin>>a>>b>>x;
    cout<<"Ma ASCII cua ky tu '"<<a<<"',   '"<<b<<"' lan luot la "<<int(a)<<" va "<<int(b)<<endl;
    cout<<"Khoang cach giua hai ky tu '"<<a<<"',  '"<<b<<"' la "<<abs(int(a)-int(b))<<endl;
    cout<<"Dang viet hoa cua ky tu '"<<a<<"' la '"<<char(a-32)<<"'"<<endl;
    cout<<x<<" la ma ASCII cua ky tu '"<<char(x)<<"'";
    return 0;
}
