#include <iostream>
#include<cstdlib>
#include<cctype>
#include<cstdio>

using namespace std;

typedef
struct gtnode
{
    gtnode *fc;
    int data;
    gtnode *ns;
}
*gtptr;

struct stak
{
    int top;
    gtptr data[50];
    int siz;
};
void initialize(stak &s)
{
    s.top=-1;
    s.siz=50;
}

void push(stak &s,gtptr k)
{
    if(s.top==(s.siz-1))
    {
        cout<<"\nStack is full.\n";
        return;
    }
    s.data[++s.top]=k;
}

gtptr pop(stak &s)
{
    if(s.top==-1)
    {
        return NULL;
    }
    return (s.data[s.top--]);
}

void initialize(gtptr &t)
{
    t=new gtnode;
    t->fc=NULL;
    t->ns=NULL;
    t->data=0;
}

void initialize_root(gtptr &t,int k)
{
    t=new gtnode;
    t->fc=NULL;
    t->data=k;
    t->ns=NULL;
}

bool empty_(stak s)
{
    if(s.top==-1)
        return  true;
    return false;
}

void icreate(gtptr &t)
{
    char temp[11];
    stak s;
    initialize(s);
    gtptr x=t;
    do
    {
        cout<<"\nIf you want to make a child of " <<x->data<< " then press the number else press '.' : ";
        gets(temp);
        if(temp[0]!='.')
        {
            initialize(x->fc);
            x->fc->data=atoi(temp);
            gtptr x2=x->fc;
            push(s,x->fc);
        while(temp[0]!='.')
        {
            cout<<"\nIf you want to make other sub-lings of "<<x2->data<<" then enter number else press '.' : ";
            gets(temp);
            if(temp[0]!='.')
            {
                initialize(x2->ns);
                x2->ns->data=atoi(temp);
                x2=x2->ns;
            }
        }
        }
        x=pop(s);
        if(x!=NULL)
        if(x->ns!=NULL)
        push(s,x->ns);
    }
    while(x);
}

void create(gtptr &t)
{
    char temp[11];
    cout<<"\nIf you want to make a child of "<<t->data<<" then enter the data else press '.' : ";
    gets(temp);
    if(temp[0]!='.')
    {
        initialize(t->fc);
        t->fc->data=atoi(temp);
        gtptr x=t;
        t=t->fc;
        do
        {
            cout<<"\nIf you want to make next sub-ling of "<<t->data<<" then enter the data else press '.' : ";
            gets(temp);
            if(temp[0]!='.')
            {
                initialize(t->ns);
                t->ns->data=atoi(temp);
                t=t->ns;
            }
        }
        while(temp[0]!='.');
        t=x;
        t=t->fc;
        while(t!=NULL)
        {
            create(t);
            t=t->ns;
        }
        t=x;
    }
}

void LDR(gtptr t)
{
    if(t!=NULL)
    {
     LDR(t->fc);
     cout<<t->data<<" ";
     if(t->fc!=NULL && t->fc->ns!=NULL)
     {
     gtptr a=t->fc->ns;
     while(a!=NULL)
     {
         LDR(a);
         a=a->ns;
     }
     }
    }
}

void DLR(gtptr t)
{
    if(t!=NULL)
    {
     cout<<t->data<<" ";
     DLR(t->fc);
     if(t->fc!=NULL && t->fc->ns!=NULL)
     {
     gtptr a=t->fc->ns;
     while(a!=NULL)
     {
         DLR(a);
         a=a->ns;
     }
     }
    }
}

void LRD(gtptr t)
{
    if(t!=NULL)
    {
     LDR(t->fc);
     if(t->fc!=NULL && t->fc->ns!=NULL)
     {
     gtptr a=t->fc->ns;
     while(a!=NULL)
     {
         LDR(a);
         a=a->ns;
     }
     }
     cout<<t->data<<" ";
    }
}

// done with tree node

// now queue

typedef
struct dllist
{
    dllist *fchild;
    gtptr data;
    dllist *next;
}
*dlptr;

void initialize(dlptr &l)
{
    l=new dllist;
    l->fchild=NULL;
    l->data=NULL;
    l->next=NULL;
}

struct que
{
    dlptr first;
    dlptr rare;
};

void initialize(que& q)
{
        q.first=NULL;
        q.rare=NULL;
}

void enq(que &q,gtptr k)
{
    if(q.first==NULL && q.rare==NULL)
    {
        initialize(q.first);
        initialize(q.rare);
        q.first=q.rare;
        q.rare->data=k;
    }
    else
    {
        dlptr x;
        initialize(x);
        x->data=k;
        q.rare->next=x;
        q.rare=x;
    }
}

gtptr deq(que &q)
{
    if(q.first!=NULL)
    {
        gtptr x=q.first->data;
        if(q.first==q.rare)
        {
            delete(q.first);
            delete(q.rare);
            q.first=NULL;
            q.rare=NULL;
            return x;
        }
        dlptr y=q.first;
        q.first=q.first->next;
        q.first->fchild=NULL;
        delete(y);
        return x;
    }
    return NULL;
}

// BFT (level print)

gtptr special;

void special_(void)
{
    initialize(special);
}

void level_print(gtptr t)
{
    que q;
    initialize(q);
    enq(q,t);
    special_();
    enq(q,special);
    while(q.first && q.rare )
    {
        gtptr x=deq(q);
        if(x==special)
        {
            if(q.first==NULL)
                break;
            enq(q,special);
            x=deq(q);
            cout<<"\n";
        }
        if(x!=NULL)
        {
            cout<<x->data<<" ";
            x=x->fc;
            while(x!=NULL)
            {
                enq(q,x);
                x=x->ns;
            }
        }
        else
            break;
    }
    delete(special);
}

int main()
{
    gtptr t;
    initialize_root(t,5);
    icreate(t);
    cout<<"\n\nLDR\n";
    level_print(t);
    return 0;
}
