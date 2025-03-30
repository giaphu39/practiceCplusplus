#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void NhapMang(vector<int>& a, int n){

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void InMang(vector<int> a){
    for(vector<int>::iterator it=a.begin(); it != a.end() ; it++){
        cout<<*it<< " ";
    }
    cout<<endl;
}

void Inketqua(int i){
    if(i == -1) cout<<" không tìm thấy x trong mảng";
    else{
        cout<<i;
    }

    cout<<endl;
}

int LinearSearch(vector<int> a , int n , int x){
    a.push_back(x);
    int i=0;
    while(a[i] != x){
        i++;
    }
    if(i<n){
        return i;
    }
    return -1;
}

int LinearSearch2(vector<int> a , int n , int x, vector<int>& dsx){
    int i=0;
    while(i<n){
        if(a[i] == x){
            dsx.push_back(i);
            
        }
        i++;
    }
    if(! dsx.empty()){
        return 1;
    }
    return -1;
}

void Inketqua2(int i,vector<int> dsx){
    if(i == -1) cout<<" không tìm thấy x trong mảng";
    else{
        // for(auto it=dsx.begin(); it != dsx.end(); it++){
        //     cout<<*it<<" ";
        // }
        for(int i=0;i<dsx.size(); i++){
            cout<<dsx[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){

    int n;cin>>n;

    vector<int> a(n); // không nên cộng +1 vì sẽ tạo số 0 ở cuối vector
    NhapMang(a,n);

    int x;cin>>x;

    Inketqua(LinearSearch(a,n,x));

    vector<int> dsx;

    Inketqua2(LinearSearch2(a,n,x,dsx), dsx);

    return 0;
}