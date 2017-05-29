#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
char o[11];
char tmp[11];
map<string, bool> dp[12];
int main() {
	int i, n, m;
	int len;
	int k, l;
	scanf("%d", &n);
	sprintf(o, "%d", n);
	scanf("%d", &m);
	if ((len = strlen(o)) == 1) {
		printf("-1");
		return 0;
	}
	dp[0][o] = true;
	map<string, bool>::iterator j;
	for (i = 0; i < m; i++) {
		for (j = dp[i].begin(); j != dp[i].end(); j++) {
			strcpy(tmp, j->first.data());
			for (k = 0; k < len; k++) {
				for (l = k + 1; l < len; l++) {
					swap(tmp[k], tmp[l]);
					if (tmp[0] != '0') dp[i + 1][tmp] = true;
					swap(tmp[k], tmp[l]);
				}
			}
		}
		dp[i].clear();
	}
	if (dp[m].size() == 0) printf("-1");
	else printf("%s", (--dp[m].end())->first.data());
	return 0;
}