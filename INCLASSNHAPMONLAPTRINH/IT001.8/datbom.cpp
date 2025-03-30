#include<iostream>
#include<cstring>
using namespace std;
int matdo[4][4];
int arr[4][4];
// tạo một mảng 2 chiều xung quanh bom 
void nhapmatdo(){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            cin>>matdo[i][j];
        }
    }
}
void cauhinhdau(){
    memset(arr,0,sizeof(arr));
}
void ketqua(){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int dembomxungquanh(int dong, int cot){
    int count=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            //lấy các cái xung quanh ra 
            int di=dong+i, dj=cot+j;
            if(di>=0 and dj>=0 and di<=3 and dj<=3 and !(i == 0 && j == 0)){
                count += arr[di][dj]; // nghĩa là có bom mới count++
            }
        }
    }
    return count;
}
bool trungkhop(){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            // if(arr[i][j]!=matdo[i][j]) return false; // sai do bản đồ bom khác bản đồ mật độ phải trích xuất mật độ từ bản đồ bom
            if(dembomxungquanh(i,j)!=matdo[i][j]) return false;
        }
    }
    return true;
}
void _try(int i, int j){
        if(i==4){ //
            if(trungkhop()) {
                ketqua();
                
            }
            return;
        }
        // chạy các i j 
        int nexti= (j==3)? i+1: i;//cột tăng dần trước sau đó hàng tăng do đó cuối cùng là i=4
        int nextj= (j==3)? 0:j+1;
        _try(nexti,nextj); // trường hợp vị trí đó không bom
        arr[i][j]=1;
        _try(nexti,nextj);// trường hợp vị trí đó có bom
        arr[i][j]=0; // backtracking lại


    }


int main(){
    nhapmatdo();
    cauhinhdau();
    _try(0,0);
    return 0;
}