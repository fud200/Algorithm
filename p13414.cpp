#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


int main(void) {
	set<string> s;
	vector<string> vec;
	vector<string> succeed;
	int K, L;
	int cnt = 0;
	string str;
	scanf("%d%d", &K, &L);
	for (int i = 0; i < L; i++) {
		cin >> str;
		vec.push_back(str);
	}
	for (int j = L - 1; j >= 0; j--) {
		str = vec[j];
		if (s.find(str) == s.end()) { // 값이 set에 없다면
			s.insert(str);
			succeed.push_back(str);
			cnt++;
		}
	}
	for (int i = cnt - 1; i > cnt - 1 - K && i >= 0; --i)
		cout << succeed[i] << "\n";
	return 0;
}