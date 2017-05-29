#include <stdio.h>
#include <vector>
using namespace std;
int moth[1010];
vector<int> son[1010];
int times[1010];
int chk[1010];
int main() {
	int k;
	int n, m;
	int i;
	int t;
	int x, y;
	int ans;
	int min1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%d", &times[i]);
			moth[i] = 0;
			son[i].clear();
			chk[i] = 0;
		}
		while (m--) {
			scanf("%d %d", &x, &y);
			moth[y]++;
			son[x].push_back(y);
		}
		scanf("%d", &k);
		for (i = 1; i <= n; i++) if (moth[i] == 0) chk[i] = 1;
		ans = 0;
		while (1) {
			min1 = 0x7fffffff;
			if (chk[k] == 1) {
				ans += times[k];
				break;
			}
			for (i = 1; i <= n; i++) {
				if (chk[i] == 1 && min1 > times[i]) min1 = times[i];
			}
			for (i = 1; i <= n; i++) {
				if (chk[i] == 1) {
					times[i] -= min1;
					if (times[i] == 0) {
						chk[i] = 0;
						while (son[i].size()) {
							if (--moth[son[i].back()] == 0) chk[son[i].back()] = 2;
							son[i].pop_back();
						}
					}
				}
			}
			for (i = 1; i <= n; i++) if (chk[i] == 2) chk[i] = 1;
			ans += min1;
		}
		printf("%d\n", ans);
	}
	return 0;
}