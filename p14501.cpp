#include <iostream>
#include <vector>
using namespace std;
int price[17];
vector<pair<int,int>> work;
int max(int a, int b) {
	return a < b ? b : a;
}
int main(void) {
	int n,a,b;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		work.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++) {
		if (i + work[i].first < n + 1) {
			price[i + work[i].first] = max(price[i + work[i].first], price[i] + work[i].second);
			res = max(res, price[i + work[i].first]);
		}
		price[i + 1] = max(price[i + 1], price[i]);
		res = max(res, price[i + 1]);
	}
	cout << res << endl;
	return 0;
}