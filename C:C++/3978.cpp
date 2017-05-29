#include <cstdio>
#include <algorithm>
using namespace std;
char o[10010];
char ans[101];
int chk[10010];
int tmp[10010];
int sa[10010];
//int R[10010];
//int lcp[10010];
int gap;
int n;
int m, k;
bool sw;
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
/*void make_lcp() {
	int i, j, k = 0;
	for (i = 0; i < n; i++) R[sa[i]] = i;
	for (i = 0; i < n; lcp[R[i++]] = k) {
		for (k ? k-- : k, j = R[i] ? sa[R[i] - 1] : n; j + k < n && i + k < n && o[j + k] == o[i + k]; k++);
	}
}*/
void dfs(int first, int last, int len) {
	if (len == m) return;
	int i;
	int lower_bound, upper_bound;
	int st, mid, ed;
	int tmp;
	char cmp;
	for (i = 0; i < k; i++) {
		if (sw) return;
		cmp = i + 'a';

		// lower_bound
		st = first;
		ed = last;
		while (st < ed) {
			mid = (st + ed) >> 1;
			tmp = sa[mid] + len;
			if (tmp >= n) st = mid + 1;
			else if (o[tmp] < cmp) st = mid + 1;
			else ed = mid;
		}
		lower_bound = st;

		// upper_bound
		st = first;
		ed = last;
		while (st < ed) {
			mid = (st + ed) >> 1;
			tmp = sa[mid] + len;
			if (tmp >= n) st = mid + 1;
			else if (o[tmp] <= cmp) st = mid + 1;
			else ed = mid;
		}
		upper_bound = st;

		if (lower_bound == upper_bound) {
			sw = true;
			int j;
			for (j = 0; j < len; j++) printf("%c", ans[j]);
			printf("%c", cmp);
			for (j = len + 1; j < m; j++) printf("a");
			return;
		}
		ans[len] = cmp;
		dfs(lower_bound, upper_bound, len + 1);
	}
}
int main() {
	int i;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n,&m,&k);
		scanf("%s", o);
		if (n < m) {
			for (i = 0; i < m; i++) printf("a");
			printf("\n");
			continue;
		}
		make_SA();
		//make_lcp();
		sw = false;
		dfs(0, n, 0);
		printf("\n");
	}
	return 0;
}