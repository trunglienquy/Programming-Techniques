#include <iostream>
#include <fstream>
using namespace std;

bool checkPrimaryNumber(int n){
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < (n - 1); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main(){
    fstream ip1;
    ofstream ip2("bangso.out");
    ip1.open("bangso.inp");
    int m, n;
    ip1 >> m; 
    ip1 >> n;
    int arr[m][n];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ip1 >> arr[i][j];
        }
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    // }
    cout << endl;

    //cau a
    ip2 << "Cau a: ";
    int max;
    int tmp1, tmp2;
    for (int i = 1; i <= m; i++)
    {
        max = 0;
        for (int j = 1; j <= n; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
                tmp1 = i;
                tmp2 = j;
            }
        }
        cout << "(" << tmp1 << ", " << tmp2 << ")";
    }

    //cau b
    cout << endl;
    int max2 = 0;
    int tmp3, tmp4, sum, tmpArr;
    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            sum = 0;
            tmpArr = arr[i][j];
            while (tmpArr != 0)
            {
                sum += tmpArr % 10;
                tmpArr /= 10;
            }
            if (max2 < sum)
            {
                max2 = sum;
                tmp3 = i;
                tmp4 = j;
            }
        }
    }
    cout << "(" << tmp3 << ", " << tmp4 << ")";
    
    //cau c
    cout << endl;
    int maxLine, minRow, line, row, test;
    bool check = true;
    maxLine = minRow = line = row = test = 0;
    for (int i = 1; i <= m; i++)
    {
        check = true;
        maxLine = minRow = 0;
        if (check == true)
        {
            for (int j = 1; j <= n; j++)

            {
                if (maxLine < arr[i][j])
                {
                    maxLine = minRow = arr[i][j];
                    row = j;
                    line = i;
                }
            }
            for (int tmp = 1; tmp <= m; tmp++)
            {
                test = arr[tmp][row];
                if (minRow > test)
                {
                    check = false;
                    break;
                }
            }
            if (check == true)
            {
                cout << "(" << line << ", " << row << ")";
                break;
            }
        }     
    }
    if (line >= m)
    {
        line = row = 0;
        cout << "(" << line << ", " << row << ")";
    }
    
    //cau d
    cout << endl;
    int x, maxPriNumTmp, maxPriNum;
    x = maxPriNum = maxPriNumTmp = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            x = arr[i][j];
            if (checkPrimaryNumber(x))
            {
                maxPriNumTmp = x;
            }
            if (maxPriNum < maxPriNumTmp)
            {
                maxPriNum = maxPriNumTmp;
            }
        }
    }
     for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (maxPriNum == arr[i][j])
            {
                cout << "(" << i << ", " << j << ")";
            }
            
        }
    }
    
    //cau e
    cout << endl;
    int sumLine, sumRow, sumArr, test2, maxTmp, ArrTmp;
    sumLine = sumRow = sumArr = test2 = maxTmp = ArrTmp = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sumLine = sumRow = sumArr = 0;
            for (int l = 1; l <= n; l++)
            {
                sumLine += arr[i][l];
            }
            for (int r = 1; r <= m; r++)
            {
                sumRow += arr[r][j];
            }
            sumArr = sumLine + sumRow;
            if (maxTmp < sumArr)
            {
                maxTmp = sumArr;
                ArrTmp = arr[i][j];
            }
        } 
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ArrTmp == arr[i][j])
            {
                cout << "(" << i << ", " << j << ")";
            }
            
        }
    }
    

    //cau f
    cout << endl;
    int caufdong = 0 , caufcot = 0 , kiemtra = 0;
    // int n;
    for ( int i=1 ; i<=m ; i++ ) 
    {
        for ( int j=1 ; j<=n ; j++ )
        {
            if (arr[i][j-1]%2 == 0 )//huojg trai
                if (arr[i-1][j-1]%2 == 0 )// huojg cheo trej trai 
                    if (arr[i-1][j]%2 == 0 )// huojg trej
                        if (arr[i-1][j+1]%2 == 0 )//cheo trej pahi
                            if (arr[i][j+1]%2 == 0 )// huojg phai
                                if (arr[i+1][j+1]%2 == 0 )// huojg cheo duoi phjai
                                    if (arr[i+1][j]%2 == 0 )// huojg duoi
                                        if (arr[i+1][j-1]%2 == 0 )// huong cheo duoi trai
                                        {
                                            caufdong = m;
                                            caufcot = n;
                                            kiemtra = 1;
                                        }
        }
    }
    if ( kiemtra==1 )
    {
        cout << "(" << caufdong << ";" << caufcot << ")";
    }
    else{

        cout << "(0;0)"; 
    }
    ip1.close();
    return 0;
}