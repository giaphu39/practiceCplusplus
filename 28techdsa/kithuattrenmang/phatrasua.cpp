#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<vector>

#define MAX 200000
//n là số 1 g bỏ vào cốc l-> r
//k là gam >= để đạt chuẩn 
//q là truy vấn -> số cốc đạt chuẩn trong khoảng l->r


int main() {

    int n,k,q;cin>>n>>k>>q;
    int maxsugar=0;
    vector<int> sococdatchuan(MAX);
    vector<int> sugar(MAX+1,0);
    while(n--){
        int l,r;cin>>l>>r;
        sugar[l]+=1; // phải là l vì l có thể là 0
        sugar[r+1]-=1;

        if(r>=maxsugar) maxsugar=r;
    }

    // tính sugar mỗi cốc

    for(int i=1;i<=maxsugar;i++){
        sugar[i]+=sugar[i-1];
    }
    sugar.pop_back();
    //luôn luôn giá trị cuối sẽ là giá trị rác

    while(q--){
        int l,r;cin>>l>>r;
        // int flag=1;
        int coun=0;
        for(int i=l;i<=r;i++){
            if(sugar[i]>=k){
                // flag--;
                // break;
                coun++;
            }
        }
        cout<<coun<<endl;
    }

    return 0;
}
