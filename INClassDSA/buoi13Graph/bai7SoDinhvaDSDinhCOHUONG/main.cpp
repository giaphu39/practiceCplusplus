

 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
 #include<vector>
# include<utility>

void Input(map<int,set<int>>& number_list,int& n){
    cin >> n;
    for(int i = 0 ; i < n;i ++){
        int v1; cin >> v1;
        int v2; cin >> v2;
        number_list[v1].insert(v2);
    }

//    cout << number_list.size();
//    cout << endl;
    int Count = 0;
    vector<int> mark (n,0);
    for(auto x : number_list){
        if(mark[x.first] == 0){
            mark[x.first] = 1;
            Count++;
        }
        for( int y : x.second){
            if(mark[y] == 0){
                mark[y] = 1;
                Count++;
            }
        }


    }
    cout << Count << endl;

    for(int i = 0 ; i < mark.size(); i++){
        if(mark[i]){
            cout << i << " ";
        }
    }

}










int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}

