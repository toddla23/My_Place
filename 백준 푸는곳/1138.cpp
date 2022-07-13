#include <iostream>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  int arr[n];
  int answer[n];

  for(int i = 0; i < n; i++)
    cin >> arr[i];

	for(int i = 0; i < n; i++)
		answer[i] = 0;

  for(int i = 0; i < n; i++)
  {
    int cnt = 0;
		for(int j = 0; j < n; j++)
		{
			if(cnt == arr[i] && answer[j] == 0)
			{
				answer[j] = i+1;
				break;
			}
			
			if(answer[j] == 0)
				cnt++;
		}


  }
		for(int i = 0; i < n; i++)
			cout << answer[i] << " ";
		cout << endl;

}