#include <iostream>
#include<vector>
using namespace std;
///12 6 70 43 91 0 -1
void input(vector<int>& a){

    while(true){
        int temp;
        cin>>temp;

        if(temp < 0) break;
        a.push_back(temp);
    }
}
void output(vector<int> a, int l, int r){
    cout<<"["<<l << "-" << r <<"]: ";

    for(int i=0;i < a.size() ; i++){
        if(i == a.size() -1 ){
            cout<<a[i]<<endl;
            break;
        }
        cout<<a[i]<<"-";
    }

}
void QuickSort(vector<int>& a, int l, int r){


    int i = l;
    int j = r;
    int mid = l + (r-l)/2;
    int parot = a[mid];

    while(i < j){
        while(a[i] > parot) i++;
        while(a[j] < parot) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    output(a,l,r);

    if(l < j) QuickSort(a,l,j);
    if(i < r) QuickSort(a, i , r);

}


void Sort(vector<int>& a){
    int n = a.size();
    if(!n){
         cout<<"EMPTY"; return;
    }
    QuickSort(a, 0, n-1); // lỗi  chỗ này phải là index nên -1

}

int main()
{
    vector<int> a;
    input(a);
    Sort(a);

    return 0;
}
