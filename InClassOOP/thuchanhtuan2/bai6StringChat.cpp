#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000

class String {
private:
    char* p;

public:
    String(char* P = nullptr);
    ~String();

    void Input();
    void Output();

    int Strlen();
    bool StrConcanate(const String& other);

    String(const String& obj);
    String& operator=(const String& other);
};




// Constructor sao chép
String::String(char* P) {
    if (P) {
        p = new char[strlen(P) + 1];
        strcpy(p, P);
    } else {
        p = new char[1];
        p[0] = '\0';
    }
}

// Destructor
String::~String() {
    delete[] p;
}

// Copy constructor
String::String(const String& obj) {
    p = new char[strlen(obj.p) + 1];
    strcpy(p, obj.p);
}

// Toán tử gán
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] p;
        p = new char[strlen(other.p) + 1];
        strcpy(p, other.p);
    }
    return *this;
}

// Nhập
void String::Input() {
    char temp[MAX];
    cin.getline(temp, MAX);
    delete[] p;
    p = new char[strlen(temp) + 1];
    strcpy(p, temp);
}

// Xuất
void String::Output() {
    cout << p << endl;
}

// Độ dài
int String::Strlen() {
    return strlen(p);
}

// Nối chuỗi
bool String::StrConcanate(const String& other) {
    int len1 = strlen(p);
    int len2 = strlen(other.p);
    char* newp = new char[len1 + len2 + 1];
    strcpy(newp, p);
    strcat(newp, other.p);

    delete[] p;
    p = newp;
    return true;
}
