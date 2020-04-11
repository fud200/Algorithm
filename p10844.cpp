#include <iostream>

using namespace std;

int main(void) {
	int dp[101][10] = { };
	int N;
	int res = 0;
	cin >> N;
	if (N == 1) {
		cout << 9 << endl;
		return 0;
	}
	else if (N == 2) {
		cout << 17 << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int j = 2; j < N + 1; j++) {
		for (int k = 0; k < 10; k++) {
			if (k == 9)
				dp[j][9] = dp[j - 1][8] % 1000000000;
			else if(k==0)
				dp[j][0] = dp[j - 1][1] % 1000000000;
			else
				dp[j][k]=(dp[j-1][k-1]+dp[j-1][k+1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++) {
		res = (res + dp[N][i]) % 1000000000;
	}
	cout << res% 1000000000 << endl;
}
	