
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n,int y);

void NhapmangSNT(int a[], int &n){
	cin>>n;
	for(int i=0;i<n;i++){
		a[i]=i;
	}
}
bool coso(int n, int u){
    while(n!=0){
		int z=n%10;
		if(z==u) return true;
		n/=10;
	}
	return false;// nhớ chỗ này
}
bool issol(int n){
	
	if(n<=1){ return false;}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

int SoPhanTuChuaY(int a[], int n,int y){
	int count=0;
	int j=n;
	for(int i=0;;i++){
		if(issol(i)){
			if(j==0){
				break;
			}
			j--;
			if(coso(i,y)){
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int a[MAX], n, y;
	cin >>y;
	NhapmangSNT(a,n);
	cout << SoPhanTuChuaY(a, n, y) << endl;;
	return 0;
}