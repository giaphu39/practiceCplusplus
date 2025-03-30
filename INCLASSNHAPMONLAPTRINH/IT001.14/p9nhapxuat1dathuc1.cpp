#include <iostream>
using namespace std;
#include<iomanip>
#define MAX 300
#include<math.h>
#include<string>
#include <cmath>
#include <sstream> // vì dùng chuỗi không thể in float đẹp được nên phải dùng ostringstream
// có thể dùng cout nhưng không tổng quát cho các đề bài khác

// Các đơn thức được nhập vào theo thứ tự giảm dần của số mũ, và không có đơn thức nào có cùng số mũ
struct DATHUC
{
    int n; // số lượng đa thức
    float hs[MAX];// hệ số
    int sm[MAX];// số mũ  
};

DATHUC* Nhap(){
    DATHUC* a= new DATHUC;// cấp phát động sau thì nhớ delete
    cin>>(*a).n;
    for(int i=0;i<(*a).n;i++){
        cin>>(*a).hs[i]>> (*a).sm[i];
    }
    return a;
}
// Biến trong đa thức ký hiệu là x.
// Số mũ ký hiệu ^.
// Phép nhân không ghi ký hiệu.
// Các ký tự biểu diễn đa thức ghi liền nhau (không khoảng trắng).
// Đơn thức đầu tiên nếu hệ số là số dương thì không được xuất dấu + trước hệ số.
// Đơn thức có hệ số bằng 0 thì không xuất đơn thức đó.
// Đơn thức có hệ số bằng 1 hoặc -1 thì không xuất số 1.
// Đơn thức có số mũ bằng 0 thì chỉ xuất hệ số của đơn thức.
// Đơn thức có số mũ bằng 1 thì không xuất số mũ.

// 2x^15-x^10+x^5+6x^2-8.5x-10.52
void Xuat(DATHUC a){
    string s;
    
    for(int i=0;i<a.n;i++){
        ostringstream os;

        os<<setprecision(5)<<abs(a.hs[i]);
        string hs=os.str();
        if(hs=="1" and a.sm[i]!=0) hs="";
        // hai dòng này giúp cho float có thể trở về dạng đẹp
        if(i==0 and a.hs[0]>0){
            // s+=to_string((a.hs[i]));
            s+=hs;
            if(a.sm[i]==1) // trường hợp đặc biệt
            {s+="x"; continue;}
            else if(a.sm[i]==0) continue;
            else s+="x^" + to_string(a.sm[i]);
        }
        else{
            // tách dấu ra 
            if(a.hs[i]<0) s+="-";
            else if(a.hs[i]>0) s+="+";
            else continue; // hs=0 thi qua cai tiep theo
            
            //truong hop dac biet
            if(a.sm[i]==0) s+=hs;
            else if(a.hs[i]==1) s+="x^"+to_string(a.sm[i]);
            else if(a.sm[i]==1) s+=hs+"x";
            else if(a.hs[i]==1 and a.sm[i]==1) s+="x";
            // 4 trường hợp đặc biệt
            else s+=hs+"x^"+to_string(a.sm[i]);
        }
    }
    if(s=="") cout<<0;
    else cout<<s;
}

double TinhDaThuc(DATHUC a, double x){
    double ans=0;
    for(int i=0;i<a.n;i++){
        // double u= 1;
        // for(int j=1;j<=a.sm[i];j++){
        //     u*=x;
        // }
        if(a.hs[i]!=0){
            ans+= a.hs[i]*pow(x,a.sm[i]);
        }
        else{
            ans+=a.hs[i];
        }
    }
    
    return ans;
}



int main() {
    DATHUC *B; B = Nhap(); // DATHUC* này là con trỏ dùng cho cấp phát động
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
} 
