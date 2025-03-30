#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string thuTrongTuan[7] = { "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay" };

int numberDaysOfMonth[13] = {0,
    31, // tháng 1
    28, // tháng 2
    31, // tháng 3
    30, // tháng 4
    31, // tháng 5
    30, // tháng 6
    31, // tháng 7
    31, // tháng 8
    30, // tháng 9
    31, // tháng 10
    30, // tháng 11
    31, // tháng 12
};

struct Date{
    string m_sFullDate;
    int m_iDay;
    int m_iMonth;
    int m_iYear;
    bool isTCN; // trước công nguyên hay không
    bool isValid; // kiểm tra ngày nhập vào hợp lệ không nếu không hợp lệ thì không in thứ 
    int dayOnWeek; // thứ trong tuần

    Date(){}
    Date(string ngayNhapVao) :  m_sFullDate(ngayNhapVao){}
};

bool isNamNhuan(const int& nam);
int SoNgayTrongThang(const int& thang, const int& nam);
bool isOverMonth(const int& ngay, const int& thang, const int& nam);
bool isOverYear(const int& ngay, const int& thang, const int& nam);
bool isValid(const int& ngay, const int& thang, const int& nam);

void processDate(Date& ngayNhapVao);
Date inputDate();
void outputDate(Date ngayNhapVao); 

unsigned int tinhSoNgayDen1_1_1(const int& ngay, const int& thang, const int& nam);
unsigned int tinhSoNgayGiuaHaiNgay(Date ngayNhapVao);
int tinhThuTrongTuan(Date ngayNhapVao);



int main(){
    // Hướng dẫn sử dụng:
    // nếu người dùng nhập vào kí tự lạ, kí tự đặc biệt hoặc không đúng định dạng chúng tôi yêu cầu thì là lỗi của người dùng
    // chương trình chỉ chấp nhận cho nhập lại ngày nếu đúng định dạng
    Date ngayNhapVao = inputDate();
    
    outputDate(ngayNhapVao);
    
    return 0;
}



bool isNamNhuan(const int& nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(const int& thang, const int& nam){
    return numberDaysOfMonth[thang] + (isNamNhuan(nam) && thang == 2); 
}

bool isOverMonth( const int& ngay, const int& thang, const int& nam ){
    return ngay > SoNgayTrongThang(thang, nam);
}

bool isOverYear( const int& ngay, const int& thang, const int& nam ){
    return thang > 12;
}

bool isValid(const int& ngay , const int& thang, const int& nam) {
    if (thang < 1 || isOverYear(ngay,thang, nam)) return false;
    if (ngay < 1 || isOverMonth(ngay, thang, nam)) return false;
    if (nam < 1) return false; // định dạng năm âm là sai không tính là trước công nguyên
    return true;
}

void processDate(Date& ngayNhapVao){ 
    stringstream ss(ngayNhapVao.m_sFullDate);

    char spaceBetweenDate;
    string fullYear;

    ss >> ngayNhapVao.m_iDay >> spaceBetweenDate >> ngayNhapVao.m_iMonth >> spaceBetweenDate;
    getline(ss, fullYear);
    
    //xử lí trước công nguyên
    if(fullYear.find("TCN") != string::npos){
        fullYear.erase(fullYear.find("TCN") , 3);
        ngayNhapVao.isTCN = 1;
        
    }
    else{
        ngayNhapVao.isTCN = 0;
    }
    ngayNhapVao.m_iYear = stoi(fullYear);

    ngayNhapVao.isValid = isValid(ngayNhapVao.m_iDay , ngayNhapVao.m_iMonth , ngayNhapVao.m_iYear);

}

Date inputDate()
{
    Date ngayNhapVao;

    cout<<"vui long nhap (ngay/thang/nam) vao:";
    getline(cin,ngayNhapVao.m_sFullDate);

    processDate(ngayNhapVao);

    while(!ngayNhapVao.isValid){
        cout << endl;
        cout<<"ngay nhap vao khong hop le vui long nhap lai:";
        cin.ignore();
        getline(cin,ngayNhapVao.m_sFullDate);
        processDate(ngayNhapVao);
    }


    return ngayNhapVao;

}

void outputDate(Date ngayNhapVao)
{
    if(!ngayNhapVao.isValid){
        cout<<" la ngay khong hop le";
    }
    
    else{
        if(ngayNhapVao.isTCN){
            cout<<" ngay hop le nhung khong tinh duoc thu truoc cong nguyen";
        }
        else{
            ngayNhapVao.dayOnWeek = tinhThuTrongTuan(ngayNhapVao);
            cout<<" la ngay ";
            cout << thuTrongTuan[ngayNhapVao.dayOnWeek];
        }
    }
}

unsigned int tinhSoNgayDen1_1_1(const int& ngay, const int& thang, const int& nam){
    unsigned int tongSoNgay = 0;

    for(int i = 1; i < nam; i++){
        tongSoNgay += isNamNhuan(i) ? 366 : 365;  
    }

    for(int i = 1; i < thang ; i++){
        tongSoNgay += SoNgayTrongThang(i,nam);
    }

    tongSoNgay += ngay;

    return tongSoNgay;
}

unsigned int tinhSoNgayGiuaHaiNgay(unsigned int daysFromStartToBaseDay, unsigned int daysFromStartToSelectedDay){
    unsigned int differentDayOfBaseDayAndSelectedDay;

    if(daysFromStartToBaseDay >= daysFromStartToSelectedDay){
        differentDayOfBaseDayAndSelectedDay = daysFromStartToBaseDay - daysFromStartToSelectedDay;
    }
    else{
        differentDayOfBaseDayAndSelectedDay = daysFromStartToSelectedDay - daysFromStartToBaseDay;
    }

    return differentDayOfBaseDayAndSelectedDay;
}

int tinhThuTrongTuan(Date ngayNhapVao){
    Date baseDay("23/3/2025"); // khi muốn đổi baseday thì chỉnh dòng này và dòng dưới
    baseDay.dayOnWeek = 0; // nhập vào thứ của ngày làm gốc thường lấy từ ngày mình biết đó là thứ mấy 
    // không nên làm hàm nhập ngày gốc vì đây là ngày mà lập trình viên chọn ra người dùng không cần quan tâm
    processDate(baseDay); 
    

    unsigned int daysFromStartToBaseDay = tinhSoNgayDen1_1_1(baseDay.m_iDay, baseDay.m_iMonth , baseDay.m_iYear);
    unsigned int daysFromStartToSelectedDay = tinhSoNgayDen1_1_1(ngayNhapVao.m_iDay, ngayNhapVao.m_iMonth , ngayNhapVao.m_iYear);

    bool ngayNhapVaoLonHonBaseDay;
    
    unsigned int soNgayChenhLech = tinhSoNgayGiuaHaiNgay(daysFromStartToSelectedDay , daysFromStartToBaseDay);

    if(daysFromStartToSelectedDay > daysFromStartToBaseDay){
        return baseDay.dayOnWeek + soNgayChenhLech % 7;
    }
    else{
        return (baseDay.dayOnWeek - soNgayChenhLech % 7 + 7) % 7;
    }
}
