#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> hap;
int main(void) {
	int n, num1, num2, T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		int cnt = 0;
		vector<int> fail(n, 0);
		hap.clear();
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &num1, &num2);
			hap.push_back(make_pair(num1, num2));
		}
		sort(hap.begin(), hap.end());
		for (int i = n-1; i >=0; i--) {
			for (int j = i; j >= 0; j--) {
				if (hap[i].second > hap[j].second) {
					cnt++;
					break;
				}
			}
		}
		int res = n - cnt;
		cout << res << endl;
	}
	return 0;
}