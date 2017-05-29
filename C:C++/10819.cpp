#include <stdio.h>

#define _abs(x) ((x) < 0 ? -(x) : (x))

int o[11];
int u[11];
int n;
int e = 0;
int max1 = -0x7fffffff;
bool chk[11];
void sub(int a) {
	if (a == n) {
		if (max1 < e) max1 = e;
		return;
	}
	int i;
	for (i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			u[a] = o[i];
			if (a >= 1) e += _abs(u[a] - u[a - 1]);
			sub(a + 1);
			if (a >= 1) e -= _abs(u[a] - u[a - 1]);
			u[a] = 0;
			chk[i] = false;
		}
	}
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &o[i]);
	sub(0);
	printf("%d", max1);
	return 0;
}