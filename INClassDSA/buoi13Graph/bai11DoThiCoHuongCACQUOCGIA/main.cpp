

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

    }

    Output(v,G);
}


//
//7 7
//VN Lao Cam Thai TQ Nhat Han
//VN Lao 1
//VN Cam 2
//Lao VN 1
//TQ Cam 3
//Thai Lao 2
//Cam Han 4
//Han Nhat 5

//11 9
//VN Lao Cam Thai TQ Indo DTimo Nhat Han
//VN Lao 1
//VN Indo 2
//Han VN 3
//Lao Cam 4
//Lao TQ 5
//Cam TQ 6
//Cam Thai 7
//DTimo TQ 8
//Thai DTimo 9
//Thai Nhat 2
//Indo DTimo 1









int main()
{
    	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}
