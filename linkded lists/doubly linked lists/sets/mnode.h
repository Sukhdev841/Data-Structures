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

int j=1;

void print (pmnode n)  // its done
{
    int k=0;
        if(n!=NULL)
        {
            if(j==1)
                {
                    cout<<"( ";
                    k=1;
                }
                j=0;
            if(n->tag)
            {
                cout<<n->data.c<<" ";
                print(n->next);
            }
            else
            {
               // j=1;
                cout<<"( ";
               print(n->data.t);
               cout<<") ";
               print(n->next);
            }
        }
        if(k)
       {
           cout<<") ";
       }
            return;
}



#endif // MNODE_H_INCLUDED
