#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
void nhap(int& n, int arr[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}


bool issol(int n){
	
	if(n<=1){ return false;}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

void sol(int n, int arr[]){
    int count=0;
    for(int i=0;i<=n;i++){
        if(issol(arr[i])){
            count++;
            cout<<arr[i]<<" ";
        }
    }
    if (count==0) {cout<<0;}
}
int main(){
    int n;
    int arr[MAX];
    nhap(n,arr);
    sol(n,arr);
    return 0;
}