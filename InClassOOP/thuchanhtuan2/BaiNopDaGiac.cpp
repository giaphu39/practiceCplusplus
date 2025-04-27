#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// có thể điều chỉnh độ chính xác Pi tại đây
#define Pi 3.14

class Point{
private:
    float fOx;
    float fOy;
public:
    Point(int Ox = 0,int Oy= 0) : fOx(Ox) , fOy(Oy){}
    void inputPoint();
    void outputPoint();

    float getOx();
    float getOy();

    void setPoint(float ox, float oy);
    void setOx(float ox);
    void setOy ( float oy);

    void moveThroughVector(float ox , float oy); 
    Point tinhTienGocQuay(float degree);
    Point nhanHeSoK(float k);
};

class DaGiac{
private:
    int iSoDinh;
    Point* pPoints;
public:
    DaGiac(int SoDinh = 0, Point* Points = NULL);
    DaGiac(const DaGiac& obj);
    DaGiac& operator= (const DaGiac& obj);

    void InputDaGiac();
    void OutputDaGiac();

    int getSoDinh();
    Point& getPointAt(int Index);
    float getEdge(Point& PointA, Point& PointB);

    float calculateCircumstance();
    float calculateArea();

    DaGiac tinhTienDaGiac(float Ox, float Oy);
    DaGiac quayDaGiac(float degree);
    DaGiac phongToDaGiac(float heSoPhongTo);
    DaGiac thuNhoDaGiac(float heSoThuNho);

    ~DaGiac();

};

float chuyenTuDoSangRadian(float degree);



int main(){


    DaGiac HinhA;
    HinhA.InputDaGiac();

    // code minh họa chức năng
    cout << "chu vi hinh la:" << HinhA.calculateCircumstance() <<endl;
    cout << "dien tich cua hinh la: "<< HinhA.calculateArea()<<endl;

    DaGiac HinhB ( HinhA );

    HinhB.OutputDaGiac();
    cout <<"sau khi tinh tien B: " << endl;
    HinhB.tinhTienDaGiac(2,2);
    HinhB.OutputDaGiac();
    cout << endl;

    HinhA = HinhB;
    
    cout << "sau khi quay A: \n";
    HinhA.quayDaGiac(90);
    HinhA.OutputDaGiac();

    cout << endl;

    cout << "sau khi phong to A: \n";
    HinhA.phongToDaGiac(5);
    HinhA.OutputDaGiac();

    cout << endl;

    cout << "sau khi thu nho A: \n";
    HinhA.thuNhoDaGiac(1.0/6);
    HinhA.OutputDaGiac();


    return 0;
}



void Point::inputPoint(){
    cin >> fOx >> fOy;
}

void Point::outputPoint(){
    cout << setprecision(2) << "(" << fOx << "," << fOy << ")" << endl;
}

float Point::getOx(){
    return fOx;
}

float Point::getOy(){
    return fOy;
}

void Point::setPoint(float ox , float oy){
    fOx = ox;
    fOy = oy;
}

void Point::setOx(float ox){
    fOx = ox;
}

void Point::setOy(float oy){
    fOy = oy;
}

void Point::moveThroughVector(float ox, float oy){
    fOx += ox;
    fOy += oy;
}

Point Point::tinhTienGocQuay(float degree){
    float radian = chuyenTuDoSangRadian(degree);
    float x = fOx * cos(radian) - fOy * sin(radian);
    float y = fOx * sin(radian) + fOy * cos(radian);

    fOx = x;
    fOy = y;

    return *this;
}

Point Point::nhanHeSoK(float k){
    fOx *= k;
    fOy *= k;
    return *this;
}


DaGiac::DaGiac(int SoDinh, Point* Points): iSoDinh(SoDinh){
    while(SoDinh < 0){
        cout <<"SO DINH DANG AM VUI LONG NHAP LAI: ";
        cin >> iSoDinh;
    }

    if(Points == NULL){
        pPoints = NULL;
    }
    else{
        pPoints = new Point[iSoDinh];

        for(int i = 0 ; i < iSoDinh ; i++){
            pPoints[i] = Points[i];
        }
    }
}

