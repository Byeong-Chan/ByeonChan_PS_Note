#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int o[1000010];
int son[1000010], cson[1000010];
int moth[1000010];
long long sum[1000010];
bool chk[1000010];
vector<int> con[1000010];
priority_queue<long long> q[1000010];
queue<int> que;
void bfs(int pos) {
	int u, v;
	chk[pos] = true;
	que.push(pos);

	while (que.size()) {
		u = que.front();
		que.pop();

		for (int i = 0; i < con[u].size(); i++) {
			v = con[u][i];
			if (!chk[v]) {
				chk[v] = true;
				moth[v] = u;
				son[u]++;
				que.push(con[u][i]);
			}
		}
	}
}
int main() {
	int t;
	int i, n, k;
	int x, y;
	int tmp, nxt;
	int cnt;
	long long st, ed, mid;
	scanf("%d", &t);
	while (t--) {
		st = ed = 0;
		scanf("%d %d", &n, &k);
		for (i = 1; i <= n; i++) {
			scanf("%d", &o[i]);
			if (o[i] > st) st = o[i];
			ed += o[i];
		}
		for (i = n - 2; i >= 0; i--) {
			scanf("%d %d", &x, &y);
			con[x].push_back(y);
			con[y].push_back(x);
		}
		bfs(1);
		while (st < ed) {
			cnt = 0;
			mid = (st + ed) / 2;
			for (i = 1; i <= n; i++) {
				sum[i] = o[i];
				cson[i] = son[i];
				if (son[i] == 0) que.push(i);
			}
			while (que.size()) {
				tmp = que.front();
				que.pop();

				while (sum[tmp] > mid) {
					sum[tmp] -= q[tmp].top();
					q[tmp].pop();
					cnt++;
				}
				while (q[tmp].size()) q[tmp].pop();

				if (tmp == 1) continue;
				nxt = moth[tmp];
				if (--cson[nxt] == 0) que.push(nxt);

				sum[nxt] += sum[tmp];
				q[nxt].push(sum[tmp]);
			}
			if (cnt <= k) ed = mid;
			else st = mid + 1;
		}
		printf("%lld\n", st);
		for (i = 1; i <= n; i++) {
			chk[i] = false;
			son[i] = moth[i] = 0;
			con[i].clear();
		}
	}
	return 0;
}