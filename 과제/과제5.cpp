#include <iostream>
#include <time.h>
using namespace std;

void temp(int n, int a, int b) {
	if (n == 1)
		cout << '1' << endl;
	else {
		clock_t start, end;
		double result;

		int na = n;
		int i = 0;
		int j = 0;
		int mini = 0;
		int maxi = n - 1;
		int minj = 0;
		int maxj = n - 1;
		int where = 0;



		while (na * 4 - 4 < a) {
			i++;
			j++;
			mini++;
			minj++;
			maxi--;
			maxj--;
			a = a - (na * 4 - 4);
			b = b - (na * 4 - 4);
			na -= 2;
		}

		for (int q = 1; q < b + 1; q++) {
			if (q >= a && q <= b) {
				printf("%d ", n * j + i + 1);

			}

			if (where == 0) {
				if (i < maxi) {
					i++;
					if (i == maxi) {
						minj++;
						where = 1;
					}
				}
			}
			else if (where == 1) {
				if (j < maxj) {
					j++;
					if (j == maxj) {
						maxi--;
						where = 2;
					}
				}
			}
			else if (where == 2) {
				if (i > mini) {
					i--;
					if (i == mini) {
						maxj--;
						where = 3;
					}
				}
			}
			else if (where == 3) {
				if (j > minj) {
					j--;
					if (j == minj) {
						mini++;
						where = 0;
					}
				}
			}





		}

		cout << '\n';
	}

}

int main()
{
	int k, n, b, c;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> b >> c;
		temp(n, b, c);
	}

}
w