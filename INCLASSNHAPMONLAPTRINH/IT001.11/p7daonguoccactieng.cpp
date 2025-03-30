
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300
//còn thiếu trường hợp "Hoa" mà thầy không có test case này
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}


void mySubstr(char s[], int b, int count, char ss[]){//hàm xóa
    for(int i=b;s[i]!='\0';i++){//b là vị trí bị xóa
        s[i]=s[i+1];
    }
    // không thao tác được gì trên size
}
void myStrcpy(char s[], int vt, char s1[], int k){//chuẩn hóa chuỗi: chưa tối ưu do có độ phức tạp n^2
    // int size=myStrlen(s,0);
    // for(int i=0; s[i]!='\0';i++){
    //     if(s[i]==' '){
    //         int j=i+1;
    //         while(s[j]==' '){
    //             mySubstr(s,j,0,s);
    //         }
    //     }
    // }    
    // if(s[0]==' ') mySubstr(s,0,0,s);
    // if(s[size-1]==' ') mySubstr(s,0,0,s);
    for(int i=0;s[i]!='\0';i++){
        s1[i]=s[i];
    }
}

int myStrcmp(char s1[MAX], char s2[MAX]){
    int i;
    int flag=0;
    for(int j=0;s1[j]!='\0';j++){
        if(s1[j]==' ' or s1[j]=='\n' or  s1[j]=='\r'){
            flag=1;
            continue;
        }
        flag=0;break;

    }
    if(flag==1) return 0;
    for( i=0;;i++){
        if(s1[i]=='\0' or s1[i]=='\n' or s1[i]=='\r') break;
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1; 
    }
    for(int j=i;;j++){
        if(s2[i]=='\0' or s2[i]=='\n' or s2[i]=='\r') break;
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1; 
    }
    return 0;
}
int myStrlen(char s[], int k){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count-1;// không lấy \n
}
//ý tưởng xét từ cuối đến đầu chuỗi, gặp khoảng space thì in ra trước 
void StringReverse(char st[]){
    int size=myStrlen(st,0);
    char s[MAX];
    myStrcpy(st,0,s,0);
    // cout<<s<<endl;
    // cout<<size;
    int sizeofw=0;
    int ind=0;
    for(int i=size-1;i>=-1;i--){
        if(st[i]==' ' or i==-1){ // nếu vậy thì chữ đầu sẽ thiếu
            for(int j=i+1;j<i+1+sizeofw;j++){
                s[ind++]=st[j];
            }
            sizeofw=0;
            s[ind++]=' ';
            if(i==-1) s[ind]='\0';
        }
        else sizeofw++;
    }
    myStrcpy(s,0,st,0);
    
}