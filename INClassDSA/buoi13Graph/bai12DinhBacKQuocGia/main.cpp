

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


void Input(int v, map<string, int>& v_index , int e, vector<vector<int>>& G ){
    for(int i = 0 ; i < v; i++){
        string temp; cin >> temp;
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


//11 10
//Sing Malay Lao Cam Thai TQ Indo DTimo Nhat Han
//Thai Malay 5
//Malay TQ 4
//TQ Indo 3
//TQ Malay 2
//Malay DTimo 1
//DTimo TQ 2
//DTimo Nhat 3
//Malay Cam 4
//Cam Nhat 5
//Cam Sing 1
//Cam Thai 1
//0
//
//Lao Han
//10 7
//VN Lao Cam Thai Malay Indo DTimo
//Indo VN 1
//Thai Indo 2
//VN Thai 3
//Malay Indo 2
//DTimo Malay 1
//Cam DTimo 4
//Lao Cam 5
//Lao Malay 6
//Malay VN 2
//VN Lao 1
//5	No find




int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}
