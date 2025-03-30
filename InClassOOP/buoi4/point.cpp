#include<iostream>


using namespace std;

class Point{
private:
    float x;
    float y;

public: // hàm ở main gọi được public
    void input();
    void output();
    void moveVector(float a, float b);
    void calculateRange();
};

int main(){
    Point a;
    a.input();
    a.moveVector(7,5);
    a.output(); 

}

void Point::input(){
    cin>>x;
    cin>>y;

}
void Point::output(){
    cout<<x;
    cout<<y;
}

void Point::moveVector(float a, float b){
    x+=a;
    y+=b;
}