#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream fi1 ("SOLIEU1.INP");
    ifstream fi2 ("SOLIEU2.INP");
    ofstream fo ("SOLIEU.OUT");
    int n1,n2;
    do
    {
        fi1 >> n1 ; fi2 >> n2;
        if ( n1 > n2 )
            fo << n2 << " "<< n1 << " ";
        else 
            fo << n1 << " " << n2 << " ";
    } while ( !fi1.eof() && !fi2.eof() );
}