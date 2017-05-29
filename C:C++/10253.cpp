#include <stdio.h>
typedef long long ll;
ll sub(ll x, ll y) {
	if(x % y == 0) return y;
	else return sub(y, x%y);
}
int main() {
	int t;
	ll n, m;
	ll d;
	ll k;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld",&n,&m);
		while(1) {
			d = sub(m,n);
			m /= d;
			n /= d;
			if(n == 1) {
				printf("%lld\n",m);
				break;
			}

			k = m/n+1;

			n = n*k - m;
			m = m*k;
		}
	}
	return 0;
}