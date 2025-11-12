#include <iostream>
using namespace std;
class nguoi
{
    private :
    string hoten;
    int namsinh;
    string cmnd;
    string diachi;
    public:
    void nhap()
    {cout<<"Nhap thong tin ho ten:";
            cin.ignore();
        getline(cin,hoten);
        cout<<"Nhap cmnd: ";
        getline(cin,cmnd);
        cout<<"Nhap dia chi: ";
        getline(cin,cmnd);
        cout<<"nhap nam sinh: ";
        cin>>namsinh;
        
    }
    void xuat()
    {
        cout<<"ho ten: "<<hoten<<endl;
        cout<<"Nam sinh: "<<namsinh<<endl;
        cout<<"Cmnd : "<<cmnd<<endl;
        cout<<"Dia chi: "<<diachi<<endl;
    }
};
class sohong
{
    protected:
    string giaychungnhan;
    nguoi * danhsachnguoisohuu;
    int sothua;
    int sotobando;
    string diachidat;
    double dientich;
    string ngaycap;
    double dongiathue;
    int songuoisudungdat;
    public:
    virtual void nhap()
    {
        cout<<"Nhap so nguoi so huu dat: ";
        cin>>songuoisudungdat;
        danhsachnguoisohuu = new nguoi[songuoisudungdat];
        for(int i=0;i<songuoisudungdat;i++)
        {
            danhsachnguoisohuu[i].nhap();
        }
        cout<<"Nhap giay chung nhan: ";
        cin.ignore();
        getline(cin,giaychungnhan);
        cout<<"Nhap dia chi dat: ";
        getline(cin,diachidat);
        cout<<("Nhap ngay cap: ");
        getline(cin,ngaycap);
        cout<<"Nhap dien tich: ";
        cin>>dientich;
        cout<<"Nhap so thua: ";
        cin>>sothua;
        cout<<"nhap so to ban do: ";
        cin>>sotobando;
        cout<<"nhap don gia thue: ";
        cin>>dongiathue;
    }
    virtual void xuat()
    {
        cout<<"Thong tin cua dat";
        cout<<"thong tin nguoi su dung dat: "<<endl;
        for(int i=0;i<songuoisudungdat;i++)
        {
            danhsachnguoisohuu[i].xuat();
        }
        cout<<"So thua: "<<sothua;
        cout<<endl;
        cout<<"So to ban do: "<<sotobando;
        cout<<endl;
        cout<<"Dia chi dat"<<diachidat;
        cout<<endl;
        cout<<"Giay chung nhan: "<<giaychungnhan;
        cout<<"Dien tich: "<<dientich;
        cout<<endl;
        cout<<"Ngay cap: "<<ngaycap;
        cout<<endl;
        cout<<"Don gai thue: "<<dongiathue;
        cout<<endl;
    }
    virtual double tinhthue()=0;
    virtual string traveloai()=0;

};
class datnongnghiep :public sohong
{
    private:
    int thoigiansudung;
    public:
    void nhap()
    {
        sohong::nhap();
        cout<<"nhap thoi gian su dung: ";
        cin>>thoigiansudung;
    }
    void xuat()
    {
        sohong::xuat();
        cout<<"Thoi gian su dung: "<<thoigiansudung;
        cout<<endl;
    }
    bool hethansudung(int namhientai)
    {
        if(namhientai>thoigiansudung)
        {
            return 0;
        }
        else return 1;
    }
    double tinhthue()    
    {
        return dientich*dongiathue;
    }
    string traveloai()
    {
        return "datnongnghiep";
    }
};
class datphinongnhiep :public sohong
{
    public:
    void nhap()
    {
        sohong::nhap();
    }
    void xuat()
    {
        sohong::xuat();
    }
    double tinhthue()    
    {
        return dientich*dongiathue;
    }
    string traveloai()
    {
        return "datphinongnhiep";
    }
};
int main()
{
    int x;
    cin>>x;
    sohong** danhsachdat = new sohong*[x];
    for(int i=0;i<x;i++)
    {
        int a;
        cout<<"chon nhap dat nong nhiep hjay phi nong nhiep: ";
        cin>>a;
        if(a==1)
        {
            danhsachdat[i]= new datnongnghiep();
        }
        else if(a==2)
        {
            danhsachdat[i]= new datphinongnhiep();
        }
        danhsachdat[i]->nhap();
    }
    int maxthue=0;
    for(int i=0;i<x;i++)
    {   double thue;
        thue= danhsachdat[i]->tinhthue();
        if(thue>maxthue)
        {
            maxthue=thue;
        }
    }
    for(int i=0;i<x;i++)
    {
        double thue;
        thue=danhsachdat[i]->tinhthue();
        if(thue==maxthue)
        {
            danhsachdat[i]->xuat();
        }
    }
    for(int i=0;i<x;i++)
    {
        string c = danhsachdat[i]->traveloai();
        if(c=="datnongnhiep")
        {
            if(((datnongnghiep*)danhsachdat[i])->hethansudung(2024))
            {
                danhsachdat[i]->xuat();
            }
        }
        else
        {
            cout<<"ko phai dat nong nghiep";
        }
    }
    return 0;
}