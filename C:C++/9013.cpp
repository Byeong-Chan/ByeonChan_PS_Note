#include <stdio.h>
int dt[100011][2][110];
int que[100011];
int moth[100011];
int son[100011];
int num[100011];
int tmp[6][110];
int main() {
	int t;
	int i, j;
	int n, k;
	int tail, head;
	int x;
	int nxt;
	int ans;
	int sav;
	int max1;
	int p, q;
	int z;
	bool sw;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		max1 = -0x7ffffff;
		for (i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			if (num[i] > max1) max1 = num[i];
			for (j = 0; j <= k; j++) {
				dt[i][0][j] = 0;
				dt[i][1][j] = 0;
			}
			if (num[i] > 0) dt[i][1][1] = num[i];
			son[i] = 0;
		}
		for (i = 1; i < n; i++) {
			scanf("%d", &moth[i]);
			son[moth[i]]++;
		}
		if (max1 <= 0) {
			printf("%d\n", max1);
			continue;
		}
		tail = head = 0;
		for (i = 0; i < n; i++) if (son[i] == 0) que[tail++] = i;
		while (tail > head) {
			x = que[head];
			if (x == 0) break;
			head++;
			nxt = moth[x];
			if (--son[nxt] == 0) que[tail++] = nxt;
			sw = true;
			if (num[nxt] < 0) sw = false;
			for (i = 0; i <= k; i++) {
				tmp[0][i] = tmp[4][i] = dt[nxt][0][i];
				tmp[1][i] = tmp[5][i] = dt[nxt][1][i];
				tmp[2][i] = dt[x][0][i];
				tmp[3][i] = dt[x][1][i];
			}
			for (i = 0; i <= k; i++) {
				p = tmp[0][i];
				q = tmp[1][i];
				if (i == 0 || p > 0) {
					for (j = 0; j <= k - i; j++) {
						z = i + j;
						sav = p + tmp[2][j];
						if (tmp[4][z] < sav) tmp[4][z] = sav;
						sav = p + tmp[3][j];
						if (tmp[4][z] < sav) tmp[4][z] = sav;
					}
				}
				if (sw && (i == 0 || q > 0)) {
					for (j = 0; j <= k - i; j++) {
						if (j > 0 && tmp[2][j] == 0) break;
						z = i + j;
						sav = q + tmp[2][j];
						if (tmp[5][z] < sav) tmp[5][z] = sav;
					}
				}
			}
			for (i = 0; i <= k; i++) {
				dt[nxt][0][i] = tmp[4][i];
				dt[nxt][1][i] = tmp[5][i];
			}
		}
		ans = 0;
		for (i = 0; i <= k; i++) {
			if (dt[0][0][i] > ans) ans = dt[0][0][i];
			if (dt[0][1][i] > ans) ans = dt[0][1][i];
		}
		printf("%d\n", ans);
	}
	return 0;
}