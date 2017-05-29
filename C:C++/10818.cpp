#include <stdio.h>
int main() {
	int i;
	int n;
	int max1 = -0x7fffffff;
	int min1 = -max1;
	int x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (max1 < x) max1 = x;
		if (min1 > x) min1 = x;
	}
	printf("%d %d", min1, max1);
	return 0;
}