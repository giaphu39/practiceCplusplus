#include<bits/stdc++.h>

using namespace std;

double RandomDouble() {
    srand(time(NULL));
    return static_cast<double>(rand()) / RAND_MAX;
}

class Virus{
protected:
    double dMucDoNhiem;
public:
    Virus(){
        dMucDoNhiem = RandomDouble();
    }
    virtual void InTrieuChungNhe()=0;
    virtual void InTrieuChungNang()=0;
    virtual double getTuVong()=0;
    virtual string getLoai()=0;
    double getMucDoNhiem(){return dMucDoNhiem;}
};

class Corona:public Virus{
    void InTrieuChungNhe(){
        cout << "cam cum thong thuong....roi khoi\n"; // dùng \n để ghi nhanh và dùng void thay vì string cho lẹ hơn
    }
    void InTrieuChungNang(){
        cout <<"sot cao... ben trong\n";
    }
    double getTuVong(){
        return 0.04;
    }
    string getLoai(){
        return "Corona";
    }
};


class Ebola:public Virus{
    void InTrieuChungNhe(){
        cout << "cam cum thong thuong....roi khoi\n"; // dùng \n để ghi nhanh và dùng void thay vì string cho lẹ hơn
    }
    void InTrieuChungNang(){
        cout <<"sot cao... ben trong\n";
    }
    double getTuVong(){
        return 0.5;
    }
    string getLoai(){
        return "Ebola";
    }
};

class HIV:public Virus{
    void InTrieuChungNhe(){
        cout << "cam cum thong thuong....roi khoi\n"; // dùng \n để ghi nhanh và dùng void thay vì string cho lẹ hơn
    }
    void InTrieuChungNang(){
        cout <<"sot cao... ben trong\n";
    }
    double getTuVong(){
        return 0.9;
    }
    string getLoai(){
        return "HIV";
    }
};

class MienDich{
    bool isVacine;
    int iLoai;
public:
    MienDich(bool daTiem = 0) : isVacine(daTiem) {}
    void Nhap(){
        cout <<"Nhap loai mien dich: 1 la cao, 2 la trung binh, 3 la thap   ";
        cin >> iLoai;
        cin.ignore();
    }
    // 1 la ko trieu chung,2 la nhe , 3 la nang
    int getLoaiTrieuChung(double nhiem){
        if(isVacine){
            if(iLoai == 1){
                if(nhiem <= 0.7) return 1;
                else if(nhiem <= 0.95) return 2;
                else return 3;
            }
            if(iLoai ==2) {
                if(nhiem <= 0.2) return 1;
                else if(nhiem <= 0.7) return 2;
                else return 3;
            }
            else{
                if(nhiem <= 0.1) return 1;
                else if(nhiem <= 0.5) return 2;
                else return 3;
            }
        }
        else{
            if(iLoai == 1){
                if(nhiem <= 0.5) return 1;
                else if(nhiem <= 0.85) return 2;
                else return 3;
            }
            if(iLoai ==2) {
                if(nhiem <= 0.1) return 1;
                else if(nhiem <= 0.5) return 2;
                else return 3;
            }
            else{
                if(nhiem <= 0.05) return 1;
                else if(nhiem <= 0.2) return 2;
                else return 3;
            }
        }
    }
    double getTuVong(){
        if(isVacine){
            if(iLoai ==1 ) return 0.4;
            else if(iLoai == 2) return 0.6;
            else return 0.8;
        }
        else{
            if(iLoai ==1 ) return 0.5;
            else if(iLoai == 2) return 0.7;
            else return 1;
        }
    }
};

class VatChu{
    string sMaSo;
    Virus* VirusNhiem[3];
    MienDich* pMienDich;
public:
    void Nhap(bool isVacine = 0){
        cout << "Nhap ma so:";
        getline(cin,sMaSo);
        VirusNhiem[0] = new Corona;
        VirusNhiem[1] = new Ebola;
        VirusNhiem[2] = new HIV;

        if(isVacine){
            pMienDich = new MienDich(1);
        }
        else{
            pMienDich = new MienDich;
        }
        pMienDich->Nhap();
    }
    void In(){
        cout << sMaSo << endl;

        double tuVongMax =0;
        for(int i = 0 ; i < 3; i++){
            int ind = pMienDich->getLoaiTrieuChung(VirusNhiem[i]->getMucDoNhiem());
            if(ind ==1 ) cout << "Khong triue chung\n";
            else if(ind ==2) VirusNhiem[i]->InTrieuChungNhe();
            else VirusNhiem[i]->InTrieuChungNang();
            tuVongMax = max(tuVongMax, VirusNhiem[i]->getTuVong() * pMienDich->getTuVong());
        }

        if(tuVongMax >= 1) cout << "Tu vong\n";
        else cout << "Chua tu vong\n";
    }
};






int main(){
    int n; cout << "Nhap n vat chu: "; cin >> n;
    VatChu* ds = new VatChu[n];
    for(int i =0 ; i < n;i ++){
        ds[i].Nhap(); // dung 1 con tro danh sang tung doi tuong khong co class rieng nen khong tro
    }
    for(int i =0 ; i < n;i ++){
        ds[i].In();
    }

    int m = n;
    VatChu* ds1 = new VatChu[m];
    for(int i =0 ; i < n;i ++){
        ds1[i].Nhap(1); // dung 1 con tro danh sang tung doi tuong khong co class rieng nen khong tro
    }
    return 0;
}