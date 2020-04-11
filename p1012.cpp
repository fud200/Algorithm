#include <iostream>
using namespace std;
int bachu[51][51];
int visit[51][51];
int moven[4] = { 1,-1,0,0 };
void init() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++) {
			visit[i][j] = 0;
			bachu[i][j] = 0;
		}
}
void dfs(int x,int y) {
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = moven[i];
		my = moven[3 - i];
		if (bachu[x + mx][y + my] == 1 && visit[x + mx][y + my] == 0) {
			visit[x + mx][y + my] = 1;
			dfs(x + mx, y + my);
		}
	}
	}
int main(void) {
	int M, N, K,T;
	int x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		init();
		int cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			if (x >= 0 && x < M && y >= 0 && y < N)
			bachu[x][y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (bachu[i][j] == 1 && visit[i][j] == 0) {
					visit[i][j] = 1;
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}