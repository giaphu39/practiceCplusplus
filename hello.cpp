#include<iostream>
#include <string>

#include<map>
using namespace std;



string tenQuocGiaMax(map<string,set<string>> ds){
    string ans;
    int soMax = 0;
    for(auto Pair: ds){
        if(Pair.second.size() > soMax){
            ans = Pair.first;
        }
    }

    return ans;
}







int main(){

    return 0;
}