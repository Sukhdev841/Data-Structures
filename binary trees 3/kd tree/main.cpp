#include <iostream>
#include"kdtree.h"

using namespace std;

int main()
{
    kdptr t;
    create(t);
    int n=7;
    int k=get_key(t);
    for(int i=0;i<n;i++)
    {
        int keys[k];
        cout<<"\nEnter key to insert : \n";
        for(int j=0;j<k;j++)
            {
                cout<<"\nEnter key "<<j+1<<" : ";
                cin>>keys[j];
            }
            reset_c();
        insert_kd(t,keys);
    }
    cout<<"\nPrinting LDR of this tree\n";
    LDR(t);

    cout<<"\nEnter the key you want to search in the tree : \n";
    int temp[k];
    for(int i=0;i<k;i++)
    {
        cout<<"\nEnter "<<i+1<<" th key of the search key : ";
        cin>>temp[i];
    }

    if(kdsearch(t,temp))
    {
        cout<<"\nKey is found in the tree.\n";
    }
    else
        cout<<"\nKey is not found in the tree.\n";

    return 0;
}

