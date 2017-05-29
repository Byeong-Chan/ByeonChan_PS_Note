#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int chk[110];
struct bung {
	int p;
	int num;
	int id;
}o[2100000];
bool fsort(bung a, bung b) {
	return a.num < b.num;
}
map<int, int> all;
int ans[110];
bung u[22000];
pair<int, int> sav[110];
int main() {
	int i, n;
	int l;
	int ed;
	int e = 0;
	int q;
	int sz;
	int x;
	int qa;
	bung tmp;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		ans[i] = 0x7fffffff;
		scanf("%d", &x);

		ed = (int)sqrt(x); 

		sz = 0;
		u[sz].num = 0;
		u[sz].id = i;
		sz++;

		if (x/ed == ed) qa = (ed << 1) - 1;
		else qa = ed << 1;

		for (l = 1; l <= ed; l++) {
			q = x / l;
			u[sz].num = l;
			u[sz].p = q;
			u[sz].id = i;
			sz++;
			if (q != l) {
				u[qa - sz + 2].num = q;
				u[qa - sz + 2].p = l;
				u[qa - sz + 2].id = i;
			}
		}
		u[qa + 1].num = x + 1;
		u[qa + 1].id = i;
		u[qa + 1].p = 0;
		for (l = 0; l <= qa; l++) {
			if (u[l].num != u[l + 1].num) {
				u[l].p = u[l + 1].p;
				o[e++] = u[l];
			}
		}
	}
	sort(o, o + e, fsort);
	o[e].num = -1;
	int max1;
	for (i = 0; i < e; i++) {
		tmp = o[i];
		if (chk[tmp.id] != 0) {
			all[chk[tmp.id]]--;
			if (all[chk[tmp.id]] == 0) all.erase(chk[tmp.id]);
		}
		all[tmp.p]++;
		chk[tmp.id] = tmp.p;
		sav[tmp.id] = make_pair(tmp.p, tmp.num);
		if (i < e && o[i + 1].num != tmp.num) {
			max1 = 0;
			for (l = 1; l <= n; l++) if (max1 < sav[l].second) max1 = sav[l].second;
			for (l = 1; l <= n; l++) if (ans[all[sav[l].first]] > max1 + 1) ans[all[sav[l].first]] = max1 + 1;
		}
	}
	for (i = 1; i <= n; i++) {
		if (ans[i] == 0x7fffffff) printf("-1\n");
		else printf("%d\n", ans[i]);
	}
	return 0;
}