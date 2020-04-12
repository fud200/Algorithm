#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int sum = 0;
	int dec;
	int x1, x2;
	vector<int> dwarf(9);
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum = sum + dwarf[i];
	}
	sum = sum - 100;
	for (int i = 0; i < 8; i++) {
		dec = sum - dwarf[i];
		if (dec > 0) {
			for (int j = i + 1; j < 9; j++) {
				if (dwarf[j] == dec) {
					x1 = i;
					x2 = j;
					break;
				}
			}
		}
	}
	dwarf[x1] = 0;
	dwarf[x2] = 0;
	sort(dwarf.begin(), dwarf.end());
	for (int i = 2; i < 9; i++)
		cout << dwarf[i] << endl;
	return 0;
}