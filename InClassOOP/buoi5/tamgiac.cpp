#include<iostream>
#include<cmath>
using namespace std;

class Diem{
private:
    float x;
    float y;
public:
    // Diem(int x = 0 , int y = 0){ //
    //     this->x = x;
    //     this->y = y;
    // }

    Diem(int x1 = 0 , int y1 = 0) : x(x), y(y) {}

    float khoangCach(Diem x2){
        return sqrt((x - x2.x) * (x - x2.x) + (y - x2.y) * (y - x2.y));
    }

    float khoangCachdenO(){
        Diem O(0,0);
        return khoangCach(O);
    }

    void printDiem(){
        cout<<"("<< x <<"," << y<<")" <<endl;
    }


    float GetX(){
        return x;
    }

    void SetX(float xO){
        x = xO;
    }

    // hoàn toàn kiểm soát được người dùng thực hiện như thế nào ( xây dựng thành hàm thay vì tất cả dùng public)
    // => nguyên tắc đóng gói
    // có thể bằng cách thêm điều kiện
    int SetY(float xO){
        if(xO >= 0){
            x = xO;
            return 1;
        }
        else{
            return -1;
        }
    }
};

// phương thức truy vấn thì dùng động từ Get 
//phương thức cập nhật tiền tố Set

// phương thức điều kiện có tiền tố is




class TamGiac{
    Diem A, B, C;
    public:
    TamGiac(double xA, double yA, double xB, double yB,
    double xC, double yC) : A(xA,yA), B(xB,yB),C(xC,yC){
    cout<<"khoi tao tam giac";
    }

};


int main(){

    Diem A(2,4); // khi đối tượng được tạo ra 
    A.printDiem();
    cout << A.khoangCachdenO();

    return 0;
}