#include <iostream>
#include <string>

using namespace std;
int answer = 0;
string s;

bool isPalindrom(string str)
{
    int cnt = str.size()/2;
    for(int i=0; i<cnt; i++){
        if(str[i]!=str[str.size()-1-i]){
            return false;
        }
    }
 
    return true;
}
 
int main()
{
    cin>>s;
 
    answer = s.size()*2-1;
    for(int i=0; i<s.size(); i++){
        string temp = s.substr(i, s.size()-i);
        if(isPalindrom(temp)){
            answer = s.size()+i;
            break;
        }
    }
 
    cout<<answer<<"\n";
    return 0;
}

