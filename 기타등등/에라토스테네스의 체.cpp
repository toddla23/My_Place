#include <iostream>
#include <vector>

using namespace std;

#define prime_size 100

int list[prime_size];
vector<int> prime;

int main(void)
{
  for(int i = 2; i*i < prime_size; i ++)
  {
    if(list[i] == 0)
    {
      prime.push_back(i);
      int n = 2; 
      while(i*n < prime_size)
      {
        list[i*n] = 1;
        n++;
      }
    }
  }

  for(int i = 0; i < prime.size(); i++)
    cout << prime[i] << " ";

}