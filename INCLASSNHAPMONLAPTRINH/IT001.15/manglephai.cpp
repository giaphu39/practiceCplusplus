#include<iostream>
using namespace std;
#define MAX 2000
//ý tưởng: kiếm hàng làm chuẩn, các hàng sau thì cách ra bằng cách trừ chữ só hàng đầu
// dùng một mảng lưu các giá trị cach ra của từng phần tử
// sai ý tưởng phải là đếm chữ số mỗi cột cao nhất
int demsochu(int n){
    int c=0;
    n=abs(n);
    while(n!=0){
       c++;
       n/=10; 
    }
    return c;
}
int cachra(int n){
    if(n<0){return demsochu(n)+1;}
    else return demsochu(n);
}
//ý tưởng kiếm socach mỗi cột max lưu vào mảng 1 chiều lưu số max vào index theo cột
int* lapcotchuan(int** a, int r, int c, int** b){
    int* u= new int[MAX];
    //lặp qua từng cột, rồi so từng hàng => lặp qua từng cột thì cột giữ nguyên
    // bình thường lặp qua từng dòng rồi cột thì a[i][j] với j đổi trong, bây giờ giống ý chang mà i đổi trong
    for(int i=0;i<c;i++){ //lặp qua cột trc
        int maxcot=0;
        for(int j=0;j<r;j++){//lặp qua dòng
            if(cachra(a[j][i])>cachra(a[maxcot][i])){ 
                // maxcot=i; // lưu lại vị trí max
                maxcot=j; // phải là gán nó cho dòng ko phải cột
            }
        }
        u[i]=cachra(a[maxcot][i]);
    }
    return u;
}
int kiemhangchuan(int** a,int r, int c, int** b){
    //lặp qua từng hàng rồi đếm cachra của nó 
    int ans;
    int tongchusomax=0;
    for(int i=0;i<r;i++){
        int tongchuso=0;
        for(int j=0;j<c;j++){
            b[i][j]=cachra(a[i][j]);
            tongchuso+=b[i][j];
        }
        if(tongchuso>tongchusomax){
            ans=i;
            tongchusomax=tongchuso;
        }
    }
    return ans;
}
void sol(int** a,int r, int c, int** b,int u){

    for(int j=0;j<r;j++){
        for(int i=0;i<c;i++){
            //khoảng cách
            int q=b[i][u]-b[i][j];
            for(int z=0;z<q;z++){
                cout<<" ";
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sol2(int** a,int r, int c, int** b,int* u){
    for(int i=0;i<r;i++){
        
        for(int j=0;j<c;j++){
            int q=u[j]-cachra(a[i][j]);
            for(int z=0;z<q;z++){
                cout<<" ";
            }
            cout<<a[i][j]<<" ";

        }
        cout<<endl;
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    // int *a=new int[2000][2000]; // c++ không cho phép khai báo như vậy

    //cách khai báo mảng động 2 chiều
    int **a=new int*[MAX];
    for(int i=0;i<MAX;i++){
        a[i]=new int[MAX];
    }
    int **b=new int*[MAX];
    for(int i=0;i<MAX;i++){
        b[i]=new int[MAX];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    // cout<<kiemhangchuan(a,r,c,b);
    // int u=kiemhangchuan(a,r,c,b);
    // lập mảng bằng hàm chỉ có cấp phát động
    int* u=lapcotchuan(a,r,c,b);
    cout<<endl<<endl;
    sol2(a,r,c,b,u);
    return 0;
}