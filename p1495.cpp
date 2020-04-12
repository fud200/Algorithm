#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int dp[101][1001];
int volume[101];
int main(void) {
	int n, s, m;
	int res = -1;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> volume[i];
	}
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j - volume[i] >= 0)
					dp[i][j - volume[i]] = 1;
				if (j + volume[i] <= m)
					dp[i][j + volume[i]] = 1;
			}
		}
	}
	for (int i = 0; i <= m; i++)
		if (dp[n][i])
			res = i;
	cout << res << endl;

	return 0;

}