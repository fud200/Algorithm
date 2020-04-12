#include <iostream>
using namespace std;

int han(int a) {
	int cnt = 0;
	int hun,ten,one;
	if (a < 100)
		return a;
	else {
		for (int i = 100; i <= a; i++) {
			hun = i / 100;
			ten = (i % 100) / 10;
			one = i % 10;
			if ((hun - ten) == (ten - one))
				cnt++;
		}
		return 99 + cnt;
	}
}
int main(void) {
	int n;
	cin >> n;
	int res = han(n);
	cout << res << endl;
	return 0;
}