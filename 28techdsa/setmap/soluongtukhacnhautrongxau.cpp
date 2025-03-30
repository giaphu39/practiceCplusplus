#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<set>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<string> a;
    string s;
    while(cin>>s){
        a.insert(s);
    }
    cout<<a.size()<<endl;
    auto st=a.begin();
    set<string>::reverse_iterator en = a.rbegin(); //nhớ rằng nếu dùng rbegin() thì phải là reverse_iterator
    cout<<*st<<" "<<*en;
    return 0;
}
