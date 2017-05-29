#include <cstdio>
#define mod 1000000007
int o[52][52][52][52];
bool ch[52][52][52][52];
int main() {
	int s, a, b, c;
	int i, j, k, l;
	scanf("%d %d %d %d", &s, &a, &b, &c);
	o[0][0][0][0] = 1;
	ch[0][0][0][0] = true;
	for (i = 0; i < s; i++) {
		for (j = 0; j <= a; j++) {
			for (k = 0; k <= b; k++) {
				for (l = 0; l <= c; l++) {
					if (ch[i][j][k][l]) {
						o[i + 1][j + 1][k][l] += o[i][j][k][l];
						o[i + 1][j + 1][k][l] %= mod;
						o[i + 1][j][k + 1][l] += o[i][j][k][l];
						o[i + 1][j][k + 1][l] %= mod;
						o[i + 1][j][k][l + 1] += o[i][j][k][l];
						o[i + 1][j][k][l + 1] %= mod;
						o[i + 1][j + 1][k + 1][l] += o[i][j][k][l];
						o[i + 1][j + 1][k + 1][l] %= mod;
						o[i + 1][j + 1][k][l + 1] += o[i][j][k][l];
						o[i + 1][j + 1][k][l + 1] %= mod;
						o[i + 1][j][k + 1][l + 1] += o[i][j][k][l];
						o[i + 1][j][k + 1][l + 1] %= mod;
						o[i + 1][j + 1][k + 1][l + 1] += o[i][j][k][l];
						o[i + 1][j + 1][k + 1][l + 1] %= mod;

						ch[i + 1][j + 1][k][l] = true;
						ch[i + 1][j][k + 1][l] = true;
						ch[i + 1][j][k][l + 1] = true;
						ch[i + 1][j + 1][k + 1][l] = true;
						ch[i + 1][j + 1][k][l + 1] = true;
						ch[i + 1][j][k + 1][l + 1] = true;
						ch[i + 1][j + 1][k + 1][l + 1] = true;
					}
				}
			}
		}
	}
	printf("%d", o[s][a][b][c]);
	return 0;
}