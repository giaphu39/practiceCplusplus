#include <iostream>

using namespace std;

#define MAX 200

struct NODE{
    int data;
};
typedef NODE* NODEPTR;
typedef NODEPTR HASHTABLE[MAX];

NODE* createNODE(int x){
    NODE* p = new NODE;
    p->data = x;
    return p;
}

void Init(HASHTABLE& h,  int m){
    for(int i = 0 ; i < m;i++){
        h[i] = NULL;
    }
}

int H(int key, int m){
    return key%m;
}

int H2(int key, int m){
    return (7 - key %7);
}


int H_i(int key, int m , int i){
    return (H(key,m) + i * H2(key,m))% m;
}

bool Insert(HASHTABLE& h, int m, int x){
    int ind = H(x,m);
    if(h[ind] == NULL){
        h[ind] = createNODE(x);
        return true;
    }
    else{
        int i = 1;
        while(true){ // loi gnhiem trong quen tang i trong vong lap
            if(i == m ) break;
            ind = H_i(x,m,i);
            if(h[ind] == NULL){
                h[ind] = createNODE(x);
                return true;
            }
            i++;
        }
        return 0;
    }

}

void CreateHash(HASHTABLE& h, int m){
    Init(h,m);

    while(true){
        int x; cin >> x;
        if(x == -1 ) break;
        Insert(h,m,x);
    }
}


void Output(HASHTABLE h, int m){
    for(int i = 0 ; i < m;i++){
        cout << i << " ";
    }
    cout <<endl << "-------------------------" << endl;
    for(int i = 0 ; i < m;i++){
//        cout << h[i]->data << " "; // loi nghiem trong truy cap NULL
        if(h[i]){
            cout << h[i]->data << " ";
        }
        else cout << "NULL" << " ";
    }
}


bool Add(HASHTABLE& h, int m, int x){
    int ind = H(x,m);
    if(h[ind] == NULL){
        h[ind] = createNODE(x);
        cout << "H1(" << x << ")=" << ind << endl;
        cout <<x << ": add Successful in bucket " << ind << endl;
        return true;
    }
    else{
         cout << "H1(" << x << ")=" << ind << " (Collision)"<< endl;
        int i = 1;
        int j = H2(x,m);
         cout << "H2(" << x << ")=" << j << endl;
        while(true){
            if(i == m) break;
            ind = H_i(x,m,i);
            cout << "prob(" << x << "," << i << ")=" << ind;
            if(h[ind] == NULL){
                h[ind] = createNODE(x);
                cout << endl <<x << ": add Successful in bucket " << ind << endl;
                return true;
            }
            i++;
            cout << "(Collision)" << endl;
        }
        cout <<x << ": add Failed"<< endl;
        return 0;
    }

}
int main()
{
    int m; cin >> m;
    HASHTABLE h;
    CreateHash(h,m);
    Output(h,m);
    int x; cin >> x;
    Add(h,m,x);
    return 0;
}
