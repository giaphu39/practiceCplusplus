/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

//###INSERT CODE HERE -
void Input(vector<int>& a){
    int temp;
    while(true){
        cin>>temp;
        if(!temp) break;
        a.push_back(temp);
    }
}
void inTungBuoc(vector<int> a, int n, int i){
    cout<<"i="<<i<<":    ";
    for(int z=0;z<n;z++){
        cout<<a[z]<<"       ";
    }
    cout<<endl;
}

void selectionSort(vector<int>& a){
    int n=a.size();
    for(int i = 0; i < n-1; i++){
        int iMin = i;
        for(int j = i + 1; j < n; j++){ // sai chỗ i++ 
            if(a[j] < a[iMin]){
                iMin = j;
            }
        }
        std::swap(a[i] , a[iMin]);
        inTungBuoc(a,n,i);
    }
    
}


int main() {
	vector<int> A;
	Input(A);
	selectionSort(A);
	return 0;
}
