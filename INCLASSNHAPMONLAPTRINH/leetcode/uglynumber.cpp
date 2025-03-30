#include<iostream>
#include<math.h>
using namespace std;

//ý tưởng phân tích thừa số nguyên tố mà không có cái nào khác 2,3,5
class Solution {
public:
    void phantichthuaso(int n){
        for(int i=2;i<=sqrt(n);i++){
            while(n%i==0){
                cout<<i<<" ";
                n/=i;
            }
        }
        if(n>1) cout<<n;
    }
    bool isUgly(int n) {
        if(n<1) return false;
        else if(n==1) return true;
        else{
            for(int i=2;i<=n;i++){ // không dùng sqrt của n được như trên vì ở trên là in ra phần còn lại
            //còn ở đây ví dụ: số 6 thì căn 6 =2.45 < 3 nên sẽ không chạy 3 mà đem xuống dưới so !=1
                if(i>5){return false;}
                while(n%i==0){
                    n/=i;
                }
                
            }
            if(n!=1) return false;
            return true;
        }
    }
};
int main(){
    int n;
    cin>>n;
    Solution a;
    cout<<a.isUgly(n);
    return 0;
}