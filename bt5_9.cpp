#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool cau_a(string &s){
    bool check = false;
    int cnt = 0;
    string t = "que huong";
    int len = t.length();
    for (int i = 0; i < s.length() + 1; i++)
    {
        if (s.substr(i,len).compare(t) == 0)
        {
            check = true;
            break;
        }
    }
    return check;
}

void cau_b(string s){
    int cnt = 0;
    int arr[12] = {0};
    s[s.length()] += ' ';
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
    cout << arr[4] << " ";
    s[s.length()] -= ' ';
}

void cau_c(string s){
    int cnt = 0;
    s[s.length()] = s[s.length()] + ' ' + 'z';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            if (s[i] == 'a'|| s[i] == 'o'|| s[i] == 'u'|| s[i] == 'i'|| s[i] == 'e')
            {
                cnt++;
            }
        }
        else{
            cout << cnt << " ";
            cnt = 0;
        }
    }
    s[s.length()] = s[s.length()] - ' ' - 'z';
}


int cau_d(string s){
    int cnt = 0;
    if (s[0] != ' ')
    {
        cnt++;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            cnt++;
        }
    }
    return cnt;
}

int countlongString(string s){
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt++;
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
            if (countlongString(arr[j]) > countlongString(arr[j+1])){
                swap(arr[j], arr[j+1]);
                haveSwap = true;
            }
        }
        if(haveSwap == false){
            break;
        }
    }
}

string mahoa (string s, int k){
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            tmp += char(int(s[i] + k - 97)%26 + 97);
        }
        if (s[i] == ' ')
        {
            tmp += ' ';
        }
    }
    return tmp;
}


int main(){
    //init file
    fstream ip;
    fstream ip_out;
    ip.open("THI.INP");
    ip_out.open("THI.OUT", ios_base::out);

    //cau a
    string s;
    int cnt = 0;
    bool check;
    while (!ip.eof())
    {
        getline(ip,s);
        check = cau_a(s);
        if (check == true)
        {
            cnt++;
        }
    }
    cout << "Cau a: " << cnt << endl;
    ip.close();

    //cau b
    ifstream ip1;
    ip1.open("THI.INP");
    string s1;
    cout << "Cau b: ";
    while (!ip1.eof())
    {
        getline(ip1,s1);
        cau_b(s1);
    }
    cout << endl;
    ip1.close();

    //cau c
    ifstream ip2;
    ip2.open("THI.INP");
    string s2;
    int count = 1;
    cout << "Cau c:" << endl;
    while (!ip2.eof())
    {
        getline(ip2, s2);
        cout << "So luong nguyen am dong thu: " << count << ": "; cau_c(s2);
        count++;
        cout << endl;
    }
    ip2.close();

    //cau d
    ifstream ip3;
    ip3.open("THI.INP");
    string s3;
    string ss3;
    int tmp, max;
    tmp = max = 0;
    while (!ip3.eof())
    {
        getline(ip3, s3);
        tmp = cau_d(s3);
        if (max < tmp)
        {
            max = tmp;
            ss3 = s3;
        }
    }
    cout << "Cau d: " << endl;
    cout << "Chuoi co so tu nhieu nhat: " << endl;
    cout << ss3 << endl <<"So luong cua tu dai nhat: " << max << endl;
    ip3.close();

    //cau e
    fstream ip4;
    ip4.open("THI.INP");
    string s4;
    string arr[9999];
    int i = 0;
    while (!ip4.eof())
    {
        getline(ip4, s4);
        arr[i] = s4;
        i++;
    }
    bubbleSort(arr,i);
    cout << "Cau e: ";
    cout << endl;
    for (int j = 0; j < i; j++)
    {
        cout << arr[j] << " " << endl;
    }
    ip4.close();

    cout << endl;
    fstream ip5;
    ip5.open("THI.INP");
    string s5;
    while (ip5.good())
    {
        getline(ip5,s5);
        cout << s5 << endl;
        cout << mahoa(s5,3) << endl;
    }
    
    ip5.close();
    ip_out.close();
    return 0;
}