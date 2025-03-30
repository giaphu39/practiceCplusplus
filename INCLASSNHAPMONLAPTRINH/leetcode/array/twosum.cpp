#include<iostream>
using namespace std;
#include <vector>

#define MAX 300

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        // for(int i=0;i<nums.size()-1;i++){
        //     cin>>nums[i];
        // }
        // cin>>target; 
        bool flag= false;
        for(int i=0;i<nums.size();i++){
            if(flag) break;
            for(int j=i+1;j<nums.size();j++){ // tại sao phải kéo tới num.size() mà không phải num.size()-1 
            // tương tự cho 0-> n-1 thì dùng <n;
                if(nums[i]+nums[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                    flag=true;
                    break;
                }
            }
        }
        return v;
    }
int main(){
    int n;
    cin>>n;
    int a[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t; cin>>t; // target
    bool flag= false;
    for(int i=0;i<n;i++){
        if(flag) break;
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==t){
                cout<<i<<" "<<j;
                flag=true;
                break;
            }
        }
    }
}