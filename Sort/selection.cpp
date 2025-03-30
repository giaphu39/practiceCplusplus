#include<iostream>
using namespace std;
void swap(int* a, int* b){
    int c= *a;
    *a=*b;
    *b=c;
}
void selection(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
                
            }
            
        }
        swap(&arr[min], &arr[i]);
    }    
}


void selectionfake(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[min]>arr[j]){
                int c=arr[min];
                arr[min]=arr[j];
                arr[j]=c;
            }
        }
    }
}

void selectionr(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[max]<arr[j]){
                int c=arr[max];
                arr[max]=arr[j];
                arr[j]=c;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection(arr,n);
    for(int x:arr){
        cout<<x<<" ";
    }
    
    // cout<<endl;
    // swap(&arr[0], &arr[1]);
    // for(int x:arr){
    //     cout<<x<<" ";
    // }
    return 0;
}