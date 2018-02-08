#include<iostream>
#include"node.h"
#include<cstdlib>
#include<cstdio>
using namespace std;

int n=27;

int main()
{
    lptr l;
    create_l(l);
    int freq[]={77,17,32,42,120,24,17,50,76,4,7,42,24,67,67,20,5,59,67,85,37,12,22,4,22,2,70};
    char alp[n+1];
    alp[n]='\0';
    alp[n-1]=' ';
    // initialization
    for(int i=0;i<n;i++)
    {
        hptr t;
        create_h(t);
        if(i!=26)
        {t->ch=i+97;
        alp[i]=i+97;
        }
        else
        {
            t->ch=' ';
        }
        t->freq=freq[i];
        addback(l,t);
    }
    delete_first(l);
    // done with initialization
    // now sorting the list according to proxy

    s_ort(l);

   hptr nnew;    // tree pointer
    make_tree(nnew,l);         // making the tree pointer according to huffman algorithm
    l2ptr l2; // a list of other node structure to save the values of the characters using huffman tree
    create_l2(l2);
    set_l(l2,nnew);       // values of 101010 set in the list and corresponding character also
    delete_first_l2(l2);

    l2ptr xv=l2;

    // now getting string to make the code
    cout<<"\nEnter string : ";
    char str[1000];
    gets(str);
    cout<<"\n";
    for(int i=0;i<strlen(str);i++)
    {
        l2ptr lx=xv;
        while(lx!=NULL)
        {
            if(lx->ch==str[i])
            {
                cout<<lx->num<<" ";
                break;
            }
            lx=lx->next;
        }
    }
    char s2[100];
    cout<<"\nNow enter code \n";
    gets(s2);

    int len=strlen(s2);

    char temps[30];
    int j=0;
    for(int i=0;i<len;i++)
    {
        temps[j]=s2[i];
        temps[j+1]='\0';
        l2ptr l3=l2;
        while(l3!=NULL)
        {
            if(!strcmp(l3->num,temps))
            {
                cout<<l3->ch;
                j=-1;
                break;
            }
            l3=l3->next;
        }
        j++;
    }

    return 0;
}
