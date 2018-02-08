#include <iostream>
#include"fnode.h"
using namespace std;

int main()
{
    fptr f;
    create(f);
    cout<<"\n";
    print(f);
    delete(f);
    return 0;
}
