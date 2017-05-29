#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char o[100010];
char u[100010];
int SA[100010];
int Rank[100010];
int chk[100010];
int p[100010];
int mnit[300010];
int adit[300010];
int ans[100010];
int gap = 1;
int n, m;
int it_sz;
pair<int, int> pi[100010];
vector< pair<int, int> > interval[100010];
bool cmp(int a, int b) {
	if (p[a] != p[b]) return p[a] < p[b];
	return a + gap < n && b + gap < n ? p[a + gap] < p[b + gap] : a > b;
}
void make_SA() {
	int i;
	for (i = 0; i < n; i++) SA[i] = i, p[i] = o[i] - '0';
	for (;; gap <<= 1) {
		sort(SA, SA + n, cmp);
		chk[i] = 0;
		for (i = 1; i < n; i++) chk[i] = chk[i - 1] + cmp(SA[i - 1], SA[i]);
		if (chk[n - 1] == n - 1) break;
		for (i = 0; i < n; i++) p[SA[i]] = chk[i];
	}
	for (i = 0; i < n; i++) Rank[SA[i]] = i;
}
int SA_lower_bound(int l, int r, int k, char cp) {
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (SA[mid] + k >= n || (SA[mid] + k < n && o[SA[mid]+k] < cp)) l = mid + 1;
		else r = mid;
	}
	return l;
}
int SA_upper_bound(int l, int r, int k, char cp) {
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (SA[mid] + k >= n || (SA[mid] + k < n && o[SA[mid] + k] <= cp)) l = mid + 1;
		else r = mid;
	}
	return l;
}
void refer_mnit(int dd) {
	while (dd > 1) {
		if (mnit[(dd >> 1)] == 0 || mnit[(dd >> 1)] > mnit[dd]) mnit[(dd >> 1)] = mnit[dd];
		dd >>= 1;
	}
}
void init_mnit() {
	int i;
	for (i = 0; i < n; i++) {
		mnit[it_sz + i] = SA[i] + 1;
		refer_mnit(it_sz + i);
	}
}
int get_min(int l, int r) {
	int min1 = 0x7fffffff;
	while (1) {
		if (mnit[l] < min1) min1 = mnit[l];
		if (mnit[r] < min1) min1 = mnit[r];
		if (l == r) break;
		if (l & 1) l++;
		if (!(r & 1)) r--;
		if (l > r) break;
		l >>= 1;
		r >>= 1;
	}
	return min1;
}
void refer_adit(int dd) {
	while (dd >= 1) {
		adit[dd]++;
		dd >>= 1;
	}
}
int get_add(int l, int r) {
	int sum = 0;
	while (1) {
		if (l == r) {
			sum += adit[l];
			break;
		}
		if (l & 1) sum += adit[l++];
		if (!(r & 1)) sum += adit[r--];
		if (l > r) break;
		l >>= 1;
		r >>= 1;
	}
	return sum;
}
int main() {
	int i, j;
	int leng;
	int st, ed;
	int tmpst, tmped;
	scanf("%d", &n);
	scanf("%s", o);
	make_SA();
	for (it_sz = 1; it_sz < n+1; it_sz <<= 1);
	init_mnit();
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%s", u);
		leng = strlen(u);
		
		st = 0, ed = n;
		for (j = 0; j < leng; j++) {
			tmpst = SA_lower_bound(st, ed, j, u[j]);
			tmped = SA_upper_bound(st, ed, j, u[j]);
			st = tmpst;
			ed = tmped;
			if (st == ed) break;
			if (j != leng - 1) interval[i].push_back(make_pair(it_sz + st, it_sz + ed - 1));
		}
		if (st == ed) pi[i] = make_pair(n-1, i);
		else pi[i] = make_pair(get_min(it_sz + st, it_sz + ed - 1) - 1, i);
	}
	sort(pi, pi + m);
	int pre = 0;
	for (i = 0; i < m; i++) {
		int now = pi[i].second;
		while (pre <= pi[i].first) refer_adit(it_sz + Rank[pre++]);
		ans[now] += pre;
		int interval_sz = (int)interval[now].size();
		for (j = 0; j < interval_sz; j++) ans[now] += get_add(interval[now][j].first, interval[now][j].second);
	}
	for (i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}