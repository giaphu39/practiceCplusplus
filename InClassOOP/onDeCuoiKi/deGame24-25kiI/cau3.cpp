#include<bits/stdc++.h>
using namespace std;













class NhanVat{
protected:    int iLevel;
    int iHP;
    int iHieuUng;
    int iLuotDoc;
    bool isBoss;
public:
     void In(){ // thu tu quan trong?+ => nên để in ở cuối , nhap thi tuy thuoc vao có dung ham ơ lớp con thì nên để ở dưới, tóm lại là để nhap và xuat ở cuối cùng
        cout << "cac thong tin chi tiet cua nhan vat lan luot: cap do, base attack, base defense, damage, max HP, HP la ";
        cout << iLevel << " " << ATK() << " " << DEF() << " " << Damage() << " " << MAXHP() << " " << getHP() << endl;
    }   virtual int getLoai() = 0;
    bool isDead(){
        if(iHP == 0) return true;
        return 0;
    }

    int& getHP(){
        return iHP;
    }

    void TanCong(NhanVat& other);
    void PhongThu();
    void Luot();
    virtual int ATK() =0 ;
    virtual int MAXHP() =0;
    virtual int Damage()=0;
    virtual int DEF()=0;

    void Nhap(bool Boss = 0){
        cout <<"nhap vao lan luot level: ";
        cin>> iLevel;
        cin.ignore();
        isBoss = Boss;

        iHP = MAXHP();
    }

   
};

class Tanker : public NhanVat{
public:

    int ATK(){
        int atk;
        if(iLevel == 1) atk= 50;
        else if(iLevel == 2) atk= 55;
        else if(iLevel == 3) atk= 60;
        else if(iLevel == 4) atk =65;
        else atk = 70;
        if(isBoss) atk*=2.5;
        return atk;
    }

    int DEF(){
        int def;
        if(iLevel == 1) def= 50;
        else if(iLevel == 2) def= 70;
        else if(iLevel == 3) def= 90;
        else if(iLevel == 4) def =11;
        else def = 130;
        if(isBoss) def*=2.5;
        return def;
    }

    int Damage(){
        int dam;
        if(iLevel == 1) dam= 5;
        else if(iLevel == 2) dam= 8;
        else if(iLevel == 3) dam= 12;
        else if(iLevel == 4) dam =17;
        else dam = 22;
        if(isBoss) dam*=2.5;
        return dam;
    }

    int MAXHP(){
        int MHP;
        if(iLevel == 1) MHP= 80;
        else if(iLevel == 2) MHP= 100;
        else if(iLevel == 3) MHP= 120;
        else if(iLevel == 4) MHP =140;
        else MHP = 160;
        if(isBoss) MHP*=2.5;
        return MHP;
    } int getLoai(){ return 1;}
    
};


class Fighter  : public NhanVat{
public:

    int ATK(){
        int atk;
        if(iLevel == 1) atk= 50;
        else if(iLevel == 2) atk= 55;
        else if(iLevel == 3) atk= 60;
        else if(iLevel == 4) atk =65;
        else atk = 70;
        if(isBoss) atk*=2.5;
        return atk;
    }

    int DEF(){
        int def;
        if(iLevel == 1) def= 50;
        else if(iLevel == 2) def= 70;
        else if(iLevel == 3) def= 90;
        else if(iLevel == 4) def =11;
        else def = 130;
        if(isBoss) def*=2.5;
        return def;
    }

    int Damage(){
        int dam;
        if(iLevel == 1) dam= 5;
        else if(iLevel == 2) dam= 8;
        else if(iLevel == 3) dam= 12;
        else if(iLevel == 4) dam =17;
        else dam = 22;
        if(isBoss) dam*=2.5;
        return dam;
    }

    int MAXHP(){
        int MHP;
        if(iLevel == 1) MHP= 80;
        else if(iLevel == 2) MHP= 100;
        else if(iLevel == 3) MHP= 120;
        else if(iLevel == 4) MHP =140;
        else MHP = 160;
        if(isBoss) MHP*=2.5;
        return MHP;
    }int getLoai(){ return 2;}
    
};

class Ranger : public NhanVat{
public:

    int ATK(){
        int temp[5] = {50,55,60,65,70};
        int atk = temp[iLevel -1]; // nhớ mảng thì -1 khi truy cập index
        // if(iLevel == 1) atk= 50;
        // else if(iLevel == 2) atk= 55;
        // else if(iLevel == 3) atk= 60;
        // else if(iLevel == 4) atk =65;
        // else atk = 70;
        if(isBoss) atk*=2.5;
        return atk;
    }

    int DEF(){
        int def;
        if(iLevel == 1) def= 50;
        else if(iLevel == 2) def= 70;
        else if(iLevel == 3) def= 90;
        else if(iLevel == 4) def =11;
        else def = 130;
        if(isBoss) def*=2.5;
        return def;
    }

    int Damage(){
        int dam;
        if(iLevel == 1) dam= 5;
        else if(iLevel == 2) dam= 8;
        else if(iLevel == 3) dam= 12;
        else if(iLevel == 4) dam =17;
        else dam = 22;
        if(isBoss) dam*=2.5;
        return dam;
    }

    int MAXHP(){
        int MHP;
        if(iLevel == 1) MHP= 80;
        else if(iLevel == 2) MHP= 100;
        else if(iLevel == 3) MHP= 120;
        else if(iLevel == 4) MHP =140;
        else MHP = 160;
        if(isBoss) MHP*=2.5;
        return MHP;
    }int getLoai(){ return 3;}
    
};

void NhanVat::TanCong(NhanVat& other){

}

int main(){
    NhanVat** player = new NhanVat*[5]; int sl = 0;
    for(int i = 0 ; i < 5; i++){
        cout << " nhap 1 la nhap nhan vat, 0 la khong nhap";
        int x; cin >> x;
        if(!x) continue;
        else{
            sl++;
            cout << "Nhap 1 la tanker, 2 la fignter, 3 la ranger";
            int y; cin >> y;
            if(y == 1) player[i] = new Tanker;
            else if (y == 2) player[i] = new Fighter;
            else player[i] = new Ranger;
        }
        cin.ignore();

        player[i]->Nhap();
        
    } 

    NhanVat* Boss;
    cout << "Nhap 1 la tanker, 2 la fignter, 3 la ranger";
    int y; cin >> y;
    if(y == 1) Boss = new Tanker;
    else if (y == 2) Boss = new Fighter;
    else Boss = new Ranger;
    Boss->Nhap(1);

    cout << "In thong tin\n";
    Boss->In();
    for(int i = 0; i < 5; i++){
        if(player[i] != NULL){
            player[i] ->In();
        }
        
    } 
    // int DeadCount = 0;
    // while(true){
    //     if(DeadCount == sl) break;
    //     if(Boss->isDead()) break;

    //     int countTanker =0;
    //     int countFighter = 0;
    //     for(int i =0 ; i < 5;i ++){
    //         if(player[i]->isDead()) continue;
    //         if(player[i]->getLoai() == 1){// lay
    //             countTanker++;
    //         }
    //         else if(player[i]->getLoai() == 2) countFighter++; // 
    //         cout << "1 la tan cong, 0 la phong thu\n";
    //         int x; cin >> x; cin.ignore();
    //         if(x) player[i]->TanCong(*Boss);
    //         else player[i]->PhongThu();
    //     }

        // double act = doubleRandom(); // random hanh dong boss
        // if(act <= 0.7){

        // }
        // else{
        //     Boss->PhongThu();
        // }
    // }

    return 0;
}