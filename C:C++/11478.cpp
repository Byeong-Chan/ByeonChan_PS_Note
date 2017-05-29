#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int chk[1000100];
int tmp[1000100];
int gap;
int n;
int SA[1000100];
int lcp[1000100];
int R[1000100];
char s[1000100];
bool cmp(int a, int b) {
	if (chk[a] != chk[b]) return chk[a] < chk[b];

	a += gap;
	b += gap;
	return a < n && b < n ? chk[a] < chk[b] : a > b;
}
void make_SA() {
	int i;
	for (i = 0; i < n; i++) {
		chk[i] = s[i] - 'a';
		SA[i] = i;
	}
	for (gap = 1;; gap <<= 1) {
		sort(SA, SA + n, cmp);
		tmp[0] = 1;
		for (i = 1; i < n; i++) tmp[i] = tmp[i - 1] + cmp(SA[i - 1], SA[i]);
		if (tmp[n - 1] == n) break;
		for (i = 0; i < n; i++)  chk[SA[i]] = tmp[i];
	}
}
void make_lcp() {
	int i, j, k = 0;
	for (i = 0; i<n; i++) R[SA[i]] = i;
	for (i = 0; i<n; lcp[R[i++]] = k) {
		for (k ? k-- : 0, j = (R[i] ? SA[R[i] - 1] : n); i + k<n && j + k<n && s[i + k] == s[j + k]; k++);
	}
}
int main() {
	int i;
	long long ans = 0;
	scanf("%s", s);
	n = strlen(s);
	make_SA();
	make_lcp();
	for (i = 0; i < n; i++) {
		ans += n - SA[i] - lcp[i];
	}
	printf("%lld", ans);
	return 0;
}