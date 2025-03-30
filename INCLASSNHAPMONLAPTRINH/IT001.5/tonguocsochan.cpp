 
#include <iostream>
using namespace std;

// Write your code here
int Input(){
    int n;
    cin>>n;
    return n;
}
void sum_even_divisor(int n){
    int ans=0;
    // cout << "Ước chẵn của "<<n<<" là: ";
    // for(int i=2;i<=n;i=i+2){
    //     if(n%i==0 and i%2==0){
    //         cout<<i;
    //         ans+=i;
    //     if(i<n){
    //         cout<<", ";  
    //       }
    //     else{
    //         break;
    //     }

    //     }
    for(int i=2;i<=n;i++){
        if(n%i==0 and i%2==0){
            ans+=i;
        }
    }
    if(ans==0){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
}


// int Input(){
//     int n;
//     cin>>n;
//     return n;
// }
// int sum_even_divisor(int n){
//     int ans=0;
//     // cout << "Ước chẵn của "<<n<<" là: ";
//     // for(int i=2;i<=n;i=i+2){
//     //     if(n%i==0 and i%2==0){
//     //         cout<<i;
//     //         ans+=i;
//     //     if(i<n){
//     //         cout<<", ";  
//     //       }
//     //     else{
//     //         break;
//     //     }

//     //     }
//     for(int i=2;i<=n;i++){
//         if(n%i==0 and i%2==0){
//             ans+=i;
//         }
//     }
//     if(ans==0){
//         return -1;
//     }
//     else{
//         return ans;
//     }
// }
int main() {
	int n;
	n= Input();
    // int ans=sum_even_divisor(n);
    sum_even_divisor(n);
    return 0;    
}
