#include <iostream>

using namespace std;

int arr[21];
int answer = 0;
int N,S;

void check(int cur, int sum)
{
  if(cur == N)
  {
    if(sum == S)
      answer++;

    return;
  }

  check(cur+1, sum);
  check(cur+1, sum + arr[cur]);
}

int main(void)
{
  cin >> N >> S;

  for(int i = 0; i < N; i++)
    cin >> arr[i];

  if(S == 0)
    answer--;

  check(0,0);

  cout << answer;


}