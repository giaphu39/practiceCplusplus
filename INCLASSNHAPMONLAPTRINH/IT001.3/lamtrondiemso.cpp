#include<iostream>
#include<iomanip>
using namespace std;
// #define ll long long
typedef long long ll; // long long là kiểu int dài nên sai
#define ld long double
#include <math.h>
// int countafter(double num){ // nhược điểm không đếm được số nhỏ hơn 0.01
    // double thapphan=num-int(num);
    // int dem;
    // while(thapphan<1 and thapphan>0.01){
    //     thapphan*=10;
    //     thapphan=thapphan-int(thapphan);
    //     dem++;
    //     if(dem>=10){
    //         dem=11; // số vô hạn sẽ đc gán là 11
    //         break;
    //     }
    // }
    // return dem;
    // }
int main(){
    // ý tưởng: nhân a cho n rồi làm tròn n sau đó chia lại n
    // đúng 10 số: đếm số trước thập phân rồi trước khi chia thì dùng fix (lấy 10-dem) (đếm sau khi làm tròn)
    // sai ngay từ đầu là đúng 10 số: đếm số sau thập phân nếu >= 10 thì dừng nếu lớn hơn 10 thì fixed còn không lớn 
    //hơn 10 là số không vô hạn thập phân không cần fixed
    // biến b để đếm d để ra đáp án

    // lỗi phát sinh: kiểu int không làm tròn lên hoặc xuống mà chỉ lấy phần nguyên (làm tròn xuống)
    ld a;
    int n;
    int dem=0;
    cin>>a>>n;
    // int c=a*n;
    double d=a*n;
    // cout<<c<<endl;
    d=int(round(d));
    // cout<<int(round(d))<<endl; // nhớ đây chỉ là in chứ chưa gán phải gán mới đúng giá trị
    double ans=d/n;
    n=ans; // gán lại dùng n để tiết kiệm ô nhớ 
    // cout<<n<<endl;
    while(n!=0){
        n/=10;
        dem++;
    }
    // cout<<dem<<endl;
    // int demsau=countafter(ans);
    // // cout<<demsau<<endl;
    // if (demsau>=10){
    //     cout<<fixed<<setprecision(10-dem)<<ans;
    // }
    // else{
    //     cout<<ans;
    // }
// giải quyết lỗi này bằng cách không ghi fixed
    cout<<setprecision(10)<<ans;


    return 0;
}