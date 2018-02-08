#include <iostream>

using namespace std;

typedef struct dnode
{
    dnode *left;
    int data;
    dnode *right;
    dnode()
    {
        left=NULL;
        right=NULL;
        data=0;
    }
}
*dptr;

void deletebegin(dptr &d)
{
    d->right->left=NULL;
    d=d->right;
}

void deleteback(dptr& d)
{
    dptr t=d;
    while(d->right->right!=NULL)
    {
        d=d->right;
    }
    d->right=NULL;
    d=t;
}

void addbegin(dptr& d ,int x)
{
    dptr t=new(dnode);
    t->data=x;
    t->right=d;
    t->left=NULL;
    d=t;
}

void addback(dptr& d,int x)
{
    dptr t=d;
    while(d->right!=NULL)
    {
        d=d->right;
    }
    d->right=new(dnode);
    d->right->data=x;
    d->right->left=d;
    d->right->right=NULL;
    d=t;
}

void show(dptr d)
{
    if(d!=NULL)
        {cout<<d->data<<" ";
        show(d->right);
        }
}

void create(dptr& d,int x)
{
    d=new(dnode);
    d->left=NULL;
    d->right=NULL;
    d->data=x;
}

void deletethis(dptr& d,int x)
{
    if(d->data==x)
        deletebegin(d);
    else
    {
    dptr t=d;
    while(d->right->data!=x)
        d=d->right;
        if(d->right->right==NULL)
            deleteback(d);
        else
        {
    d->right=d->right->right;
    d->right->left=d;
        }
        d=t;
    }
}

void addbefore(dptr& d,int n,int x)
{
    if(d->data==n)
        addbegin(d,x);
    else
    {
        dptr t=d,t2=new(dnode);
        t2->data=x;
        while(d->data!=n)
            d=d->right;
        d->left->right=t2;
        t2->left=d->left;
        d->left=t2;
        t2->right=d;
        d=t;
    }
}

void addafter(dptr& d,int n,int x)
{
    dptr t=d;
    while(d->data!=n)
    {
        d=d->right;
    }
        if(d->right==NULL)
            addback(d,x);
        else
        {
            dptr t2=new(dnode);
            t2->data=x;
            d->right->left=t2;
            t2->right=d->right;
            t2->left=d;
            d->right=t2;
        }
        d=t;
}

int main()
{
    dptr s=new(dnode);
    cout<<"\nEnter 5 elements\n";
    for(int i=0;i<5;i++)
    {
        if(i==0)
            create(s,i+1);
        else
            addback(s,i+1);
    }
    cout<<"\n";
    show(s);
    deletebegin(s);
    cout<<"\n";
    show(s);
    deleteback(s);
    cout<<"\n";
    show(s);
   // deletethis(s,4);
   // cout<<"\n";
   // show(s);
    addafter(s,3,6);
    cout<<"\n";
    show(s);
    return 0;
}
