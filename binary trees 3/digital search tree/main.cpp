#include <iostream>
#include"digitalnode.h"
#include<cstdlib>
using namespace std;

int main()
{
    dptr t;
    char num[8];
    cout<<"\nEnter root node's binary number : ";
    gets(num);
    create(t,num);
    int n=6;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter binary number : ";
        gets(num);
        insert_dtree(t,num);
    }
    cout<<"\nNow printing LDR \n";
    LDR(t);
    return 0;
}
