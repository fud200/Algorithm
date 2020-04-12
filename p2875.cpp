#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int N,M, K;
	int res=0;
	cin >> N >> M >> K;
	for (int i = 0; i <= K; i++) {
		res = max(res, min((N - i) / 2, (M - K + i)));
	}
	cout << res << endl;
}