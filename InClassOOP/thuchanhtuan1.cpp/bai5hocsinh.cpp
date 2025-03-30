#include<iostream>

using namespace std;
#include<string>

class Student{
private:
    string FullName;
    float MathPoint;
    float LiteraturePoint;
public:
    Student(string Ten ="Không có tên", float diemToan = 0 , float diemVan = 0) : FullName(Ten), MathPoint(diemToan) , LiteraturePoint(diemVan){}
    // friend float AveragePoint(){
    //     return (MathPoint + LiteraturePoint) / 2;
    // }
    //sai vì hàm bạn được xem như hàm bên ngoài có thể truy cập biến trong class nhưng phải có tham số truyền vào
    float AveragePoint(){
        return (MathPoint + LiteraturePoint) / 2;
    }

    string getFullName(){
        return FullName;
    }
};

Student Input(){
    string s;
    getline(cin,s);
    float diemToan, diemVan;
    cin>>diemToan>>diemVan;
    // return Student a(s,diemToan,diemVan); // sai khi return không được khai báo biến
    return Student (s,diemToan,diemVan);
}

int main(){
    Student a = Input();
    cout<<a.AveragePoint();
    cout<<a.getFullName();

    return 0;
}