#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{
    bstptr t1,t2;
    int arr[]={1,2,3,4,5,10,9,8,7,6};
    int n=10;
    t1=new bstnode;
    t1->lchild=NULL;
    t1->rchild=NULL;
    t1->data=arr[0];
    for(int i=1;i<n;i++)
    {
        insertAVL(t1,arr[i]);
    }

    int f;
    cout<<"\nEnter the number you want to find in the both trees (AVL and normal ) : ";
    cin>>f;

    cout<<"\nNumber of steps taken to find the number "<<f<<" in AVL tree is : ";
    cout<<find_this(t1,f);

    cout<<"\n\n\nNow creating simple binary tree\n";
    t2=new bstnode;
    t2->lchild=NULL;
    t2->rchild=NULL;
    t2->data=arr[0];
    for(int i=1;i<n;i++)
    {
        bstinsert(t2,arr[i]);
    }

    cout<<"\nNumber of steps taken to find number "<<f<<" in the normal binary tree is : ";
    cout<<find_this(t2,f)<<endl<<endl;

    return 0;
}
