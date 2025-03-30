#include <iostream>
#include<vector>
using namespace std;
//12 6 70 43 91 0 -1
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

void Merge(vector<int>& a, int l, int r, int mid){

    // số phần tử không phải index
    int nB = mid - l + 1;
    int nC = r - mid;

    int B[nB];
    int C[nC];

    for(int i=0;i<nB;i++) B[i] = a[l + i];
//    for(int i = mid+1; i<nC ; i++) C[i] = a[mid + 1 + i]; // sai ở đây
    for(int i = 0; i<nC ; i++) C[i] = a[mid + 1 + i];
    int iB = 0 , iC=0 , i = l; // nhớ kĩ chỗ này
    while(iB < nB && iC <  nC){
        if(B[iB] >= C[iC]){ // đổi dấu ở đây
            a[i++] = B[iB++]; // lỗi nghiêm trọng ở dây  không phải lúc nào cũng là vị trí i =0
        }
        else{
            a[i++] = C[iC++];
        }
    }


    while(iB < nB){
        a[i++] = B[iB++];
    }
    while(iC < nC){
        a[i++] = C[iC++];
    }
}

void MergeSort(vector<int>& a, int l, int r){
    if(l >= r) return;
    // lỗi nghiêm trọng thiếu điểm dừng trong đệ quy

    int mid = l + (r-l)/2;

    MergeSort(a,l, mid);
    MergeSort(a, mid+1, r);

    Merge(a,l,r, mid);
    output(a,l,r);

}

void Sort(vector<int>& a){
    int n = a.size();
    MergeSort(a, 0, n-1); // lỗi  chỗ này phải là index nên -1

}

int main()
{
    vector<int> a;
    input(a);
    Sort(a);

    return 0;
}
