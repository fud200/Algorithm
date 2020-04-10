#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> time(8001,0);
	int cnt = 0;
	int sum = 0;
	int max=0;
	int pre;
	int num;
	int times = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec[i] = num;
		time[num+4000]++;
		if (max < time[num+4000]) 
			max = time[num+4000];
		sum = sum + num;
		cnt++;
	}
	for (int i = 0; i < 8001; i++) {
		if (time[i] == max) {
			pre = i - 4000;
			times++;
			if (times == 2) {
				break;
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << round(sum / (double)cnt) << endl;
	cout << vec[cnt / 2] << endl;
	cout << pre<< endl;
	cout <<vec[N - 1]-vec[0] << endl;
	return 0;
}