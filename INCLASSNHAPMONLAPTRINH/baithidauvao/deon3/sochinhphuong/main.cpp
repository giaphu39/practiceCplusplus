#include <bits/stdc++.h>

using namespace std;
// đếm cặp số nguyên dương từ một tập hợp các số nguyên dương không lớn hơn số nguyên N
int* sang=new int[100000];
void sangnguyento(int n){
    memset(sang,1,n);
    sang[0]=0;
    sang[1]=0;
    for(int i=2;i<=sqrt(n);i++){

        for(int j=i*i;j<=n;j+=i){
            sang[j]=0;
        }
    }

}
bool phantichntchan(int n){
    for(int i=2;i<=sqrt(n);i++){
        int div=0;
        while(n%i==0){
            div++;
            n/=i;
        }
        if(div%2!=0) return false;
    }
    if(n==1) return true;
    else if(n>1) return false; // vẫn còn 1 số nguyên tố là lẻ=>false
}
int main()
{

    int n;cin>>n;
    int ans=0;
    //giảm đc trường hợp i*i, trường hợp i*so không phải nguyên tố
//    sangnguyento(n);

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            int u=i*j;
//            if(pow(sqrt(u),2)==u)ans++;
//        }
//    }
    for(int i=1;i<=n;i++){
//        ans++; // từng i*i
        for(int j=1;j<=n;j++)
        if(phantichntchan(i*j)) ans++;
    }
    cout<<ans;
    return 0;
}
