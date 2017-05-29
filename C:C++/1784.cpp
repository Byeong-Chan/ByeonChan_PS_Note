#include <stdio.h>
#include <string.h>
struct bung {
	int cnt;
	char p;
}u[10001];
int main() {
	char o[10001];
	int i;
	int n;
	int e = 1;
	scanf("%s", o);
	n = strlen(o);
	u[0].p = o[0];
	u[0].cnt = 1;
	for (i = 1; i < n; i++) {
		if (u[e - 1].p == o[i]) u[e - 1].cnt++;
		else {
			u[e].p = o[i];
			u[e].cnt = 1;
			e++;
		}
	}
	if (e == 1) {
		printf("1");
		return 0;
	}
	for (i = 1; i < e-1; i++) if (u[i].cnt >= 2) break;
	printf("%d", i + 1);
	return 0;
}