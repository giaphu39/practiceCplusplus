#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<climits>
// cách 1: dùng mảng đánh dấu 
//cách 2: sort rồi khi kết thúc số đó thì so nó với số được lưu

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    int ans;
    int Countans=0;
    int temp=a[0];
    int Counttemp=0;
    for(int i=1;i<a.size(),i++){
        if(a[i] == temp ){
            Counttemp++;
        }
        else{
            if(Countans <= Counttemp){
                if(Countans == Counttemp){
                    
                }
            }
        }
    }

    return 0;
}
