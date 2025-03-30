#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void NhapMang(vector<int>& a, int n){

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void InMang(vector<int> a){
    for(vector<int>::iterator it=a.begin(); it != a.end() ; it++){
        cout<<*it<< " ";
    }
    cout<<endl;
}

int LinearSearch(vector<int> a , int n , int x){
    a.push_back(x);
    int i=0;
    while(a[i] != x){
        i++;
    }
    if(i<n){
        return i;
    }
    return -1;
}

int BinarySearch(vector<int> a, int n, int x){
    int l=0; int r=n-1;
    
    while(l<=r){
        int mid= (l+r)/2;
        
        if(a[mid] == x)
            return mid;

        if(x < a[mid]){
            r=mid-1; // phải là -1 vì tại mid không đúng rồi
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int InterpolationSearch(vector<int> a, int n, int x){
    int l=0; int r=n-1;
    
    while(l<=r){
        int mid= l + (r-l)* double ( (x-a[l]) )/ (a[r] - a[l]) ;
        
        if(a[mid] == x)
            return mid;

        if(x< a[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}


// int InterpolationSearch(vector<int> a, int n, int x) {
//     int l = 0, r = n - 1;

//     while (l <= r && x >= a[l] && x <= a[r]) { // Kiểm tra tránh lỗi
//         if (a[l] == a[r]) {
//             if (a[l] == x) return l;
//             else return -1;
//         }

//         int mid = l + (r - l) * (double)(x - a[l]) / (a[r] - a[l]);

//         if (a[mid] == x) return mid;
//         if (a[mid] < x) l = mid + 1;
//         else r = mid - 1;
//     }
//     return -1;
// }

int main(){

    int n;cin>>n;

    vector<int> a(n); // không nên cộng +1 vì sẽ tạo số 0 ở cuối vector
    NhapMang(a,n);

    int x;cin>>x;

    cout<<LinearSearch(a,n,x)<<endl;

    
    sort(a.begin(), a.end()); // dòng này là quan trọng nhất
    InMang(a);


    cout<<BinarySearch(a,n,x)<<endl;
    cout<<InterpolationSearch(a,n,x)<<endl;

    // InMang(a);
    return 0;
}