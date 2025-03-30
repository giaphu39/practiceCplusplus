#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    int k;
    cin>>n>>k;
    int*a = new int[n];
    int *b= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    //ý tưởng sắp xếp mảng này theo thứ tự giá tiền tăng dần, trừ hết sl thì xong

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>=b[j]){
                swap(b[i],b[j]);
                swap(a[i],a[j]);
            }
        }
    }
    int ans=0;
    int i=0;
    while(k>0){
        k-=a[i];
        if(k<0){
//            ans+= (b[i++]*(a[i]-abs(k)));
            //dòng này sai vì i++ thì sau đó a[i+1]
            ans+= (b[i]*(a[i++]-abs(k)));
        }
        else{
            ans+=b[i]*a[i++];
        }
    }
    cout<<ans<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    delete[] a;
    delete[] b;
//    pair <int,int> a;

    return 0;
}
