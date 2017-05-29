#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int> indextree[2100000], max1;
long long dt[1000002];
int main() {
	int st, ed;
	int t;
	int i, k, d;
	int n;
	int pos;
	int tmp;
	long long ans = 0, buy, sell;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (k = 1; k < n; k <<= 1);
		for (i = 1; i < k + n; i++) indextree[i].first = indextree[i].second = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			indextree[(d = k + i)].first = tmp;
			indextree[d].second = i+1;
			dt[i + 1] = dt[i] + tmp;
			while (d > 1) {
				if (indextree[d >> 1].first < indextree[d].first) indextree[d >> 1] = indextree[d];
				d >>= 1;
			}
		}
		pos = 0;
		ans = 0;
		while (pos < n - 1) {
			st = k + pos;
			ed = k + n - 1;
			max1.first = max1.second = 0;
			while (1) {
				if (indextree[st].first > max1.first) max1 = indextree[st];
				if (indextree[ed].first > max1.first) max1 = indextree[ed];
				if (st == ed) break;
				if (st & 1) st++;
				if (!(ed & 1)) ed--;
				if (st > ed) break;
				st >>= 1;
				ed >>= 1;
			}
			buy = dt[max1.second - 1] - dt[pos];
			sell = (long long)max1.first * (max1.second - pos - 1);
			ans += (sell - buy);
			pos = max1.second;
		}
		printf("%lld\n", ans);
	}
	return 0;
}