#ifndef KDTREE_H_INCLUDED
#define KDTREE_H_INCLUDED

#include<iostream>
#include<cstring>

using namespace std;

int flag=1;
int key=0;
int c=0;

void reset_c(void)
{
    c=0;
}

typedef
struct kdnode
{
    kdnode *lchild;
    int *data;
    int k;
    kdnode *rchild;
}
*kdptr;

int get_key(kdptr t)
{
    if(t!=NULL)
    return t->k;
    else
    {
        cout<<"\nTree node is null.Returning 0.\n";
        return 0;
    }
}

void create(kdptr &t)
{
    cout<<"\nEnter how many integer keys you want to store in a node : ";
    cin>>key;
    flag=0;
    t=new kdnode;
    t->lchild=NULL;
    t->rchild=NULL;
    t->k=key;
    t->data=new int[key];
    cout<<"\nNow enter root node's key values : \n";
    for(int i=0;i<key;i++)
    {
        cout<<"\nEnter key "<<i+1<<" : ";
        cin>>t->data[i];
    }
}

void insert_kd(kdptr &t,int *kk )
{
    if(t!=NULL)
    {
        if(kk[c]<t->data[c])
        {
            c++;
            if(c==key)
                c=0;
            insert_kd(t->lchild,kk);
        }
        else if(kk[c]>t->data[c])
        {
            c++;
            if(c==key)
                c=0;
            insert_kd(t->rchild,kk);
        }
    }
    else
    {
        t=new (kdnode);
        t->lchild=NULL;
        t->rchild=NULL;
        t->k=key;
        t->data=new int[key];
        for(int i=0;i<key;i++)
        {
            t->data[i]=kk[i];
        }
    }
}

void LDR(kdptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDR(t->lchild);

    cout<<"\n";
    for(int i=0;i<t->k;i++)
        cout<<t->data[i]<<" ";

    if(t->rchild!=NULL)
        LDR(t->rchild);
    }
}

void rest_key(void)
{
    key=0;
    flag=1;
}

bool kdsearch(kdptr t, int *kk)
{
    static int c=0;

    if(t!=NULL)
    {
        if(kk[c]<t->data[c])
        {
            c++;
            if(c==t->k)
                c=0;
            return (kdsearch(t->lchild,kk));
        }
        else if(kk[c]>t->data[c])
        {
            c++;
            if(c==t->k)
                c=0;
            return(kdsearch(t->rchild,kk));
        }
        else if(kk[c]==t->data[c])
        {

         for(int i=0;i<t->k;i++)
         {
             if(kk[i]!=t->data[i])
                return false;
         }
            return true;
        }
    }
    return false;
}

#endif // KDTREE_H_INCLUDED
