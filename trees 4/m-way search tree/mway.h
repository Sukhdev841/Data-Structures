#ifndef MWAY_H_INCLUDED
#define MWAY_H_INCLUDED

#include<iostream>

using namespace std;

int M=0;

int set_m(void)
{
    cout<<"\nEnter value of m : ";
    cin>>M;
    return M;
}

#define SIZE M
typedef int datatype;

void bubble_sort(datatype *arr,int siz)
{
    for(int i=0;i<(siz-1);i++)
    {
        for(int j=0;j<(siz-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                datatype temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

typedef
struct mtnode
{
    int coun_t;
    datatype data[];
    mtnode **ptr;
}
*mptr;

void initialize(mptr &t)
{
    t=new mtnode;
    t->coun_t=0;
    (t->ptr)=new mptr[SIZE+1];
    for(int i=0;i<SIZE+1;i++)
    {
        t->ptr[i]=NULL;
    }
}

void insert_here(mptr &t,datatype k)    // if coun_t is less than the SIZE
{
    if(t->coun_t==0)
    {
        t->data[t->coun_t]=k;
        t->coun_t++;
    }
    else
    {
    datatype temp[t->coun_t+1];
    int i;
    for(i=0;i<t->coun_t;i++)
        temp[i]=t->data[i];
    temp[i]=k;
    bubble_sort(temp,t->coun_t+1);
    for(i=0;i<t->coun_t+1;i++)
        t->data[i]=temp[i];
    t->coun_t++;
    }
}

void insert_(mptr &t,datatype k)
{
    if(t->coun_t<SIZE)     // first checking if spaces are available in the node
    {
        insert_here(t,k);
    }
    else
    {
        mptr temp=NULL;
        bool flag=true;
        for(int i=0;i<SIZE;i++)       // will find the position where the data is greater than the key
        {
            if(t->data[i]>k)
            {
                temp=t->ptr[i];
                if(t->ptr[i]==NULL)     // no next node is present there so we are creating new node
                {
                    initialize(t->ptr[i]);
                    insert_here(t->ptr[i],k);
                    flag=false;
                }
                break;
            }
        }
        if(temp!=NULL)
        {
            insert_(temp,k);
        }
        else if(flag)
        {
            if(t->ptr[SIZE]==NULL)
            {
                initialize(t->ptr[SIZE]);
                insert_here(t->ptr[SIZE],k);
            }
            else
                insert_(t->ptr[SIZE],k);
        }

    }
}

void print(mptr t)
{
    if(t!=NULL)
    {
        int i;
        for(i=0;i<SIZE;i++)
        {
            print(t->ptr[i]);
            cout<<t->data[i]<<" ";
        }
        print(t->ptr[i]);
    }
}

#endif // MWAY_H_INCLUDED
