#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

// chỉnh mức thuế ở đây
#define TAX_BELOW_100CC 0.01
#define TAX_FROM_100CC_TO_200CC 0.03
#define TAX_ABOVE_200CC 0.05


class Vehicle
{
private:
    string sOwner;
    string sType;
    float fPrice;
    int iCapacity;
public:
    Vehicle(string Owner = "No Name", string Type = "No Type", float Price = 0, int Capacity = 0);
    void inputDetail();

    string getOwner();
    string getType();
    float getPrice();
    int getCapacity();

    void setOwner(string owner);
    void setType(string type);
    void setPrice(float price);
    void setCapacity(int capacity);

    float calculateTax();
    float calculateSumOfValue();

    void printDetail();
};

// có thể tạo một class quản lí các xe được bán ra thay vì dùng void này
void printDetailAllVehicle(Vehicle xe1, Vehicle xe2, Vehicle xe3);

int main(){

    Vehicle xe1("Peter Parker", "bicycle",3000000);
    Vehicle xe2("Elon Musk", "Lamborghini Urus", 13100000000, 3996);
    Vehicle xe3;
    xe3.inputDetail();
    
    printDetailAllVehicle(xe1,xe2,xe3);

    return 0;
}

Vehicle::Vehicle(string Owner , string Type , float Price , int Capacity) : sOwner(Owner), sType(Type) , fPrice(Price) , iCapacity(Capacity){}
void Vehicle::inputDetail(){
    cout << "vui long nhap vao chu so huu: ";
    getline(cin,sOwner);

    cout << "vui long nhap vao loai xe: ";
    getline(cin,sType);

    cout << "vui long nhap vao gia goc: ";
    cin >> fPrice;
    while(fPrice < 0){
        cout << "vui long nhap lai gia tien goc: ";
        cin >> fPrice;
    }

    cout << "vui long nhap vao dung tich xi lanh xe: ";
    cin >> iCapacity;
    while(iCapacity < 0){
        cout << "vui long nhap lai dung tich xi lanh xe: ";
        cin >> iCapacity;
    }
}


string Vehicle:: getOwner(){
    return sOwner;
}

string Vehicle:: getType(){
    return sType;
}

float Vehicle:: getPrice(){
    return fPrice;
}

int Vehicle::getCapacity(){
    return iCapacity;
}

void Vehicle::setOwner(string owner){
    sOwner = owner;
}

void Vehicle::setType(string type){
    sType = type;
}

void Vehicle::setPrice(float price){
    while(price < 0){
        cout << "vui long nhap lai gia tien goc: ";
        cin >> price;
    }
    fPrice = price;
}

void Vehicle::setCapacity(int capacity){
    while(capacity < 0){
        cout << "vui long nhap lai dung tich xi lanh xe: ";
        cin >> capacity;
    }
    iCapacity = capacity;
}

float Vehicle::calculateTax(){
    if(iCapacity < 100){
        return fPrice * TAX_BELOW_100CC;
    }

    else if(iCapacity <= 200){
        return fPrice * TAX_FROM_100CC_TO_200CC;
    }

    else if(iCapacity > 200){
        return fPrice * TAX_ABOVE_200CC;
    }

    else{
        cout << "khong the tinh duoc thue";
        return 0;
    }
}

float Vehicle::calculateSumOfValue(){
    return fPrice + calculateTax();
}

void Vehicle::printDetail(){
    cout << fixed << setprecision(0); // làm tròn xuống giá tiền nếu lẻ
    cout << left << setw(20) << getOwner();
    cout << left << setw(20) << getType();
    cout << left << setw(20) << getCapacity();
    cout << left << setw(20) << getPrice();
    cout << left << setw(20) << calculateTax();
    cout << left << setw(20) << calculateSumOfValue();
    cout << endl;
}

void printDetailAllVehicle( Vehicle xe1, Vehicle xe2, Vehicle xe3){
    cout << left << setw(20) << "Chu xe";
    cout << left << setw(20) << "Loai xe";
    cout << left << setw(20) << "Dung tich xi lanh";
    cout << left << setw(20) << "Gia goc";
    cout << left << setw(20) << "Gia thue";
    cout << left << setw(20) << "Gia mua vao";
    cout << endl;

    xe1.printDetail();
    xe2.printDetail();
    xe3.printDetail();
}