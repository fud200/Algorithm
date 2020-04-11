#include <iostream>
using namespace std;

int max(int a, int b) {
	return a < b ? b : a;
}
int main(void) {
	int n, T;
	char c1[100001], c2[100001];
	cin >> T;
	for (int i = 0; i < T; i++) {
		int changed = 0;
		int w = 0 , b = 0;
		cin >> n>>c1>>c2;

		for (int i = 0; i < n; i++) {
			if (c1[i] != c2[i]) {
				if (c1[i] == 'W')
					w++;
				else
					b++;
			}
		}
		cout <<max(w,b) << endl;
	}
	return 0;
}