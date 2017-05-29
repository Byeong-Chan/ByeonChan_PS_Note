#include <cstdio>
int o[10010];
struct bung {
	int x;
	int y;
	int z;
}town[10010];
int _abs(int a) {
	if (a < 0) return -a;
	return a;
}
int main() {
	int i, j, n;
	int ans = 1000000009;
	int tmp;
	int tmp2;
	int tmp3;
	int tmp4;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &town[i].x, &town[i].y, &town[i].z);
		o[i] = o[i] = o[i] = 1000000009;
	}
	for (i = 0; i < n; i++) {
		tmp2 = o[i];
		tmp3 = 1000000009;
		for (j = i + 1; j < n; j++) {
			tmp4 = o[j];

			tmp = _abs(town[i].x - town[j].x) + _abs(town[i].y - town[j].y) + _abs(town[i].z - town[j].z);

			if (tmp2 + tmp < ans) ans = tmp2 + tmp;
			if (tmp3 + tmp < ans) ans = tmp3 + tmp;
			if (tmp4 + tmp < ans) ans = tmp4 + tmp;

			if (tmp < o[j]) o[j] = tmp;
			if (tmp3 > tmp) tmp3 = tmp;
		}
	}
	printf("%d", ans);
	return 0;
}