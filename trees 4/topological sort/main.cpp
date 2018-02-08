#include<iostream>

using namespace std;

typedef
struct tnode
{
    int data;
    tnode *next;
    int rel[20];
}
*tptr;

void initialize(tptr &t)
{
    t=new tnode;
    t->data=0;
    t->next=NULL;
    t->rel[0]=-1;
}

void addback(tptr& t,int k)
{
    if(t==NULL)
    {
        initialize(t);
        t->data=k;
    }
    else
    {
        tptr x=t;
        while(x->next!=NULL)
            x=x->next;
        initialize(x->next);
        x->next->data=k;
    }
}

void realloc(int *arr,int siz)       //siz-1 == -1     or size (0)
{
    if(siz==0)
    {
        arr=new int[2];
        arr[1]=-1;
        return ;
    }

    int *p=new int[siz+1];
    for(int i=0;i<(siz-1);i++)         // add element at arr[siz-1]       ///
    {
        p[i]=arr[i];
    }
    p[siz]=-1;
    delete  [] (arr);
    arr=p;
}

void relate(tptr &t,int a,int b)       // course 'a' after course 'b'
{
    tptr a1=t;
    while(a1->data!=a)
        a1=a1->next;
    int i=0;
    while(a1->rel[i]!=-1)
        i++;
    a1->rel[i]=b;
    a1->rel[i+1]=-1;
}

void addback(int *arr,int k)
{
    int i=0;
    while(arr[i]!=-1)
        {
            if(arr[i]==k)
                return;
            i++;
        }
    arr[i]=k;
    arr[i+1]=-1;
}

int main()
{
    tptr t=NULL;
    tptr t2;
    int arr[50];
    arr[0]=-1;
    int n=4;
    for(int i=0;i<n;i++)
    {
        addback(t,i+1);
    }
    /// asking for the relation
    t2=t;
    for(int i=0;i<n;i++)
    {
        int x;
        do
        {
            cout<<"\nIf "<<t2->data<<" is done after any course enter the course number else press -1 : ";
            cin>>x;
            if(x!=-1)
            {
                relate(t,t2->data,x);            ///after course x
            }
        }
        while(x!=-1);
        t2=t2->next;
    }

    t2=t;
    cout<<"\nCourses that you can do : \n";
    while(t2!=NULL)
    {
        if(t2->rel[0]==-1)
            cout<<t2->data<<" ";
        t2=t2->next;
    }
    int y;
    cout<<"\nEnter the course you want to do : ";
    cin>>y;
    addback(arr,y);

    while(1)
    {
        t2=t;
        cout<<"\nCourses that you can do : ";
        while(t2!=NULL)
        {
            if(t2->rel[0]==-1)
                cout<<t2->data<<" ";
            else
            {
                int flag=0;
                int i=0;
                while(t2->rel[i]!=-1)
                {
                    flag=0;
                    int j=0;
                    while(arr[j]!=-1)
                    {
                        if(arr[j]==t2->rel[i])
                        {
                            flag=1;
                            break;
                        }
                        j++;
                    }
                    i++;
                }
                if(flag)
                    cout<<t2->data<<" ";
            }
            t2=t2->next;
        }
        cout<<"\nEnter course number : ";
        cin>>y;
        addback(arr,y);
        int x=0;
        while(arr[x]!=-1)
            x++;
        if(x==n)
            break;
    }
    cout<<"\nYou have done all the courses.\n";
    return 0;
}
