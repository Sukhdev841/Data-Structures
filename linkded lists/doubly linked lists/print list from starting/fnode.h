#ifndef FNODE_H_INCLUDED
#define FNODE_H_INCLUDED

#include<iostream>
#include"stack.h"
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

/*int calculate(fptr n)
{
    int sum=0;
    if(n->p1)
    {
        sum=sum+calculate(n->p1);
    }
    if(n->p2)
    {
        sum=sum+calculate(n->p2);
    }
    if(n->p3)
    {
        sum=sum+calculate(n->p3);
    }

    if(n->p1&&n->p2&&n->p3)
    {
        cout<<"\n"<<n->data<<" has 2 ways.\n";
        sum++;
        sum++;
    }

    else if((n->p1&&n->p2)||(n->p2&&n->p3)||(n->p3&&n->p1))
        {
            sum++;
            cout<<"\n"<<n->data<<" has 1 way.\n";
        }
       // if(n->p1->p1)
        //    cout<<"\nNot null\n";
    if ((!(n->p1->p1))&&(!(n->p1->p2))&&(!(n->p1->p3)))
                 {
                     if ((!(n->p2->p1))&&(!(n->p2->p2))&&(!(n->p2->p3)))
                         {
                             if ((!(n->p3->p1))&&(!(n->p3->p2))&&(!(n->p3->p3)))
                                 {sum++;}
                         }
                 }

    if(!(n->p1) && !(n->p2) && !(n->p3))
        return 0;
    else
    return (sum);
}
*/

void print2(fptr n)
{
    static stak s; // static stack
    stak s2; // local stack
    cp(s2,s); // copy static stack from local stack
    push(s2,n->data); // pushing own element to local stack
    if(n->p1!=NULL||n->p2!=NULL||n->p3!=NULL) //because if all these are null then last element is this
    {
        if(n->p1) // if p1 element is there
        {
            push(s,n->data);
            print2(n->p1);
            int k=*popup(s);
        }
        if(n->p2)
        {
            push(s,n->data);
            print2(n->p2);
            int k=*popup(s);
        }
        if(n->p3)
        {
            push(s,n->data);
            print2(n->p3);
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
#endif // FNODE_H_INCLUDED
