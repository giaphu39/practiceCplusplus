#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<iomanip>
#include<cstring> //khai bao thu vien cho strlen
class student{
private:
    // char hoten[51];
    string hoten;
    string ngaysinh;
    string lop;
    float gpa;
public:
    void input(){
        getline(cin,hoten);
        getline(cin,lop);
        getline(cin,ngaysinh);
        cin>>gpa;
    }
    void chuanhoa(){
        string ans;
        int count1=0;
        int j=0;
        for(int i=0;i<ngaysinh.size();i++){ // phai ep lai thanh kieu int
            if(count1==2) break;
            if(ngaysinh[i]=='/'){
                count1++;
                string tu;
                for(int ind=j;ind<i;ind++){
                    tu+=ngaysinh[ind];
                }
                j=i+1;
                if(stoi(tu)<10) ans+='0'+tu;
                else ans+=tu;
                ans+='/';
            }
        }
        string year=ngaysinh.substr(j);
        ans+=year;
        this->ngaysinh=ans;
        
    }
//     void chuanhoa() {
//     string ans;
//     int j = 0;
//     for (int i = 0; i < ngaysinh.size(); i++) {
//         if (ngaysinh[i] == '/') {
//             string tu;
//             for (int ind = j; ind < i; ind++) {
//                 tu += ngaysinh[ind];
//             }
//             j = i + 1;  
//             if (stoi(tu) < 10) 
//                 ans += '0' + tu;  
//             else 
//                 ans += tu;
//             ans += '/'; 
//         }
//     }

//     // Xử lý phần còn lại sau dấu '/'
//     string lastPart = ngaysinh.substr(j); // trích xuất 1 chuỗi con từ chuỗi gốc bắt đầu từ vị trí j
//     if (stoi(lastPart) < 10) 
//         ans += '0' + lastPart;
//     else 
//         ans += lastPart;

//     this->ngaysinh = ans;  // Gán lại giá trị cho ngaysinh
// }

    void output(){
        cout<<hoten<<" "<<lop<<" "<<ngaysinh<<" "<<fixed<<setprecision(2)<<gpa;
    }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    student a;
    a.input();
    //nho phai goi chuan hoa truoc khi in
    a.chuanhoa();
    a.output();
    
    return 0;
}
