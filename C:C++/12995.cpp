#include <cstdio>
#include <vector>
#include <queue>

#define mod 1000000007

using namespace std;
long long dt[52][52][2];
long long sav[52][2];
vector<int> con[52];
int degree[52];
bool chk[52];
queue<int> q;
int main() {
	int i, j, n;
	int x, y;
	int k;
	int m;
	int rt;
	int tmp, nxt;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &x, &y);
		degree[x]++;
		degree[y]++;
		con[x].push_back(y);
		con[y].push_back(x);
	}
	k = n;
	for (i = 1; i <= n; i++) {
		dt[i][0][0] = dt[i][1][0] = 1;
		if (degree[i] == 1) {
			if (k == 1) {
				rt = i;
				continue;
			}
			k--;
			chk[i] = true;
			q.push(i);
		}
	}
	while (q.size()) {
		tmp = q.front();
		q.pop();
		while (con[tmp].size()) {
			nxt = con[tmp].back();
			con[tmp].pop_back();
			if (chk[nxt]) continue;
			if (--degree[nxt] == 1) {
				if (k == 1) rt = nxt;
				else {
					chk[nxt] = true;
					k--;
					q.push(nxt);
				}
			}
			for (i = 0; i <= n; i++) {
				sav[i][0] = dt[nxt][i][0];
				dt[nxt][i][0] = 0;
			}
			for (i = 0; i <= m; i++) {
				dt[nxt][i][1] += dt[tmp][i][1];
				dt[nxt][i][1] %= mod;
				for (j = 0; j <= m - i; j++) {
					if (i > 0) {
						dt[nxt][i + j][0] += sav[i][0] * dt[tmp][j][0];
						dt[nxt][i + j][0] %= mod;
					}
					else {
						if (j > 0) {
							dt[nxt][i + j][1] += sav[i][0] * dt[tmp][j][0];
							dt[nxt][i + j][1] %= mod;
						}
						else {
							dt[nxt][i + j][0] += sav[i][0] * dt[tmp][j][0];
							dt[nxt][i + j][0] %= mod;
						}
					}
				}
			}
		}
	}
	printf("%lld", (dt[rt][m][0] + dt[rt][m][1]) % mod);
	return 0;
}