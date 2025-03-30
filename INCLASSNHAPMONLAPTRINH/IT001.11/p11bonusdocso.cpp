#include<iostream>
using namespace std;
#include<string.h>
// ý tưởng: đếm lượng chữ số


void input(int& n){
    cin>>n;
}
int dem(int n){
    n=abs(n);
    int count=0;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}
void doisangchu(string a[]){
    a[11]="mười";
    a[10]="mươi";
    a[13]="mốt";
    a[0]="không";
    a[1]="một";
    a[2]="hai";
    a[3]="ba";
    a[4]="bốn";
    a[5]="lăm";
    a[12]="năm";
    a[6]="sáu";
    a[7]="bảy";
    a[8]="tám";
    a[9]="chín";
}
void sol(int n, string s, string a[]){ // nếu là mảng chứa string phải có 
    if(n==0) {s+=a[0];}
    int sochu=dem(n);
    // cout<<sochu;
    if(n<0){
        s+="âm ";
    }
    n=abs(n);
    if(sochu==1){
        if(n==5){s+=a[12];}
        else{s+=a[n];}
    }
    else if(sochu==2){
        int c=n%10; // số hàng đơn vị
        int b= (n/10);// số hàng chục
        if(b==1){
            s+=a[11];
            if(c==0) {cout<<s<<endl; return; }
        }
        else if(b==5) s+=a[12];
        else{
            s+=a[b];
        }
        if(c==0){
            s+=" ";
            s+=a[10];
        }
        else{
            if(b==1){
                s+=" ";
                s+=a[c];
            }
            else{
                s+=" ";
                s+=a[10];
                s+=" ";
                if(c==1){
                    s+=a[13];
                }
                else{
                    s+=a[c];
                }
            }
        }
    }
    else if(sochu==3){
        s+="một trăm";
    }
    cout<<s<<endl;
}
int main(){
    int n;
    string a[100];
    input(n);
    string s;
    doisangchu(a);
    sol(n,s,a);
    // for(int i=0;i<=100;i++){
    //     sol(i,s,a);
    // }
    return 0;
}