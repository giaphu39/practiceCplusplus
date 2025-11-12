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

void TimBacNua(Graph G, int e, int truyVan){
    int BACVAO =0;
    int BACRA = 0;

    for(int i = 0 ; i< G.v ; i++){
        Node* p = G.arr[i].head;
        if(i == truyVan){
            while(p != NULL){
                BACRA++;
                p = p->next;
            }
        }
        else{
            while(p!= NULL){
                if(p->info == truyVan) BACVAO++;
                p = p->next;
            }
        }
    }

    cout << "Nua bac ngoai: "<< BACRA <<endl;
    cout <<"Nua bac trong: " << BACVAO <<endl;
}

void Input(Graph& G, int e){
    for(int i = 0 ; i < e; i++){
        int temp1; cin >> temp1;
        int temp2; cin >> temp2;
        Node* p = createNODE(temp2);
        addTail(G.arr[temp1], p);
    }
    int truyVan; cin >> truyVan;
    if(truyVan <= -1 || truyVan >= G.v){
        cout << "No find";
        return;
    }
    TimBacNua(G,e,truyVan);


}





//11 10
//4 1
//1 5
//5 6
//5 2
//2 7
//7 5
//7 8
//2 3
//3 9
//3 0
//3 4
//8	Nua bac ngoai: 0
//Nua bac trong: 1
//11 10
//4 1
//1 5
//5 6
//5 2
//2 7
//7 5
//7 8
//2 3
//3 9
//3 0
//3 4
//-1	No find




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
