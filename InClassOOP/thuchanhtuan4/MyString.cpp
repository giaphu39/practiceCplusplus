#include <iostream>
using namespace std;

class String{
    char* pHead;
public:
    // String(char* Head);
    String(const char* Head = NULL); // ghi vậy mới đúng 
    String(const String& other);
    ~String();

    
    friend ostream& operator<<(ostream& os, String s); // phải là tham chiếu 
    friend istream& operator>>(istream& is, String& s);
    friend istream& Getline(istream& is, String& s);

    String operator=(String s);
    String operator+(String s);
    bool operator==(String s);
    bool operator>(String s);

    int Size();
};

int Size(const char* s);
int myStrcmp(const char* s, const char a);


int main(){
    String s("saf"); // do "saf" là hằng số biến RValue nên hàm cũng phải có tham số hằng
    cout << s;
    String b("dsa");
    cout << endl;
    cout << s+b;
    String u;
    Getline(cin,u);
    cout << u;
    cout << (u > s) << endl;
    String sv(u);
    cout << sv;

    return 0;
}

int Size(const char* s){
    int Count = 0;
    for(int i =0; s[i] !='\0'; i++){
        Count++;
    }
    return Count;
}
#define MAX 100


String::~String(){
    if(pHead != NULL){
        delete pHead;
    }
}

String:: String(const String& other){
    int size = ::Size(other.pHead);
    pHead = new char[size + 1];
    for(int i = 0 ; i< size+1 ; i++){
        pHead[i] = other.pHead[i];
    }
}

// String:: String(char* Head = NULL): pHead(Head){ // ghi vậy sai
// String:: String(const char* Head): pHead(Head){ // không được lạm dụng truyền kiểu này nữa ép hằng sang char* tiếp
String:: String(const char* Head){
    // phải cấp phát mới pHead
    if(Head == NULL) // nhớ phải có dòng này để khi không truyền gì vào thì không bị lỗi
{
    pHead = new char[MAX]; // dù là NULL cũng phải tạo mới để gán vì có những hàm không gán mà hủy sẽ rất nguy hiểm
    return ;
}
    // int size = Size(Head); // gọi vậy là hàm trong class nên sai
    int size = ::Size(Head);
    pHead = new char[size+1]; // cấp phát 
    int i;
    for( i =0; i< size; i++){
        pHead[i] = Head[i];
    }
    pHead[i] = '\0'; // nhớ phải có kí tự kết thúc chuỗi 

}

int String:: Size(){
    int Count = 0;
    for(int i =0; pHead[i] !='\0'; i++){
        Count++;
    }
    return Count;
}

int myStrcmp( char* a, char* b){
    while( *a!= '\0' && * b !='\0'){
        if(*a!= * b){
            return *a - *b;
        }
        a++;
        b++;
    }
    return *a - *b;

}

ostream& operator<<(ostream& os, String s){
    int size = s.Size();
    for(int i = 0 ; i< size; i++){
        os << s.pHead[i];
    }
    return os;
}

istream& operator>>(istream& is, String& s){
    // getline(is, s); // chỉ cho string
    // cho một mảng lưu các giá trị nhập rồi ghép từng giá trị sang s
    char buffer[1000];
    is >> buffer;
    delete[] s.pHead;
    int size = ::Size(buffer);
    s.pHead = new char [size + 1];
    for(int i =0; i< size ;i++){
        s.pHead[i] = buffer[i];
    }
    
    s.pHead[size] = '\0';
    return is;
}
istream& Getline(istream& is, String& s){
    char buffer[1000];
    is.getline(buffer, 1000);
    delete[] s.pHead;
    int size = ::Size(buffer);
    s.pHead = new char [size + 1];
    for(int i =0; i< size ;i++){
        s.pHead[i] = buffer[i];
    }
    
    s.pHead[size] = '\0';
    return is;
}


String String:: operator+(String s){
    int size1 = ::Size(this->pHead);
    int size2 = ::Size(s.pHead);

    String other;
    other.pHead = new char[size1+ size2 + 1];
    int i;
    for( i = 0 ; i < size1; i++){
        other.pHead[i] = this->pHead[i];
    }
    for(int j = 0 ; j < size2; j++){
        other.pHead[i] = s.pHead[j];
        i++;
    }
    other.pHead[i] = '\0';
    return other;
}

bool String::operator==(String s){
    int i = myStrcmp(this->pHead,s.pHead );
    if(i == 0) return true;
    return false;
}

bool String::operator>(String s){
    int i = myStrcmp(this->pHead,s.pHead );
    if(i > 0) return true;
    return false;
}