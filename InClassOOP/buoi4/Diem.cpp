#include<iostream>

using namespace std;


class Diem{
public:
    Diem (){
        cout<<"Qua mon"<<endl;
    }
    ~Diem(){
        cout<<"That De dang"<<endl;
    }

};

int main(){

    Diem a;
    cout<<"Lap trinh huong doi tuong"<<endl;
    return 0;
}