
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	fgets(s,MAX,stdin);
	fgets(s1,MAX,stdin);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{
        ChenChuoiTaiVitriK(s,s1,k);
        cout<<s;
        // cout<<endl<<myStrlen(s,0);
    }
    return 0;
}
int myStrlen(char s[], int k){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count-1;//=> không lấy \n
}
void mySubstr(char s[], int b, int count, char ss[]){//hàm xóa
    for(int i=b;s[i]!='\0';i++){//b là vị trí bị xóa
        s[i]=s[i+1];
    }
    // không thao tác được gì trên size
}
bool myStrcat(char s1[], char s2[]){
    int i; int ind=0;
    int size1=myStrlen(s1,0);
    int size2=myStrlen(s2,0);
    for( i=size1;i<=size1+size2-1;i++){
        s1[i]=s2[ind++];
    }
    s1[i]='\0';
}
void mySubstr(char s[], int b, int count, char ss[]){// hàm chép phần đầu( theo vị trí b) s vào ss
    for(int i=0;i<=b;i++){
        ss[i]=s[i];
    }
}
// void ChenChuoiTaiVitriK(char s[], char s1[], int k){
//     int size1=myStrlen(s1,0);
//     int size=myStrlen(s,0);
//     int ind1=0;int i;
//     for( i=k;i<=size1+1;i++){ // phải là size1 +1 vì nó xét tiếp tới dấu cách
//         //cứ đẩy lên liên tục rồi đặt tại trí đó char s1
//         size++;
//         for(int j=size;j>i;j--){
//             s[j]=s[j-1];
//         }
//         s[i]=s1[ind1++];
//     }
//     //nếu k là vị trí ở space thì cuối khi thêm phải thêm ' '
//     // if(s[k]==' '){
//     //     for(int j=size;j>i;j--){
//     //         s[j]=s[j-1];
//     //     }
//     //     s[i]=' ';       
//     // }
//     //sai 
// }
void ChenChuoiTaiVitriK(char s[], char s1[], int k){


    int size=myStrlen(s,0);
    int size1=myStrlen(s1,0);
    // cout<<size<<" "<<size1<<endl;
    // for(int i=size+size1-1;i>=k+size1-1;i--){

    // }
    //cộng dồn lên
    for(int i=size;i>=k;i--){
        s[i+size1]=s[i]; // đặt cho vị trí thứ i cộng dồn lên size1 = i
    }
    int ind1=0;
    for(int i=k;i<=k+size1-1;i++){// -1 vì không tính \n và bắt đầu từ 0
        s[i]=s1[ind1++];    
    }
}