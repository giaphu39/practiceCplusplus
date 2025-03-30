// Nếu một dãy 10 số tồn tại 3 số có chữ số bắt đầu là chữ số 1 và 1 số bắt đầu bằng chữ số 4 thì có thể giả định rằng dãy số đó tuân thủ theo luật Benford. Hãy viết chương trình kiểm tra dãy số nhập vào có thỏa luật Benford không?
// Nếu dãy số đó có 3 con số bắt đầu bằng chữ số 1 và 1 con số bắt đầu bằng chữ số 4 thì xuất ra màn hình ra TRUE.

#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int a[],int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int sobatdau(int n){
    while(n>9){
        n/=10;
    }
    return n;
}

bool isBenford(int a[], int n){
    int dem1=0;
    int dem4=0;
    for(int i=0;i<n;i++){
        if(sobatdau(a[i])==1) dem1++;
        else if (sobatdau(a[i])==4) dem4++;
    }
    if(dem1>=3 and dem4>=1){
        return true;
    }
    else return false;
}


int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
    // for(int i=0;i<n;i++){
    //     cout<<sobatdau(a[i])<<" ";
    // }
	return 0;
}