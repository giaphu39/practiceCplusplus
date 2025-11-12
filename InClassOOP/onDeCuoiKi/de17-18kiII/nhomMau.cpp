#include<iostream>
#include<string>

using namespace std;

class NhomMau{
protected:
    bool bRH;
public:
    virtual void Nhap(){
        cout << "nhap RH: 0 la - , 1 la +";
        cin >> bRH;
    }

    virtual string getLoaiMau() = 0;
    virtual bool getRH(){
        return bRH;
    }

    virtual bool isPhuHopLuatDiTruyen(string cha, string me) = 0;
    virtual bool isNhanDuoc(NhomMau NguoiCho)= 0;


};


class O : public NhomMau{
public:
    string getLoaiMau(){
        return "O";
    }
    bool isPhuHopLuatDiTruyen(string cha, string me){
        if(cha == "AB" || me =="AB") return false;
        return true;
    }
    bool isNhanDuoc(NhomMau NguoiCho){
        if(bRH){
            if(NguoiCho.getLoaiMau() == "O") return true;
            return false;
        }
        else{
            if(NguoiCho.getLoaiMau() == "O" && !NguoiCho.getRH()) return true;
            return false;
        }
    }
};

class A : public NhomMau{
public:
    string getLoaiMau(){
        return "A";
    }
    bool isPhuHopLuatDiTruyen(string cha, string me){
        if(cha == "AB" || me =="AB" || cha =="A" || me=="A") return true;
        return false;
    }
    bool isNhanDuoc(NhomMau NguoiCho){
        if(bRH){
            if(NguoiCho.getLoaiMau() == "O"){
                return true;
            }
            if(NguoiCho.getLoaiMau() == "A"){
                return true;
            }
            return false;
            
        }
        else{
            if(NguoiCho.getLoaiMau() == "O" && !NguoiCho.getRH()){
                return true;
            }
            else if(NguoiCho.getLoaiMau() == "A" && !NguoiCho.getRH()) return true;
            return false;
        }
    }
};

class B : public NhomMau{
public:
    string getLoaiMau(){
        return "B";
    }
    bool isPhuHopLuatDiTruyen(string cha, string me){
        if(cha == "AB" || me =="AB" || cha =="B" || me=="B") return 0;
        return 1;
    }
    bool isNhanDuoc(NhomMau NguoiCho){
        if(bRH){
            if(NguoiCho.getLoaiMau() == "O"){
                return true;
            }
            if(NguoiCho.getLoaiMau() == "B"){
                return true;
            }
            return false;
            
        }
        else{
            if(NguoiCho.getLoaiMau() == "O" && !NguoiCho.getRH()){
                return true;
            }
            else if(NguoiCho.getLoaiMau() == "B" && !NguoiCho.getRH()) return true;
            return false;
        }
    }
};

class AB : public NhomMau{
public:
    string getLoaiMau(){
        return "AB";
    }
    bool isPhuHopLuatDiTruyen(string cha, string me){
        if((cha =="A" && me == "B")||(cha =="B" && ))
    }
    bool isNhanDuoc(NhomMau NguoiCho){
        if(bRH){
            if(NguoiCho.getLoaiMau() == "O"){
                return true;
            }
            if(NguoiCho.getLoaiMau() == "A"){
                return true;
            }
            return false;
            
        }
        else{
            if(NguoiCho.getLoaiMau() == "O" && !NguoiCho.getRH()){
                return true;
            }
            else if(NguoiCho.getLoaiMau() == "A" && !NguoiCho.getRH()) return true;
            return false;
        }
    }
};



int main(){

    return 0;
}