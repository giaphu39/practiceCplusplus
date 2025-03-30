#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<map>
#include<vector>
// #include<sstream>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    
    map<string, vector<string>> a; //ket qua voi key la ten doi, con vector luu ds doi
    // stringstream ss;
    cin.ignore(1);

    for(int i=0;i<n;i++){
        
        string team1,team2,line;
        getline(cin,line);
        // stringstream ss(line);
        // getline(ss,line);// chi co the dung ss>>line;
        // getline(ss,team1," - "); // khonog khai bao kieu vay duoc chi la kieu char thoi
        // getline(ss,team1,' '); // bo qua ' ' dau luon // se sai neu team1 co cach ra

        // ss.ignore(2); // bo " - " // nho phai la luong ss
        // getline(ss,team2);

        //nen dung cach nay thay vi dung stringstream
        string temp=" - ";
        int ind=line.find(temp);
        if(ind!=string::npos){
            team1=line.substr(0,ind);
            team2=line.substr(ind+3);// bỏ qua vị trí " - ";
        }

        a[team1].push_back(team2);
        a[team2].push_back(team1);
    }
    // for(auto it: a){
    //     cout<< it<<" "<<a[0];
    // }


    for(auto team : a){
        cout<<team.first<<" : ";
        sort(team.second.begin(),team.second.end()); // vector sort thi dung it
        for(int i=0;i<team.second.size();i++){
            if(i==0) cout<<team.second[i];
            else cout<<", "<<team.second[i];
        }
        cout<<endl;
    }
    return 0;
}
