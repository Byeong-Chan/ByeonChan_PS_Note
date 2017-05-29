#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct bung {
	int x;
	int y;
}o[300010];
int uclid(int a, int b) {
	if (a%b == 0) return b;
	else return uclid(b, a%b);
}
int p[300010];
bool fsort(bung a, bung b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
long long comb2(long long d) {
	return (d * (d - 1)) >> 1;
}
int main() {
	int i, j;
	int n;
	int m;
	long long k;
	long long ans;
	long long hap;
	int tmp;
	int x, y, z;
	int x0 = 0, y0 = 0;
	scanf("%d", &n);
	k = comb2(n);
	m = n;
	for (i = 0; i<n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0) x0++;
		if (y == 0) y0++;
		if (x < 0) {
			x *= -1;
			y *= -1;
		}

		if (x != 0 && y != 0) {
			if (y < 0) tmp = uclid(x, -y);
			else tmp = uclid(x, y);
			x /= tmp;
			y /= tmp;
		}
		o[i].x = x;
		o[i].y = y;
	}
	if (x0 > 1) m -= x0;
	if (y0 > 1) m -= y0;
	k -= comb2(x0);
	k -= comb2(y0);

	sort(o, o + n, fsort);
	for (i = 0; i<n; i++) {
		if (o[i].x == 0) {
			p[i] = x0;
			continue;
		}
		if (o[i].y == 0) {
			p[i] = y0;
			continue;
		}
		for (j = i + 1; j<n; j++) {
			if (o[j].x != 0 && o[j].y != 0 && o[i].x == o[j].x && o[i].y == o[j].y) continue;
			break;
		}
		m -= (j - i);
		k -= comb2(j - i);
		for (x = i; x<j; x++) p[x] = (j - i);
		i = j - 1;
	}
	ans = 0;
	tmp = 0;
	for (i = 0; i<n; i++) {
		hap = k - (long long)(n - p[i]) * p[i];
		ans += hap / 3;
		tmp += hap % 3;
		ans %= MOD;
	}
	ans += (tmp / 3);
	ans %= MOD;
	printf("%lld", ans);
	return 0;
}