DaGiac::DaGiac(const DaGiac& obj){
    iSoDinh = obj.iSoDinh;
    pPoints = new Point[iSoDinh];

    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i] = obj.pPoints[i];
    }

}

DaGiac& DaGiac:: operator= (const DaGiac& obj){
    if (this == &obj) return *this; 

    iSoDinh = obj.iSoDinh;
    if(pPoints != NULL){
        delete [] pPoints;
    }
    pPoints = new Point[iSoDinh];

    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i] = obj.pPoints[i];
    }

    return *this;
}

void DaGiac::InputDaGiac(){
    cin >> iSoDinh;
    while(iSoDinh < 3){
        cout <<"DA GIAC KHONG HOP LE VUI LONG NHAP LAI SO DINH:  ";
        cin >> iSoDinh;
    }
    pPoints = new Point[iSoDinh];
    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i].inputPoint();
    }
}


void DaGiac::OutputDaGiac(){
    if(pPoints == NULL){
        cout << "DA GIAC RONG" << endl;
        return; 
    }
    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i].outputPoint();
    }
}

int DaGiac::getSoDinh(){
    return iSoDinh;
}

Point& DaGiac::getPointAt(int Index){
    if(Index < 0 || Index >= iSoDinh){
        cout << "TRUY XUAT KHONG HOP LE" << endl;

        return pPoints[0];
    }
    return pPoints[Index];
}

float DaGiac::getEdge(Point& PointA, Point& PointB){ 
    return sqrt(pow(PointA.getOx() - PointB.getOx(), 2) + pow(PointA.getOy() - PointB.getOy(), 2));

}

float DaGiac::calculateCircumstance(){
    float sum = 0;
    for(int i = 0; i < iSoDinh - 1 ; i++){
        sum += getEdge(pPoints[i], pPoints[i+1]);
    }
    sum += getEdge(pPoints[iSoDinh - 1], pPoints[0]);
    return sum;
}

float DaGiac::calculateArea(){
    float tich = 1.0 / 2;
    float sumOfPoint = 0;

    for(int i = 0; i < iSoDinh - 1 ; i++){
        sumOfPoint += pPoints[i].getOx() * pPoints[i + 1].getOy() - pPoints[i + 1].getOx() * pPoints[i].getOy();
    }
    sumOfPoint += pPoints[iSoDinh - 1].getOx() * pPoints[0].getOy() - pPoints[0].getOx() * pPoints[iSoDinh - 1].getOy();

    return tich * abs(sumOfPoint);
}

DaGiac DaGiac::tinhTienDaGiac(float Ox , float Oy){
    for(int i = 0; i < iSoDinh ; i++){
        pPoints[i].moveThroughVector(Ox , Oy);
    }

    return *this;
}

DaGiac DaGiac::quayDaGiac(float degree){
    for(int i = 0; i < iSoDinh ; i++){
        pPoints[i].tinhTienGocQuay(degree);
    }

    return *this;
}

DaGiac DaGiac::phongToDaGiac(float heSoPhongTo){
    if(heSoPhongTo == 1){
        return *this;
    }
    while(heSoPhongTo <1){
        cout << "VUI LONG NHAP LAI HE SO PHONG TO: ";
        cin >> heSoPhongTo;
    }

    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i].nhanHeSoK(heSoPhongTo);
    }

    return *this;
}

DaGiac DaGiac::thuNhoDaGiac(float heSoThuNho){
    if(heSoThuNho == 1){
        return *this;
    }
    while(heSoThuNho <= 0 || heSoThuNho > 1){ 
        cout << "VUI LONG NHAP LAI HE SO PHONG TO: ";
        cin >> heSoThuNho;
    }

    for(int i = 0 ; i < iSoDinh ; i++){
        pPoints[i].nhanHeSoK(heSoThuNho);
    }

    return *this;
}

DaGiac:: ~DaGiac(){
    if(pPoints != NULL){
        delete[] pPoints;
    }
}

float chuyenTuDoSangRadian(float degree){
    return degree * Pi / 180;
}








