#include <iostream>
#include "fnode.h"
using namespace std;

int main()
{
    fptr f;
    cout<<"\nFirst create the list\n";
    create(f);
//   int c=calculate(f)+1;

   cout<<"\nAll possible ways to search a number are :"<<endl;
   print2(f);
   return 0;
}
