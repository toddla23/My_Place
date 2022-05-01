#include<iostream>

using namespace std;

void solve(int n,int a,int b){
    int cnt=0,now=0;
	int top = 0, bottom = n-1, left = 0, right = n-1;
	int X = 0, Y = 0;

	if(n == 1)
	{
		cout << 1;
	}
	else
	{
	while(cnt <= b)
	{
		while(Y == top && X != right)
		{
			if(cnt > b)
				break;
			X++;
			cnt++;
			if(cnt + 1 >= a && cnt + 1 <= b)
			{
				cout << Y * n + X + 1 << "\n ";
				cout <<cnt<< " \n";
			}
		}
		top++;

		while(X == right && Y != bottom)
		{
			if(cnt > b)
				break;
			Y++;
			cnt++;
			if(cnt + 1 >= a && cnt + 1 <= b)
			{
				cout << Y * n + X + 1 << " \n";
				cout <<cnt<< " \n";
			}
		}
		right--;

		while(Y == bottom && X != left)
		{
			if(cnt > b)
				break;
			X--;
			cnt++;
			if(cnt + 1 >= a && cnt + 1 <= b)
			{
				cout << Y * n + X + 1 << " \n";
				cout <<cnt<< " \n";
			}		}
		bottom--;

		while(X == left && Y != top)
		{
			if(cnt > b)
				break;
			Y--;
			cnt++;
			if(cnt + 1 >= a && cnt + 1 <= b)
			{
				cout << Y * n + X + 1 << " \n";
				cout <<cnt<< " \n";
			}

		}
		left++;
	}
	}
}

int main(){
    int T,N,A,B;

    cin>>T;

    for (int i = 0; i < T; i++){
        cin>>N>>A>>B;
        solve(N,A,B);
        cout<<endl;
    }
}