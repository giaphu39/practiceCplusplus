/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

//###INSERT CODE HERE -
int x;
void Input( vector<int>& a){
    int temp;
    while(1){ // nên dùng while true rồi xét điều kiện mới đúng 
        cin>>temp;
        if(temp == 0) break;
        a.push_back(temp);
    }
    cin >> x;
}


void output(const std:: vector<int>&  a){
    int n = a.size();
    for(int i=0;i<n;i++){
        std::cout << a[i]<<" ";
    }
    std::cout<< std::endl;
}
void linearSearch(const vector<int>& a){

    int n=a.size();
    bool flag=0;
    for(int i =0 ;i< n; i++){
        if(a[i] == x){
            flag=1;
            cout<< i<< " ";
        }
    }
    if(!flag) cout<< "No Find";
}
int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
