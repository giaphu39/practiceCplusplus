TREE createNODE(int x){
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

bool Insert(TREE& T, int x){
    if(T){
        if(T->key == x) return 0;
        else if(T->key < x) return Insert(T->pRight , x);
        else return Insert(T->pLeft, x);
    }

    TREE p = createNODE(x);
    T = p;
    return true;
}

void CreateTree(TREE& T){
    T = NULL;
    while(true){
        int x; cin >> x;
        if(x == -1) break;
        Insert(T,x);
    }
}

void LNR(TREE T){
    if(T){
        LNR(T->pLeft);
        cout << T->key << " ";
        LNR(T->pRight);
    }
    return;
}




int FIND(TREE T,TREE current, int& dem , bool& flag){
    if(T){

        int LNODE = FIND(T->pLeft,current, dem, flag);
        int RNODE = FIND(T->pRight,current, dem , flag);
        if(LNODE == RNODE && T->pLeft != NULL && T->pRight != NULL && T == current){
            dem++;
            flag =1 ;
        }

        return LNODE + RNODE + 1;
    }
    return 0;
}

void Find(TREE T, int& dem){
    if(T){
        bool flag = 0;
        FIND(T,T,dem,flag);
        if(flag){
            cout << T->key << " ";
        }

        Find(T->pLeft, dem);
        Find(T->pRight, dem);
    }
    return;
}