

 #include<iostream>
 using namespace std;
 #include<map>
 #include<set>
 #include<vector>
# include<utility>

#define NGUOCHUONG -1

void Output(int v, vector<vector<int>>& G){
    for(int i = 0 ; i < v; i++){
        for(int j = 0; j < v; j++){
            cout << G[i][j] <<" ";
        }
        cout << endl;
    }
}

int Count(int v, vector<vector<int>>& G, int dinh){
    int COUNT = 0;

    for(int i = 0 ; i < v; i++){
        if(G[i][dinh]) COUNT++;
        if(G[dinh][i]) COUNT++; // else vì để 1 điểm trùng // sai phải bỏ else vì đang xét 2 lần vòng lặp gọp trong 1 vong lặp và chắc chắn điểm trùng là 0
        // vì không có khuyên 
    }
    return COUNT;
}

void Output1(int v, vector<vector<int>>& G,  map<string, int> v_index ,int dinh, bool flag){

    for(int i = 0; i< v; i++){
        if(dinh == Count(v,G,i)){
            for(pair<string,int> p : v_index){
                if(p.second == i){
                    flag = 1;
                    cout << p.first << " ";
                    break;
                }
            }
        }
    }

    if(!flag) cout <<"No find";
}


void Input(vector<vector<int>>& G , int v, int e, map<char, int>& v_index){
    for(int i = 0 ; i < v; i++){
        char temp; cin >> temp;
        v_index[temp] = i;
    }

    for(int i = 0; i < e; i++){
        string qg1, qg2;
        cin >> qg1 >> qg2;
        int index1 = v_index[qg1];
        int index2 = v_index[qg2];

        int trongSo; cin >> trongSo;
        G[index1][index2] = trongSo;
//        G[index2][index1] = trongSo;

    }
    bool flag = 0;
    int dinh; cin >> dinh;
    Output1(v,G,v_index,dinh,flag);
}





int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<char, int> NameIndex; // Danh sách ánh xạ tên đỉnh --> index
	Input(G,v,e,NameIndex);
	return 0;
}
