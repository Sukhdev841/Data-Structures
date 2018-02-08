#include <iostream>
#include"bt.h"

using namespace std;

int main()
{
    btptr t;
    int i=4;
    create(t,i);
    cout<<"\nPrinting iteratively \n";
    LDRi(t);
    return 0;
}
