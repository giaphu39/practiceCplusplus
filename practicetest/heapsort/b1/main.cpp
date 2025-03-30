#include <iostream>
#include<vector>
using namespace std;
//12 6 70 43 91 0 -1


void Input(vector<int>& a){
    while(1){
        int temp;
        cin>>temp;
        if(temp < 0) break;
        a.push_back(temp);
    }
}

void Output(vector<int> a, int HeapSize){
    if(HeapSize == a.size()){
       cout<<"buildHeap: ";
    }
    else{
        cout<<"n="<< HeapSize<<": ";
    }


    for(int i=0 ;i < a.size(); i++){
        if(i == a.size() - 1){
            cout<<a[i]<<endl;
            break;
        }
        cout<< a[i]<<"-";
    }

}


void Heapify(vector<int> & a, int HeapSize, int i){
    int childLeft = i*2 + 1;
    int childRight = i*2 + 2;

    int Max = i; // tên min mới đúng

    if(childLeft< HeapSize && a[childLeft] < a[Max]){
        Max = childLeft;
    }
    if(childRight< HeapSize && a[childRight] < a[Max]){
        Max = childRight;
    }

    if(Max != i){
        swap(a[Max], a[i]);

        Heapify(a,HeapSize, Max);
    }
}

void BuildHeap(vector<int> & a, int HeapSize){

    for(int i= HeapSize / 2 - 1; i >=0 ; i--){
        Heapify(a,HeapSize, i);
    }
}

void Sort(vector<int> & a){
    int n = a.size();
    int HeapSize = n;

    BuildHeap(a,HeapSize);
    Output(a,HeapSize);

    //HeapSize -= 1;
    for(int i = 0 ; i < n;i++){
//        swap(a[0], a[HeapSize]); // chỗ này sai vì sẽ outrange
        swap(a[0], a[HeapSize -1]);
        HeapSize -= 1;
        Heapify(a,HeapSize,0);

        Output(a,HeapSize);
    }



}

int main()
{
    vector<int> a;
    Input(a);
    Sort(a);


    return 0;
}
