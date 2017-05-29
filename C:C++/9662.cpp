#include <cstdio>
#include <algorithm>
using namespace std;
bool table[10100];
int p[10100]; 
int chk[10100];
int tmp[10100];
int sa[10100];
int lcp[10100];
int R[10100];
int gap;
int n;
bool cmp(int a, int b) {
	if (chk[a] != chk[b]) return chk[a] < chk[b];
	a += gap;
	b += gap;
	return (a<n && b<n) ? chk[a] < chk[b] : a > b;
}
void makeSA() {
	int i;
	for (i = 0; i<n; i++) chk[i] = p[i], sa[i] = i;
	for (gap = 1;; gap <<= 1) {
		sort(sa, sa + n, cmp);
		tmp[0] = 0;
		for (i = 0; i<n - 1; i++) tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		if (tmp[n - 1] == n - 1) break;
		for (i = 0; i<n; i++) chk[sa[i]] = tmp[i];
	}
}
void makeLCP() {
	int i, j, k = 0;
	for (i = 0; i<n; i++) R[sa[i]] = i;
	for (i = 0; i<n; lcp[R[i++]] = k) {
		for (k ? k-- : 0, j = (R[i] ? sa[R[i] - 1] : n); i + k<n&&j + k<n&&p[i + k] == p[j + k]; k++);
	}
}
int main() {
	int i, j;
	int N, m;
	int o[24];
	int pre;
	int sz = 0;
	int pat = 0;

	int st;
	int sem;
	int rem;
	int ans = 0;
	n = 0;
	scanf("%d %d", &N, &m);
	table[0] = 1;
	for (i = 0; i < m; i++) scanf("%d", &o[i]);
	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < m; j++) if (i - o[j] >= 0 && table[i - o[j]]) break;
		if (j == m) table[i] = true;
	}
	pre = 0;
	for (i = 1; i <= 10000; i++) {
		if (table[i]) {
			p[n++] = i - pre;
			pre = i;
		}
	}
	makeSA();
	makeLCP();
	int sup;
	for (i = 1; i < n; i++) {
		sup = lcp[i] - lcp[i - 1];
		if (sa[i] < 100) continue;
		if (sz < sup) {
			sz = sup;
			st = sa[i];
		}
		if (sz == sup) if (sa[i] < st) st = sa[i];
	}

	for (i = 0; i < st; i++) {
		N -= p[i];
		if (N >= 0) ans++;
		else break;
	}
	if (N < 0) N = 0;

	for (i = st; i < st + sz; i++) pat += p[i];

	sem = N / pat;
	rem = N % pat;
	ans += sem * sz;

	for (i = st; i < st + sz; i++) {
		rem -= p[i];
		if (rem >= 0) ans++;
		else break;
	}
	printf("%d", ans);
	return 0;
}