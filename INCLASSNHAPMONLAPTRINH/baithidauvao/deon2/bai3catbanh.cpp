#include<iostream>
#include<climits>
using namespace std;
#define MAX 1000000000 // vượt quá 300 là out range nên phải dùng cấp phát động
void input(int& n, int a[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void solve(int n, int a[], int b[]){
    b[0]=360;
    int j=0;
    int z=n;
    bool flag=false; // da quay vong chua
    for(int i=0;i<n;i++){
        if(j==n) break;
        // if(b[i]-a[i]<0)
        while(b[i]-a[j]<0){
            a[j]-=b[i];
            i++;
            if(i==n){ i=0; flag=true;}
        }
    // khi quay vong se bi xep chong nen phai day no len
        // for(int q=z;q>i;q--){
        //     b[q+1]=b[q];
        // }
        if(!flag){
            b[i+1]=b[i]-a[j];
            b[i]=a[j++];
        }
        else{
            z++;
            // cat de dung index con du don len
            for(int q=z;q>i+1;q--){
                b[q]=b[q-1];
            }
            b[i+1]=b[i]-a[j];
            b[i]=a[j++];
        }
    }

    // for(int i=0;i<z;i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    int max=INT_MIN;
    for(int i=0;i<z+1;i++){
        if(b[i]>max) max=b[i];
    }
    cout<<max;
    delete[] a;
    delete[] b;
}
// 4
// 30 30 30 30
// 30 330-> 30 30 300 -> 30 30 30 270 -> 30 30 30 30 240
int main(){
    int n;
    int* a=new int[MAX];
    int* b=new int[MAX];
    input(n,a);
    solve(n,a,b);
    // 90 270 -> 90 180 90 ->90 180 45 45 -> 90 60 120 45 45 (quy luật là cắt nhát nào tách ra nhát đó tại đúng vị trí 
    //phần tử được cắt ) và tách ra phần còn lại ở cuối mảng 
    // lần cắt tiếp theo ngay tại chỗ mới được cắt ( cuối mảng),
    // nếu vượt quá 360 độ thì sẽ vòng lại từ đầu mảng cứ trừ trừ đến khi bằng 0 thì đó là phần tử được cắt
    return 0;
}