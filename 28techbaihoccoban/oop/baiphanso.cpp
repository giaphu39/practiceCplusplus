#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include<string>
#include <numeric>

using namespace std;

class phanso{
private:
    int tu;
    int mau;
public:
    void input(){
        // int a,b;
        // cin>>a>>b;
        // tu=a;
        // mau=b;
        cin>>tu>>mau;
    }

    int gettu(){return tu;}
    int getmau(){return mau;}
    string dangthapphan(){
        int rutgon=__gcd(abs(tu),abs(mau));
        string ans;
        if(tu*mau<0)ans+="-";
        if(abs(mau)/rutgon==1) ans+=to_string(abs(tu)/rutgon);
        else ans+= to_string(abs(tu)/rutgon) +"/"+to_string(abs(mau)/rutgon);
        return ans;
    }

};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    phanso a;
    a.input();
    // cout<<a.gettu();
    cout<<a.dangthapphan();


    return 0;
}
