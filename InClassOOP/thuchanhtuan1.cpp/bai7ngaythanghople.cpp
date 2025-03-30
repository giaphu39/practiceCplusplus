#include<iostream>
#include<sstream>
using namespace std;
// int a[13];
// a[1]=a[3]=a[5]=a[7]=a[8]=a[10]=a[12] =31;
// a[4]=a[6]=a[9]=a[11] = 30 ;
// a[2]=28;
// sai phải để cái này trong hàm

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isNamNhuan(const int& nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(const int& thang, const int& nam){
    return a[thang] + (isNamNhuan(nam) && thang==2); 
}

struct Date{
    int ngay,thang,nam;
    string FullDate;

    // void Input(){
    //     cin.ignore(1);
    //     getline(cin,FullDate);
        
    //     string word;
    //     int i=0;
    //     int tusomay=1;
    //     while(i != FullDate.size()){
    //         if( FullDate[i] != ("/" || '/n')){
    //             word+=FullDate[i];
    //         }
    //         else{
    //             if(tusomay==1){
    //                 ngay= stoi(word);
    //                 word.clear();
    //             }
    //             if(tusomay==2){
    //                 thang= stoi(word);
    //                 word.clear();
    //             }
    //             if(tusomay==3){
    //                 nam= stoi(word);
    //                 word.clear();
    //             }

    //         }
    //         i++;
            
    //     }
    // }
    void Input() {
        getline(cin, FullDate);
        stringstream ss(FullDate);
        string word;
        char delim;
    
        ss >> ngay >> delim >> thang >> delim >> nam;
    }
    bool isValid() {
        if (thang < 1 || thang > 12) return false;
        if (ngay < 1 || ngay > SoNgayTrongThang(thang, nam)) return false;
        return true;
    }
};
void outputDate(Date ngayNhapVao){
    cout << ngayNhapVao.ngay<<" ";
    cout << ngayNhapVao.thang<<" ";
    cout << ngayNhapVao.nam;
}
int main(){

    Date d;
    cout << "Nhap ngay thang nam (dd/mm/yyyy): ";
    d.Input();
    
    if (d.isValid()) {
        cout << "Ngay hop le.\n";
    } else {
        cout << "Ngay khong hop le.\n";
    }
    outputDate(d);
    return 0;
}