// Doraemon muốn leo lên 1 cầu thang gồm n bước. Anh ta có thể leo 1 hoặc 2 bước mỗi lần di chuyển. Doraemon muốn số lần di chuyển là bội số của 1 số nguyên m. Số lượng di chuyển tối thiếu làm cho anh ta leo lên đỉnh cầu thang thỏa mãn điều kiện của anh ta là gì?

// đi hết n bậc thang trong ans bước mà ans là bội số của m

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//ý tưởng: lúc đầu chỉ đi 2 bước, còn dư thì đi 1 bước cho tới bội số 
// dùng vòng lặp +m mỗi lần rồi xét điều kiện 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    // for(int i=m; ; i+=m){
        // i nầy là số bước
        // int c=(n/2);
        // int d=n%2;
        // if(i==(c+d)){
        //     cout<<i;
        //     break;
        // }
// cách này sai do phần dư + lại chưa chắc bằng phần còn lại cần bước

        // int count=i/2+i%2;
        // if (count%m==0 and count<=n){
        //     cout<<count;
        //     break;
        // }

    // int step=((n+1)/2);
    // while(step%m!=0){
    //     step++;
    // }
    // cout<<step;
    // ý tưởng:
//1. n<m ra -1 
//2. vì đi đc 2 bước nên lúc đầu đi 2 bước tối đa được n/2 bước hoặc n/2 +1 bước 
//3. nếu như số bước tối đa bé hơn m thì lấy m vì sẽ được cộng thêm 1 bước nhiều lần
//4. nếu bước tối đa chia hết m thì lấy lun nó
//5. nếu bước tối đa lớn hơn m thì lấy số chia hết m gần nhất
    int max;
    if(n<m){
        cout<<-1;
    }
    else{
        if(n%2==0){
            max=n/2;
        }
        else{
            max=n/2+1;
        }
        if(max<=m){
            cout<<m;
        }
        else if(max%m==0){
            cout<<max;
        }
        else{ // làm tròn số cho 1 bội số
            int a=max/m;
            cout<<(a+1)*m;
        }
        // 7/2 = 3; 4*2

    }

    return 0;
}
