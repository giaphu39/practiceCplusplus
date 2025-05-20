#include <iostream>
#include< cstring>
using namespace std;
#define MAX 1000

class String{
private:
    char* p;

public:
    String(char* P = NULL);
    // ~String();

    void Input();
    void Output();

    int Strlen();
    bool StrConcanate(String other);
    String StrReverse();
    String ToUpper();
    String ToLower();

    String (const String& obj);
    String& operator=(String other);

    String& my_Strcpy(String other);
};



int main(){

    String a;
    a.Input();
    a.Output();
    cout << a.Strlen() <<endl;
    String b;
    b.Input();
    a.StrConcanate(b);
    a.Output();
    return 0;
}


String:: String(char* P){
    p = P;
}

// void String::Input(){
//     static char Str[MAX]; // cần dùng static để mảng tĩnh không bị xóa, không nên vì các obj khác cũng mang gia tri tuong tự 
//     cin.getline(Str,MAX);

//     p = Str;
// }

void String::Input(){
    char Str[MAX];
    cin.getline(Str,MAX);

    
}

void String::Output(){
    for(int i = 0 ; p[i] != '\0' ; i++){
        cout << p[i];
    }
}

int String::Strlen(){
    int count = 0;
    for(int i = 0 ; p[i] != '\0' ; i++){
        count++;
    }
    return count;
}

bool String::StrConcanate(String other){
    int n = this->Strlen();
    int nOther = other.Strlen();
    for(int i = 0; i < nOther ; i++){
        this->p[n+i] = other.p[i]; // cap nhat lai '\0'
    }
    this->p[n+nOther] = '\0';
    return true;

}


String& String::my_Strcpy(const String& other) {
    int n = other.Strlen();
    
    delete[] p;
    p = new char[n + 1];

    for (int i = 0; i < n; i++) {
        p[i] = other.p[i];
    }
    p[n] = '\0'; // cần thiết!

    return *this;
}
