
#include <iostream>

using namespace std;

class cNgay{
private:
    int ngay,thang, nam;
public:
    cNgay(int y = , int m = 1, int d = 1) : nam(y),thang(m), ngay(d){}
    void xuat(){
        cout << ngay << "/" << thang <<"/" << nam << endl;
    }
    void nhap(){
        cin >> nam >> thang >> ngay;
    }

    bool isBefore(cNgay a){
        if(nam < a.nam) return true;
        if( nam == a.nam && thang < a.thang ) return true;
        if( nam == a.nam && thang == a.thang && ngay < a.ngay) return true;

        return false;
    }
};



int main(){
    cNgay ng1;
    cNgay ng2(2017,1);
    cNgay ng3(2017,1,7);

    ng1.nhap();
    ng1.xuat();


    if (ng1.isBefore(ng2))
    cout << "Dung" << endl;
    else
    cout << "Sai" << endl;

    return 0;
}