#ifndef MNODE_H_INCLUDED
#define MNODE_H_INCLUDED

#include <iostream>

using namespace std;

typedef
struct mnode
{
    bool tag; // 1 or zero
    union
    {
        char c;// tag is true
        mnode *t; // tag is false
    }
    data;
    mnode *next; // for pointing to next node
}
*pmnode;

void print (pmnode n)  // its done
{
        if(n!=NULL)
        {
            if(n->tag)
            {
                cout<<n->data.c<<" ";
                print(n->next);
            }
            else
            {
               print(n->data.t);
               print(n->next);
            }
        }
            return;
}

void create(pmnode &n)
{
    n=new(mnode);
    int s;
    cout<<"\nFor entering data element press 1.";
    cout<<"\nFor linking this node to a new list press 2.";
    cout<<"\nFor ending this linked list here press 3.";
    cout<<"\nEnter your choice : ";
    cin>>s;
    if(s==1)
    {
        char c;
        cout<<"\nEnter data element : ";
        cin>>c;
        n->data.c=c;
        n->tag=true;
    }
    else if (s==2)
    {
        n->tag=false;
        cout<<"\nNow every input goes to this node series. Keep in mind.\n";
        create(n->data.t);
    }
    else if(s==3)
    {
        cout<<"\nThis node series is done.\n";
        n=NULL;
    }
    if(s==1||s==2)
    {
        //cout<<"found s==1\n";
    create(n->next);
    }
}

#endif // MNODE_H_INCLUDED
