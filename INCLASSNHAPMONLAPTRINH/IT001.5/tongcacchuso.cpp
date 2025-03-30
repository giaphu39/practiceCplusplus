
#include <iostream>


int input(int &a){
    std::cin>>a;
    return a;
}
int TongChuSo(int a){
    int ans=0;
    while (a!=0){
        int i = a%10;
        ans+=i;
        a/=10;
    }
    return ans;
}




int main() {
int a;
input(a);
std::cout << TongChuSo(a);
return 0;}