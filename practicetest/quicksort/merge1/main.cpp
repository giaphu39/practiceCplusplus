#include <iostream>

using namespace std;

#define MAX 200

// 3 2 5 1 4 0 -1
int b[MAX], c[MAX];
void input(int *a, int& n){
    int Count=0;

    while(true){
        int temp;
        cin>>temp;
        if(temp<0) break;
        a[Count]=temp;
        Count++;

    }
    n=Count;
}
void outputmang(int *a, int n){
    for(int i=0;i<n;i++){
        if(i==n-1) cout<<a[i]<<endl;
        else{
            cout<<a[i]<<"-";
        }
    }
}
void output(int * a, int k, int nb, int nc, int n){
    cout<<"-------------"<<endl;
    cout<<"k="<<k<<endl;
    cout<<"B: "; outputmang(b,nb);
    cout<<"C: "; outputmang(c,nc);
    cout<<"A: "; outputmang(a,n);
//    cout<<"-------------"<<endl;
}

void Merge(int *a, int n, int nb, int nc, int k){
    int p,pb,pc,ib,ic,kb,kc;
    p=pb=pc=ib=ic=0;
    kb=min(nb, k);
    kc=min(nc,k);

    while(nb >0 && nc >0){
        if(b[pb+ib] <= c[pc+ic]){
            a[p++] = b[pb + ib];
            ib++;
            if(ib == kb){
                for(;ic < kc ; ic++) a[p++] = c[pc+ic];

                // cap nhat
                pb += ib; pc+= ic; ib=ic=0; nb -= kb; nc-=kc;
                kb=min(nb, k);
                kc=min(nc,k);
            }

        }
        else{
            a[p++] = c[pc+ ic];
            ic++;
            if(ic == kc){
                for(;ib < kb ; ib++) a[p++] = b[pb+ib];

                // cap nhat
                pb += ib; pc+= ic; ib=ic=0; nb -= kb; nc-=kc;
                kb=min(nb, k);
                kc=min(nc,k);
            }
        }
    }

}

void MergeSort(int *a, int n){
    int p, pb, pc, k;


    k=1;
    while(k < n){
        p=pb=pc =0;

        while(p < n){

            for(int i=0;(i<k)&&(p<n);i++) b[pb++] = a[p++]; // bị sai chỗ này nhớ chú ý kĩ điều kiện quan trọng nhất
            for(int i=0;(i<k)&&(p<n);i++) c[pc++] = a[p++];

        }

        Merge(a,n,pb,pc,k);
        output(a,k,pb,pc,n);
        k*=2;
    }

}

int main()
{
    int a[MAX], n;
    input(a,n);
    MergeSort(a,n);
    return 0;
}
