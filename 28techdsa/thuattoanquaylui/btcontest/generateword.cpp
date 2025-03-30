#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<utility>
int n,m;

bool ok=0;
char de[100][100];
string word;
bool used[100][100]; // nhớ phải đánh dấu kí từ đầu tiên tìm được nữa
string s="URDL";
string ans;
pair<int,int> moves[4]={{-1,0},{0,1},{1,0},{0,-1}};


void quaylui(int i, int j, int sizew){

    if(ans==word){
        ok=1;
        return; // quên này thì sai chắc vì không dừng
    }

    for(int z=0;z<4;z++){
        int i1=i + moves[z].first;
        int j1=j + moves[z].second;

        if(i1>=0 && j1>=0 && i1<n && j1<m && !used[i1][j1] && de[i1][j1]==word[sizew]){ // nhớ là dùng i1, j1
            used[i1][j1]=1;
            ans+= de[i1][j1];

            quaylui(i1,j1,sizew+1);

            used[i1][j1]=0;
            ans.pop_back();

        }

    }

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>de[i][j];
        }
    }            

    //nhớ phải ignore sau khi cin
    cin.ignore(1);

    getline(cin,word);

    //tìm kí tự đầu của word đã
    bool flag=0;
    for(int i=0;i<n;i++){
        if(flag) break;

        for(int j=0;j<m;j++){
            if(de[i][j]==word[0]){ // sai do lộn word thành s
                
                //lỗi chỗ này là nghiêm trọng nhất chưa bỏ phần tử đầu và used đầu vào
                ans+=word[0];
                used[i][j]=1;   
                quaylui(i,j,1);
                used[i][j]=0;
                ans.pop_back();
                if(ok){
                    // break;
                    flag=1;

                    break;// đặt sai vị trí
                }
            }

        }
        
    }  
    if(ok) cout<<"YES";
    else cout<<"NO";
    // cout<<word;
    return 0;
}
