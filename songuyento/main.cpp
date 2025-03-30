#include <iostream>

using namespace std;

int main()
{
    int n;
    int d=0;
    cin>>n;
    if(n==1){
        cout<<"ko phai so nguyen to";
    }
    if (n == 2){
		cout<<"so nguyen to";
	}

	for (int i = 2; i < (n - 1); i++){
		if (n % i == 0){
			cout<<"ko phai so nguyen to";
			d=1;
			break;
		}
	}

	if(d==0){
        cout<<"so nguyen to";
	}
    return 0;
}
