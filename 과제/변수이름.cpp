#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;


    for(int i = 0; i < t; i++)
    {
        string sentence;
	    cin >> sentence;

        int n = 1;
        if(sentence.at(0) >= 48 && sentence.at(0) <= 57)
        {
            n = 0;
        }
        else
        {
            for(int j = 0; j < sentence.size(); j++)
            {
                if((sentence.at(j) < 48) || (sentence.at(j) > 57 && sentence.at(j) < 65) || (sentence.at(j) > 91 && sentence.at(j) < 95) || (sentence.at(j) > 95 && sentence.at(j) < 97) || (sentence.at(j) > 122 && sentence.at(j) < 127))
                {
                    n = 0;
                    break;
                }
            }
        }
        cout << n << endl;
    }
}