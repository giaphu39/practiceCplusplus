#include<iostream>
using namespace std;
#define MAX 300
void mySubstr(char s[], int b, int count, char ss[]){//hàm xóa
    for(int i=b;s[i]!='\0';i++){//b là vị trí bị xóa
        s[i]=s[i+1];
    }
    // không thao tác được gì trên size
}
int myStrlen(char s[], int k){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count-1;// -1 để loại bớt kí tự \n
}
void strcat(char s1[] , char s2[], int size1, int size2){
    // s1[size1]=' ';
    // để ý kĩ test case
    // Toi la
    // sinh vien
    // có khoảng trống space ngay chỗ la 
    int i; int ind=0;
    for( i=size1;i<=size1+size2-1;i++){
        s1[i]=s2[ind++];
    }
    s1[i]='\0';
}
int main(){
    char s1[MAX];
    char s2[MAX];
    fgets(s1,MAX,stdin);
    fgets(s2,MAX,stdin);
	int size1=myStrlen(s1,0);
    int size2=myStrlen(s2,0);
    // cout<<size1<<" "<<size2<<endl; // từ đây suy ra size lấy lun kí tự \n
    // có cách là dùng string rồi cộng hai chuỗi
    
    if(size1+size2>254){
        cout<<"Khong noi duoc. Khong du bo nho.";
    }
    else {
        strcat(s1,s2,size1,size2);
        cout<<s1;
    }

    return 0;
}