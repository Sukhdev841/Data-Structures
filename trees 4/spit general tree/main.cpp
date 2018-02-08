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

void addback(dlptr &l,gtptr &k)
{
    if(l!=NULL)
    {
        dlptr x=new dllist;
        initialize(x);
        x->data=k;
        dlptr t=l;
        while(t->next!=NULL)
            t=t->next;
        t->next=x;
    }
    else
    {
        initialize(l);
        l->data=k;
    }
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

int balance(gtptr t)
{
    if(t!=NULL)
    {
        if(t->fc!=NULL)
            return 1;
        else
            return 0;
    }
    return 0;
}

void split(gtptr &t,gtptr &x)
{
    if(t!=NULL)
    {
    initialize(x);
     x->data=t->data;
     split(t->fc,x->fc);
     if(t->fc!=NULL)
     {
     split(t->fc->ns,x->fc->ns);
     if(balance(t->fc)==0)
     t->fc=t->fc->ns;                // first check
     }
     //2nd check here
     if(t->fc!=NULL)
     if(balance(t->fc)==0)
     {
         t->fc=t->fc->ns;
     }
    }
}

int main()
{
    gtptr t;
    initialize_root(t,1);
    create(t);
    cout<<"\n\nLDR\n";
    level_print(t);

    dlptr d=NULL;
    int i=0;
    while(balance(t)!=0)
    {
        gtptr n;
        split(t,n);
        addback(d,n);
    }

    cout<<"\nLDR's of split trees are :\n";

    while(d!=NULL)
    {
        cout<<"\n\nldr \n";
        LDR(d->data);
        d=d->next;
    }

    return 0;
}
