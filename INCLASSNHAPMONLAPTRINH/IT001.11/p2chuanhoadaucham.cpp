
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);


int main()
{
	char s[MAX];

	fflush(stdin);
	fgets(s,MAX,stdin);

	char s1[MAX];
	myStrcpy(s1, 0, s, 0);//s chuỗi đich, s1 chuỗi đích, vt là vị trí lấy chuỗi nguồn
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}
void myStrcpy(char s[], int vt, char s1[], int k){ // s1 chuỗi nguồn, s chuỗi đích, vt là vị trí lấy chuỗi đích
    for(int i=k;s1[i]!='\0';i++){ //nhớ cái này phải dùng char
        s[vt]=s1[i];
        vt++;
    }
    s[vt]='\0'; // phải có dòng này để kết thúc chuỗi nếu không sẽ có giá trị rác vào ô cuỗi
}
// trường hợp: hai. . ?
int myStrlen(char s[], int k){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count;
}
void Chuanhoa(char s[]){
    int size=myStrlen(s,0);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '){ // kiểm tra cho đến khi hết ' ' nếu nó là . thì thu gọn lại
            for(int j=i+1;s[j]!='\0';j++){
                if(s[j]==' '){
                    continue;
                }
                else if(s[j]=='.'){
                    //thu gọn lại
                    // đặt cờ
                    // int flag=0;
                    while(s[i]==' '){
                        for(int z=i;s[z]!='\0';z++){
                            s[z]=s[z+1];
                        }                        
                    }
                }
                else break;
            }            
        }
        if(s[i]=='.'){ // không đặt else if và đặt if này sau if kia để kiểm tra đưa về đúng dạng . rồi kiểm tiếp
            // thiếu trường hợp: hai.hai
            int j=i+1;
            if(s[j]=='\0') break; // bếu chỉ có 1 . thì kết thúc
            //nếu tất cả là ..... thì break
            // int flag=0;
            // int l=j;
            // while(s[l]!='\0'){
            //     if(s[l]!='.') {
            //         flag=0;
            //         break;
            //     }
            //     flag=1;
            // }
            // if(flag==1) break;
            if(s[j]==' '){// bắt đầu xét nếu char sau nó vẫn là ' ' thì xóa bằng cách cộng đồn lên
            // if này để xóa ' ' dư
                int u=j+1;
                while(s[u]==' '){
                    for(int z=j;s[z]!='\0';z++){
                        s[z]=s[z+1];
                    }
                }

            }
            else if(s[j]=='.'){
                size++; 
                // nhớ phải cập nhật size trước khi đôn lên
                for(int u=size;u>j;u--){
                    s[u]=s[u-1];
                }
                s[j]=' ';
                i++;
            }
            else if(s[j]!=' '){ // if này để cách ra nếu thiếu ' ' sau dấu .
                size++;
                for(int u=size;u>j;u--){
                    s[u]=s[u-1];
                }
                s[j]=' ';
            }
 
        }
    }
}