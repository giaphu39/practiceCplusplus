
// #include <iostream>
// using namespace std;
// #include <cstring>
// int main(){
//   int n;
//   cin>>n;
//   int u=n;
//   int count=0;
  
//   while(u!=0){
//     u/=10;
//     count++;
//   }
//   // // cout<<count;
//   // //đặt 1 cái để đánh dấu đã in gì
//   // for(int i=0;i<count;i++){
//   //   int max=-10;
//   //   int z=n;
//   //   for(int j=i;j<count;j++){
//   //     int q=z%10;

//   //     if(max<q) max=q;
//   //     z/=10;
//   //   }
//   //   cout<<max;
//   // }

//   // int c=count;
//   // // while(c!=0){
//   // //   int max=-10;

//   // // }
//   string ans;
//   string s=to_string(n);
//   int max=0;
//   for(int i=0;i<count;i++){
//     max=0;
//     int mark=-1;
//     for(int j=0;j<count;j++){
//       if((stoi(s[i]))>max){
//         max=stoi(s[j]);
//         mark=j;
//       } 
//     }
//     ans+=to_string(max);
//     s[mark]='0';
//   }
//   cout<<ans;
//   return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    int sl=0, m=n;
    int so_0=0;
    while(m)
    {
        if(m%10!=0) sl++;
        else so_0++;
        m/=10;
    }
    while(n)
    {
        if(n%10!=0)
            m=m*10+n%10;
        n/=10;
    }
    int result=0;
    while(1)
    {
        int dem=0;
        int max_val=m%10;
        for(int i=0; i<sl; i++)
        {
            if(max_val>m%10)
            {
                result=result*10+m%10;
            }
            else
            {
                int tmp=result, sl1=0;
                while(tmp)
                {
                    sl1++;
                    tmp/=10;
                }
                tmp=m%10;
                for(int k=0; k<sl1; k++)
                    tmp*=10;
                result=result+tmp;
                max_val=m%10;
                dem++;
            }
            m/=10;
        }
        m=result;
        if(dem==sl) break;
        else result=0;
    }
    if(so_0!=0)
    {
        for(int i=0; i<so_0; i++)
            result*=10;
    }
    cout << result << endl;
    return 0;
}​