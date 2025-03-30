#include<iostream>

using namespace std;
#include<string>

struct Class
{
    int m_iSiSo;
    Student* m_SDanhSach;
    float m_fDTBChung;
};


struct Student
{
private:
    //thang điểm 0-10 nên dùng float
    string FullName;
    float MathPoint;
    float LiteraturePoint;
public:
    Student(string Ten ="Khong co ten", float diemToan = 0 , float diemVan = 0) : FullName(Ten), MathPoint(diemToan) , LiteraturePoint(diemVan){}
    
    float AveragePoint(); // hàm trả về giá trị trung bình
    string getFullName();
    void getInfo(); // hàm trả xuất thông tin học sinh
};

Student Input();
void InputList(Student *a, const int& n);
Student SearchMax(Student* a,const int& n);
Student* Init(int& n);
void Delete(Student* a);

int main()
{   
    int SoLuongStudent;
    Student* arr = Init(SoLuongStudent);
    InputList(arr, SoLuongStudent);
    SearchMax(arr,SoLuongStudent).getInfo();
    Delete(arr);
    return 0;
}


float Student::AveragePoint(){
    return (MathPoint + LiteraturePoint) / 2;
}

string Student::getFullName(){
    return FullName;
}
void Student::getInfo(){
    cout<<"hoc sinh:";
    cout<<FullName<<endl;
    cout<<AveragePoint();
}



Student Input()
{
    //do nhập nhiều cái nên phải dùng ignore vì các lần sau sẽ có /n
    cin.ignore(1);
    string s;
    getline(cin,s);
    float diemToan, diemVan;
    cin>>diemToan>>diemVan;
    return Student (s,diemToan,diemVan);
}
void InputList(Student *a, const int& n)
{
    for(int i=0;i<n;i++){
        a[i]=Input();
    }
}
Student SearchMax(Student* a,const int& n)
{
    //tránh truy cập giá trị âm
    unsigned int Max = 0;
    for(int i=1 ; i < n ; i++){       
        if(a[i].AveragePoint() > a[Max].AveragePoint()){
            Max = i;
        }
    }

    cout<<"Hoc sinh co diem trung binh cao nhat la";
    return a[Max];
}

Student* Init(int& n)
{
    cout<<"vui long nhap vao so luong học sinh: n=";
    // không dùng biến toàn cục để có thể tạo nhiều struct Student có số lượng hs khác nhau
    cin >> n;
    cout<<n<<endl;
    return new Student[n];
}

void Delete(Student* a){
    delete[] a;
}
