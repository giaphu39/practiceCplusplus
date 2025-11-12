#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include<iostream>
using namespace std;

int Bac(vector<vector<int>> G, int u, int v)
{
    int dem=0;
    for(int i=0;i<v;i++)
        if(G[i][u]>0) dem++;
    for(int i=0;i<v;i++)
        if(G[u][i]>0) dem++;
    return dem;
}

string TenDinh(map<string, int> v_index, int u)
{
    for( map<string, int>::iterator itr = v_index.begin( ); itr != v_index.end( ); ++itr )
        if(itr->second==u)
            return itr->first;

}

vector<string> dinhke(vector<vector<int> > G,map<string, int> v_index,string p, int v)
{
    vector<string> ds;
    for(int i=0;i<v;i++)
        if(G[v_index[p]][i]==1)
        {
            ds.push_back(TenDinh(v_index,i));
        }
    return ds;
}

void Input(int v,map<string, int> &v_index, int e,vector<vector<int>> &G)
{
    string s;
    for(int i=0;i<v;i++)
    {
        cin>>s;
        v_index[s]=i;
    }
    string x,y;
	for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        G[v_index[x]][v_index[y]]=1;
    }



//    cin>>s;
//    int flag=0;
//    for(int i=0;i<v;i++)
//        if(G[v_index[s]][i]>0)
//         {
//             cout<<TenDinh(v_index,i)<<" ";
//             flag=1;
//         }
//    if(flag==0) cout<<"No find";



//    for(int i=0;i<v;i++)
//    {
//        for(int j=0;j<v;j++)
//            cout<<G[i][j]<<" ";
//        cout<<endl;
//    }


}



void DFS(vector<vector<int> > G,map<string, int> v_index, int v)
{
   // vector<vector<int> > matrix; 	 // ma trận kề của đồ thị
//    vector<string> v_list;           	 //  lưu danh sách các tên đỉnh (chuỗi)
//    map<string, int> v_index;   	 //  ánh xạ từ tên đỉnh sang index để có thể truy xuất thông tin trong ma trận kề


    stack<string> open;  		// lưu các đỉnh chờ duyệt
    vector<bool> close(v, 0);  	// lưu thông tin đỉnh nào đã đi qua rồi
    map<string, string> parent; 	// lưu thông tin cha con, parent[u]=v nghĩa là cha của u và v

    bool found = false;
    string s,g; // đỉnh bắt đầu s, đỉnh kết thúc g
    //cin>>s>>g;
    cin>>s;
    open.push(s);
    while (!open.empty())
    {
        string p = open.top();
        cout<<p<<"\t";
        open.pop();
        //if (p == g) {found = true; break; }
        close[v_index[p]] = 1;
        vector<string> q = dinhke(G,v_index,p,v);
        for (int i = 0; i < q.size(); i++)
        {
            if (close[v_index[q[i]]]== 0)
                open.push(q[i]);
           // parent[dinhke[i]] = p;
        }
    }
//
//    for(int i=0;i<v;i++)
//        cout<<close[i]<<" ";

    //Bước 3: Xử lý xuất đường đi hoặc kết luận không tìm thấy

}



void BFS(vector<vector<int> > G,map<string, int> v_index, int v)
{
    queue<string> open;  		// lưu các đỉnh chờ duyệt
    vector<bool> close(v, 0);  	// lưu thông tin đỉnh nào đã đi qua rồi
    map<string, string> parent; 	// lưu thông tin cha con, parent[u]=v nghĩa là cha của u và v

    bool found = false;
    string s,g; // đỉnh bắt đầu s, đỉnh kết thúc g
    //cin>>s>>g;
    cin>>s;
    open.push(s);
    while (!open.empty())
    {
        string p = open.front();
        cout<<p<<"\t";
        open.pop();
        //if (p == g) {found = true; break; }
        close[v_index[p]] = 1;
        vector<string> q = dinhke(G,v_index,p,v);
        for (int i = 0; i < q.size(); i++)
        {
            if (close[v_index[q[i]]]== 0)
                open.push(q[i]);
           // parent[dinhke[i]] = p;
        }
    }
//
//    for(int i=0;i<v;i++)
//        cout<<close[i]<<" ";

    //Bước 3: Xử lý xuất đường đi hoặc kết luận không tìm thấy

}



int main()
{ 

    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	DFS(G,v_index,v);
	return 0;
}