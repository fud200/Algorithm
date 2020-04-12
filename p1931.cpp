#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int cnt = 0;
	vector<pair<int, int>> vec;
	int N;
	cin >> N;
	int finish, start;
	for (int i = 0; i < N; i++) {
		cin >> start >> finish;
		vec.push_back(make_pair(finish, start));
	}
	sort(vec.begin(), vec.end());
	pair<int, int> cur;
	int rear = 0;
	int front = 0;
	for (int i = 0; i < N; i++) {
		cur = vec[i];
		if (cur.second >= rear) {
			rear = cur.first;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}