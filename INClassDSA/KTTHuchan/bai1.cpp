/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
###End banned keyword*/ 


#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;



//###INSERT CODE HERE -
void Input(vector<int>& a){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        a.push_back(x);
    }
}

void quick(vector<int>& a, int l, int r){
    if(l > r) return; // co = ?

    int i = l ; int j = r;
    int ind = l + (r-l)/2;
    int pivot = a[ind];
    cout << "[" << l << " - " << r << "]: pivot=" << pivot <<endl;
    while(i < j){
        while(a[i] > pivot) i++;
        while(a[j] < pivot) j--;

        if(i <= j){ // =?
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) quick(a,l,j);
    if(i < r) quick(a,i , r);
}

void output(vector<int> a){
    for(int i = 0; i < a.size();i++){
        cout << a[i] << " ";
    }
}

void SAPXEP(vector<int>& a){
    int l = 0; int r = a.size() -1;
    quick(a,l,r);
//    output(a);
}
int main() {
	vector<int> A;
	Input(A);
	SAPXEP(A);
	return 0;
}
