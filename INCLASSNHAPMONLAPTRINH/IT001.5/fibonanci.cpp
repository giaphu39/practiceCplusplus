
#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int x){
    int n1=0, n2=1, n;
    if(x==1) n=1;
    else {for(int i=2;i<=x;i++){
        n=n1+n2;
        n1=n2;
        n2=n;
    }}
    return n;
}

int main()
{
	int x;
	cin >> x;
	if (x < 1 || x>30)
		cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
	else
	{
		cout << Fibo(x) << endl;
	}
	return 0;
}

