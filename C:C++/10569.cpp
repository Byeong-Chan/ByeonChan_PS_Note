#include <stdio.h>
int main() {
	int v, e;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &e);
		printf("%d\n", e - v + 2);
	}
	return 0;
}