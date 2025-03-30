
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


void Heapify(vector<int> &a, int heapSize, int i, int &dem) { // hàm dùng để đổi nốt đó thành max của nút cha và 2 con của nó, sau đó nếu có thay
    //đổi thì sẽ đếm lần swap++ và check vị trí nốt con được đổi xuống các node con tiếp theo của nó cho đến khi không đổi nữa
	int childLeft = i * 2 + 1;
	int childRight = i * 2 + 2;
	int max = i;
	if (childLeft<heapSize && a[max]>a[childLeft])//sort tăng chỉnh dấu a[max]<a[childLeft]
		max = childLeft;
	if (childRight<heapSize && a[max]>a[childRight])//sort tăng chỉnh dấu a[max]<a[childLeft]
    // nếu max đc cập nhật trước đó mà vẫn < hơn nốt còn lại thì vẫn đổi nghĩa là lấy max của 3 nốt
		max = childRight;
	if (max != i) {
        //cout<<a[max]<<"\t"<<a[i]<<endl;
        dem++;
		swap(a[max], a[i]);
		Heapify(a, heapSize, max,dem);
	}
}
void buildHeap(vector<int> &a, int n, int &dem) {
	int heapSize = n;
	for (int i = n/2 - 1; i >= 0; i--) // từ phần giữa hoán các nhánh con sau đó đi lên nhánh cao hơn rồi tiếp tục hoán các nhánh con cần đổi ở dưới
		Heapify(a, heapSize, i,dem);
}
void Sort(vector<int> &a) {
    int n=a.size();
	int heapSize= n;
	int dem=0;

	cout<<"\nN="<<heapSize<<":\t";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";
    cout<<endl;

	buildHeap(a, heapSize,dem);
	cout<<endl<<"swap: "<<dem<<endl; // swap lần đầu là của build

	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]); // lúc đã xong 1 lần đổi
		heapSize -= 1;
        dem=0;
        cout<<"\nN="<<heapSize<<":\t";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << "\t";
        cout<<endl;

		Heapify(a, heapSize, 0,dem);

        cout<<"swap: "<<dem<<endl; // số swap này sau đó sẽ cho cấu hình tiếp theo
		
	}
}



int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
