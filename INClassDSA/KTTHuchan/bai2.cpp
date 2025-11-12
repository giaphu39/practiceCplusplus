/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
set
map
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Queue
struct Queue{
	node* head;
	node* tail;
};
void CreateEmptyQueue(Queue &l)
{
    l.head=NULL;
    l.tail=NULL;
}
node* CreateNode(int x)
{
    node* p = new node();
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}
//###INSERT CODE HERE -
bool addTail(Queue& L, int x){
    node* p = CreateNode(x);
    if(L.tail == NULL){
        L.head = p;
        L.tail = p;
        return true;
    }
    else{
        L.tail->next = p;
        L.tail = p;
        return true;
    }
}

int stringToInt(const std::string& s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}


void CreateQueue(Queue& L){
    CreateEmptyQueue(L);
    string s;
    getline(cin,s);
    char Char = 0;
    char dem= 0;
    for(int i = 0 ; s[i]!= '\0' ; i++){
        if(!Char){
            Char = s[i];
            dem++;
        }
        else{
            if(Char == s[i]){
                dem++;
            }
            else{



                addTail(L,Char);
                addTail(L,dem);
                Char = s[i];
                dem = 1;
            }
        }
    }
    addTail(L,Char);
    addTail(L,dem);


}

void PrintQueue(Queue l)
{
     for(node*p=l.head; p!=NULL; p=p->next)
        cout<<p->info;
}
int main() {
    Queue L;
    CreateEmptyQueue(L);
    CreateQueue(L);
    PrintQueue(L);
    return 0;
}