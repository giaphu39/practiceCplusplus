#include <bits/stdc++.h>

using namespace std;
// 2 tp co tram ga va chung canh
//it nha 2 tram ga
//chung canh nhung neu co 3 # thi qua duoc
int main()
{
    //chi co 2 moi xet, 1 thi No, 34 thi YES
    string s,temp;
    getline(cin,s);
    getline(cin,temp);
    s+=temp;
//    cout<<s;
    int ga=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#')ga++;
    }
//    cout<<ga;
    //cach hai lúc đầu bỏ nó vào mảng 1 khi nhập#, rồi xét
    if(ga<=1)cout<<"No";
    else if(ga==2){ //nhớ and và or không được hỗ trợ
        if((s[0]=='#'&& s[1]=='#') || (s[0]=='#'&& s[2]=='#') || (s[1]=='#' && s[3]=='#') || (s[3]=='#'&& s[2]=='#') ){
            cout<<"Yes";
        }
        else cout<<"No";
    }
    else cout<<"Yes";

    return 0;
}
