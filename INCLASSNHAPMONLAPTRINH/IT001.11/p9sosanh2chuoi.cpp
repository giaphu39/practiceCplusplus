
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1,MAX,stdin);
	fgets(s2,MAX,stdin);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
	return 0;
}
int myStrcmp(char s1[], char s2[]){
    for(int i=0;;i++){
        if(s1[i]=='\0' or s1[i]=='\n' or s1[i]=='\r'){
           if(s2[i]!='\0' and s2[i]!='\n' and s2[i]!='\r'){ // khác thì phải dùng and
            return -1;
           }
           else return 0;
        }
        if(s2[i]=='\0' or s2[i]=='\n' or s2[i]=='\r'){
           if(s1[i]!='\0' and s1[i]!='\n' and s1[i]!='\r'){
            return 1;
           }
           else return 0;
        }
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1; 
    }
}