#include <iostream>
#include"fnode.h"
using namespace std;

int main()
{
    fptr f;
    int n;
    cout<<"\nEnter data : ";
    create(f);
    cout<<"\nEnter number you want to search : ";
    cin>>n;
    print2(f,n);
    return 0;
}
