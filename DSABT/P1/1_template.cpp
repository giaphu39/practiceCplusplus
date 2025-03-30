/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 400000

//###INSERT CODE HERE -
void NhapMang(int a[],int& n){ // thiếu nhập vào n và truyền tham chiếu 
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
}

int LinearSearch(int a[], int n, int x){

    a[n]=x;
    int i=0;
    while(a[i] != x){
        i++;
    }
    if(i < n){
        return 1;
    }
    else return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i= LinearSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
