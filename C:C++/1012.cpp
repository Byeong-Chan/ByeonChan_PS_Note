#include <stdio.h>
int stk[2510][2];
int o[52][52];
int main() {
	int i, j;
	int t, n, m, k;
	int x, y;
	int top;
	int e;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		e = 1;
		for (i = 0; i < n; i++) for (j = 0; j < m; j++) o[i][j] = 0;
		while (k--) {
			scanf("%d %d", &x, &y);
			o[x][y] = 1;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (o[i][j] == 1) {
					o[i][j] = ++e;
					top = 0;
					stk[top][0] = i;
					stk[top][1] = j;
					top++;
					while (top--) {
						x = stk[top][0];
						y = stk[top][1];
						if (x + 1 < n && o[x + 1][y] == 1) {
							o[x + 1][y] = e;
							stk[top][0] = x + 1;
							stk[top][1] = y;
							top++;
						}
						if (x - 1 >= 0 && o[x - 1][y] == 1) {
							o[x - 1][y] = e;
							stk[top][0] = x - 1;
							stk[top][1] = y;
							top++;
						}
						if (y + 1 < m && o[x][y + 1] == 1) {
							o[x][y + 1] = e;
							stk[top][0] = x;
							stk[top][1] = y + 1;
							top++;
						}
						if (y - 1 >= 0 && o[x][y - 1] == 1) {
							o[x][y - 1] = e;
							stk[top][0] = x;
							stk[top][1] = y - 1;
							top++;
						}
					}
				}
			}
		}
		printf("%d\n", e - 1);
	}
	return 0;
}