#include <iostream>
#include <cstring>

using namespace std;

#define MAXDIGIT 100
string longDivision(char *number, int divisor)
{
    char ans[100];
    int ansidx=0;
 
    int n = 0;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    while (strlen(number) > idx) {
        ans[ansidx]= (temp / divisor) + '0';
        ansidx++;
        ans[ansidx]='\0';

        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (n != 0)
        return "0";
    
    string str(ans);
    
    return str;
}

int main(void)
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        char str[100];
        cin >> str;

        int a = 0, b = 0;

        for(int j = 0; j < 100; j++)
        {
            cout << longDivision(str, 11) <<endl;
        }

    }
}