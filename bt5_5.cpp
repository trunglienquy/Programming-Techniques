#include <iostream>
#include <fstream>
using namespace std;




int sumSo ( int x ) 
{
    if ( x!= 0 )
        return x%10 + sumSo(x/10);
}
int main () 
{
    ifstream fi ("bangso.inp");
    ofstream fo ("bangso.out");
    int i,j;
    fi >> i;            //nhap dong
    fi >> j;            //nhap cot
    int arr2D[i][j];
    for ( int m=1 ; m<=i ; m++ ) 
    {
        for ( int n=1 ; n<=j ; n++ ) 
        {
            fi >> arr2D[m][n];
        }
    }




//cau a
    fo << "Cau a: ";
    int maxA;
    int a,b;
    for ( int m=1 ; m<=i ; m++ )
    {
        maxA = 0;
        for ( int n=1 ; n<=j ; n++ )
        {
            if ( maxA < arr2D[m][n])
            {
                maxA = arr2D[m][n];
                a = m;
                b = n;
            }
        }
        fo << "(" << a << ";" << b << ")" << "  ";
    }
//cau b
    fo << "\nCau b: ";
    int maxB = 0;
    for ( int m=1 ; m<=i ; m++ ) 
    {
        for ( int n=1 ; n<=j ; n++ ) 
        {
            if ( maxB < arr2D[m][n] )
            {
                maxB = arr2D[m][n];
                a = m;
                b = n;
            }
        }
    }
    fo << "(" << a << ";" << b << ")";




//cau c
    int max = 0 , maxCdong = 0 , maxCcot = 0;
    for ( int m=1 ; m<=i ; m++ ) 
    {
        for ( int n=1 ; n<=j ; n++ ) 
        {
            if ( maxCdong < arr2D[m][n] )
            {
                maxCdong = arr2D[m][n];
                maxCcot = n;
            }
        }

        for ( int a=1 ; a<=i ; a++ )
        {
            if ( maxCdong > arr2D[a][maxCcot] )
            {
                maxCdong = 0;
                break;
            }
        }
        
        if ( maxCdong != 0 )
            break;

    }   
        max = maxCdong;
        fo << max << endl;
        cout << max;


//cau d




//cau e





//cau f




}