#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
class Rectangle{
private:
    double width;
    double height;
    string color;


public:
    Rectangle(){}
    Rectangle(double width, double height, string color){
        this->width=width;
        this->height=height;
        this->color=color;
    }
    double getWidth(){
        return width;
    }
    void setWidth(double width){
        this->width=width;
    }
    double getHeight(){
        return height;
    }
    void setHeight(double height){
        this->height=height;
    }
    string getColor(){
        return color;
    }
    void setColor(string color){
        this->color=color;
    }
    double findArea(){
        return height*width;
    }

    double findPerimeter(){
        return (height+width)*2;
    }

    bool check(){
        // int flag=0 //co check hop le

        if(height<=0 or width<=0) return false;
        else return true;
    }

    void output(){
        if(!check()) cout<<"INVALID";
        else cout<<findPerimeter()<<" "<<findArea()<<" "<<color;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double a,b;cin>>a>>b;
    string c;cin>>c;
    // Rectangle(a,b,c) hcn; //sai cu phap
    
    Rectangle hcn(a,b,c);
    hcn.output();
    return 0;
}
