#include <iostream>
//#include "mway.h"
using namespace std;

int m=0;

int set_m(void)
{
    cout<<"\nEnter value of m : ";
    cin>>m;
    return m;
}

void bubble_sort(int *arr,int siz)
{
    for(int i=0;i<(siz-1);i++)
    {
        for(int j=0;j<(siz-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
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
    int *data;
    mtnode **ptr;
}
*mptr;

void initialize(mptr &t)
{
    t=new mtnode;
    t->coun_t=0;
    t->data=new int[m];
    for(int i=0;i<(m);i++)
    {
        t->data[i]=0;
    }
    t->ptr=new mptr[m+1];
    for(int i=0;i<(m+1);i++)
    {
        t->ptr[i]=NULL;
    }

}

void insert_here(mptr &t,int k)    // if coun_t is less than the m
{
    if(t->coun_t==0)
    {
        t->data[t->coun_t]=k;
        t->coun_t++;
    }
    else
    {
        int x=t->coun_t,temp[x+1],z=0;

    for(z=0;z<x;z++)
    {
        temp[z]=t->data[z];
    }
    temp[z]=k;
    bubble_sort(temp,x+1);
    for(z=0;z<(x+1);z++)
        t->data[z]=temp[z];
    t->coun_t++;
    }
}

void insert_(mptr &t,int k)
{
    if(m>(t->coun_t))     // first checking if spaces are available in the node
    {
        insert_here(t,k);
    }
    else
    {
        mptr temp=NULL;
        bool flag=true;
        int i;
        for(i=0;i<m;i++)       // will find the position where the data is greater than the key
        {
            if((t->data[i])>k)
            {
                temp=t->ptr[i];
                if((t->ptr[i])==NULL)     // no next node is present there so we are creating new node
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
            if(t->ptr[(t->coun_t)]==NULL)
            {
                initialize(t->ptr[m]);
                insert_here(t->ptr[m],k);
            }
            else
            {
                initialize(t->ptr[m]);
                insert_(t->ptr[m],k);
            }
        }
    }
}

void print(mptr &t)
{
    if(t!=NULL)
    {
        int i;
        for(i=0;i<(t->coun_t);i++)
        {
            print(t->ptr[i]);
            cout<<t->data[i]<<" ";
        }
        print(t->ptr[i]);
    }
}

bool find_(mptr t,int k)
{
    if(t!=NULL)
    {
        int i=0;
        for(i=0;i<m;i++)
        {
            if(k==(t->data[i]))
            {
              return true;
            }
            else if(k<(t->data[i]))
            {
                return(find_(t->ptr[i],k));
            }
        }
        find_(t->ptr[i],k);
    }
    return false;
}

int main()
{
    mptr t=NULL;
    set_m();
    initialize(t);
    for(int i=0;i<(5);i++)
    {
        int x;
        cin>>x;
        insert_(t,(x));
    }

    cout<<"\n\nLDR\n";
    print(t);

    if(find_(t,4))
        cout<<"\nFound the number.\n";
    else
        cout<<"\nNot found\n";

        return 0;
}
