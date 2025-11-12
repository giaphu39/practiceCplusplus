#include<iostream>
#include <string>


using namespace std;

class VongDoi{
protected:
    int iSoGiaiDoan;
    int iGiaiDoan1;
    int iGiaiDoan2;
    int iGiaiDoan3;
    int iGiaiDoan4;
public:
    virtual void Nhap(){
        cout <<" nhap so giai doan cua con vat: ";
        cin >> iSoGiaiDoan;
        cout << "nhap thoi gian giai doan 1(theo ngay): ";
        cin >> iGiaiDoan1;
        cout << "nhap thoi gian giai doan 2(theo ngay): ";
        cin >> iGiaiDoan1;
        cout << "nhap thoi gian giai doan 3(theo ngay): ";
        cin >> iGiaiDoan1;
        cout << "nhap thoi gian giai doan 4(theo ngay): ";
        cin >> iGiaiDoan1;
    }

    virtual bool isTheoQuiLuat() = 0;
    virtual string getLoai() = 0;
    int getGiaiDoan1(){
        return iGiaiDoan1;
    }
};

class Muoi: public VongDoi{
public:
    bool isTheoQuiLuat(){
        if(iGiaiDoan1 < 1 || iGiaiDoan1 > 3) return 0;
        if(iGiaiDoan2 < 4 || iGiaiDoan2 > 10) return 0;
        if(iGiaiDoan3 < 2 || iGiaiDoan3 > 3) return 0;
        if(iGiaiDoan4 < 5 || iGiaiDoan4 > 8) return 0;
        return true;
    }

    string getLoai(){
        return "Muoi";
    }

};

class Ech: public VongDoi{
    int iGiaiDoan5;
public:
    void Nhap(){
        VongDoi::Nhap();
        cout <<  "nhap thoi gian giai doan 5(theo nam): ";
        cin >> iGiaiDoan5;
    }

    bool isTheoQuiLuat(){
        if(iGiaiDoan1 < 7 || iGiaiDoan1 > 21) return 0;
        if(iGiaiDoan2 < 28) return 0;
        if(iGiaiDoan3 < 6*7 || iGiaiDoan3 > 9*7) return 0;
        if(iGiaiDoan4 < 7 || iGiaiDoan4 > 28) return 0;
        if(iGiaiDoan5 < 2 || iGiaiDoan5 >4) return 0;
        return true;
    }

    string getLoai(){
        return "Ech";
    }

};

class Buom: public VongDoi{
public:
    bool isTheoQuiLuat(){
        if(iGiaiDoan1 < 3 || iGiaiDoan1 > 8) return 0;
        if(iGiaiDoan2 < 15 || iGiaiDoan2 > 16) return 0;
        if(iGiaiDoan3 == 10) return 0;
        if(iGiaiDoan4 < 2 || iGiaiDoan4 > 3) return 0;
        return true;
    }

    string getLoai(){
        return "Buom";
    }

};



int main(){
    int iSoConVat;
    cout << "Nhap so con vat:(1 <= N <= 20) ";
    cin >> iSoConVat;
    VongDoi** pDanhSach = new VongDoi*[iSoConVat];
    for(int i = 0 ; i < iSoConVat; i++){
        cout << "Nhap 1 la con Muoi, 2 la con Ech, 3 la con Buom: ";
        int temp; cin >> temp;
        if(temp == 1){
            pDanhSach[i] = new Muoi;
        }
        else if(temp == 2){
            pDanhSach[i] = new Ech;
        }
        else{
            pDanhSach[i] = new Buom;
        }

        pDanhSach[i]->Nhap();
    }

    cout << "nhung con vat khong tuan theo quy luat la con thu: ";
    for(int i = 0 ; i < iSoConVat ;i++){
        if(!pDanhSach[i]->isTheoQuiLuat()){
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "con Muoi co tong thoi gian phat trien tu trung thanh nhong (giai doan 1) dai nhat la con thu: ";
    int MAX = 0;
    int ind = -1;
    for(int i = 0 ; i < iSoConVat ;i++){
        if(pDanhSach[i]->getGiaiDoan1() > MAX){
            MAX = pDanhSach[i]->getGiaiDoan1();
            ind = i;
        }
    }

    if(ind == -1) cout << "NOTFOUND" <<endl;
    else cout << ind;

    return 0;
}