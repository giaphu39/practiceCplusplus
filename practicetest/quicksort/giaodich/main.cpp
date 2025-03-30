#include <iostream>

//3 4
//110 90 120
//100 80 120 10000

//110

// cổ đông >= ai mới bán
// đầu tư <= bi mới mua
// số cổ đông >= số người đầu tư cho mức giá tối thiểu

using namespace std;

void input(int*a,int n){

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

bool R(int x, int * a, int * b, int n, int m){
    int SoCoDong=0;
    int SoDauTu=0;

    for(int i=0;i<n;i++){
        if(x >= a[i]) SoCoDong++;

    }

    for(int i=0;i<m;i++){
        if(x <= b[i]) SoDauTu++;

    }

    return SoCoDong >= SoDauTu;
}

int Search(int l, int r, int *a, int *b, int n, int m){
    int SoCanTim =-1;
    while(l <= r){
        int mid = l + (r-l)/2;


        if(R(mid, a, b,n,m)){
                SoCanTim = mid;
                r = mid -1;
        }

        else{
            l = mid +1;
        }

    }

    return SoCanTim;

}
int main()
{
    int n,m;
    cin>>n>>m;

    int a[n];
    int b[m];
    input(a,n);
    input(b,m);

    int MAX = int(1e9);

    cout<<Search(0,MAX,a,b,n,m);
    return 0;
}
