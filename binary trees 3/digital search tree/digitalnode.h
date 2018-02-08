#ifndef DIGITALNODE_H_INCLUDED
#define DIGITALNODE_H_INCLUDED

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

int pow(int x)
{
    int f=1;
    for(int i=0;i<x;i++)
        f=f*10;
    return f;
}

int integer(char *s)
{
    int len=strlen(s);
    int num=0;
    for(int i=0;i<len;i++)
    {
        num=num+(s[i]-48)*pow(len-i-1);
    }
    return num;
}

typedef
struct dnode
{
    dnode *lchild;
    char data[9];
    dnode *rchild;
}
*dptr;

void create(dptr &t,char *s)
{
    t=new dnode;
    t->lchild=NULL;
    t->rchild=NULL;
    strcpy(t->data,s);
}

void insert_dtree(dptr &t, char *s)
{
    if(t!=NULL)
    {
        int i1=integer(s);
        int i2=integer(t->data);
        if(i1<i2)
            insert_dtree(t->lchild,s);
        if(i1>i2)
            insert_dtree(t->rchild,s);
    }
    else
    {
        create(t,s);
    }
}

void LDR(dptr t)
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

#endif // DIGITALNODE_H_INCLUDED
