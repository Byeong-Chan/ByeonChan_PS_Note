#include <cstdio>
#include <algorithm>
using namespace std;
char o[200010];
int chk[200010];
int tmp[200010];
int sa[200010];
int R[200010];
int lcp[200010];
int gap;
int n;
bool cmp(int a, int b) {
	if (chk[a] != chk[b]) return chk[a] < chk[b];

	a += gap;
	b += gap;
	return a < n && b < n ? chk[a] < chk[b] : a > b;
}
void make_SA() {
	int i;
	for (i = 0; i < n; i++) {
		chk[i] = o[i] - 'a';
		sa[i] = i;
	}
	for (gap = 1;; gap <<= 1) {
		sort(sa, sa + n, cmp);
		tmp[0] = 1;
		for (i = 1; i < n; i++) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
		if (tmp[n - 1] == n) break;
		for (i = 0; i < n; i++) chk[sa[i]] = tmp[i];
	}
}
void make_lcp() {
	int i, j, k = 0;
	for (i = 0; i < n; i++) R[sa[i]] = i;
	for (i = 0; i < n; lcp[R[i++]] = k) {
		for (k ? k-- : k, j = R[i] ? sa[R[i] - 1] : n; j + k < n && i + k < n && o[j + k] == o[i + k]; k++);
	}
}
int main() {
	int ans = 0;
	scanf("%d", &n);
	scanf("%s", o);
	make_SA();
	make_lcp();
	for (int i = 0; i < n; i++) if (lcp[i] > ans) ans = lcp[i];
	printf("%d", ans);
	return 0;
}