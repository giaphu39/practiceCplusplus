
 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
#include<vector>
void Input(map<int,set<int>>& number_list,int& n){
    cin >> n;
    for(int i = 0 ; i < n;i ++){
        int v1; cin >> v1;
        int v2; cin >> v2;
        number_list[v1].insert(v2);
        number_list[v2].insert(v1);
    }
//    int Count = 0;
//    for(map<int,set<int>>:: iterator it = number_list.begin(); it != number_list.end(); it++){
//
//    }
    cout << number_list.size();
}






int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
