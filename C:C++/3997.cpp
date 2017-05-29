#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
char o[300010];
map<long long, int> cnt;
long long ans = 0;
long long chk[55];
int trans(char c) {
	if (c <= 'Z') return c - 65;
	else return c - 71;
}
int main() {
	int i, n;
	long long max1;
	long long j, t, tmp;
	scanf("%d", &n);
	scanf("%s", o);
	for (i = 0; i < n; i++) chk[trans(o[i])] = 1;
	for (i = 1; i < 52; i++) {
		if (chk[i]) {
			if (chk[i - 1] == 0) chk[i] = 1;
			else chk[i] = chk[i - 1] << 1;
			max1 = chk[i];
		}
		else chk[i] = chk[i - 1];
	}
	cnt[0] = 1;
	t = 0;
	for (i = 0; i < n; i++) {
		t ^= chk[trans(o[i])];
		if (cnt.find(t) != cnt.end()) ans += cnt[t];

		tmp = t;
		for (j = 1; j <= max1; j <<= 1) {
			tmp ^= j;
			if (cnt.find(tmp) != cnt.end()) ans += cnt[tmp];
			tmp ^= j;
		}
		cnt[t]++;
	}
	printf("%lld", ans);
	return 0;
}