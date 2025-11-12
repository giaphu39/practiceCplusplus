

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

    int iDinh1; cin >> iDinh1;
    int iDinh2; cin >> iDinh2;
    bool flag = 0;

//    for(int x : number_list[iDinh1]){
//        if(x == iDinh2){
//            flag = 1;
//        }
//    }
//    for(int x : number_list[iDinh2]){
//        if(x == iDinh1){
//            flag =1;
//        }
//    }
//
//    if(flag){
//        cout << iDinh1 << " la dinh ke cua dinh " << iDinh2;
//    }
//    else {
//        cout << "2 dinh khong ke nhau";
//    }
//
    if (number_list[iDinh1].count(iDinh2)) {
        cout << iDinh2 << " la dinh ke cua dinh " << iDinh1;
    } else if (number_list[iDinh2].count(iDinh1)) {
        cout << iDinh1 << " la dinh ke cua dinh " << iDinh2;
    } else {
        cout << "2 dinh khong ke nhau";
    }


}










int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}

