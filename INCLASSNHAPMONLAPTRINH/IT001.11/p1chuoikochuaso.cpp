
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

bool chuoiso(char str[]){
    if(str[0]=='\0') return false;
    for(int i=0;;i++){
        if(str[i]=='\0') break;
        if(str[i]>='0' && str[i]<='9') return false;
    }
    return true;
}
int main(){
    char str[MAX];
    // cin>>str; // lấy đến gặp space
    cin.getline(str,MAX); // MAX để 
    if(chuoiso(str)) cout<<str;
    else cout<<"CHUOI KHONG HOP LE.";
    return 0;
}