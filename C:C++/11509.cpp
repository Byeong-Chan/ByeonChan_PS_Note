#include <cstdio>
int o[1000001];
int chk[1000001];
int main() {
	int i, n;
	int tmp;
	int ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &o[i]);
	}
	for (i = 0; i < n; i++) {
		tmp = o[i];
		if (chk[tmp + 1]) {
			chk[tmp + 1]--;
			chk[tmp]++;
		}
		else {
			chk[tmp]++;
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}