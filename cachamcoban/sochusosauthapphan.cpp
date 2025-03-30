#include <iostream>
#include <cmath>
using namespace std;
//xây dựng hàm
int countafter(double num){
    double thapphan=num-int(num);
    int dem;
    while(thapphan<1 and thapphan>0.01){
        thapphan*=10;
        thapphan=thapphan-int(thapphan);
        dem++;
        if(dem>=10){
            dem=11;
            break;
        }
    }
    return dem;
    }


int main() {
    double num = 123.456789;
    int dem=0;
    double thapphan=num-int(num);
    // cout<<num<<endl;
    cout<<thapphan<<endl;
    while(thapphan<1 and thapphan>0.1){ // lấy 0.01 hoặc 0.1 vì sau khi trừ số cuối thì sẽ có số tiệm cận 0 rất bé 
    //nên chỉ cần dùng 0.1 không nên lấy số quá bé như 0.000000000001 thì chắc chắn sẽ đếm tiếp

    // sai ở chỗ nếu cho số 9.0007
        thapphan*=10;
        thapphan=thapphan-int(thapphan);
        // cout<<thapphan<<endl;
        dem++;
    
        if(dem>=10){
            break;
        }
    }

    double a;
    cin>>a;
    cout<<countafter(a);
    // cout<<dem;
    // std::cout << "So chu so sau dau phay: " << demChuSoSauDauPhay(num) << std::endl;
    return 0;
}
