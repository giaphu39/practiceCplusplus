#include<iostream>
using namespace std;
#include <cstring>
int n,arr[100],cot[100],d1[100],d2[100]; // chú ý nếu bài toán quá lớn thì d1 d2 phải là 2*n nghĩa là 200
int a[100][100];
int count=0;//đếm số cách đặt quân hậu
void cauhinhdau(){
    for(int i=1;i<=100;i++){
        cot[i]=d1[i]=d2[i]=1;
    }
}
void ketqua(){
    for(int i=1;i<=n;i++){ 
        cout<<"con hau o hang "<<i<<" o cot "<<arr[i];
        cout<<endl;
    }
}

void ketqua2(){
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        a[i][arr[i]]=1; // đánh dấu các con hậu
    }
    
    //in ra toàn bộ bàn cờ
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<< a[i][j]; 
        }
        cout<<endl;
    }
    cout<<endl; // để cách các đáp án ra

}

// có bài toán là + giá trị trong used sử dụng xong thì trừ ra
void _try(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==1 and d1[i-j+n]==1 and d2[i+j-1]==1){ // nhớ tất cả lệnh thực thi đều sau if này
            arr[i]=j;
            cot[j]=d1[i-j+n]=d2[i+j-1]=0;
            if(i==n){
                // ketqua();
                // ketqua2();
                count++;

            }
            else{
                _try(i+1);
            }
            cot[j]=d1[i-j+n]=d2[i+j-1]=1;
        }
    }
}
int main(){
    cin>>n;
    cauhinhdau();// cho các ô trống
    _try(1);
    cout<<count;
    return 0;
}