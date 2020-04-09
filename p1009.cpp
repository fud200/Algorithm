# include <iostream>
# include <cstdio>
using namespace std;

int check(int a, int b) {
	int mod[10] = {0, };
	mod[0] = 1;
	int cnt=0;
	int res=0;
	mod[1] = a%10;
	for (int i = 2; i < 10; i++) {
		if (mod[i-1] * a % 10 == mod[1]) {
			cnt = i - 1;
			break;
		}
		else if (mod[i - 1] * a % 10 == 0) {
			mod[i] = 0;
			break;
		}
		else {
			mod[i] = mod[i-1] * a % 10;
		}
	}
	if (mod[cnt] == 0 && b >= cnt)
		return 10;
	if (b != 0 && b % cnt == 0)
		res = mod[cnt];
	else
		res = mod[b % cnt];
	return res;
}
int main(void) {
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		if (b == 0)
			cout << 1 << endl;
		else {
			cout << check(a, b)<<endl;
		}
	}
	return 0;


}