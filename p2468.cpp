#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int height[101][101];
int visit[101][101];
int moven[4] = { 1,-1,0,0 };
int min(int a, int b) {
	return a > b ? b : a;
}
int max(int a, int b) {
	return a < b ? b : a;
}
void dfs(int a, int b, int h) {
	visit[a][b] = h;
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = moven[i];
		my = moven[3 - i];
		if (height[a + mx][b + my] > h && visit[a + mx][b + my] < h)
			dfs(a + mx, b + my, h);
	}
}
int main(void) {
	int n, num;
	int highest = 0;
	int lowest = 987654231;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			height[i][j] = num;
			visit[i][j] = 0;
			highest = max(highest, num);
			lowest = min(lowest, num);
		}
	}
		int res = 1;
		for (int h = lowest; h < highest; h++) {
			cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (height[i][j] > h && visit[i][j] < h) {
						dfs(i, j, h);
						cnt++;
					}
				}
			}
			res = max(res, cnt);
		}
		cout << res << endl;
		return 0;
	}