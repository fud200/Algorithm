#include <iostream>
using namespace std;
bool bbutton[10];
int absolute(int a) {
	if (a <= 0)
		return a * (-1);
	else
		return a;
}
int min(int a, int b) {
	return a > b ? b : a;
}
int nlength(int a) {
	int res = 0;
	if (a == 0)
		return 1;
	for (a; a > 0; a = a / 10)
		res++;
	return res;
}
bool isPossible(int a, int length, bool* bbutton) {
	for (int i = 0; i < length; i++) {
		if (bbutton[a % 10] == true)
			return false;
		a = a / 10;
	}
	return true;
}
int main(void) {
	int N, M;
	int k,res;
	cin >> N >> M;
	int direct = absolute(N - 100);
	int more;
	if (M == 0) {
		res = min(direct, nlength(N));
		cout << res << endl;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> k;
		bbutton[k] = true;
	}
	if (M == 10) {
		cout << direct << endl;
		return 0;
	}
	if (N == 100)
		res = 0;
	else if (isPossible(N, nlength(N), bbutton) == true)
		res = min(direct, nlength(N));
	else {
		for (int i = 1;; i++) {
			if (isPossible(N - i, nlength(N - i), bbutton) == true&&N-i>=0) {
				more = nlength(N - i) + i;
				break;
			}
			else if (isPossible(N + i, nlength(N + i), bbutton) == true) {
				more = nlength(N + i) + i;
				break;
			}
		}
		res = min(direct, more);
	}
	cout << res << endl;
	return 0;

}