#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct Data {
    string loai;    // ví dụ: "A", "B", "C"
    int diem;
    string ten;
};


Data* createData(string ten, string loai, int diem){
    Data* p = new Data;
    p->diem = diem;
    p->loai = loai;
    p->ten = ten;
    return p;
}

bool Cmp(Data a, Data b){
    if(a.ten != b.ten) return a.ten < b.ten;
    if(a.loai != b.loai) return a.loai < b.loai;
    if(a.diem != b.diem) return a.diem < b.diem;
    return false;
}

void Sort(vector<Data>& a){
    for(int i =0 ;i < a.size() -1;i++){
        int iMin = i;
        for(int j = i + 1; j <a.size();j++){
            if(Cmp(a[j] , a[iMin])){
                iMin = j;
            }
        }

        if(iMin != i){
            swap( a[i] , a[iMin]);
        }
    }
}


int main()
{
    vector<Data> a;
    int n;cin >> n;
    for(int i =0 ;i < n;i++){
        int diem ; cin >> diem;
        string loai; cin.ignore();
        string ten;
        getline(cin,loai);
        getline(cin,ten);
        Data p = *createData(ten,loai,diem);
        a.push_back(p);
    }

    Sort(a);
    for(auto d : a){
    cout << d.diem << "\n" << d.loai << "\n" << d.ten << "\n";
}

    return 0;
}
