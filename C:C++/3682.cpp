#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[20010];
int cnt, ph;
int k;
int num[20010], low[20010];
int chk[20010];
int extend_node[20010];
bool extend_indegree[20010];
bool extend_outdegree[20010];
bool visit[20010];
bool chk2[20010];
bool follow[20010];
bool scc[20010];
vector<pair<int, int> > stk;
vector<int> stk2;
void dfs(int in_u) {
	int i, v;
	int sz;
	pair<int, int> top;
	top = make_pair(in_u, 0);
	stk.push_back(make_pair(-1, 0));
	while (stk.size()) {
		if (top.second == 0) {
			chk[top.first] = k;
			num[top.first] = ++cnt;
			low[top.first] = cnt;
			follow[num[top.first]] = true;
		}
		sz = edge[top.first].size();
		for (i = top.second; i < sz; i++) {
			v = edge[top.first][i];
			top.second++;
			if (chk[v] == k) {
				if (follow[num[v]] || follow[low[v]]) {
					low[top.first] = min(low[top.first], low[v]);
				}
			}
			else {
				if (chk[v]) continue;
				stk.push_back(top);
				top = make_pair(v, 0);
				break;
			}
		}
		if (i == sz) {
			v = top.first;
			follow[num[v]] = false;
			top = stk.back();
			stk.pop_back();
			if (top.first == -1) break;
			low[top.first] = min(low[top.first], low[v]);
		}
	}
}
void make_extend(int in_u) {
	int i, u, v;

	stk2.push_back(in_u);
	chk2[in_u] = true;
	while (stk2.size()) {
		u = stk2.back();
		stk2.pop_back();

		if (!extend_node[low[u]]) extend_node[low[u]] = ++ph;

		int sz = edge[u].size();
		for (i = 0; i < sz; i++) {
			v = edge[u][i];
			if (chk2[v]) continue;
			chk2[v] = true;
			stk2.push_back(v);
		}
	}
}
int main() {
	int i, j;
	int n, m;
	int x, y;
	int t;
	int sz;
	int zero_indegree_sum, zero_outdegree_sum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			edge[x].push_back(y);
		}
		zero_indegree_sum = zero_outdegree_sum = 0;
		ph = cnt = k = 0;
		for (i = 1; i <= n; i++) {
			if (chk2[i]) continue;
			k++;
			dfs(i);
			make_extend(i);
		}
		for (i = 1; i <= n; i++) {
			sz = edge[i].size();
			for (j = 0; j < sz; j++) {
				y = edge[i][j];

				if (extend_node[low[i]] == extend_node[low[y]]) continue;

				extend_outdegree[extend_node[low[i]]] = true;
				extend_indegree[extend_node[low[y]]] = true;
			}
		}
		for (i = 1; i <= ph; i++) {
			if (!extend_indegree[i]) zero_indegree_sum++;
			if (!extend_outdegree[i]) zero_outdegree_sum++;
		}
		if (ph == 1) printf("0\n");
		else printf("%d\n", max(zero_indegree_sum, zero_outdegree_sum));
		for (i = 1; i <= n; i++) {
			while (edge[i].size()) edge[i].pop_back();
			extend_node[i] = extend_indegree[i] = extend_outdegree[i] = num[i] = chk[i] = chk2[i] = visit[i] = low[i] = scc[i] = 0;
		}
	}
	return 0;
}