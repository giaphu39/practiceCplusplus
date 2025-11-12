 #include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head=NULL;
    Node* tail=NULL;
};

struct Graph
{
    int v; // số đỉnh của đồ thị
    List* arr; //mảng của các danh sách
};





Node* createNODE(int x){
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

bool addHead(List& l, Node* p){
    if(p == NULL) return false;

    if(l.head == NULL){
        l.head = p;
        l.tail = p;
    }
    else{
        p->next = l.head;
        l.head = p;
    }
    return true;
}

bool addTail(List& l, Node* p){
    if(p == NULL) return false;

    if(l.tail == NULL){
        l.head = p;
        l.tail = p;
    }
    else{
        l.tail->next = p;
        l.tail = p;

    }
    return true;
}

void Output(Graph G, int e){
    for(int i = 0 ; i < G.v; i++){
        cout << i << ": {";
        Node* p = G.arr[i].head;
        while(p != NULL){
            cout << p->info;
            if(p->next == NULL) break;
            cout << ", ";
            p = p->next;
        }

        cout << "}" << endl;
    }
}

void Input(Graph& G, int e){
    for(int i = 0 ; i < e; i++){
        int temp1; cin >> temp1;
        int temp2; cin >> temp2;
        Node* p = createNODE(temp2);
        addTail(G.arr[temp1], p);
    }

    Output(G,e);


}










int main()
{
    int e,v;
    cin>>e>>v;
    Graph G;
    G.v=v;
    G.arr = new List[v];
    Input(G,e);

    return 0;
}
