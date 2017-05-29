#include <cstdio>
int o[1011];
int cst[1011];
int times[1011];
int moth[1011];
bool chk[1011];
int main() {
	int i, j, n, r;	
	int x, y;
	int pos;
	double max1, tmp;
	scanf("%d %d", &n, &r);
	for (i = 1; i <= n; i++) {
		scanf("%d", &o[i]);
		cst[i] = o[i];
		times[i] = 1;
	}
	for (i = 1; i < n; i++) { scanf("%d %d", &x, &y); moth[y] = x; }
	chk[r] = true;
	for (i = 1; i < n; i++) {
		max1 = 0.0;
		for (j = 1; j <= n; j++) {
			if (!chk[j]) {
				tmp = (double)o[j] / times[j];
				if (max1 < tmp) {
					max1 = tmp;
					pos = j;
				}
			}
		}
		cst[moth[pos]] += o[pos] * times[moth[pos]] + cst[pos];
		o[moth[pos]] += o[pos];
		times[moth[pos]] += times[pos];
		chk[pos] = true;
		for (j = 1; j <= n; j++) if (moth[j] == pos) moth[j] = moth[pos];
		moth[pos] = o[pos] = cst[pos] = times[pos] = 0;
	}
	printf("%d", cst[r]);
	return 0;
}