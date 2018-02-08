#ifndef STAK_H_INCLUDED
#define STAK_H_INCLUDED

#include<iostream>

using namespace std;

class stak
{
    int siz;
    int elements[50];
    int top;
public:
    stak()
    {
       // cout<<"\nIn constructor\n";
        siz=50;
        top=-1;
    }

    friend void push(stak&,int);
    friend int* pop(stak&);
    friend int* popup(stak&);
    friend void show(stak);
    friend void cp(stak&,stak&);
    friend void rest(stak&);
};

void show(stak s)
{
    cout<<"\n";
    for(int i=0;i<=s.top;i++)
    {
        cout<<s.elements[i]<<" ";
    }
    cout<<"\n";
}

void cp (stak&x,stak&y)
{
    x.siz=y.siz;
    x.top=y.top;
    for(int i=0;i<=x.top;i++)
    {
        x.elements[i]=y.elements[i];
    }
}

void push(stak& s,int x)
{
    if(s.siz-1==s.top)
        cout<<"\nUnable to push.\n";
    else
    {
        s.top++;
        s.elements[s.top]=x;
    }
}

int* pop(stak& s)
{
    if(s.top==-1)
        cout<<"\nNO ELEMENTS\n";
    else
        return(&s.elements[s.top]);
}

int *popup(stak&s)
{
    if(s.top==-1)
        cout<<"\nNo elements\n";
    else
        return(&s.elements[s.top--]);
}

void rest(stak &s)
{
    s.top=-1;
    s.siz=50;
}

#endif // STAK_H_INCLUDED
