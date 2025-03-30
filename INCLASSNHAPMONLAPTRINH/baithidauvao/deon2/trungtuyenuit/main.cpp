#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> a(n+1,vector<int>(m+1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++){
            cin>>a[i][j];
        }
    }
    //dùng bitset lặp qua các trường hợp bỏ nó vào mảng chứa độ thuần thục của bài toán
    bitset<32> b;
    int flagtungin=0;
    int ans=INT_MAX;
    int total=1<<n; // số tổ hợp lặp qua các sách
    for(int mask=0;mask<total;mask++){
        vector<int> dothuanthuc(m+1,0); // phần tử đầu chứa giá, phần tử sau chứa độ thuần thục
        b=mask;
        for(int i=0;i<n;i++){ // lặp qua các trường hợp sách
            if(b[i]){
                //lặp qua giá và độ thuần thục
                for(int j=0;j<m+1;j++){
                    dothuanthuc[j]+=a[i][j];
                }
            }
        }

        //xét điều kiện tìm được
        int flag=1;
        for(int i=1;i<m+1;i++){
            if(dothuanthuc[i]<k) flag=0;
        }
        if(flag) {
            ans=min(ans,dothuanthuc[0]);
            flagtungin++;
        }
    }
    if(flagtungin==0) cout<<-1;
    else cout<<ans;



    return 0;
}
