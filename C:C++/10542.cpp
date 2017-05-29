#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int table[500010][2];
int moth[500010];
int num[500010], low[500010];
int chk[500010];
int dt[500010][2];
bool visit[500010];
bool follow[500010];
bool scc[500010];
bool profit[500010];
int son[500010];
int cnt = 0;
int k = 0;
vector<int> stk;
vector<pair<int, int> > trace;
queue<int> q;
void dfs(int in_u) {
	int i, u, v;
	int son;
	int sz;
	pair<int, int> tmp, tmp2;
	stk.push_back(in_u);
	visit[in_u] = true;
	while (stk.size()) {
		u = stk.back();
		stk.pop_back();
		chk[u] = k;
		num[u] = ++cnt;
		low[u] = cnt;
		son = 0;

		v = moth[u];
		if (chk[v] == k) {
			if (scc[low[v]] || follow[v]) {
				low[u] = min(low[u], low[v]);
				scc[low[v]] = true;
			}
		}
		else {
			if (visit[v]) continue;
			visit[v] = true;
			son++;
			stk.push_back(v);
		}

		follow[u] = true;
		trace.push_back(make_pair(u, son));
		while (trace.size() > 0 && trace.back().second == 0) {
			tmp = trace.back();
			trace.pop_back();
			follow[tmp.first] = false;

			if (trace.size() > 0) {
				tmp2 = trace.back();
				trace.pop_back();

				low[tmp2.first] = min(low[tmp2.first], low[tmp.first]);

				tmp2.second--;
				trace.push_back(tmp2);
			}
		}
	}
}
int main() {
	int n;
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &moth[i]);
		son[moth[i]]++;
	}
	for (i = 1; i <= n; i++) {
		table[i][1] = 1;
		if (son[i] == 0) q.push(i);
		if (chk[i]) continue;
		k++;
		dfs(i);
	}
	int d, nxt;
	while (q.size()) {
		d = q.front();
		q.pop();
		nxt = moth[d];
		table[nxt][1] += table[d][0];
		table[nxt][0] += max(table[d][0], table[d][1]);
		if (scc[low[nxt]]) continue;
		if (--son[nxt] == 0) q.push(nxt);
	}
	bool sw, sw2;
	int ans = 0;
	int nt;
	for (i = 1; i <= n; i++) {
		if (!scc[low[i]]) continue;
		if (profit[low[i]]) continue;

		profit[low[i]] = true;
		d = i;
		sw = true;
		sw2 = false;
		nt = 1;
		while (1) {
			nxt = moth[d];
			dt[nt][1] = dt[nt][0] = table[d][1] - table[d][0];
			if (table[d][1] - table[d][0] < 0) dt[nt][1] = dt[nt][0] = 0;

			if (nt >= 2) dt[nt][0] += dt[nt - 2][0];
			if (nt >= 4) dt[nt][1] += dt[nt - 2][1];
			if (nt >= 3 && dt[nt - 1][1] > dt[nt][1]) dt[nt][1] = dt[nt - 1][1];
			if (dt[nt - 1][0] > dt[nt][0]) dt[nt][0] = dt[nt - 1][0];
			nt++;
			ans += table[d][0];
			if (nxt == i) break;
			d = nxt;
		}
		ans += (dt[nt - 2][0] > dt[nt - 1][1] ? dt[nt - 2][0] : dt[nt - 1][1]);
	}
	printf("%d", ans);
	return 0;
}