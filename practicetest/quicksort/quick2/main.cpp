#include <iostream>
#include<vector>
using namespace std;
///2 5 3 2 6 8 2 -1
void input(vector<int>& a){

    while(true){
        int temp;
        cin>>temp;

        if(temp < 0) break;
        a.push_back(temp);
    }
}
void output1(vector<int> a, int l, int r){
    cout<<"["<<l << "-" << r<<"]" <<endl;

}

void output2(vector<int> a, int l, int r){
//    cout<<"["<<l << "-" << r <<"]: ";

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
    int pivot = a[mid];

    while(i <= j){ // chỉnh tiếp ở đây
//        while(a[i] < parot) i++;
//        while(a[j] >= parot){
//            if(j == mid) break;
//            j--;
//        }
    while (a[i] < pivot) i++;  // ✅ Duyệt đến phần tử >= pivot
    while (a[j] > pivot) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    output1(a,l,r);

    if(l < j) QuickSort(a,l,j);
    if(i < r) QuickSort(a, i , r);

}


void Sort(vector<int>& a){
    int n = a.size();
    if(!n){
         cout<<"EMPTY"; return;
    }
    QuickSort(a, 0, n-1); // lỗi  chỗ này phải là index nên -1
    output2(a,0,0);
}

int main()
{
    vector<int> a;
    input(a);
    Sort(a);

    return 0;
}
