class Solution {
public:
    int demchuso(int n){
    int dem=0;
    while(n!=0){
        n/=10;
        dem++;
    }
    return dem;
}
// phải đặt unsigned long long để có độ rộng cao nếu không sẽ out of range
unsigned long long mu(int b){
    unsigned long long ans=1;
    for(int i=1;i<b;i++){
       ans*=10; 
    }
    return ans;
}
long long reverse(int n){
    unsigned long long ans=0;
    int dem=demchuso(n);
    
    for(int i=dem;i>=1;i--){
        int u=i-1;
        if(i==1) ans+=n%10;
        else ans+=(n%10)*(mu(i));
        n/=10;
    }
    return ans;
}

    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else if(x==reverse(x)){
            return true;
        }
        else return false;
    }
};