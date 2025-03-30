// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #include<string>
// #include<iomanip>
// #include<cstring> //khai bao thu vien cho strlen
// class student{
// private:
//     // char hoten[51];
//     string mnv;
//     string hoten;
//     string sex;
//     string ngaysinh;
//     string noio;
//     string mst;
//     string hopdong;
// public:
//     void input(){
//         getline(cin,mnv);
//         getline(cin,hoten);
//         getline(cin,sex);
//         getline(cin,ngaysinh);
//         getline(cin,noio);
//         getline(cin,mst);
//         getline(cin,hopdong);
//     }
//     void chuanhoa(string a){
//         string ans;
//         int count1=0;
//         int j=0;
//         for(int i=0;i<ngaysinh.size();i++){ // phai ep lai thanh kieu int
//             if(count1==2) break;
//             if(ngaysinh[i]=='/'){
//                 count1++;
//                 string tu;
//                 for(int ind=j;ind<i;ind++){
//                     tu+=ngaysinh[ind];
//                 }
//                 j=i+1;
//                 if(stoi(tu)<10) ans+='0'+tu;
//                 else ans+=tu;
//                 ans+='/';
//             }
//         }
//         string year=ngaysinh.substr(j);
//         ans+=year;
//         this->ngaysinh=ans;
        
//     }

//     void output(){
//         cout<<hoten<<" "<<lop<<" "<<ngaysinh<<" "<<fixed<<setprecision(2)<<gpa;
//     }

// };

// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
//     student a;
//     a.input();
//     // a.chuanhoa();
//     a.output();
    
//     return 0;
// }



// chatgpt: https://chatgpt.com/share/6797b3a7-fdd0-800d-817f-df74af4c5942
//cac ham xet kieu char trong cctype: https://chatgpt.com/share/6797ba39-aa38-800d-82bb-f40f2225ae3e
#include <iostream>
#include <iomanip>
#include <string>
#include<cctype> // khai bao cho ham isdigit
using namespace std;

class student {
private:
    string mnv = "00001";
    string hoten;
    string sex;
    string ngaysinh;
    string noio;
    string mst;
    string hopdong;

    string chuanhoangay(const string &date) {
        string ans;
        int count1 = 0;
        int j = 0;
        for (int i = 0; i < (int)date.size(); i++) {
            if (date[i] == '/') {
                count1++;
                string tu = date.substr(j, i - j);
                if (stoi(tu) < 10 && tu.size() == 1) ans += "0" + tu;
                else ans += tu;
                ans += '/';
                j = i + 1;
            }
        }
        string year = date.substr(j);
        ans += year;
        return ans;
    }
    string chuanhoaten(const string &ten){
        string ans;
        ans+=toupper(ten[0]);
        int flag=0; // biet cho nao can in hoa
        for(int i=1;i<ten.size();i++){
            if(flag){
                flag=0;
                ans+=toupper(ten[i]);
            }
            else{
                if(isalpha(ten[i])){
                    ans+=tolower(ten[i]);
                }
                else if(ten[i]==' '){
                    flag++;
                    ans+=ten[i];
                }
                else{
                    ans+=ten[i];
                }
            }
        }
        return ans;

    }

public:
    void input() {
        getline(cin, hoten);
        getline(cin, sex);
        getline(cin, ngaysinh);
        getline(cin, noio);
        getline(cin, mst);
        getline(cin, hopdong);
    }

    void process() {
        ngaysinh = chuanhoangay(ngaysinh);
        hopdong = chuanhoangay(hopdong);
        hoten= chuanhoaten(hoten);
        sex= chuanhoaten(sex);
        noio=chuanhoaten(noio);
    }

    void output() {
        cout << mnv << " " << hoten << " " << sex << " " << ngaysinh << " " << noio << " " << mst << " " << hopdong << endl;
    }
};

int main() {
    student a;
    a.input();
    a.process();
    a.output();
    return 0;
}
