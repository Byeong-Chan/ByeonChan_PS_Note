#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef long long ll;
pr rep(ll n) {
	ll k;
	ll d;
	ll e = 0;
	ll a2 = 0, a5 = 0;
	ll s;
	e = 0;
	for(k=1;k<n;k<<=1) e++;
	d = n;
	s = 0;
	for(;k>=2;k>>=1) {
		a2 += d/k * e - s;
		s += d/k;
		e--;
	}
	e = 0;
	for(k=1;k<n;k*=5) e++;
	d = n;
	s = 0;
	for(;k>=5;k/=5) {
		a5 += d/k * e - s;
		s += d/k;
		e--;
	}
	return make_pair(a2, a5);
}
int main() {
	ll n, m;
	ll p, q;
	ll a2 = 0, a5 = 0, b2 = 0, b5 = 0;
	pr tmp;
	scanf("%lld %lld",&n,&m);
	p = m;
	q = n-m;
	tmp = rep(n);
	a2 += tmp.first;
	a5 += tmp.second;
	tmp = rep(p);
	b2 += tmp.first;
	b5 += tmp.second;
	tmp = rep(q);
	b2 += tmp.first;
	b5 += tmp.second;

	a2 -= b2;
	a5 -= b5;
	printf("%lld",(a2 < a5 ? a2 : a5));
	return 0;
}