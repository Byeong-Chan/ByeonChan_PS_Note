#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int x;
	int y;
	int num;
}o[200010];
long long h[200010], p[2020];
long long ans[200010];
bool cmp(bung a, bung b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
int main() {
	int n;
	int i;
	long long k, all = 0;
	bung tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &o[i].x, &o[i].y);
		o[i].num = i;
	}
	sort(o, o + n, cmp);
	k = 0;
	for (i = 0; i < n; i++) {
		tmp = o[i];
		ans[tmp.num] = all - h[tmp.x] - p[tmp.y] + k;
		if (tmp.x == o[i + 1].x && tmp.y == o[i + 1].y) k += o[i].y;
		else k = 0;
		h[tmp.x] += tmp.y;
		p[tmp.y] += tmp.y;
		all += o[i].y;
	}
	for (i = 0; i < n; i++) printf("%lld\n", ans[i]);
	return 0;
}