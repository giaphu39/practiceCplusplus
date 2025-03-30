#include <iostream>

#include <math.h>
#include <iomanip>
using namespace std;
//ý tưởng: trong vòng j dùng n + j, vòng i để cộng căn  n +j=> sai
//ý tưởng 2: dùng đệ quy tạo một hàm  để viết căn => chưa ra ý tưởng tiếp theo
//ý tưởng 3: phải tính từ trong ra ngoài, thấy 1 tăng dần đến i chứ không phải căn trong căn rồi trừ=> 
//bài học rút ra là khi làm một bài phải cố tìm quy luật của nó trước
double calculate(int n){
    double ans=1;//sai chỗ này là sai cả bài
    // for(int i=0;i<n;i++){
    //     ans=sqrt(ans+i);
    // }
    // return ans;
    for(int i=2;i<=n;i++){
        ans=sqrt(ans+i);
    }
    return ans;

    
}


int main() {
	int n;
	cin >> n;
    cout << setprecision(3) << calculate(n);
}