

 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
 #include<vector>
# include<utility>

void Input(vector<vector<int>>& G,int v, int e){
    for(int i = 0 ; i< e; i++){
        int v1; cin >> v1;
        int v2; cin >> v2;
        int trongSo; cin>> trongSo;
        G[v1][v2] += trongSo;

    }

    for(int i = 0 ; i< v ; i++){
        for(int j = 0; j < v; j++){
            if(G[i][j]){
                cout << G[i][j] << " ";
            }
            else cout << 0 << " ";
        }
        cout << endl;
    }

}








int main()
{
	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0));
	Input(G,v,e);
	return 0;
}
