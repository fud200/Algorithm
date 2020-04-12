#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	vector<int> vec;
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, vec[i] * (n - i));
	}
	cout << ans << endl;
	return 0;
}