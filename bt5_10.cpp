#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//cau a
void readfile(ifstream &ip, ofstream &ip1 ,string &s){
    while (ip.good())
    {
        getline(ip,s);
        int cnt = 0, check = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cnt++;
            if (s[i] == ' ')
            {
                check++;
            }
            if (check == 3)
            {
                break;
            }
        }
        ip1 << s.substr(0,cnt);
        cnt = s.length(), check = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                check++;
            }
            if (check == 3)
            {
                ip1 << s.substr(i+1,cnt) << endl;
                break;
            }
        }
    }
}
//cau b
int countNA(string s){
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i + 1] == 'a' && s[i] == ' '|| s[i + 1] == 'o' && s[i] == ' '|| s[i + 1] == 'u' && s[i] == ' '|| s[i + 1] == 'i' && s[i] == ' '|| s[i + 1] == 'e' && s[i] == ' ')
        {
            cnt++;
        }
    }
    return cnt;
}
//cau d
int countspace(string s){
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[0] != ' ')
        {
            cnt++;
        }
    }
    return cnt;   
}

void bubbleSort(string arr[], int n)
{
    int i,j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (countspace(arr[j]) > countspace(arr[j+1])){
                swap(arr[j], arr[j+1]);
                haveSwap = true;
            }
        }
        if(haveSwap == false){
            break;
        }
    }
}
//cau e
void test(ofstream &ip1,string &s){
    int cnt = 0;
    int arr[12] = {0};
    for (int i = 0; i < s.length() + 1; i++)
    {
        if (s[i] != ' ')
        {
            cnt++;
        }
        else{
            arr[cnt - 1]++;
            cnt = 0;
        }
        
    }
    for (int i = 0; i < 12; i++)
    {
        cout << "So la xuan hien phan tu co " << i + 1 << " ky tu la: " << arr[i] << endl;
        
    }
    cout << endl;
}
//cau f
string mahoa (string s, int n){
    string kq = "";
    for (int i = 0; i < s.length(); i++)
    {
        kq += char(int(s[i] + n - 97)%26 +97);
    }
        return kq;
}

int main(){
    ifstream ip("THI.INP");
    ofstream ip1("THI.OUT");
    string s;
    int cnt = 0;
    //cau a
    while (ip.eof() == false){
        getline(ip,s);
        int cnt = countNA(s);
        ip1 << cnt << " ";
    }
    ip1 << endl;
    ip.close();
    //cau b;
    ifstream ip2("THI.INP");
    readfile(ip2,ip1,s);
    ip2.close();
    //cau c
    ifstream ip3("THI.INP");
    while (ip3.eof() == false)
    {
        getline(ip3,s);
        int max = 0;
        int cnt = countNA(s);
        if (max < cnt)
        {
            max = cnt;
            ip1 << s << endl << "So luong nguyen am la: " << cnt << endl;
        }
    }
    ip3.close();
    //cau d
    ifstream ip4("THI.INP");
    string a[10000];
    int i = 0;
    while (ip4.good())
    {
        getline(ip4,s);
        a[i] = s;
        i++;
    }
    bubbleSort(a,i);
    for (int j = 0; j < i; j++)
    {
        ip1 << a[j] << endl;
    }
    ip4.close();

    //cau e
    ifstream ip5("THI.INP");
    string t = "";
    int c = 0;
    while (!ip5.eof())
    {
        getline(ip5,s);
        t = t + s + ' ';
    } 
    test(ip1,t);
    ip5.close();

    //cau f
    ifstream ip6("THI.INP");
    while (ip6.good())
    {
        getline(ip6,s);
        ip1 << mahoa(s,3) << endl;
    }
    ip6.close();
    ip1.close();
    return 0;
}