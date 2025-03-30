
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);	//Nhap chuoi s	
	if (myStrcmp(s, "") == 0 ) // so sánh chuỗi s với ""
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);//in ra tần số xuất hiện 

	return 0;
}
int myStrcmp(char s1[MAX], char s2[MAX]){
    for(int i=0;;i++){
        if(s1[i]=='\0' or s1[i]=='\n' or s1[i]=='\r') break;
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1; 
    }
    return 0;
}
void DemKyTu(char s[]){
    for(int i=0;;i++){
        if(s[i]=='\0' ) break;
        if( s[i]=='\n' or s[i]=='\r') continue; //phải có dòng này vì trong wecode  sẽ in ra 2 \ này
        int count=1; // lúc đầu phải là 1 vì chạm ngay số đó
        for(int j=i+1;s[j]!='\0';j++){
            if(s[i]==s[j]){
                count++;
                s[j]='\n'; // không tổng quát hết các trường hợp
            }
        }
        cout<<s[i]<<": "<<count<<endl;
    }
}