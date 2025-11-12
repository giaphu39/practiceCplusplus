

 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
 #include<vector>
# include<utility>

#define NGUOCHUONG -1

int CountInALLExecptDinh(int Dinh, map<int,set<int>> number_list){
    int COUNT = 0;
    for(pair<int, set<int>> x : number_list){
        if(x.first == Dinh) continue;
        for(int y : x.second){
            if(y == Dinh) COUNT++;
        }
    }
    return COUNT;
}

void Input(map<int,set<int>>& number_list,int& n){
    cin >> n;
    for(int i = 0 ; i < n;i ++){
        int v1; cin >> v1;
        int v2; cin >> v2;
        number_list[v1].insert(v2);
//        number_list[v2].insert(v1);
//        number_list[v2].insert(NGUOCHUONG);
    }

    int k; cin >> k;
    bool flag = 0;
    for(pair<int, set<int>> x : number_list){
        int COUNT = CountInALLExecptDinh(x.first, number_list) + x.second.size();
        if(k == COUNT){
            flag = 1;
            cout << x.first << " ";
        }
    }
    if(!flag) cout << "No find";
}










int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}

