#ifndef FNODE_H_INCLUDED
#define FNODE_H_INCLUDED

#include<iostream>
#include"stack.h"
#include<cstdlib>
using namespace std;

typedef
struct fnode
{
    int data;
    fnode *p1;
    fnode *p2;
    fnode *p3;
    fnode()
    {
        data=0;
        p1=NULL;
        p2=NULL;
        p3=NULL;
    }
}
*fptr;

void print (fptr n)  // its done
{
    if(n!=NULL)
    {
        cout<<n->data<<" ";
        if(n->p1!=NULL)
        {
            print(n->p1);
        }
        if(n->p2!=NULL)
        {
            print(n->p2);
        }
        if(n->p3!=NULL)
        {
            print(n->p3);
        }
    }

}

void create(fptr &n)
{
    n=new(fnode);
    int d;
    cout<<"\nEnter data element : ";
    cin>>d;
    n->data=d;
    n->p1=NULL;
    n->p2=NULL;
    n->p3=NULL;
    cout<<"\nIf you want to point p1 pointer of "<<n->data<<" to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p1);
    cout<<"\nIf you want to point p2 pointer of "<<n->data<<" to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p2);
    cout<<"\nIf you want to point p3 pointer of "<<n->data<<" to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p3);

}

void print2(fptr n,int k)
{
    static stak s; // static stack
    stak s2; // local stack
    cp(s2,s); // copy static stack from local stack
    push(s2,n->data); // pushing own element to local stack
    if(n->data!=k)
    {
    if(n->p1!=NULL||n->p2!=NULL||n->p3!=NULL) //because if all these are null then last element is this
    {
        if(n->p1) // if p1 element is there
        {
            push(s,n->data);
            print2(n->p1,k);
            int k=*popup(s);
        }
        if(n->p2)
        {
            push(s,n->data);
            print2(n->p2,k);
            int k=*popup(s);
        }
        if(n->p3)
        {
            push(s,n->data);
            print2(n->p3,k);
            int k=*popup(s);
        }
    }
    else
    {
        //found last element of a search
        // should print local stack
        show(s2);
    }
    }
    else
    {
        cout<<"\nNumber is Here\n";
        show(s2);
        exit (0);
    }
}
#endif // FNODE_H_INCLUDED
