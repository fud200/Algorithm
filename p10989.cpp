#include <iostream>
#include <vector>
using namespace std;
int cmax(int a, int b) {
	return a < b ? b : a;
}
int numc[10001] = { 0, };
int main(void) {
	int max = 0;
	int n,num;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		numc[num] = numc[num] + 1;
		max = cmax(max, num);
	}
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < numc[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}