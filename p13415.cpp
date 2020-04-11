#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	vector<int> vec;
	vector<int> one;
	vector<int> two;
	int N,a,s;
	int start, end;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		vec.push_back(a);
	}
	scanf("%d %d %d", &s, &start, &end);
	for (int i = 0; i < s; i++) {
		for (int i = 0; i < start; i++) {
			one.push_back(vec[i]);
		}
		sort(one.begin(), one.end());
		for (int i = start; i < N; i++) {
			one.push_back(vec[i]);
		}
		for (int i = 0; i < end; i++) {
			two.push_back(one[i]);
		}
		sort(two.begin(), two.end(), greater<int>());
		for (int i = end; i < N; i++) {
			two.push_back(one[i]);
		}
		for (int i = 0; i < N; i++) {
			vec[i] = two[i];
		}
		one.clear();
		two.clear();
	}
	for (int i = 0; i < N; i++)
		printf("%d ", vec[i]);
	return 0;
}