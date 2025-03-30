#include <bits/stdc++.h>

using namespace std;
//ý tưởng: lặp tất cả trường hợp
int main()
{
    int h,w,k;
    cin>>h>>w>>k;
    string s;
    cin.ignore(1);
    for(int i=0;i<h;i++){
        string temp;
        getline(cin,temp);
        s+=temp;
    }
//    cout<<s;
    int a[h][w];
    int z=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[z]=='.'){ // làm vậy là sai vì trong if sẽ tăng z++ lun else if sẽ là z++)++
                a[i][j]=1;// đã tô
                z++;
            }
            else if(s[z++]=='#'){
                a[i][j]=0;
            }
        }
    }
//    for(int i=0;i<h;i++){
//        for(int j=0;j<w;j++){
//                cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int ans=0;
    bitset<32> mr;
    bitset<32> mc;
    for(int maskrow=0;maskrow<(1<<h);maskrow++){
        for(int maskcol=0;maskcol<(1<<w);maskcol++){
            mr=maskrow;
            mc=maskcol;
            int oden=0;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(mr[i] && mc[j]){
                        if(a[i][j]==0) oden++;
                    }
                }
            }

            if(oden==k) ans++;

        }
    }
    cout<<ans;
    return 0;
}
