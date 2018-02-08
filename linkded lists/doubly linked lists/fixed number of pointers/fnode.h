#ifndef FNODE_H_INCLUDED
#define FNODE_H_INCLUDED

#include<iostream>
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
    cout<<"\nIf you want to point p1 pointer of this list to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p1);
    cout<<"\nIf you want to point p2 pointer of this list to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p2);
    cout<<"\nIf you want to point p3 pointer of this list to another new list press 1 : ";
    cin>>d;
    if(d==1)
        create(n->p3);

}

#endif // FNODE_H_INCLUDED
