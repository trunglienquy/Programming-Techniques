#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cau_a(string s){
    string tmp = s;
    int cnt = 0;
    int cnt2 = 0;
    tmp[tmp.length()] = tmp[tmp.length()] + ' ';
    for (int i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] != ' ')
        {
            if (tmp[i] == 'a'|| tmp[i] == 'o'|| tmp[i] == 'u'|| tmp[i] == 'i'|| tmp[i] == 'e')
            {
                cnt++;
            }
            else
            {
                cnt2++;
            }
        }
    }
    cout << "So luong nguyen am la: " << cnt << endl << "So luong phu am la: " << cnt2 << endl;
}

void cau_b(string &s){
    s[0] = char(int(s[0]) - 32);
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == ' ')
        {
            s[i + 1] = char(int(s[i + 1]) - 32);
        }
    }
}

void cau_c(string s){
    int cnt = 0;
    string t = s + ' ';
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != ' ')
        {
            cnt++;
        }
        else
        {
            cout << cnt << " ";
            cnt = 0;
        }
    }
}

int main(){
    fstream ip;
    ip.open("STR.INP");
    string s, t;
    while (!ip.eof())
    {
        getline(ip, s);
        t += s + ' ';
    }
    cau_a(t);
    ip.close();
    fstream ip2;
    ip2.open("STR.INP");
    string s2;
    while (!ip2.eof())
    {
        getline(ip2, s2);
        cau_b(s2);
        cout << s2 << endl;
    }
    ip2.close();
    fstream ip3;
    ip3.open("STR.INP");
    string s3;
    while (!ip3.eof())
    {
        getline(ip3, s3);
        cau_c(s3);
        cout << endl;
    }
    ip3.close();
    
    return 0;
}