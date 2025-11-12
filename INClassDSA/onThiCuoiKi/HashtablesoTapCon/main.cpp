#include <iostream>

using namespace std;

#define MAX 200
struct NODE{
    char* x;
};

typedef NODE* NODEPTR;
typedef NODEPTR HASHTABLE[MAX];
// ý tưởng : lặp qua chuỗi dung while xét từng tập từ 1 -> n là kich thước chuỗi sau đó


int Size(char*s){
    int C = 0;
    for(int i = 0; s[i] != '\0' ; i++){
        C++;
    }
    return C;
}
void Init(HASHTABLE& H){
    for(int i =0 ; i< MAX ;i ++){
        H[i] = NULL;
    }
}

int index(char* s){
    int S = Size(s);
    int temp = 0;
    for(int i = 0 ;i < S ;i++){
        temp += s[i];

    }
    temp%=MAX;
    return temp;
}

NODE* createNODE(char* s){
    NODE* p = new NODE;
    p->x = s;
    return p;
}

void XuLy(char* s){
    int S = Size(s);
    HASHTABLE H;
    Init(H);

    int total = 1 << S;
    for(int i = 1 ;i < total ; i++){ // 0 la tap rong nen bo
        char* temp = new char[MAX];
        int z = 0;
        for(int j = 0 ; j < S;j++){
            if(i &(1 << j)){
                temp[z++] = s[j];
            }
        }
        temp[z] = '\0';
        int ind = index(temp);
        if(H[ind] == NULL){
            H[ind] = createNODE(temp);
        }

    }
    int Count = 0 ;
    for(int i = 0 ; i< MAX ;i++){
        if(H[i] != NULL){
            Count++;
        }
    }

    cout << Count;


}

int main()
{
    char s[MAX];
    cin.getline(s,MAX);
    XuLy(s);
    return 0;
}
