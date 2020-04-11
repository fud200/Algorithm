#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	string s;
	string cur;
	cin >> s;
	int sizes = s.size();
	for (int i = 0; i < n - 1; i++) {
		cin >> cur;
		for (int j = 0; j < sizes; j++) {
			if (s[j] != cur[j])
				s[j] = '?';
		}
	}
	cout << s << endl;
	return 0;
}