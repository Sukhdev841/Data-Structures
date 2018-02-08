#ifndef bt_H_INCLUDED
#define bt_H_INCLUDED

#include<iostream>
#include<cctype>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

typedef int  datatype;

typedef
struct btnode
{
    datatype data;
    btnode *lchild;
    btnode *rchild;
    btnode()
    {
        data=0;
        lchild=NULL;
        rchild=NULL;
    }
}
*btptr;

int  *arr,siz_e=0;
int flag=1;

void resize_array(int k)
{
    if(k==1)
    {
    int *n_arr=new int[siz_e+1];
    memcpy(n_arr,arr,(siz_e)*sizeof(int));
    delete [] arr;
    arr=n_arr;
    siz_e++;
    }
    else
    {
        int *n_arr=new int[--siz_e];
    memcpy(n_arr,arr,(siz_e)*sizeof(int));
    delete [] arr;
    arr=n_arr;
    }

}

void print (btptr n)  // its done
{
    if(n!=NULL)
    {
        cout<<n->data<<" ";
        if(n->lchild!=NULL)
        {
            print(n->lchild);
        }
        if(n->rchild!=NULL)
        {
            print(n->rchild);
        }
    }

}

void create(btptr &n,datatype &d)
{
    char k[4];
    n=new(btnode);
    n->data=d;
    n->lchild=NULL;
    n->rchild=NULL;
    cout<<"\nIf you want to enter data to lchild of "<<n->data<<" then enter number else press '.' ";
    gets(k);
    if(k[0]!='.')
        {
            d=atoi(k);
        create(n->lchild,d);
        }
    cout<<"\nIf you want to enter data to rchild of "<<n->data<<" then enter number else press '.' ";
    gets(k);
    if(k[0]!='.')
    {
        d=atoi(k);
        create(n->rchild,d);
    }
}

void LDR(btptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDR(t->lchild);
    cout<<t->data<<" ";
    if(t->rchild!=NULL)
        LDR(t->rchild);
    }
}

void DLR(btptr t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
    if(t->lchild!=NULL)
        LDR(t->lchild);
    if(t->rchild!=NULL)
        LDR(t->rchild);
    }
}

void LRD(btptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDR(t->lchild);
    if(t->rchild!=NULL)
        LDR(t->rchild);
    cout<<t->data<<" ";
    }
}

/// creating stack of the bt pointers

typedef
struct stak
{
    int top;
    btptr elements[50];
    int siz;
}
*sptr;

void initialize(sptr &s)
{
    s=new(stak);
    s->top=-1;
    s->siz=50;
}

void push(sptr s,btptr t)
{
    if(t!=NULL)
    {
    if((s->top)==s->siz)
        cout<<"\nStack is full.\n";
    else
    {
        s->top++;
        s->elements[s->top]=t;
    }
    }
}

btptr pop(sptr s)
{
    if(s->top==-1)
        return NULL;
    else
    {
        btptr t=s->elements[s->top];
        s->top--;
        return t;
    }
}

bool check(sptr s)
{
    if(s->top==-1)
        return false;
    else
        return true;
}

//all done with the stack

void DLRi(btptr t)
{
    cout<<"\n";
    sptr s;
    initialize(s);
    push(s,t);
    while(check(s))
    {
        btptr t2=pop(s);
        cout<<t2->data<<" ";
        if(t2->rchild!=NULL)
            push(s,t2->rchild);
        if(t2->lchild!=NULL)
            push(s,t2->lchild);
    }
    cout<<"\n";
}


void LRDi(btptr t)
{
    cout<<"\n";
    btptr t1,x;
    sptr s;
    initialize(s);
    push(s,t);
    while(check(s))
    {
        t1=pop(s);
        if((t1->lchild==NULL) && (t1->rchild == NULL))
        {
            cout<<t1->data<<" ";
            x=pop(s);
            if(x!=NULL)
            {
            while(x!=NULL && (t1==x->lchild || t1==x->rchild))
            {
                cout<<x->data<<" ";
                t1=x;
                x=pop(s);
            }
            }
            push(s,x);
        }
        else
        {
            btptr l,r;
            l=t1->lchild;
            r=t1->rchild;
            push(s,t1);
            push(s,r);
            push(s,l);
        }
    }
}


void LDRi(btptr t)
{
    cout<<"\n";
    sptr s;
    initialize(s);
    push(s,t);
    while(check(s))
    {
       btptr t1=pop(s);
        if(check(s))
        {
            btptr x=pop(s);
            if(x==t1->rchild)
            {
                cout<<t1->data<<" ";
                push(s,x);
                continue;
            }
            push(s,x);
        }
        if(t1->lchild==NULL && t1->rchild ==NULL )
        {
            cout<<t1->data<<" ";
        }
        else
        {
            btptr r=t1->rchild;
            btptr l=t1->lchild;
            push(s,r);
            push(s,t1);
            push(s,l);
        }
    }
}

#endif // bt_H_INCLUDED
