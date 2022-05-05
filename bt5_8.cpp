#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cau_a(string s);
void cau_b(string &s);
void cau_c(string s);
int cau_d(string s);
void cau_e(string s);
int cau_f(string s);
string cau_g1(string s);
string cau_g2(string s);
void cau_h(string s);
void cau_i(string s);
void cau_j(string s);
string cau_k(string s);
string cau_l(string s);
void cau_m(string s);
void cau_n(string s);
string cau_o (string s, int k);
void cau_p(string &s);
void cau_q(string &s);
void cau_r(string s);
void bt5_8a();
void bt5_8b();
void bt5_8c();
void bt5_8d();
void bt5_8e();
void bt5_8f();
void bt5_8g();
void bt5_8h();
void bt5_8i();
void bt5_8j();
void bt5_8k();
void bt5_8l();
void bt5_8m();
void bt5_8n();
void bt5_8o();
void bt5_8p();
void bt5_8q();
void bt5_8r();

int main(){
    bt5_8a();
    bt5_8b();
    bt5_8c();
    bt5_8d();
    bt5_8e();
    bt5_8f();
    bt5_8g();
    bt5_8h();
    bt5_8i();
    bt5_8j();
    bt5_8k();
    bt5_8l();
    bt5_8m();
    bt5_8n();
    bt5_8o();
    bt5_8p();
    bt5_8q();
    bt5_8r();
    return 0;
}

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
    cout << "So luong nguyen am la: " << cnt << endl << "So luong phu am la: " << cnt2 << endl << endl;
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

void cau_e(string s){
    string tmp = "abcdefghijklmpnoqrstuvxywz";
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (s[i] == tmp[j])
            {
                arr[j]++;
            }
        }
    }
    for (int a = 0; a < 26; a++)
    {
        if (arr[a] != 0)
        {
            cout << "So lan xuat hien cua " << tmp[a] << ": " << arr[a] << endl;
        }  
    }
}

int cau_f(string s){
    string tmp;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt++;
    }
    return cnt;
    
}

string cau_g1(string s){
    int i = 0;
    while (s[i] != ' ')
    {
        ++i;
    }
    string tmp = s.substr(0,i);
    return tmp;
}

string cau_g2(string s){
    int i = s.length() - 1;
    int len = s.length() - 1;
    while (s[i] != ' ')
    {
        --i;
    }
    string tmp = s.substr(i,len);
    return tmp;
}

void cau_h(string s){
    int cnt, max, start, end, i2, sum;
    cnt = max = start = end = i2 = sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum++;
        if (s[i] != ' ')
        {
            cnt++;
        }
        if (s[i] == ' ')
        {
            i2 = i - 1 - cnt;
            if (max < cnt)
            {
                max = cnt;
                start = (i2 + 1);
                end = max;
            }
            cnt = 0;
        }
    }
    string tmp = s.substr(start, end);
    cout << "Tu trong file dai nhat la: " << tmp << " va co " << max << " ky tu" << endl;
    cout << endl;
}

void cau_i(string s){
    int cnt = 0;
    int arr[12] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            cnt++;
        }
        else
        {
            arr[cnt - 1]++;
            cnt = 0;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        cout << "So la xuan hien phan tu co " << i + 1 << " ky tu la: " << arr[i] << endl;
    }
}

void cau_j(string s){
    int start = 0;
    int j = 0;
    string arr[100] = {};
    string t = s;
    string tmp;
    t += ' ';
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != ' ')
        {
            start++;
        }
        if (t[i] == ' ')
        {
            arr[j] = t.substr((i - start), (start));
            j++;
            start = 0;
        }
    }
    for (int i = 0; i < j; i++)
    {
        for (int a = i + 1; a < j; a++)
        {
            if (arr[i] > arr[a])
            {
                swap(arr[i], arr[a]);
            }
            
        }
    }
    for (int i = 0; i < j; i++)
    {
        tmp += arr[i] + ' ';
    }
    cout << tmp;   
    
    
}

string cau_k(string s){
    int cnt, start, end;
    cnt = start = end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            cnt++;
        }
        if (cnt == 1)
        {
            start = i + 1;
            cnt++;
        }
        if (cnt == 5)
        {
            end = i - 1;
            cnt++;
        }
    }
    string tmp = s.erase(start, (end - start + 2));
    return tmp;
    
}

string cau_l(string s){
    int i = 0;
    while (s[i] != ' ')
    {
        i++;
    }
    string tmp = "sai gon university";
    string s1 = s.insert((i + 1), (tmp + ' '));
    return s1;
}

void cau_m(string s){
    string t = "";
    int cnt = 0;
    for (int i = s.length(); i >= 0; i--)
    {
        t += s[i];
    }
    int len = t.length();
    for (int i = 0; i <= (t.length()); i++)
    {
        if (t[i] != ' ' && i != len)
        {
            cnt++;
        }
        
        if (t[i] == ' ' || i == len)
        {
            for (int j = (i-1); j >= (i - cnt); j--)
            {
                cout << t[j];
            }
            cout << " ";
            cnt = 0;
        }
    }
    
    
}

void cau_n(string s){
    int cnt = 0;
    int t = s.length();

    for (int i = 0; i <= (s.length()); i++)
    {
        if (s[i] != ' ' && i != t)
        {
            cnt++;
        }
        
        if (s[i] == ' ' || i == t)
        {
            for (int j = (i-1); j >= (i - cnt); j--)
            {
                cout << s[j];
            }
            cout << " ";
            cnt = 0;
        }
    }
}

