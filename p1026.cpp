#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int n,res;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	res = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < n; i++) {
		res = res + A[i]*B[n - i - 1];
	}
	cout << res << endl;
	return 0;
}