
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long prime[1000000];
// số có đúng 3 ước số là bình phương số nguyên tố
void sangngto(long long m)
{
    for(long long i=0;i<=m;i++)
    {
        prime[i]=1;
    }
    prime[0]=prime[1]=0;
    for(long long i=2;i<=sqrt(m);i++)
    {
        for(long long j=i*i;j<=m;j=j+i)
        {
            prime[j]=0;
        }
    }
}
int main(){
    long long a=0, b;
    cin>>b;
    sangngto(sqrt(b));
    for(long long i=2;i<=sqrt(b);i++)
    {
       if(prime[i]==1)
       {
           a++;
       }
    }
    cout<<a;
}