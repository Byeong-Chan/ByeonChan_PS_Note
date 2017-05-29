#include <stdio.h>
#include <algorithm>
using namespace std;
int o[110];
int u[110];
int main() {
	int t;
	int i, p;
	int n;
	int sz;
	int st, ed;
	int k;
	int x1, x2, x3;
	bool re;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &o[i]);
			if (o[i] == 1) k = i;
		}
		o[n + 1] = 0;
		sz = 0;
		for (i = 1; i <= n; i++) {
			if (o[i - 1] < o[i] && o[i] > o[i + 1]) u[sz++] = i;
		}
		st = 0;
		ed = sz - 1;
		if (u[st] > k) {
			if (u[st] - k > 1) {
				if (!((n - k) & 1)) printf("Alice\n");
				else printf("Bob\n");
			}
			else {
				for (p = u[st] + 1 == n + 1 ? n : u[st] + 1; p < n; p++) if (o[p - 1] > o[p] && o[p] < o[p + 1]) break;
				if (!((n - p + 1) & 1)) printf("Alice\n");
				else printf("Bob\n");
			}
			continue;
		}
		if (u[ed] < k) {
			if (k - u[ed] > 1) {
				if (!((n - 1) & 1)) printf("Alice\n");
				else printf("Bob\n");
			}
			else {
				for (p = u[ed] - 1 == 0 ? 1 : u[ed] - 1; p >= 2; p--) if (o[p - 1] > o[p] && o[p] < o[p + 1]) break;
				if (!(p & 1)) printf("Alice\n");
				else printf("Bob\n");
			}
			continue;
		}
		while (1) {
			re = true;
			if (st + 1 < sz && u[st + 1] < k) st++, re = false;
			if (ed - 1 >= 0 && u[ed - 1] > k) ed--, re = false;
			if (re) break;
		}
		x1 = x2 = x3 = -1;
		if (u[st] + 1 == k) {
			for (p = u[st] - 1 == 0 ? 1 : u[st] - 1; p >= 2; p--) if (o[p - 1] > o[p] && o[p] < o[p + 1]) break;
			x1 = p + n - k;
		}
		if (u[ed] - 1 == k) {
			for (p = u[ed] + 1 == n + 1 ? n : u[ed] + 1; p < n; p++) if (o[p - 1] > o[p] && o[p] < o[p + 1]) break;
			x2 = k + n - p;
		}
		if (u[ed] - 1 != k || u[st] + 1 != k) x3 = n - 1;

		if (x3 != -1 && (x3 & 1)) printf("Bob\n");
		else if (x3 != -1 && !(x3 & 1)) printf("Alice\n");
		else if (x1 != -1 && !(x1 & 1)) printf("Alice\n");
		else if (x2 != -1 && !(x2 & 1)) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}