#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define _abs(x) ((x) < 0 ? -(x) : (x))
typedef pair<long long, long long> pr;

long long o[38];
long long u[38];
long long e = 0;
long long t = 0, f = 0;
long long s = 0;
long long l = 0;
long long min1;
long long ans = 0;
bool chk[39] = { false, };
int n;
map<long long, pr> chk2[2][40];
pr p[2][40][50000];
int psize[2][40];
bool can;
void sub(int a, long long k, int b, bool sw) {
	if (sw) {
		pr tmp;
		pr h;
		h = chk2[can][b][s];
		if (h.first == 0) {
			tmp = make_pair(s, l);
			p[can][b][psize[can][b]++] = tmp;
			tmp = make_pair(l, psize[can][b]-1);
			chk2[can][b][s] = tmp;
		}
		else if (can && h.first < l) {
			tmp = make_pair(s, l);
			p[can][b][h.second] = tmp;
			tmp = make_pair(l, h.second);
			chk2[can][b][s] = tmp;
		}
		else if (!can && h.first > l) {
			tmp = make_pair(s, l);
			p[can][b][h.second] = tmp;
			tmp = make_pair(l, h.second);
			chk2[can][b][s] = tmp;
		}
	}
	if (can && a == n) return;
	if (!can && a == n / 2) return;

	l += k;
	s += o[a];
	sub(a + 1, k >> 1, b + 1, true);
	l -= k;
	s -= o[a];

	sub(a + 1, k >> 1, b, false);
}
bool fsort(pr a, pr b) {
	return a.first < b.first;
}
int main() {
	int i, j;
	long long c = 1;
	long long q, w;
	scanf("%d", &n);
	for (i = 0; i<n; i++) scanf("%lld", &o[i]);
	for (i = 0; i<n; i++) {
		scanf("%lld", &u[i]);
		e += u[i];
		o[i] += u[i];
		if (i < n / 2) {
			ans += c;
			c <<= 1;
			t += o[i];
		}
	}
	ans <<= (n / 2);
	f = ans;
	min1 = _abs(e - t);

	can = false;
	c <<= (n / 2);
	sub(0, c >> 1, 0, 0);

	can = true;
	sub(n / 2, c >> (n / 2 + 1), 0, 0);

	long long tmp1, tmp3;
	long long tmp2, tmp4;
	pr sav;
	int st, ed, mid;
	int fr, ba;
	long long cmp;
	for (i = 1; i <= n / 2; i++) {
		sort(p[1][i], p[1][i] + psize[1][i], fsort);
		for (j = 0; j<psize[0][i]; j++) {
			tmp1 = p[0][i][j].first;
			tmp2 = p[0][i][j].second;
			q = t - tmp1;
			w = f - tmp2;

			if (q < e) {
				cmp = e - q;
				st = 1;
				ed = psize[1][i];
				while (st < ed) {
					mid = (st + ed) >> 1;
					if (p[1][i][mid - 1].first >= cmp) ed = mid;
					else st = mid + 1;
				}

				mid = ed;
				if (mid > 0) mid--;

				tmp3 = p[1][i][mid].first;
				tmp4 = p[1][i][mid].second;
				if (_abs(q + tmp3 - e) < min1) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
				if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
				for (fr = mid - 1; fr >= (mid - 7 > 0 ? mid - 7 : 0); fr--) {
					tmp3 = p[1][i][fr].first;
					tmp4 = p[1][i][fr].second;
					if (_abs(q + tmp3 - e) < min1) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
					if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
				}
				for (ba = mid + 1; ba < (mid + 7 < psize[1][i] ? mid + 7 : psize[1][i]); ba++) {
					tmp3 = p[1][i][ba].first;
					tmp4 = p[1][i][ba].second;
					if (_abs(q + tmp3 - e) < min1) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
					if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
				}

				cmp = e - q;
				st = 1;
				ed = psize[1][i];
				while (st < ed) {
					mid = (st + ed) >> 1;
					if (p[1][i][mid - 1].first > cmp) ed = mid;
					else st = mid + 1;
				}

				mid = ed;
				if (mid > 0) mid--;

				tmp3 = p[1][i][mid].first;
				tmp4 = p[1][i][mid].second;
				if (_abs(q + tmp3 - e) < min1) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
				if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
				for (fr = mid - 1; fr >= (mid - 7 > 0 ? mid - 7 : 0); fr--) {
					tmp3 = p[1][i][fr].first;
					tmp4 = p[1][i][fr].second;
					if (_abs(q + tmp3 - e) < min1) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
					if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
				}
				for (ba = mid + 1; ba < (mid + 7 < psize[1][i] ? mid + 7 : psize[1][i]); ba++) {
					tmp3 = p[1][i][ba].first;
					tmp4 = p[1][i][ba].second;
					if (_abs(q + tmp3 - e) < min1) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
					if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
						min1 = _abs(q + tmp3 - e);
						ans = w + tmp4;
					}
				}
			}
			else {
				sav = p[1][i][0];

				tmp3 = sav.first;
				tmp4 = sav.second;
				if (_abs(q + tmp3 - e) < min1) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
				if (_abs(q + tmp3 - e) == min1 && ans < w + tmp4) {
					min1 = _abs(q + tmp3 - e);
					ans = w + tmp4;
				}
			}
		}
	}

	c >>= 1;
	for (i = 0; ans>0; ans >>= 1, i++) {
		chk[i] = ans & 1;
	}
	for (i = n-1; i>=0; i--) {
		if (chk[i]) printf("1 ");
		else printf("2 ");
	}
	return 0;
}