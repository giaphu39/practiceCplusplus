#include<iostream>
using namespace std;

// tam giác dùng 3 cạnh xét 

//2 vector cùng phương thì không là tam giác, khi nhập tam giác phải kiểm tra người dùng nhập đúng hay sai, dùng do while, tư duy này rất cần cho lập trình viên
// không được đổ lỗi cho người dùng 

// nhập từng điểm 
// tịnh tiến tam giác thì tịnh tiến từng điểm
// phép quay trong tam giác

// tính chất dễ sử dụng: không gây khó khăn cho người dùng
// người dùng nhập độ sau đó mình chuyển sang radian để tính phép quay tam giác


// bài DaGiac cho tuần 3: làm như tam giác có các hàm như Tam giac nhưng không check điều kiện nhập như tam giac

class Point{
private:
    int iOx;
    int iOy;
public:
    Point(int Ox = 0,int Oy= 0) : iOx(Ox) , iOy(Oy){}
    void Nhap();
    void Xuat();

    int getOx();
    int getOy();

    void setPoint(int ox, int oy);
    void setOx(int ox);
    void setOy ( int oy);

    void moveThroughVector(int ox , int oy); // vector không được dùng Point 
};



int main(){
    Point a;
    a.Nhap();
    a.moveThroughVector(7,1);
    a.Xuat();

    return 0;
}

void Point::Nhap(){
    cin >> iOx >> iOy;
}

void Point::Xuat(){
    cout << "(" << iOx << "," << iOy << ")" << endl;
}

int Point::getOx(){
    return iOx;
}

int Point::getOy(){
    return iOy;
}

void Point::setPoint(int ox , int oy){
    iOx = ox;
    iOy = oy;
}

void Point::setOx(int ox){
    iOx = ox;
}

void Point::setOy( int oy){
    iOy = oy;
}

void Point::moveThroughVector(int ox, int oy){
    iOx += ox;
    iOy += oy;
}