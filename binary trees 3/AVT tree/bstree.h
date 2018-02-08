#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include<iostream>

using namespace std;

int c=0;

void initialize_c(void)
{
    c=0;
}

int maxx(int a,int b)
{
    if(a>b)
        return (a+1);
    if(b>a)
        return (b+1);
    else
        return (a+1);
}

int diff(int a,int b)
{
    if(b>a)
        return (b-a);
    if(a>b)
        return (a-b);
    return (a-b);
}

typedef
struct bstnode
{
    bstnode *lchild;
    int data;
    bstnode *rchild;
}
*bstptr;

void create(bstptr &t)
{
    t=new(bstnode);
    cout<<"\nEnter root node's data : ";
    cin>>t->data;
    t->lchild=NULL;
    t->rchild=NULL;
}

void bstinsert(bstptr t,int n)
{
    initialize_c();
    if(n<t->data && t->lchild==NULL)
    {
        bstptr x=new(bstnode);
        x->data=n;
        x->lchild=NULL;
        x->rchild=NULL;
        t->lchild=x;
    }
    else if(n>t->data && t->rchild==NULL)
    {
        bstptr x=new(bstnode);
        x->data=n;
        x->lchild=NULL;
        x->rchild=NULL;
        t->rchild=x;
    }
    else if(n<t->data)
    {
        bstinsert(t->lchild,n);
    }
    else if(n>t->data)
    {
        bstinsert(t->rchild,n);
    }
}

void print(bstptr t)
{
    if(t->lchild!=NULL)
    {
        print(t->lchild);
    }
    cout<<t->data<<" ";
    if(t->rchild!=NULL)
    print(t->rchild);
}

void LDR(bstptr t)
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

void DLR(bstptr t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
    if(t->lchild!=NULL)
        DLR(t->lchild);
    if(t->rchild!=NULL)
        DLR(t->rchild);
    }
}

void LRD(bstptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LRD(t->lchild);
    if(t->rchild!=NULL)
        LRD(t->rchild);
    cout<<t->data<<" ";
    }
}

bstptr ffind(int num,bstptr t)    // returns pointer to the entered node
{
    if(t!=NULL)
    {
        if(num<t->data)
            return (ffind(num,t->lchild));
        else if(num==t->data)
            return t;
        else if(num>t->data)
            return (ffind(num,t->rchild));
    }
    return NULL;
}

bstptr find1(int num,bstptr t)   //returns pointer to the one node previous than searched node
{
    if(t!=NULL)
    {
        if(num==t->data)
        return NULL;
        if(t->rchild!=NULL)
         {
             if (num== (t->rchild->data))
            return t;
        }
        if(t->lchild!=NULL)
         {
             if(num==(t->lchild->data))
            return t;
         }
        if(num<(t->data))
            {
                return (find1(num,t->lchild));
            }
        if(num>(t->data))
            {
                return (find1(num,t->rchild));
            }
    }
    return NULL;
}

int num (bstptr t)
{
    if(t==NULL)
        return -1;
    else
    {
        int a,b;
        a=num(t->lchild);
        b=num(t->rchild);
        return(maxx(a,b));
    }
}

void rshift(bstptr &t)
{
    bstptr k1,k2;
     // step 1
    k1=t;
    k2=k1->lchild;
    // step2
    k1->lchild=k2->rchild;
    // step3
    k2->rchild=k1;
    //step4
    t=k2;
    //done rshift
}

void lshift(bstptr &t)
{
    bstptr k1,k2;
    //step1
    k1=t;
    k2=k1->rchild;
    //step2
    k1->rchild=k2->lchild;
    //step3
    k2->lchild=k1;
    //step4
    t=k2;
}

void l2shift(bstptr &t)
{
    bstptr k1,k2,k3;
    //step1
    k1=t;
    k2=k1->rchild;
    k3=k2->lchild;
    //step 2
    k1->rchild=k3->lchild;
    k2->lchild=k3->rchild;
    //step3
    k3->lchild=k1;
    k3->rchild=k2;
    //step 4
    t=k3;
    // done :)
}

void r2shift(bstptr &t)
{
    bstptr k1,k2,k3;
    //step1
    k1=t;
    k2=k1->lchild;
    k3=k2->rchild;
    //step 2
    k1->lchild=k3->rchild;
    k2->rchild=k3->lchild;
    //step 3
    k3->lchild=k2;
    k3->rchild=k1;
    //step 4
    t=k3;
    //done :)
}

bstptr ubnode(bstptr t) // returns pointer to the node whose balance is 2
{
    if(t==NULL)
        return NULL;
     //   cout<<"\nChecking ubnode of  "<<t->data<<endl;
        /*if(t->lchild!=NULL)
        cout<<"\nL child "<<t->lchild->data;
        if(t->rchild!=NULL)
            cout<<"\n R child "<<t->rchild->data;*/
       // cout<<"\nDifference is : "<<diff(num(t->lchild),num(t->rchild));
    bstptr a=NULL,b=NULL;
    a=ubnode(t->lchild);
    b=ubnode(t->rchild);
    if(a!=NULL)
        return a;
    if(b!=NULL)
        return b;
        if(diff(num(t->lchild),num(t->rchild))==2)
    {
        if(a==NULL && b==NULL)
        return t;
    }
    return NULL;
}

void LDRp(bstptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDRp(t->lchild);
        cout<<"\n num of "<<t->data<<" is ";
    cout<<num(t)<<" ";
    if(t->rchild!=NULL)
        LDRp(t->rchild);
    }
}

void insertAVL(bstptr &t,int m)
{
    initialize_c();
    //first insert normally
    bstinsert(t,m);
    // now check if there is any unbalance
    bstptr t2=ubnode(t);
    // if there is unbalance then t2 contains node
    // else contains NULL
    if(t2==NULL)
        return ;
    // else do these things
    bstptr t3=find1(t2->data,t);
    bool a=false,b=false,flag=false;
    if(t3==NULL)
        flag =true;
    if(!flag)
    {
        if((t2->data)==(t3->lchild->data))
        {
            a=true;
        }
    else
        b=true;
     }
    int n=num(t2); // contains unbalance of the node
    bool l1=false,l2=false,l3=false,l4=false;
    if(num(t2->lchild)==(n-1))
        l1=true;
    else
        l2=true;
    // now carefully
    if(l1)
    {
        if(num(t2->lchild->lchild)==(n-2))
            l3=true;
        else
            l4=true;
    }
    else
    {
        if(num(t2->rchild->lchild)==(n-2))
            l3=true;
        else
            l4=true;
    }

    // now do shifts

    if(l2&&l3)
        l2shift(t2);
    else if(l1&&l4)
        r2shift(t2);
    else if(l2&&l4)
        lshift(t2);
    else if(l1&&l3)
        rshift(t2);
        if(a)
            t3->lchild=t2;
        else if(b)
            t3->rchild=t2;
            else if(flag)
                t=t2;

}

int find_this(bstptr t,int n)
{
    c++;
    int x=c;
    if(t->data==n)
        return c;
    if(n<t->data)
        x=find_this(t->lchild,n);
    if(n>t->data)
        x=find_this(t->rchild,n);
    return x;

}

#endif // BSTREE_H_INCLUDED
