#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int i;
	int n = 10;
	int x, y;
	int o[22];
	for (i = 0; i<20; i++) o[i] = i + 1;
	for (i = 0; i<n; i++) {
		scanf("%d %d", &x, &y);
		reverse(o + x - 1, o + y);
	}
	for (i = 0; i<20; i++) printf("%d ", o[i]);
	return 0;
}