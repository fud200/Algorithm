#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int tomato[1001][1001];
int visit[1001][1001];
int moven[4] = { 1,-1,0,0 };
queue<pair<int, int>> ripen;
int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int M, N;
	cin >> M>>N;
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			visit[i][j] = -1;
			if (tomato[i][j] == 1) {
				ripen.push(make_pair(i, j));
				visit[i][j] =0;
			}
		}
	}
	while (!ripen.empty()) {
		pair<int, int> numset = ripen.front();
		ripen.pop();
		for (int i = 0; i < 4; i++) {
			int mx = numset.first + moven[i];
			int my = numset.second + moven[3 - i];
				if (tomato[mx][my] == 0 && visit[mx][my] == -1) {
					visit[mx][my] = visit[numset.first][numset.second] + 1;
					res = max(res, visit[mx][my]);
					ripen.push(make_pair(mx, my));
				}

			}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0 && visit[i][j] == -1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << res << endl;
	return 0;
}