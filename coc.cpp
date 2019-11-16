#include <iostream>

using namespace std ;

struct node{
    int data;
    node *pnext;
};
struct list
{
    node *pHead ;
    node *pTail;
};

node *createNode(int data)  {
    node *p = new node ;
    p->data = data;
    p->pnext = NULL;
    return p;
}
void createList(list &l ){
    l.pHead = NULL ;
    l.pTail = NULL;
}

void add(list &l , node *p){
    if(l.pHead == NULL ){
        l.pHead = l.pTail = p ;
    }else {
        l.pTail ->pnext ;
        l.pTail = p;
    }
}
void output(list l ){
    node *p = l.pHead;
    while ( p != NULL ){
        cout << p->data;
        p= p-> pnext;
    }
}
void xoa(list &l , int x ){
    node *coc = l.pHead ; 
    node *precoc ;
    while (coc != NULL ){
        if(coc ->data == x ){
            node * tmp  = coc ;
            if( coc == l.pHead ){
                l.pHead = l.pHead -> pnext;
                delete tmp ;
            }else {
                if( coc == l.pTail ){
                    l.pTail = precoc ;
                    precoc ->pnext = NULL ;
                    delete tmp ;
                }else {
                    precoc->pnext = coc -> pnext ;
                    delete tmp ;
                }
            }
        }
        coc= coc ->pnext;
        precoc = coc ;
    }

}


int main (){
    list l ; 
    createList(l);
    int n , k ;
    int a[100];
    cin >> n >> k ; 
    for (int i = 0 ; i < n ; ++i ){
        add(l, createNode(i));
    }
    for (int i = 0 ; i < k ; ++ i){
        cin >> a[i];
    }
    node *tmp = l.pHead;
    for (int j = 0 ; j < 3 ; ++ j){
        for (int i = 0 ; i < a[2] ; ++ i  ){
            if (tmp == NULL ){
                tmp = l.pHead ;
            }else {
                tmp = tmp ->pnext;
            }
        }
        cout << tmp -> data;
        xoa(l,tmp->data);
        tmp = tmp -> pnext;
    }
   


    return  0 ;
}