// https://onlinegdb.com/lOI8wLBG-N

/******************************************************************************
************ Bài tập lập trình C++ OOP - Bài 7.1 *****************************
********************** vunguyencoder.com **************************************

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std; // không dùng hàm này vì có thể tự tạo class trùng với cái có sẵn trong std ví dụ tạo class tên vector hay tạo phương thức count
class Vehicle
{
public:
    virtual void run() = 0;
};

class Car : public Vehicle
{
/* Noi dung can hoan thanh */
public:
    void run(){
        cout<<"A car is running...\n";
    }
};

class Pickup : public Vehicle
{
/* Noi dung can hoan thanh */
public:
    void run(){
        cout<<"A pickup is running...\n";
    }
};

class Motorbike : public Vehicle
{
/* Noi dung can hoan thanh */
public:
    void run(){
        cout<<"A Motorbike is running...\n";
    }
};

class Skateboard : public Vehicle
{
/* Noi dung can hoan thanh */
public:
    void run(){
        cout<<"A Skateboard is running...\n";
    }
};

class Person
{
/* Noi dung can hoan thanh */
public: 
    void setVehicle(vector<Vehicle*> vehicleList, int numofDays, vector<Vehicle*>& plan ){
        
        plan.resize(numofDays);
        int t=0;
        for(int i=0;i<plan.size();i++){
            if(t >= vehicleList.size()) // chú ý chỗ này
                t=0;
            plan[i]=vehicleList[t++];
        }

    }
    void drive(Vehicle* Vehicle){
        Vehicle->run();
    }
};

void solution(Person *person, std::vector<Vehicle*> vehicleList, int numOfDays)
{
/* Noi dung can hoan thanh */
// public: // trong void không có 
    
    vector<Vehicle*> plan; //chú ý chữ vehicle viết hoa V theo đúng tên lớp

    person->setVehicle(vehicleList,numOfDays,plan);

    for(int i=0;i<plan.size();i++){
        cout<<"Day "<<i+1<<" : ";
        person -> drive(plan[i]);
    }

}

int main()
{
    std::vector<Vehicle*> vehicleList;
    vehicleList.push_back(new Car());
    vehicleList.push_back(new Motorbike());
    vehicleList.push_back(new Pickup());
    Person* person = new Person;
    
    int numOfDays = 0;
    std::cout << "Enter number of days using vehicles: ";
    std::cin >> numOfDays;
    solution(person, vehicleList, numOfDays);
    
    std::cout << "\nAfter adding Skateboard vehicle:\n";
    vehicleList.push_back(new Skateboard());
    solution(person, vehicleList, numOfDays);
}


