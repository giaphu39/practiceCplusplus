
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

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
    int size=myStrlen(s,0);
    for(int i=0; s[i]!='\0';i++){
        if(s[i]==' '){
            int j=i+1;
            while(s[j]==' '){
                mySubstr(s,j,0,s);
            }
        }
        // if(s[i]=='\\'){
        //     if(s[i+1]=='n' or s[i+1]=='r'){
        //         mySubstr(s,i,0,s);
        //         s[i]=' ';
        //     }
        // }
    }    
    if(s[0]==' ') mySubstr(s,0,0,s);
    if(s[size-1]==' ') mySubstr(s,0,0,s);
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
    return count;
}
void StringReverse(char st[]){
    // myStrcpy(st,0,st,0);
    
    int ind=0;
    int flag=0;
    int size=myStrlen(st,0);
    char s[MAX]; // làm sao để cho biến tạm này trở lại ban đầu khi chạy xong 1 từ
    for(int i=0;st[i]!='\0';i++){
        

        if(st[i]!=' ' and st[i]!='\n' and st[i]!='\r'){
            s[ind++]=st[i];
        }
        else{ // gặp space thì đổi từ, tiếp tục qua từ tiếp theo
            s[ind]='\0';
            int sizes=myStrlen(s,0);
            for(int j=sizes-1;j>=0;j--){
                st[flag++]=s[j]; // index st ở đây phải là vị trí đầu của từ-> dùng flag
            }
            st[flag++]=' ';
            ind=0;
        }
    }
    if(st[size-1]==' ') st[size-1]='\0';
    
    
}