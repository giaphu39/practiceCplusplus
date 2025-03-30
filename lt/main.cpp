#include <iostream>

using namespace std;
# include<cstdio>
int main()
{
    freopen("sochan.inp","r",stdin );
    freopen("sochan.out","w",stdout);
    int n;
    cin>>n;
    int temp;
    int flag;
    for (int i=0;i<n;i++){
        cin>>temp;
    int d=2;
    if (temp==1){
        cout<<temp<< " ko phai so nguyen to"<<endl;
    }
    if (temp== 2){
		cout<<temp<< " so nguyen to"<<endl;
	}

	else if(temp>2){
        for (int j = 2; j <temp; j++){
		if (temp % j == 0){
			cout<<temp<<" ko phai so nguyen to"<<endl;
			d=1;
			break;
		}
		else{
            d=0;
		}
	}

	}
	if(d==0){
        cout<<temp<<" so nguyen to"<<endl;
	}
    }
    return 0;
}
