#include<iostream>

using namespace std;


using ll=long long;
int n,cnt,a[1000], final=0;

void ktao(){
    cin>>n;
    cnt=1; // cnt đếm số phần tử mỗi khi sinh
    a[1]=n;

}

void sinh(){
    // đi tìm số hạng đầu tiên từ phải sang trái cái đầu tiên khác 1
    int i=cnt;
    while(i>=1 && a[i]==1){
        i--;
    }
    if(i==0) final=1;
    else{
        --a[i];
        // giảm giá trị khi nó không phải 1

        //tính xem còn thiếu bao nhiêu phần tử 
        int d=cnt-i+1;
        // đây là số giá trị còn thiếu sau số đổi +1 do mới -1 đơn vị
        // vì các số sau số đổi đều bằng 1 nên nó sẽ bằng số lượng ban đầu - số lượng không đổi

        cnt=i;
        // reset số lượng cho số lượng của các số từ số biến đổi qua trái

        int q=d/a[i]; 
        // lượng đơn vị còn thiếu gấp mấy lần a[i] (số được -1)


        int r=d%a[i];

        for(int j=1;j<=q;j++){
            ++cnt;
            a[cnt]=a[i];
        }

        // nếu có phần dư < a[i] mà không chia hết thì in ra nó luôn
        if(r!=0){
            ++cnt;
            a[cnt]=r;
        }


    }
}


int main(){
    ktao();
    while(!final){
        for(int i=1;i<=cnt;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        sinh();
    }


    return 0;
}