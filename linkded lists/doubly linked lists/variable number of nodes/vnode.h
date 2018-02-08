#ifndef VNODE_H_INCLUDED
#define VNODE_H_INCLUDED

#include<iostream>

using namespace std;

typedef
struct vnode
{
    int data;
    int c;
    vnode **p;
    vnode()
    {
        data=0;
        c=0;
        p=NULL;
    }
}
*vptr;

void create(vptr& n)
{
    n=new(vnode);
    cout<<"\nEnter data element : ";
    cin>>n->data;
    cout<<"\nEnter number of nodes you want to join with node  "<<n->data<<" : ";
    cin>>n->c;
    n->p=new vptr[n->c];
    int k=0;
    while(k!=n->c)
    {
        create(n->p[k]);
        k++;
    }
}

void print(vptr n)
{
    if(n!=NULL)
    {
        cout<<n->data<<" ";
        for(int i=0;i<n->c;i++)
        {
            print(n->p[i]);
        }
    }
}

#endif // VNODE_H_INCLUDED
