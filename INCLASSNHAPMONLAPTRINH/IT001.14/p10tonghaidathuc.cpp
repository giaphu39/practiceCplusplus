#include <iostream>
using namespace std;
#include<iomanip>
#define MAX 300
#include<math.h>
#include<string>
#include <cmath>
#include <climits>
#include <sstream> // vì dùng chuỗi không thể in float đẹp được nên phải dùng ostringstream
// có thể dùng cout nhưng không tổng quát cho các đề bài khác

//ý tưởng: dùng mảng đánh dấu sm khi cin - cho nhau, nếu bằng không thì không in 
//tìm max sm trước để rút ngắn khoảng for
int max1=INT_MIN;
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
        if((*a).sm[i]>max1) max1 =(*a).sm[i];
    }
    return a;
}
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
double mark[MAX];
DATHUC Tong2DaThuc(DATHUC* a,DATHUC* b){
    fill(begin(mark), end(mark), 0);
    DATHUC c;
    int i1=0;
    int i2=0;
    int i3=0;
    int n=0;
    for(int i=max1;i>=0;i--){ // truy cập theo số mũ
        // c.hs[i]=(a.hs[i]-b.hs[i]);
        // c.sm
        // bool flag=0;
        if(i1==((*a).n) and i2==((*b).n)) break;
        if(i==(*a).sm[i1]){ mark[i]+=(*a).hs[i1++]; }
        if(i==(*b).sm[i2]){ mark[i]+=(*b).hs[i2++];}
        // if(flag) n++;
    }
    for(int i=max1;i>=0;i--){
        if(mark[i]!=0){
            n++;
            c.sm[i3]=i;
            c.hs[i3++]=mark[i];
        }
    }
    c.n=n;
    return c;

}
int main() {
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    // cout<<max1;
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
