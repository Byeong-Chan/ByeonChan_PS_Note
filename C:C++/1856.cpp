#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[310];
char o[310];
char u[610][27];
int len[610];
int main() {
	int i, j;
	int k, l, cnt;
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", o);
	for (i = 0; i < n; i++) {
		scanf("%s", u[i]);
		len[i] = strlen(u[i]);
	}
	dp[0] = 1;
	for (i = 0; i < m; i++) {
		if (dp[i] == 0) continue;
		for (k = 0; k < n; k++) {
			l = i;
			cnt = 0;
			for (j = i + len[k]; j <= m; j++) {
				for (; l < j; l++) {
					if (cnt == len[k]) break;
					if (u[k][cnt] == o[l]) cnt++;
				}
				if (cnt == len[k]) {
					if(dp[j] == 0) dp[j] = dp[i] + j - i - cnt;
					else dp[j] = min(dp[j], dp[i] + j - i - cnt);
				}
			}
		}
	}
	printf("%d", dp[m] - 1);
	return 0;
}