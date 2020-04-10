#include <iostream>
#include <vector>
using namespace std;

int cmax(int a, int b) {
	return a < b ? b : a;
}
int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n);
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dp[0] = num[0];
	int max = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = cmax(dp[i - 1] + num[i], num[i]);
		max = cmax(max, dp[i]);
	}
	cout << max << endl;
	return 0;
}

