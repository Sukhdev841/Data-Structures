#include <iostream>
#include<cstring>
#include<cmath>

using namespace std;

typedef
struct tnode
{
    tnode *lchild;
    int data;
    tnode *rchild;
}
*tptr;

void create(tptr&,int);
void initialize(tptr&);
void add_to_leafs(tptr&);
void insert_(tptr&,int);
void LDR(tptr);
void DLR(tptr);
void delete_(tptr&,tptr);

bool flag=true; // for every insert flag should be one

void delete_(tptr& t,tptr x)
{
    if(t!=NULL)
    {
    if(t==x)
        t->data=0;
    else
        {
        delete_(t->lchild,x);
        delete_(t->rchild,x);
        }
    }
}

int winner(tptr &t,tptr &m)
{
    if(t!=NULL)
    {
            if(t->lchild==NULL && t->rchild==NULL)
            {
                if(m->data<t->data)
                    m=t;
                return t->data;
            }
            else
            {
            int a=winner(t->lchild,m);
            int b=winner(t->rchild,m);
            if(a>b)
            return(a);
            return b;
            }
    }
}

void tournament_print(tptr &t,int n)
{
    tptr ma_x;
    cout<<"\n\nWinners : \n\n";
    for(int i=0;i<n;i++)
    {
        ma_x=t;
        cout<<winner(t,ma_x)<<" ";
        delete_(t,ma_x);
    }
}

void initialize(tptr &t)
{
    t=new tnode;
    t->lchild=NULL;
    t->rchild=NULL;
    t->data=0;
}

void add_to_leafs(tptr &t)
{
    if(t!=NULL)
    {
        if(t->lchild!=NULL)
            add_to_leafs(t->lchild);
        if(t->rchild!=NULL)
            add_to_leafs(t->rchild);
        else if(t->lchild==NULL && t->rchild==NULL)
        {
            tptr temp1,temp2;
            initialize(temp1);
            initialize(temp2);
            t->lchild=temp1;
            t->rchild=temp2;
        }
    }
}

void create(tptr &t,int n)
{
    if(n<=0)
        return;
    if(n%2!=0&& n!=1)
        n++;
    initialize(t);
    for(int i=1;i<(log2(n)+1);i++)
    {
        add_to_leafs(t);
    }
}

void insert_(tptr &t,int n)
{
    if(t!=NULL && flag)
    {
        if(t->lchild!=NULL)
            insert_(t->lchild,n);
        if(t->rchild!=NULL)
            insert_(t->rchild,n);
        else if(t->lchild==NULL && t->rchild==NULL && t->data==0 && flag)
        {
            t->data=n;
            flag=false;
        }
    }
}

void LDR(tptr t)
{
    if(t!=NULL)
    {
        LDR(t->lchild);
        cout<<t->data<<" ";
        LDR(t->rchild);
    }
}

void DLR(tptr t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        DLR(t->lchild);
        DLR(t->rchild);
    }
}

int main()
{
    int n;
    tptr t=NULL;
    cout<<"\nEnter number of players in the tournament : ";
    cin>>n;
    create(t,n);
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"\nEnter element : ";
        cin>>x;
        flag=true;
        insert_(t,x);
    }

    tournament_print(t,n);
    return 0;
}
