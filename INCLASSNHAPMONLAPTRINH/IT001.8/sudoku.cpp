//ý tưởng: đánh dấu vị trí x khi nhập mảng 92
// quay lui 9 mũ 5 lần sao cho tổng khi vào vị trí đó tổng cột, tổng hàng, tổng 9 ô xung quanh =45;
// thay vì lấy tổng 45 thì xét số nào chưa xuất hiện


// cách 2: đặt tất cả số vào x sau đó kiểm tra xem mảng thỏa không nếu không thỏa thì quay lui.
#include <iostream>
#include <string>
using namespace std;
const int size1=9;// nếu muốn đặt 1 biến thành mảng mà ở ngoài global thì phải đặt const
// 9:9: error: reference to 'size' is ambiguous // nghĩa là trùng tên với tên hàm có sẵn
string result;
int arr[size1][size1];
char debai[size1][size1];

void ketqua(){
    for(int i=0;i<size1;i++){
        for(int j=0;j<size1;j++){
            result+=to_string(arr[i][j]) + " ";
        }
        result+="\n";
    }
    result+="\n";
}
void nhap(){
    for(int i=0;i<size1;i++){
        for(int j=0;j<size1;j++){
            cin>>debai[i][j];
            if(debai[i][j]!='X'){
                arr[i][j]=int(debai[i][j]-'0');
            }
            else{
                arr[i][j]=0;
            }
        }
    }    
}
bool check(int a[size1][size1], int row, int col, int i){
    //check cột
    for(int j=0;j<size1;j++){
        if(a[row][j]==i) return false;
    }
    //check dòng
    for( int j=0;j<size1;j++){
        if(a[j][col]==i) return false;
    }
    //check trong ô??????????
    int strow=row-row%3;
    int stcol=col-col%3;
    for(int j=strow;j<=strow+2;j++){
        for(int e=stcol;e<=stcol+2;e++){
            if(a[j][e]==i) return false;
        }
    }

    return true;
}
void _try(int a[size1][size1], int row, int col){
    // điều kiện kết thúc, phải cẩn thận điều kiện này nhất
    if(row==size1-1 and col==size1-1){ //sai trường hợp
        ketqua();
        return; // chỉ in 1 lần
    }
    // điều kiện tăng dòng 
    if(col==size1-1){
        col=0;
        row++;
    }
    // điều kiện tăng cột tăng cho đến khi gặp X được đại diện =0
    if(a[row][col]>0){ 
        _try(a,row,col+1);
        return; // phải đặt cái này nếu không sẽ gọi rất nhiều gây nên overflow
    }
    //khi đã gặp x thì đặt 1-9 vào ô rồi check thỏa điều kiện
    for(int i=1;i<=9;i++){
        if(check(a,row,col,i)){
            arr[row][col]=i;
            _try(arr,row,col+1); // lặp đến đâu thì bị backtrack lại?
        }
        arr[row][col]=0;// backtracking lại 
    }
}
int main(){
    nhap();
    _try(arr,0,0);
    cout<<result;
    return 0;
}   
