#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include<iostream>
#include<cstring>

using namespace std;

typedef
struct hnode
{
    hnode *lchild;
    int freq;
    char ch;
    hnode *rchild;
}
*hptr;

typedef
struct llist
{
      hptr node;
     llist *next;
}
*lptr;

typedef
struct l2
{
    char num[30];
    int siz;
    char ch;
    l2 *next;
}
*l2ptr;

void create_l2(l2ptr &l)
{
    l=new l2;
    strcpy(l->num,"n");
    l->siz=0;
    l->ch='\0';
    l->next=NULL;
}

void create_l(lptr &l)
{
    l=new llist;
    l->next=NULL;
    l->node=NULL;
}

void addback(lptr l,hptr t)
{
    if(l!=NULL)
    {
        while(l->next!=NULL)
            l=l->next;
        lptr a=new llist;
        a->next=NULL;
        a->node=t;
        l->next=a;
    }
    else
    {
        cout<<"\nCan't do addback function.\n";
    }
}

void addback(l2ptr l,char *n,char c)
{
    if(l!=NULL)
    {
        while(l->next!=NULL)
            l=l->next;
        l2ptr a=new l2;
        a->next=NULL;
        strcpy(a->num,n);
        a->siz=strlen(n);
        a->ch=c;
        l->next=a;
    }
    else
    {
        cout<<"\nCan't do addback function in l2.\n";
    }
}

void create_h(hptr &t)
{
    t=new hnode;
    t->freq=0;
    t->ch='*';
    t->lchild=NULL;
    t->rchild=NULL;
}

void delete_first(lptr &l)
{
    if(l!=NULL)
    {
        lptr a=l;
        l=l->next;
        delete(a);
    }
    else
    {
        cout<<"\nCan't do delete_first function.\n";
    }
}

void delete_first_l2(l2ptr &l)
{
    if(l!=NULL)
    {
        l2ptr a=l;
        l=l->next;
        delete(a);
    }
    else
    {
        cout<<"\nCan't do delete_first function on l2.\n";
    }
}

void s_ort(lptr l)
{
    lptr l2=l;
    while(l!=NULL)
    {
        lptr a=l2;
        while(a!=NULL)
        {
            if(a->node->freq > l->node->freq)
            {
                hptr temp=a->node;
                a->node=l->node;
                l->node=temp;
            }
            a=a->next;
        }
        l=l->next;
    }
}

hptr mnode()
{
    hptr t=new hnode;
    return t;
}

void LDR(hptr t);
void DLR(hptr t);

void make_tree(hptr &t,lptr l)
{
    hptr x;
    while(l->next!=NULL)
    {
        s_ort(l);
        x=new hnode;
        x->lchild=l->node;
        x->rchild=l->next->node;
        x->freq=l->node->freq + l->next->node->freq;
        delete_first(l);
        x->ch='*';
        l->node=x;
    }
    t=l->node;
}

void LDR(hptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDR(t->lchild);
    cout<<t->freq<<" "<<t->ch<<endl;
    if(t->rchild!=NULL)
        LDR(t->rchild);
    }
}

void DLR(hptr t)
{
    if(t!=NULL)
    {
        cout<<t->freq<<" "<<t->ch<<endl;
    if(t->lchild!=NULL)
        LDR(t->lchild);
    if(t->rchild!=NULL)
        LDR(t->rchild);
    }
}

void LRD(hptr t)
{
    if(t!=NULL)
    {
    if(t->lchild!=NULL)
        LDR(t->lchild);
    if(t->rchild!=NULL)
        LDR(t->rchild);
    cout<<t->freq<<" "<<t->ch<<endl;
    }
}

void set_l(l2ptr l,hptr t)
{
    static char str[50];
    static int i=0;
    if(t->lchild!=NULL)
    {
        str[i]='0';
        i++;
        set_l(l,t->lchild);
        i--;
    }
    if(t->rchild!=NULL)
    {
        str[i]='1';
        i++;
        set_l(l,t->rchild);
        i--;
    }
    if(t->lchild ==NULL && t->rchild==NULL)
    {
        str[i]='\0';
        addback(l,str,t->ch);
    }
}

#endif // NODE_H_INCLUDED
