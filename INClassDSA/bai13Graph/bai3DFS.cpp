#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;


void Input(vector<vector<int>>& G , int v, int e, map<string, int>& v_index){
    for(int i = 0; i < v; i++){
        string temp; cin >> temp;
        v_index[temp] = i;
    }

    for (int i = 0; i < e ; i++){
        string temp1 ; cin >> temp1;
        string temp2; cin >> temp2;
        int ind1 = v_index[temp1];
        int ind2 = v_index[temp2];
        G[ind1][ind2] = 1;
    }


}
#include<utility>
string chuyenDoiKieuInt(map<string, int> v_index, int target){
    for(pair<string, int> x : v_index){
            if(x.second == target) return x.first;
    }
}


void Fun(vector<vector<int>>& G , int v, int e, map<string, int>& v_index){
    string diemBatDau; cin >> diemBatDau;

    stack<int> open;
    vector<string> close;
    open.push(v_index[diemBatDau]);
    int target = v_index[diemBatDau]; // diem dang xet
//    vector<vector<int >> visited (v,vector<int> (v,0));
    vector<bool> visited(v, false);
    visited[target] = true;
    while(!open.empty()){
        target = open.top();
        open.pop();

        close.push_back(chuyenDoiKieuInt(v_index,target)); // choox nay sua

        for(int i = 0 ; i< G[target].size() ; i++){
//            if(G[target][i] && !visited[target][i]){ // kt da duyet truoc chua
//                    visited[target][i] = 1;
//                temp.push_back(i);
//            }
            if(G[target][i] && !visited[i]){
                visited[i] = true;
                open.push(i);
            }


        }


    }

    for(int i = 0 ; i < close.size() ; i ++){
        cout << close[i] << " ";
    }

}





int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> NameIndex; // Danh sách ánh xạ tên đỉnh --> index
	Input(G,v,e,NameIndex);
	// DFS(G,v_index,v);
    Fun(G,v,e,NameIndex);
	return 0;
}
