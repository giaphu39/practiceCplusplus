#include<iostream>
#include<sstream>
using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date{
    int ngay,thang,nam;
    string FullDate;

    void Input();
    bool isValid();
};

void GoToNextDay(Date& day);
bool isNamNhuan(const int& nam);
int SoNgayTrongThang(const int& thang, const int& nam);
bool isOverMonth(int ngay, int thang, int nam);
bool isOverYear(int ngay, int thang, int nam);
void SolveProblem(Date d);

int main(){

    Date d;

    d.Input();

    SolveProblem(d);

    return 0;
}

void SolveProblem(Date d){
    if (d.isValid()) {
        cout << "Ngay hop le.\n";
        GoToNextDay(d);
    } else {
        cout << "Ngay khong hop le.\n";
    }
}

bool isNamNhuan(const int& nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(const int& thang, const int& nam){
    return a[thang] + (isNamNhuan(nam) && thang==2); 
}

void Date::Input() {
    // cin.ignore();
    cout << "Nhap vao (ngay/thang/nam): ";
    getline(cin, FullDate);
    stringstream ss(FullDate);
    string word;
    char SpaceBetweenDate;

    ss >> ngay >> SpaceBetweenDate >> thang >> SpaceBetweenDate >> nam;
}
bool Date::isValid() {
    if (thang < 1 || isOverYear(ngay,thang, nam)) return false;
    if (ngay < 1 || isOverMonth(ngay, thang, nam)) return false;
    if (nam < 0) return false;
    return true;
}

bool isOverMonth( int ngay, int thang, int nam ){
    return ngay > SoNgayTrongThang(thang, nam);
}

bool isOverYear( int ngay, int thang, int nam ){
    return thang > 12;
}

void GoToNextDay(Date& day){
    day.ngay++;

    if(isOverMonth( day.ngay, day.thang, day.nam )){
        day.thang++;
        if(isOverYear(day.ngay, day.thang, day.nam)){
            day.nam++;
            day.thang=1;
            day.ngay=1;
        }

        else{
            day.ngay = 1;
            day.thang++;
        }
        
    }
    cout<<day.ngay<<"/"<<day.thang<<"/"<<day.nam;
}
