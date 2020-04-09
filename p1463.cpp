#include <iostream>
#include <cstdio>
using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	int n, i;
	int dp[1000001] = { 0 };
	dp[1] = 0;
	cin >> n;
	for (i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}