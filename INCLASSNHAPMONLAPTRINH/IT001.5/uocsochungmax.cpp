#include <iostream>
using namespace std;

int input(){
    int a;
    std::cin>>a;
    return a;
}
int input(int &b){
    std::cin>>b;
    return b;
}
int gcd(int a, int b){
    int min=std::min(a,b);
    int ans=0;
    for(int i=1;i<=min;i++){
        if(a%i==0 and b%i==0){
            if(ans<=i){
                ans=i;
            }
        }
    }
    return ans;
}


int main() {
	int m, n;
	input(n);
	m=input();
	cout << gcd(m, n);
}