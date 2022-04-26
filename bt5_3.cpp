#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

bool isPrime(int n){
    if (n<=1) return false;
    for (int i=2;i<n;i++){
        if (n%i==0) return false;
    }
    return true;
}

void wFilePrimes(){
    fstream outf;
    outf.open("bt5-3.out.txt", ios::out);
    int i=0;
    while (true){
        if (i>=1000000) break;
        
        if (isPrime(i)){
            outf << i << " ";
        }
        i++;
    }
}

void print(int a[]){
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            cout << (char)(i + 'a') << "-" << a[i] << endl;
        }
        
    }
    
}

void checkword(char s[]){
    int i = 0;
    int a[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >='A' && s[i] <= 'Z')
        {
            s[i]+=32;
        } 
    }
    
    while (s[i] != '\0')
    {
       a[s[i] - 'a']++;
       i++;
    }
    print(a);
}


int main(){
    wFilePrimes();
    fstream ip;
    char a[1000];
    ip.open("bt5-3.word.txt", ios_base::in);
    while (!ip.eof())
    {
        ip.getline(a,10000);
        checkword(a);
    }
    ip.close();
    return 0;
}