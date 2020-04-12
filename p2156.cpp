#include <iostream>
#include <vector>
using namespace std;
vector<int> cup;
int dp[10003] = { 0, };
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n,num;
	int res = 0;
	cin >> n;
	for (int i = 0; i < 3; i++)
		cup.push_back(0);
	for (int i = 3; i < n+3; i++) {
		cin >> num;
		cup.push_back(num);
	}
	for (int i = 3; i < n+3; i++) {
		dp[i] = max(dp[i - 3] + cup[i - 1] + cup[i], dp[i - 2] + cup[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
}