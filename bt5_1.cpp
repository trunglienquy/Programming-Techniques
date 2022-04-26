#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

float findA(){
    ifstream inpf;
    inpf.open("bt5-1c.inp.txt");
    float tmp, a;
    int min = 1001, idx = 0;
    float arr[1001];
    while (!inpf.eof()){
        inpf >> tmp;
        arr[idx] = tmp;
        idx++;
    }
    for (int i=0;i<idx;i++){
        int d1 = 0, d2 = 0;
        for (int j=0;j<idx;j++){
            float a1 = arr[i];
            float a2 = arr[j];
            if (arr[i] < arr[j]) d1++;
            if (arr[i] > arr[j]) d2++;
        }
        if (min > abs(d1-d2)){
            min = abs(d1-d2);
            a = arr[i];
        } 
    }
    return a;
}

void bt51c(){
    fstream inpf;
    int i = 0;
    float sum = 0;
    inpf.open("bt5-1c.inp.txt");
    while (!inpf.eof()){
        float val;
        inpf >> val;
        sum+=val;
        i++;
    }
    cout << "Sum: " << sum << endl;
    cout << "AVG: " << sum/i << endl;
    cout << "A: " << findA();
}

int main(){
    //cau a;                                                                                                                
    char n;
    int cnt = 0;
    ifstream ip("file1.txt");
    ofstream ip2("file2.txt");
    while (ip>>n)
    {
        string t = to_string(int (n));
        for (int i = 0; i < t.length(); i++)
        {
            cout << t[i];
            cnt++;
            if (cnt == 81)
            {
                ip2 << endl << t[i];
                cnt = 1;
            }
            else{
                ip2 << t[i];
            }
        }
        ip2 << " ";
        
    }
    ip.close();
    ip2.close();
    cout << endl;

    //cau b
    string str;
    ifstream ip3("file3.txt");
    ofstream ip4("file4.txt");
    while (ip3.good())
    {
        bool check = false;
        getline(ip3,str);
        string tmp = "VIET NAM";
        int len = tmp.length();
        for (int i = 0; i < str.length(); i++)
        {
            if (str.substr(i,len).compare(tmp) == 0)
            {
                check = true;
                break;
            }
        }
        if (check == true)
            {
                ip4 << str << endl;
            }
    }
    
    //cau c
    bt51c();
    ip3.close();
    ip4.close();

    return 0;
}
