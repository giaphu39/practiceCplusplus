#include<iostream>

using namespace std;
#include<string>

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


struct Class
{
private:
    int m_iSiSo;
    Student* m_SDanhSach = NULL;
    float m_fDTBChung;
    float m_fDTBMax;
public:
    void nhapDSLop();
    void xuLiSoLieu();
    float CalculateDTBchung();
    float CalculateDTBMax();
    void xuatHSCoDTBMAX();
    void xuatHSDuoiDTBChung();
    void destructor();

};



Student Input();

int main()
{   Class lophoc;
    lophoc.nhapDSLop();
    lophoc.xuLiSoLieu();

    lophoc.xuatHSCoDTBMAX();
    lophoc.xuatHSDuoiDTBChung();

    lophoc.destructor();

    return 0;
}



float Student::AveragePoint(){
    return (MathPoint + LiteraturePoint) / 2;
}

string Student::getFullName(){
    return FullName;
}

void Student::getInfo(){
    cout<<"hoc sinh: ";
    cout<<FullName<<endl;
    cout<<"Diem trung binh: ";
    cout<<AveragePoint()<<endl;
    cout<<endl;
}

Student Input()
{
    //do nhập nhiều cái nên phải dùng ignore vì các lần sau sẽ có /n
    cin.ignore(1);
    string s;
    getline(cin,s);
    float diemToan, diemVan;
    cin>>diemToan;
    while(diemToan < 0 || diemToan > 10){
        cout << "nhap lai diem Toan:";
        cin >> diemToan;
        cout<<endl;
    }
    cin >> diemVan;
    while(diemVan < 0 || diemVan >10){
        cout << "nhap lai diem Van:";
        cin >> diemVan;
        cout << endl;
    }
    return Student (s,diemToan,diemVan);
}

void Class::nhapDSLop(){
    while(true){
        int temp;
        cin >> temp;
        if(temp < 0) cout << "vui long nhap lai so hoc sinh:"; // không được nhập số học sinh là âm
        else{
            m_iSiSo = temp;
            break;
        }
    }
    if(!m_iSiSo){ // nếu sỉ số = 0 thì không nhập gì cả
        cout<<"Lop nay khong co hoc sinh"<<endl;
        return;
    }
    m_SDanhSach = new Student[m_iSiSo];

    for(int i = 0 ; i < m_iSiSo ; i++){
        m_SDanhSach[i] = Input();
    }
}

void Class::xuLiSoLieu(){
    m_fDTBChung = CalculateDTBchung();
    m_fDTBMax = CalculateDTBMax();
}

float Class::CalculateDTBchung(){
    float DTBchung = 0;
    for(int i = 0; i < m_iSiSo; i++){
        DTBchung += m_SDanhSach[i].AveragePoint();
    }
    return DTBchung / m_iSiSo;
}
float Class::CalculateDTBMax(){
    float DTBMax = 0;
    for(int i = 0; i < m_iSiSo; i++){
        if(m_SDanhSach[i].AveragePoint() > DTBMax){
            DTBMax = m_SDanhSach[i].AveragePoint();
        }
    }
    return DTBMax;
}

void Class::xuatHSCoDTBMAX(){

    bool isPrinted =0;
    cout<<"Danh sach hoc sinh co diem cao nhat la:"<<endl;
    for(int i = 0; i < m_iSiSo; i++){
        if(m_SDanhSach[i].AveragePoint() == m_fDTBMax){
            isPrinted = 1;
            m_SDanhSach[i].getInfo();
        }
    }

    if(!isPrinted) cout << "khong co";
    cout<<endl;
}

void Class::xuatHSDuoiDTBChung(){

    bool isPrinted =0;
    cout<<"Danh sach hoc sinh duoi diem trung binh chung la:"<<endl;
    for(int i = 0; i < m_iSiSo; i++){
        if(m_SDanhSach[i].AveragePoint() < m_fDTBChung){ // nếu bằng điểm trung bình chung thì vẫn chấp nhận là trên ĐTB chung
            isPrinted = 1;
            m_SDanhSach[i].getInfo();
        }
    }
    if(!isPrinted) cout << "khong co";
    cout<<endl;
}

void Class::destructor(){ // không dùng destructor trực tiếp vì Lớp là database không nên tự xóa khi kết thúc chương trình
    delete[] m_SDanhSach;
    m_SDanhSach = nullptr;
}