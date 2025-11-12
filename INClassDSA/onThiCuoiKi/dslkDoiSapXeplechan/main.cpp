#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = nullptr;
    }


};

Node* createNode(int x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

 void addLast(DoublyLinkedList& l, int x){
    Node* p = createNode(x);
    if(l.tail == NULL){
        l.head = p;
        l.tail = p;
    }
    else{
        l.tail->next = p;
        p->prev = l.tail;
        l.tail = p;
    }

}
void printList(DoublyLinkedList l){
    Node* p = l.head;
    while(p){
        cout <<  p->data << " ";
        p = p->next;
    }
}

void Nhap(DoublyLinkedList& l){
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        addLast(l,x);
    }
}

//bool cmp(int a, int b){
//    bool oddA = a%2 != 0;
//    bool oddB = b%2 != 0; // sai ghi b thanh a
//    if(oddA && !oddB) return 1;
//    if(!oddA && oddB) return 0;
//    return oddA <= oddB;
//}

bool cmp(int a, int b){
    bool oddA = a % 2 != 0;
    bool oddB = b % 2 != 0;

    if(oddA && !oddB) return true;   // lẻ đứng trước
    if(!oddA && oddB) return false;  // chẵn đứng sau

    // Cùng nhóm thì tăng dần
    return a < b;
}


void sortOddEven(DoublyLinkedList& l){

    // y tuong: selection sort lap qua neu la le thi cho len dau,
    Node* i = l.head, *j, * MIN;

    while(i!= l.tail){
        MIN = i;
        j = i->next;

        while(j!=NULL){

            if(cmp(j->data, MIN->data)){
                MIN = j;
            }
            j = j->next;
        }

        if(MIN != i){
            swap(i->data, MIN->data);
        }

        i = i->next;
    }
}




void bubbleSort(DoublyLinkedList& l){
    if (!l.head || !l.head->next) return;

    bool swapped;
    Node* end = nullptr;

    do {
        swapped = false;
        Node* p = l.head;

        while (p->next != end) {
            if (!cmp(p->data, p->next->data)) {
                swap(p->data, p->next->data);
                swapped = true;
            }
            p = p->next;
        }
        end = p;
    } while (swapped);
}









int main(){
    DoublyLinkedList l;
    Nhap(l);
    sortOddEven(l);
//    bubbleSort(l);
    printList(l);
return 0;
}
