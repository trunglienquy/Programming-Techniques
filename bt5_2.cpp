#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void writeFile1(ofstream &ip);
void readFile(ifstream &ip1, int arr[], int &n);
void outputArray(int arr[], int n);
bool checknumber(int n);
void Primenumber(ofstream &ip2, int arr[], int n);
bool checkSquareNumber(int n);
void printSquareNumber(ofstream &ip2, int arr[], int n);
bool checkperfectNumber(int n);
void PerfectNumber(ofstream &ip2, int arr[], int n);

int main(){
    int arr[100];
    int n = 0;
    ofstream ip;
    ip.open("SONGUYEN.INP.txt", ios_base::out);
    writeFile1(ip);
    ifstream ip1;
    ip1.open("SONGUYEN.INP.txt", ios_base::in);
    readFile(ip1,arr,n);
    ofstream ip2;
    ip2.open("SONGUYEN.OUT.txt", ios_base::out);
    Primenumber(ip2,arr,n);
    printSquareNumber(ip2,arr,n);
    PerfectNumber(ip2,arr,n);
    ip.close();
    ip1.close();
    ip2.close();
    return 0;
}

void writeFile1(ofstream &ip){
    int n;
    cout << "Enter line: ";
    cin >> n;
    for (int i = 1; i < n*10+1; i++)
    {
        ip << rand() << " ";
        if (i%10==0)
        {
            ip << endl;
        }
    }
}

void readFile(ifstream &ip1, int arr[], int &n){
    while (ip1.eof() == false)
    {
        ip1 >> arr[n];
        n++;
    }
}

void outputArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
//Prime_Number
bool checknumber(int n){
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Primenumber(ofstream &ip2, int arr[], int n){
    int cnt = 0;
    ip2 << "Prime Number have: ";
    for (int i = 0; i < n; i++)
    {
        if (checknumber(arr[i]))
        {
            cnt++;
        }
    }
    ip2 << cnt;
}
//SquareNumber
bool checkSquareNumber(int n){
    if(n<1)
        return false;
    int i = sqrt(n);
    if(i*i==n)
        return true;
    return false;
}

void printSquareNumber(ofstream &ip2, int arr[], int n){
    int cnt = 0;
    ip2 << endl << "Square Number have: ";
    for(int i = 0; i < n; i++){
        if(checkSquareNumber(arr[i])){
            cnt++;
        }
    }
    ip2 << cnt;
}
//Perfect_Number
bool checkperfectNumber(int n){
    int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(sum==n)
    {
        return true;
    }
    return false;
}

void PerfectNumber(ofstream &ip2, int arr[], int n){
    int cnt = 0;
    ip2 << endl << "Perfect Number have: ";
    for (int i = 0; i < n; i++)
    {
        if (checkperfectNumber(arr[i]))
        {
            cnt++;
        }
    }
    ip2 << cnt;
}
