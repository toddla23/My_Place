#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  int arr[n][2];
  for(int i = 0; i < n; i++)
    cin >> arr[i][0] >> arr[i][1];

  double max = 0;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < n; k++)
      {
        double S = fabs((arr[i][0] * arr[j][1] + arr[j][0] * arr[k][1] + arr[k][0] * arr[i][1]) - 
        (arr[j][0] * arr[i][1] + arr[k][0] * arr[j][1] + arr[i][0] * arr[k][1])) / 2;

        if(max < S)
          max = S;
      }
    }
  }
  cout << fixed;
  cout.precision(1);
  cout << max;
}