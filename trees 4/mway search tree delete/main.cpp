#include <iostream>

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
                insert_(t->ptr[m],k);
            }
        }
    }
}

void print(mptr t)
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
        return(find_(t->ptr[i],k));
    }
    return false;
}

mptr find_node(mptr &t,int k)
{
    if(t!=NULL)
    {
        int i=0;
        for(i=0;i<m;i++)
        {
            if(k==(t->data[i]))
            {
              return t;
            }
            else if(k<(t->data[i]))
            {
                return(find_node(t->ptr[i],k));
            }
        }
        return (find_node(t->ptr[i],k));
    }
    return NULL;
}

void remove_(mptr &t,int i_th)
{
    mptr  temp[t->coun_t];
    int temp2[t->coun_t-1];
    int i,j;
    for(i=0,j=0;i<t->coun_t;i++)
    {
        if(i!=i_th)
        {
            temp[j]=t->ptr[i];
            temp2[j]=(t)->data[i];
            j++;
        }
    }
    temp[j]=(t)->ptr[i];
    j=i-1;
    t->coun_t=0;
    for(t->coun_t=0;t->coun_t<j;t->coun_t++)
    {
        t->ptr[t->coun_t]=temp[t->coun_t];
        t->data[t->coun_t]=temp2[t->coun_t];
    }
    t->ptr[t->coun_t]=temp[t->coun_t];
}

void delete_(mptr &t,int k)
{
    mptr x=find_node(t,k);
    if(x!=NULL)
    {
        int i;
        for(i=0;i<m;i++)
        {
            if(x->data[i]==k)
                break;
        }
        if(x->ptr[i]==NULL)
            {
                remove_(x,i);
            }
        else
        {
            mptr y=x->ptr[i];
            while(y->ptr[m]!=NULL && y->coun_t==m )
            {
                y=y->ptr[m];
            }
            x->data[i]=y->data[y->coun_t-1];
            if(y->coun_t!=m)
            {
                remove_(y,y->coun_t-1);
            }
            else
            delete_(y,y->data[m-1]);
        }
    }
}

int main()
{
    mptr t=NULL;
    set_m();
    initialize(t);
    int arr[]={12,50,85,6,10,37,25,60,70,80,62,65,69,100,120,150,110};
    for(int i=0;i<17;i++)
    {
       insert_(t,arr[i]);
    }
    cout<<"\n\nLDR\n";
    print(t);
    cout<<"\n";
    delete_(t,12);
    cout<<"\nAfter deletion LDR\n";
    print(t);
        return 0;
}

