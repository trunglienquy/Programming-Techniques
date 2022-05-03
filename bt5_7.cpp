#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void coutWord(string s){
    int cnt = 0;
    int arr[8] = {0};
    int max = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            cnt++;
        }
        else{
            arr[cnt]++;
            cnt = 0;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "So tu loai xuat hien nhieu nhat: " << max;
    
    
}

int main(){
    ifstream ip;
    ip.open("null.txt");
    string s;
    string tmp;
    while (!ip.eof())
    {
        getline(ip, tmp);
        s += tmp + ' ';
    }
    coutWord(s);
    return 0;
}