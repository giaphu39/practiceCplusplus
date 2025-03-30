#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Số nguyên tố cùng nhau là ước chung lớn nhất của nó =1

//đệ qui ước chung lớn nhất: chia cho nhau liên tục
long long gcd(int a,int b){
    if(b==0){return a;} // nếu a chia hết b thì đó là ước chung lớn nhất
    else{return gcd(b,a%b);}
}
void giai(int a,int b){
        for(int i=a;i<=b;i++){
            for(int j=i+1;j<=b;j++){ // cộng thêm 1 tránh trường hợp trùng
                if(gcd(i,j)==1){
                    cout<<"("<<i<<","<<j<<")"<<endl;
                }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a,b;
    cin>>a>>b;
    giai(a,b);
    return 0;
}
