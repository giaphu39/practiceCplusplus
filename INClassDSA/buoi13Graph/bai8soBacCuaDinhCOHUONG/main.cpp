

 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
 #include<vector>
# include<utility>
#define MAX 100

void Init(int* a){
    for(int i = 0 ; i< MAX ; i++){
        a[i] = 0;
    }
}

void Input(map<int,set<int>>& number_list,int& n){
    cin >> n;
    int CountSLDinh[MAX];
    Init(CountSLDinh);
    for(int i = 0 ; i < n;i ++){
        int v1; cin >> v1;
        int v2; cin >> v2;
        number_list[v1].insert(v2); // có thể có những số sau không được add vào đồ thị lúc đó find sẽ sai
        CountSLDinh[v1] = 1;
        CountSLDinh[v2] = 1;
    }

    int iDinh; cin >> iDinh;

    if(iDinh < 0 || CountSLDinh[iDinh] == 0){
        cout << 0;
        return;
    }
    int sizeTaiDinh = number_list[iDinh].size();

//    for(int i = 0 ; i< number_list.size(); i++){
//        if(i == iDinh) continue;
//        for( int x : number_list[i]){
//            if(x == iDinh) sizeTaiDinh += 1;
//        }
//    }
    for(pair<int , set<int>> p : number_list){
        int key = p.first;
        if(key == iDinh) continue;
        for(int x : p.second){
            if(x == iDinh) sizeTaiDinh +=1;
        }
    }
    cout << sizeTaiDinh;
}










int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}

