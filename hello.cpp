// #include<iostream>
// using namespace std;



// int main(){


//     // int n;cin>>n;
//     // int s=(n*(n+1))/2;
//     // cout<<s/n<<endl;
//     // int flag=0;
//     // for(int i=1;i<=n;i++){
//     //     if(i%2==0){
//     //         flag++;
//     //         cout<<i<<" ";
//     //     }
//     // }
//     // if(!flag){
//     //     cout<<"NotFound";
//     // }
    
//     int temp;cin>>temp;
//     int min1=temp;
//     int min2=temp;
//     while(1){
//         cin>>temp;
//         if(temp == 0) break;
//         if(temp <= min1){
//             min2 = min1;
//             min1 = temp;
            
//         }
//         else if(temp > min1 && temp <= min2){
//             min2=temp;
//         }
//     }
//     cout<<min2;

//     // int temp;cin>>temp;
//     // int max1=temp;
//     // int max2=temp;
//     // while(1){
//     //     cin>>temp;
//     //     if(!temp) break;

//     // }

//     return 0;
// }
#include<iostream>  
using namespace std;  
int Search (int A[], int n, int x) {  
  int l = 0, r = n-1;  
  int m=(l+r)/2;  
  while (l <= r) {  
    m=(l+r) / 2;  
    if (x == A[m])  
    {  
      cout<<l<<"-"<<r;  
      return m;  
    }  
    if (x > A[m]) r = m - 1;  
    else l = m + 1;  
  }  
  return -1;  
}  
int main()  
{  
  int a[]={5,4,3,2,1};  
  Search (a,5,5);  
  return 0;  
}  
