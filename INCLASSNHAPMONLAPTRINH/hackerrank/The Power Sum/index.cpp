#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */
void findCombinations(long long arr[], int n, int index, int X, long long& count) {
    // Điều kiện dừng: nếu X bằng 0, đã tìm thấy một cách hợp lệ
    if (X == 0) {
        count++;
        return; // Trả về vì đã tìm thấy một tổ hợp hợp lệ
    }
    // Nếu X nhỏ hơn 0 hoặc index vượt quá kích thước mảng, quay lại
    if (X < 0 || index >= n) {
        return;
    }

    // Duyệt qua các số lũy thừa từ vị trí hiện tại
    for (int i = index; i < n; i++) {
        // Gọi đệ quy với X giảm đi giá trị của arr[i], đồng thời tăng chỉ số để tránh lặp lại
        findCombinations(arr, n, i + 1, X - arr[i], count); 
    }
}
int powerSum(int X, int N) {
    long long arr[10000];
    int n=0;
    for(int i=1;pow(i,N)<=X;i++){
        // arr[i-1]=pow(i,N);// thay vì dùng vậy thì nên đặt n=0 rồi n++
        arr[n++]=pow(i,N);
    }
    long long ans=0;
    long long count = 0; // Biến đếm số cách hợp lệ
    findCombinations(arr, n, 0, X, count); // Gọi hàm tìm cách kết hợp

    return count; // Trả về số cách hợp lệ
    
}
int main(){
    int X,N;
    cin>>X>>N;
    cout<<powerSum(X,N);
    return 0;
}



// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string X_temp;
//     getline(cin, X_temp);

//     int X = stoi(ltrim(rtrim(X_temp)));

//     string N_temp;
//     getline(cin, N_temp);

//     int N = stoi(ltrim(rtrim(N_temp)));

//     int result = powerSum(X, N);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

