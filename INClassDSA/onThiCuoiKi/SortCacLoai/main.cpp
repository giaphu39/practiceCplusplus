#include <iostream>

using namespace std;

void Input(int *&a, int& n){ // nhớ tham chiếu
    cin >> n;
    a = new int[n];
    for(int i =0  ; i < n;i++){
        cin >> a[i] ;
    }

}

void Output(int* a, int n){
    for(int i =0 ; i < n ; i++){
        cout << a[i] << " ";
    }
}

bool Cmp(int a, int b){
    return a < b;
}

void Sort1(int* a , int n){
    // selection sort
    for(int i= 0; i< n-1;i++){
        int iMin = i;
        for(int j = i +1; j < n;j++){
            if(Cmp(a[j], a[iMin])){
                iMin =j;
            }
        }

        if(iMin != i){
            swap(a[iMin],a[i]);
        }
    }
}

void Sort2(int* a, int n){
    for(int i = 1; i< n ;i++){
        int j, temp = a[i];
        for( j = i -1; j > -1;j--){
            if(Cmp(a[j],temp)) break;
            a[j + 1] = a[j];
        }
        a[j +1] = temp;
    }
}

void QuickSort(int* a, int n, int l, int r){
    if(l >= r) return;
    int i = l;
    int j = r;
    int mid = l + (r-l)/2;
    int pivot = a[mid];
    while(i <= j){ // co bang de bang nhau van dc sưap
        while(Cmp(a[i], pivot)){
            i++;
        }
        while(Cmp(pivot,a[j])){ // sai o day vi if sai gay = j van tru do do vong lap vo tan do ko co diem dung la pivot vi pivot van j-- la sai
            j--;
        }
        if(i <= j){
            swap(a[i],a[j]); i++; j--;
        }
    }
    if(l < j) QuickSort(a,n,l,j);
    if(i < r) QuickSort(a,n,i,r);
}

void Sort3(int * a, int n){
    int l = 0, r = n-1;
    QuickSort(a,n,l,r);
}

void Heapify(int* a, int n, int i){
    int iMax = i;
    int iL = i*2 +1;
    int iR = i*2 +2;
    if(iL < n && a[iL] > a[iMax]) iMax = iL;
    if(iR < n && a[iR] > a[iMax]) iMax = iR;

    if(iMax != i){
        swap(a[iMax], a[i]);
        Heapify(a,n,iMax);
    }
}

void BuildHeap(int* a, int n){
    for(int i = n/2-1; i>=0; i--){
        Heapify(a,n,i);
    }
}

void Sort4(int * a, int n){
    int heapsize = n;
    BuildHeap(a,heapsize);

    for(int i = heapsize -1; i>0;i--){ // chua thuoc tu heapsize -1, den 1
        swap(a[0],a[i]);
        Heapify(a,i,0);
    }
}



int b[200];
int c[200];
void Merge(int* a, int nb, int nc, int k){
    int p, pb,pc, i, ib, ic;
    int kb = min(nb,k);
    int kc = min(nc, k);
    p = pc =pb = ic = ib =0;
    while(nb > 0 && nc > 0){
        if(b[pb+ib] <= c[pc + ic]){
            a[p++] = b[pb+ib];
            ib++;
            if(ib == kb){
                for(;ic<kc; ic++) a[p++] = c[pc+ic];
                pb+=kb; pc+=kc;
                ib = ic = 0;
                nb -= kb;
                nc -= kc;
                kb = min(nb,k);
                kc = min (nc,k);
            }
        }
        if(b[pb+ib] > c[pc + ic]){
            a[p++] = c[pc+ic];
            ic++;
            if(ic == kc){
                for(;ib<kb; ib++) a[p++] = b[pb+ib];
                pb+=kb; pc+=kc;
                ib = ic = 0;
                nb -= kb;
                nc -= kc;
                kb = min(nb,k);
                kc = min (nc,k);
            }
        }
    }
}

void Sort5(int* a, int n){
    int p, pb,pc, i, k;
    k = 1;
    while(k < n){
        p = pb= pc =0;
        while(p < n ){
            for(i= 0 ; (p < n) && (i < k); i++) b[pb++] = a[p++];
            for(i = 0; (p < n) && (i < k); i++) c[pc++] = a[p++];
        }

        Merge(a,pb,pc, k);
        k*=2;
    }
}

int Search1(int* a , int n){
    int x; cin >> x;
    for(int i = 0 ; i < n; i++){
        if(a[i] == x) return i;
    }
}

int Search2(int* a, int n){
    int x; cin >> x;
    int l = 0; int r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == x) return mid;
        else if(x < a[mid]) r = mid-1;
        else l = mid +1;
    }
    return -1;
}

int main()
{
    int n;
    int * a;
    Input(a,n);
    Output(a,n);
    cout << Search1(a,n);

    Sort5(a,n);
    cout << endl;
    Output(a,n);
    cout << Search2(a,n); // dk phaiduoc sap xep
    return 0;
}
