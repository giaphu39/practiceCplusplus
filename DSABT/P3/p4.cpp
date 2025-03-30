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
void inTungBuoc(vector<int> a, int n, int temp, int i){
    cout<<"i="<<i<<":    e="<<temp<<":    ";
    for(int z=0;z<n;z++){
        cout<<a[z]<<"       ";
    }
    cout<<endl;
}

void insertionSort(vector<int> a){
    int n=a.size();
    for(int i = 1; i< n; i++){
        int temp = a[i];
        int j;
        for(j = i - 1 ; j >= 0; j--){ // chỗ này kiến code có lúc chạy được có lúc không, không đc cho index >-1
            if(a[j] < temp){ // suy nghĩ giảm dần thì temp < a[j] mà lấy ngược lại để dừng
                break;
            }
            a[j + 1] = a[j];
        }
        // a[j] = temp; // gán sai vị trí
        a[j+1] = temp;
        inTungBuoc(a,n,temp,i);
        
    }
    
}
int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
