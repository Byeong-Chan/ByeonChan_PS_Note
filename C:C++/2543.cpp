#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

#define MOD 20070713;

typedef long long ll;
typedef pair<int, ll> ci;
ll table[100001];
set<ci> s;
struct bung {
	int x;
	int y;
}o[100001];
struct seo {
	int p;
	int num;
	bool sub;
}f[200001];

bool fsort(bung a, bung b) {
	return a.y < b.y;
}
bool ksort(seo a, seo b) {
	return a.p < b.p;
}

int main() {
	int i, n;
	int t = 0;
	ll sav;
	ci tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &o[i].x, &o[i].y);
		f[i].p = o[i].x;
		f[i + n].p = o[i].y;
		f[i].num = i;
		f[i + n].num = i;
		f[i].sub = false;
		f[i + n].sub = true;
	}
	sort(f, f + (n << 1), ksort);
	for (i = 0; i < (n << 1); i++) {
		t++;
		(f[i].sub ? o[f[i].num].y : o[f[i].num].x) = t;
	}
	sort(o, o + n, fsort);
	tmp = make_pair(0, 1);
	s.insert(tmp);
	tmp = make_pair(o[0].y, 2);
	s.insert(tmp);
	table[0] = 2;
	set<ci>::iterator it;
	for (i = 1; i < n; i++) {
		// 1일때
		sav = table[i - 1];

		// 0일때
		it = --s.upper_bound(make_pair(o[i].x, 0));
		tmp = *it;
		sav += tmp.second;

		sav %= MOD;

		table[i] = sav;
		s.insert(make_pair(o[i].y, sav));
	}
	printf("%lld", table[n - 1]);
	return 0;
}