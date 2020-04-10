#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int INF = 987654321;
vector<pair<int, int>> graph[20001];
typedef pair<int, int> Pair;
vector<int> checkDistance(int start, vector<int> dist) {
	priority_queue<Pair,vector<Pair>,greater<Pair>> que;
	que.push(make_pair(0, start));
	int cur,distance;
	while (!que.empty()) {
		cur = que.top().second;
		distance = que.top().first;
		que.pop();
		if (dist[cur] < distance)
			continue;
		for (int i = 0; i < graph[cur].size();i++) {
			int nvertex = graph[cur][i].first;
			int distanceTo = graph[cur][i].second + distance;
			if (dist[nvertex] > distanceTo) {
				dist[nvertex] = distanceTo;
				que.push(make_pair(distanceTo, nvertex));
			}
		}
		
	}
	return dist;
}


int main(void){
	int V, E, K;
	scanf_s("%d %d %d",&V, &E, &K);
	int a, b, c;
	V = V + 1;
	for (int i = 0; i < E; i++) {
		scanf_s("%d %d %d", &a, &b, &c);;
		graph[a].push_back(make_pair(b, c)); // a에서 b까지 가는데 비용 c인 엣지가 있다.
	}
	vector<int> distance(V, INF);
	distance[K] = 0;
	vector<int> result=checkDistance(K, distance);
	for (int i = 1; i < V; i++) {
		if (result[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", result[i]);
	}
	return 0;
}