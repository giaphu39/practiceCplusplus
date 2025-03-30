#include<iostream>
using namespace std;
#define MAX 100
int myStrlen(char s[], int k){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count;
}
void xoa(char s[],int k){
    // size=myStrlen(s,0);
    for(int i=k;s[i]!='\0';i++){
        s[i]=s[i+1];
    }
}
// trường hợp chữ đầu không phải chữ
void chuanhoa(char s[]){
    //chữ đầu viết hoa nếu là chữ, nếu gặp khoảng trắng thì in hoa
    int flag=0;
    for(int i=0;s[i]!='\0';i++){
        if(i==0 ){
            if(s[i]<='z' and s[i]>='a'){
                s[i]-=32;
            }
        }
        if(s[i]==' ') { // dòng này xóa các khoảng cách dư
            flag =1;
            while(s[i+1]==' ') xoa(s,i+1);
        }
        else if(flag==1 and s[i]<='z' and s[i]>='a'){
            s[i]-=32;
            flag=0;
        }
        else if(s[i]<='Z' and s[i]>='A' and i!=0){
            if(flag==1){
                flag=0;
            }
            else s[i]+=32;
        }
        else flag=0; // dòng này giúp không phải chữ mà ở đầu dòng thì sẽ mất cờ, xong sẽ ảnh hưởng chữ số đầu Nếu viết hoa
        
    }
    if(s[0]==' ') xoa(s,0); // sau khi làm xong hết còn 1 khoảng trắng ngay đầu thì cần xóa
}
void in(char s[]){
    cout<<s;
}
int main(){
    char s[MAX];
    fgets(s,MAX,stdin);
    chuanhoa(s);
    in(s);
    return 0;
}