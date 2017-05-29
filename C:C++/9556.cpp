#include <cstdio>

#define MOD 1000000007

long long sq(long long x, long long n, long long pi) {
	if (n == 1) return x % pi;
	else {
		long long tmp = sq(x, n >> 1, pi);
		tmp *= tmp;
		tmp %= pi;
		if(n & 1) tmp *= x;
		tmp %= pi;
		return tmp;
	}
}
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}
long long sub(int a, int nx, int k, char *o, long long *inv, long long num, long long *del) {
	int i;
	long long tmp = 0;
	if (a == 0) {
		tmp = ((num*inv[k]) % MOD) - ((del[k] * inv[k]) % MOD);
		tmp %= MOD;
		if (tmp < 0) tmp += MOD;
		return tmp;
	}
	for (i = nx; i < 6; i++) if (o[i] == '0') tmp += sub(a - 1, i + 1, k*(i + 1) / gcd(k, i + 1), o, inv, num, del);
	tmp %= MOD;
	return tmp;
}
int main() {
	int i;
	int t;
	int k = 1;
	long long n;
	long long num, ans;
	long long inv[723];
	long long del[723];
	char o[8];
	inv[1] = MOD + 1;
	del[1] = 0;
	for (i = 2; i <= 60;i++) inv[i] = sq(i, MOD - 2, MOD);
	scanf("%d", &t);
	while (t--) {
		k = 1;
		scanf("%lld %s", &n, o);
		for (i = 2; i <= 60; i++) {
			del[i] = sq(10, n, i);
			del[i]--;
			if (del[i] < 0) del[i] += i;
		}
		num = sq(10, n, MOD);
		num--;
		if (num < 0) num += MOD;
		for (i = 0; i < 6; i++) if (o[i] == '1') k = k * (i+1) / gcd(k, (i+1));
		ans = ((num * inv[k]) % MOD) - ((del[k] * inv[k]) % MOD);
		for (i = 0; i < 6; i++) if (o[i] == '0') break;
		if (i == 6) ans++;

		for (i = 1; i <= 6; i++) {
			ans -= ((i&1) ? 1 : -1) * sub(i, 0, k, o, inv, num, del);
			ans %= MOD;
			if (ans < 0) ans += MOD;
		}
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}