string cau_o (string s, int k){
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

void cau_p(string &s){
    string tmp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s.erase(i,1);
        }
        
    }
}

void cau_q(string &s){
    string tmp1, tmp2, maxString;
    int max = 0, start = 0, start1 = 0;;
    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
        if (s[i] == ' ')
        {
            tmp1 = s.substr(start, (i - start));
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == ' ')
                {
                    tmp2 = s.substr((start1), (j - start1));
                    if (tmp1 == tmp2)
                    {
                        cnt++;
                    }
                    
                    start1 = j + 1;
                }
            }
            start = i + 1;
            if (max < cnt)
            {
                max = cnt;
                maxString = tmp1;
            }
        }
        
    }
    cout << "Tu xuat hien nhieu nhat trong chuoi la: " << "(" << maxString << ")" << " xuat hien: " << max << " lan" << endl;
}

void cau_r(string s){
    string tmp = "abcdefghijklmpnoqrstuvxywz";
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (s[i] == tmp[j])
            {
                arr[j]++;
            }
        }
    }
    for (int a = 0; a < 26; a++)
    {
        if (arr[a] != 0)
        {
            cout << tmp[a] << " ";
        }  
    }
}


// Main Function

void bt5_8a(){
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
}

void bt5_8b(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    cout << "Chuoi sau khi chuyen cac chu dau thanh viet hoa: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        cau_b(s);
        cout << s << endl;
    }
    cout << endl;
    ip.close();

}

void bt5_8c(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    cout << "So ky tu cua moi tu trong chuoi: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        cau_c(s);
        cout << endl;
    }
    cout << endl;
    ip.close();
}

void bt5_8d(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    while (!ip.eof())
    {
        getline(ip, s);
        int x = cau_d(s);
        cout << "So tu cua moi chuoi la: " << x << endl;
    }
    cout << endl;
}

void bt5_8e(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    while (!ip.eof())
    {
        getline(ip, s);
        tmp += s + ' ';
    }
    cau_e(tmp);
    cout << endl;
}

void bt5_8f(){
    fstream ip;
    ip.open("STR.INP");
    string s, sTmp;
    int max, tmp, len;
    max = tmp = len = 0;
    while (!ip.eof())
    {
        getline(ip, s);
        int tmp = cau_f(s);
        if (max < tmp)
        {
            max = tmp;
            sTmp = s;
        }
    }
    cout << "Chuoi dai nhat la: " << endl;
    cout << sTmp << endl;
    len = sTmp.length();
    cout << "Do dai cua chuoi dai nhat la: " << len << endl;
}

void bt5_8g(){
    fstream ip;
    ip.open("STR.INP");
    string s, s1, s2, s3;
    while (!ip.eof())
    {
        s1 = "", s2 = "", s3 = "";
        getline(ip, s);
        s1 = cau_g1(s);
        s2 = cau_g2(s);
        s3 = s1 + s2;
        cout << "Chuoi con sau khi tao thanh la: " << endl;
        cout << s3 << endl;
    }
    
    cout << endl;
}

void bt5_8h(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    while (!ip.eof())
    {
        getline(ip, s);
        tmp += s + ' ';
    }
    cau_h(tmp);
}

void bt5_8i(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    while (!ip.eof())
    {
        getline(ip, s);
        tmp += s + ' ';
    }
    cau_i(tmp);
    cout << endl;
}

void bt5_8j(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    cout << "Chuoi sau khi sap xep cac chuoi con la: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        cau_j(s);
        cout << endl;
    }
    cout << endl;
}

void bt5_8k(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    cout << "Chuoi sau khi xoa ki tu 2 3 4 la: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        tmp = cau_k(s);
        cout << tmp << endl;
    }
    cout << endl;
}

void bt5_8l(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    cout << "Chuoi sau khi chen (sai gon university) " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        s = cau_l(s);
        cout << s << endl;
    }
    cout << endl;
}

void bt5_8m(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    cout << "Chuoi sau khi dao nguoc tu la: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        cau_m(s);
        cout << endl;
    }
    cout << endl;
}

void bt5_8n(){
    fstream ip;
    ip.open("STR.INP");
    string s;
    cout << "Chuoi sau khi dao nguoc ky tu la: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        cau_n(s);
        cout << endl;
    }
    cout << endl;
}    

void bt5_8o(){
    fstream ip;
    ip.open("STR.INP");
    string s, t;
    cout << "Chuoi da ma hoa voi khoa k = 5: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        t = cau_o(s, 5);
        cout << t << endl;
    }
    cout << endl;
}

void bt5_8p(){
    fstream ip;
    ip.open("STR.INP");
    string s, t;
    cout << "Chuoi sau khi da xoa khoang trang: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        t = s;
        cau_p(t);
        cout << t << endl;
    }
}

void bt5_8q(){
    fstream ip;
    ip.open("STR.INP");
    string s, t;
    cout << "Tu dai nhat trong File la: " << endl;
    while (!ip.eof())
    {
        getline(ip, s);
        t += s + ' ';
    }
    cau_q(t);
    cout << endl;
}

void bt5_8r(){
    fstream ip;
    ip.open("STR.INP");
    string s, tmp;
    while (!ip.eof())
    {
        getline(ip, s);
        tmp += s + ' ';
    }
    cout << "Cac ky tu xuat hien trong chuoi la: " << endl;
    cau_r(tmp);
    cout << endl;
}
