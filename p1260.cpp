#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
vector<int> dfsv;
vector<int> bfsv;
int visit[1001];
queue<int> que;
void init(int a) {
	for (int i = 1; i <= a; i++)
		visit[i] = 0;
}
void dfs(int a) {
	visit[a] = 1;
	sort(graph[a].begin(), graph[a].end());
	dfsv.push_back(a);
	for (int i = 0; i < graph[a].size(); i++) {
		if(visit[graph[a][i]]==0)
			dfs(graph[a][i]);
	}
}
void bfs(int a) {
	que.push(a);
	int cur;
	while (!que.empty()) {
		cur = que.front();
		bfsv.push_back(cur);
		que.pop();
		visit[cur] = 1;
		sort(graph[a].begin(), graph[a].end());
		for (int i = 0; i < graph[cur].size(); i++) {
			if (visit[graph[cur][i]] == 0) {
				que.push(graph[cur][i]);
				visit[graph[cur][i]] = 1;
			}
		}
	}
}
int main(void) {
	int N, M, V;
	int a, b;
	cin >> N >> M >> V;
	init(N);
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(V);
	for (int i = 0; i < dfsv.size(); i++)
		cout << dfsv[i] << " ";
	cout << endl;
	init(N);
	bfs(V);
	for (int i = 0; i < bfsv.size(); i++)
		cout << bfsv[i] << " ";
	return 0;

}