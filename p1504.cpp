#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> oneto(801);
vector < pair<int, int>> graph[801];
int min(int a, int b) {
	return a < b ? a : b;
}
vector<int> check(int start, int end) {
	vector<int> cost(end, 987654321);
	cost[start] = 0;
	int neighbor,distanceton;
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
	int N,E,A,B,W;
	int res;
	cin >> N>>E;
	N=N+1;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> W;
		graph[A].push_back({ B,W });
		graph[B].push_back({ A,W });
	}
	cin >> A >> B;
	vector<int> OnetoN = check(1, N);
	vector<int> AtoN = check(A, N);
	vector<int> BtoN = check(B, N);
	res = min(OnetoN[A] + AtoN[B] + BtoN[N-1], OnetoN[B] + BtoN[A] + AtoN[N-1]);
	if (res >= 987654321 || res < 0)
		res = -1;
	cout << res << endl;
	return 0;
	
}