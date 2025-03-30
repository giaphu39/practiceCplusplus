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
    void Info(){
        cout<<FullName<<endl;
        // cout<<this->AveragePoint();
        //hoặc viết
        cout<<AveragePoint();
    }
};

Student Input(){
    //do nhập nhiều cái nên phải dùng ignore vì các lần sau sẽ có /n
    cin.ignore(1);
    string s;
    getline(cin,s);
    float diemToan, diemVan;
    cin>>diemToan>>diemVan;
    // return Student a(s,diemToan,diemVan); // sai khi return không được khai báo biến
    return Student (s,diemToan,diemVan);
}
void InputList(Student *a, int n){
    for(int i=0;i<n;i++){
        a[i]=Input();
    }
}
Student SearchMax(Student*a, int n){
    int Max = 0;
    for(int i=1 ; i < n ; i++){
        // if(Student[i].AveragePoint() > Student[Max].AveragePoint()){ // sai vì dùng tên class thay vì tên biến
        if(a[i].AveragePoint() > a[Max].AveragePoint()){
            Max = i;
        }
    }
    return a[Max];
}
int main(){
    // Student a = Input();
    // cout<<a.AveragePoint();
    // cout<<a.getFullName();
    int n;cin>>n;
    Student a[n];
    InputList(a, n);
    SearchMax(a,n).Info();
    return 0;
}