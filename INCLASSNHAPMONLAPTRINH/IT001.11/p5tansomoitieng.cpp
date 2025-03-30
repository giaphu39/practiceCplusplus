
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k); // tự đặt cái này thành chuẩn hóa chuỗi
int myStrstr(char s[], char s1[]); // thứ tự hàm không ảnh hưởng cách chạy hàm
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemTieng(s);
        // myMemmove(s,0,0);
        // cout<<s;
	return 0;
}

// ý tưởng: chuẩn hóa nó về dạng đúng rồi tạo một str nhỏ đến khi gặp ' ' thì kết thúc,
//sau đó so với các từ sau nó, nếu giống thì thay đổi tất cả từ này thành \n
int myStrcmp(char s1[MAX], char s2[MAX]){
    int i;
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
void myMemmove(char s[], int vt, int k){//chuẩn hóa chuỗi: chưa tối ưu do có độ phức tạp n^2
    for(int i=0; s[i]!='\0';i++){
        if(s[i]==' '){
            int j=i+1;
            while(s[j]==' '){
                mySubstr(s,j,0,s);
            }
        }
        if(s[i]=='\\'){
            if(s[i+1]=='n' or s[i+1]=='r'){
                mySubstr(s,i,0,s);
                s[i]='\n';
            }
        }
    }
    
    if(s[0]==' ') mySubstr(s,0,0,s);
}

void mySubstr(char s[], int b, int count, char ss[]){//hàm xóa
    for(int i=b;s[i]!='\0';i++){//b là vị trí bị xóa
        s[i]=s[i+1];
    }
    // không thao tác được gì trên size
}
// tạo từng tiếng (2 lần) so khớp nếu giống nhau thì đặt flag ngay vị trí đầu của điểm lấy
//nếu gặp điểm đó sau đó sẽ bỏ qua
void DemTieng(char s1[]){
    myMemmove(s1,0,0);
    char c[MAX]; // biến tạm thay đổi liên tục các từ
    int flag[MAX]={0};//thay vì dùng bool thì dùng in để lưu độ dài từ
    int z=0;
    int count=1;
    int size=myStrlen(s1,0);
    for(int i=0;s1[i]!='\0';i++){
        if(flag[i]!=0){
            //nếu đã được tìm rồi thì không gọi nữa bỏ qua tìm từ tiếp theo
            // tìm size của c rồi i+=size
            i+=flag[i]; // sai do có thể size này của phần tử trước trước nữa của vòng lặp
        }
        // else if(s1[i]==' ' or s1[i]=='\n' or s1[i]=='\r'){//hết 1 từ thì tìm từ tiếp theo để so
//làm theo cách else if trên thì sẽ sai nếu trong chuỗi có \n
        else if(s1[i]==' ' or s1[i]=='\n' or s1[i]=='\r'){
            c[z]='\0';
            char d[MAX];//biến tạm lưu từ tiếp theo
            int u=0;
            for(int j=i+1;s1[j]!='\0';j++){
                
                if(s1[j]==' ' or s1[j]=='\n' or s1[j]=='\r'){ // phải thêm 2 or này vì có thể xét đến chữ cuối
                    d[u]='\0';
                    // sau dó so sánh hai cái
                    if(myStrcmp(c,d)==0){
                        
                        flag[j-u]=myStrlen(c,0); //j-u là vị trí đầu của từ
                        // cout<<c<<endl;
                        count++;
                    }
                    u=0;
                }
                else{
                    d[u++]=s1[j];

                }

            }
            z=0;
            // sizeofc=(myStrlen(c,0));
            cout<<c<<": "<<count<<endl;
            count=1;
        }
        else{
            c[z++]=s1[i];
        }
    }
}



// void DemTieng(char s1[]){
//     myMemmove(s1,0,0);
    

// }