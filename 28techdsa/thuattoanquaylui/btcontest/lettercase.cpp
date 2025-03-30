#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<vector>

#include <cctype> // cho isdigit

string current;

void sol(string& s, int i, vector<string>& present){
    if(i==s.size()){
        present.push_back(current);

        return;// nho luon phai co
    }

    if(isdigit(s[i])){
        current+=s[i];
        sol(s,i+1,present);
        current.pop_back();
    }
    else{
        current+=(char)toupper(s[i]);
        sol(s,i+1,present);
        current.pop_back();
        current+=(char)tolower(s[i]);
        sol(s,i+1,present);
        current.pop_back();
    }
    

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    vector<string> present;
    string S;
    getline(cin,S);
    // cout<<S;
    sol(S,0,present);
    sort(present.begin(),present.end());
    for(int i=0;i<present.size();i++){
        cout<<present[i]<<endl;
    }

    return 0;
}
