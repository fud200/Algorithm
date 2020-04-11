#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}
vector<int> check(int start, int end,vector<int> oneto,vector<pair<int,int>> *graph) {
	vector<int> cost(end, 987654321);
	cost[start] = 0;
	int neighbor, distanceton;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myque;
	myque.push({ 0,start });
	while (!myque.empty()) {
		int dist = myque.top().first;
		int cur = myque.top().second;
		myque.pop();
		if (cost[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			neighbor = graph[cur][i].first;
			distanceton = dist + graph[cur][i].second;
			if (cost[neighbor] > distanceton) {
				cost[neighbor] = distanceton;
				oneto[neighbor] = cur;
				myque.push({ distanceton,neighbor });

			}
		}
	}
	return cost;


}
int main(void) {
	int T;
	cin >> T;
	for (int i=0; i < T; i++) {
		vector<int> oneto(2001);
		int n, m, t, a, b, d;
		cin >> n >> m >> t;
		vector<pair<int, int>> graph[50001];
		vector<int> goal(t);
		vector<int> realgoal(t,2001);
		n = n + 1;
		int s, g, h;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			graph[a].push_back({ b,d });
			graph[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++) {
			cin >> goal[i];
		}
		vector<int> distfromS = check(s, n,oneto,graph);
		vector<int> distfromG = check(g, n, oneto, graph);
		vector<int> distfromH = check(h, n, oneto, graph);
		int road = distfromG[h];
		int z;
		int cnt = 0;
		for (int i = 0; i < t; i++) {
			z = goal[i];
			if (distfromS[z] == distfromS[g] + road + distfromH[z] || distfromS[z] == distfromS[h] + road + distfromG[z]) {
				realgoal[cnt] = z;
				cnt++;
			}
		}
		sort(realgoal.begin(), realgoal.end());
		for (int i = 0; i < cnt; i++) {
			cout << realgoal[i] << " ";
		};
		cout << endl;
	}
	return 0;
}