#include <stdio.h>
#include <algorithm>
using namespace std;

#define rep(b) ((b)*(b))

typedef long long ll;
ll a, b, c;
ll sigx[1000003], x[1000003], dt[1000003];
pair<ll, int> L[1000003];
bool calc(ll k1, ll k2, ll c1, ll c2, int n) {
	if (c1 - c2 <= (k2 - k1) * x[n]) return true;
	return false;
}
bool calc2(ll k1, ll k2, ll k3, ll c1, ll c2, ll c3) {
	if ((c3 - c1) * (k2 - k3) <= (c3 - c2) * (k1 - k3)) return true;
	return false;
}
int main() {
	int i, n;
	int head = 0, tail = 0;
	long long e = 0;
	scanf("%d", &n);
	scanf("%lld %lld %lld", &a, &b, &c);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		e += a*x[i] * x[i] + b*x[i] + c;
	}
	L[tail++] = make_pair(0, 0);
	for (i = 1; i <= n; i++) {
		sigx[i] += x[i] * x[i];
		sigx[i] += sigx[i - 1];
		x[i] += x[i - 1];
		while (tail > head + 1) {
			if (calc((-2 * a)*x[L[head].second], (-2 * a)*x[L[head + 1].second], L[head].first, L[head + 1].first, i)) head++;
			else break;
		}
		dt[i] = ((-2 * a) * x[L[head].second] * x[i]) + L[head].first + (a*rep(x[i]) - a*sigx[i]) - (c * (i - 1));
		L[tail++] = make_pair(dt[i] + (a*rep(x[i]) + a*sigx[i]) + c * i, i);
		while (tail > head + 2) {
			if (calc2((-2 * a)*x[L[tail - 1].second], (-2 * a)*x[L[tail - 2].second], (-2 * a)*x[L[tail - 3].second], L[tail - 1].first, L[tail - 2].first, L[tail - 3].first)) {
				tail--;
				L[tail - 1] = L[tail];
			}
			else break;
		}
	}
	printf("%lld", e + dt[n]);
	return 0;
}