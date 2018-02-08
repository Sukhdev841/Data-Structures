#include<iostream>
#include"mnode.h" // mnode is included here

using namespace std;

typedef
struct info
{
    char c;   // name of the set
    mnode *p; //pointer to the node of starting of the set
    info()
    {
        c='\0'; // by default character is null character
        p=NULL;  // by default pointer is null pointer
    }
}
*pinfo;

pinfo *a; // pointer that can hold array elements of the pointer declared in main() function
int number; // this will hold the number of sets there in the array
// declaring a function that will associate a to the array declared in the main
void associate(pinfo *x)
{
    a=x; // associating global array to array declared in main function
}

// defining a function that will set number to the number of sets created

void snum(int n)
{
    number=n;
}

// defining a function that will check if given set name is there in the name of a array

pmnode check(char name)
{
    for(int i=0;i<number;i++)
    {
        if(a[i]->c==name)
        {
            return (a[i]->p);
        }
    }
    cout<<"\nNo such set is found.\n";
    return NULL;
}

void create(pmnode &n)
{
    n=new(mnode);
    int s;
    cout<<"\nFor entering data element press 1.";
    cout<<"\nFor making another set as element of this set press 2.";
    cout<<"\nFor ending this set here press 3.";
    cout<<"\nEnter your choice : ";
    cin>>s;
    if(s==1)
    {
        char c;
        cout<<"\nEnter data element : ";
        cin>>c;
        n->data.c=c;
        n->tag=true;
    }
    else if (s==2)
    {
        // link this element of this set to the set given
        char sname;
        cout<<"\nEnter set name you want to enter as element of this set : ";
        cin>>sname;
        n->data.t=check(sname);
        if(n->data.t!=NULL)
            n->tag=false;
        else
        {
            n->tag=true;
            cout<<"\nEnter this element again.";
        }
    }
    else if(s==3)
    {
        //cout<<"\nThis node series is done.\n";
        n=NULL;
    }
    if(s==1||s==2)
    {
        //cout<<"found s==1\n";
        if(s==2&& n->tag)
            create(n);
        else
      create(n->next);
    }
}

int main()
{
    int n;
    cout<<"\nEnter number of sets you want to create : ";
    cin>>n;
    if(n>0)
    {
        pinfo *data;
        data=new pinfo[n];
        for(int i=0;i<n;i++)
            data[i]=new(info);  // creating all elements of the data array of info elements

            // now associating data array with global array a so that create function can use it
            associate(data);

        for(int i=0;i<n;i++)
        {
            cout<<"\nCreating "<<i+1<<" set \nEnter name of the set (only one character) : ";
            cin>>data[i]->c;
            create(data[i]->p);
            snum(i+1);
        }
        char sn;
        cout<<"\nEnter name of the set you want to print: ";
        cin>>sn;
        print(check(sn));
    }
    else
        cout<<"\nWrong input.\n";
    return 0;
}
