#include <iostream>
#include <vector>

#define prime_size 100000

using namespace std;
int list[prime_size];
vector<int> prime;

void make_prime_list(void)
{
  for(int i = 2; i < prime_size; i ++)
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
}

int underprime(int n)
{
    int X = 2, num = 0;
      int i = 0;
      while(n != 1)
      {
      if(n % prime[i] != 0)
      {
        i++;
        continue;
      }
      else
      {
        n = n / prime[i];
        num++;
      }
      }
    

    for(int i = 0; i < prime.size(); i++)
    {
      if(num == prime[i])
        return 1;
      else if(num < prime[i])
        return 0;
    }
}


int main(void)
{
    make_prime_list();
    int a, b, answer = 0;

    cin >> a >> b;

    for(int i = a; i <= b; i++)
        answer += underprime(i);

    cout <<answer;

    return 0;
}