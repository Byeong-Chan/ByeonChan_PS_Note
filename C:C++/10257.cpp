#include <stdio.h>
#include <string.h>
bool tmpo[12][1003];
bool o[12][1003];
bool alsw;
bool xi[12][2];
bool sav[2][3602][12][2];
int cut[2][3602];
int bp[23];
int dt[2][3602];
int e[2];
int n, m, c;
int kke[2][1048578];
void make_start(int a, int b, int hap, int pos) {
	int k, cnt = 0;
	for (k = 0; k < n; k++) {
		if (!o[k][b]) cnt++;
	}
	if (cnt == n) {
		if (b == 0) make_start(0, 1, hap, pos);
		else {
			if (kke[0][pos] == 0) {
				kke[0][pos] = ++e[0];
				cut[0][e[0]] = pos;
				dt[0][e[0]] = hap;
				int i;
				for (i = 0; i<n; i++) {
					sav[0][e[0]][i][0] = xi[i][0];
					sav[0][e[0]][i][1] = xi[i][1];
				}
			}
			else if (dt[0][kke[0][pos]] > hap) dt[0][kke[0][pos]] = hap;
		}
		return;
	}
	if (a >= n) {
		if (b == 0) {
			int i, j;
			for (i = 0; i < n; i++) {
				if (xi[i][b] == 1) {
					int tmpx = i;
					int tmpy = i + 2;
					if (tmpy >= n) tmpy = n - 1;
					for (j = tmpx; j <= tmpy; j++) o[j][b+1] = 0;
				}
			}
			make_start(0, 1, hap, pos);
			for (i = 0; i < n; i++) o[i][b+1] = tmpo[i][b+1];
		}
		else {
			if (kke[0][pos] == 0) {
				kke[0][pos] = ++e[0];
				cut[0][e[0]] = pos;
				dt[0][e[0]] = hap;
				int i;
				for (i = 0; i<n; i++) {
					sav[0][e[0]][i][0] = xi[i][0];
					sav[0][e[0]][i][1] = xi[i][1];
				}
			}
			else if (dt[0][kke[0][pos]] > hap) dt[0][kke[0][pos]] = hap;
		}
		return;
	}
	if (!o[a][b]) {
		xi[a][b] = false;
		make_start(a + 1, b, hap, pos);
	}
	xi[a][b] = true;
	make_start(a + 3, b, hap+1, pos+bp[n*b + a]);
	xi[a][b] = false;
}
void solv(int a, int b, int hap, int pos) {
	if (a >= n) {
		int p = kke[!alsw][pos];
		if (p == 0) {
			int i;
			kke[!alsw][pos] = ++e[!alsw];
			cut[!alsw][e[!alsw]] = pos;
			dt[!alsw][e[!alsw]] = hap;
			for (i = 0; i<n; i++) {
				sav[!alsw][e[!alsw]][i][0] = xi[i][0];
				sav[!alsw][e[!alsw]][i][1] = xi[i][1];
			}
		}
		else {
			if (dt[!alsw][p] > hap) {
				dt[!alsw][p] = hap;
			}
		}
		return;
	}
	if (!o[a][b]) {
		xi[a][1] = false;
		solv(a + 1, b, hap, pos);
	}
	xi[a][1] = true;
	solv(a + 3, b, hap + 1, pos + bp[n + a]);
	xi[a][1] = false;
}
int main() {
	int t;
	int x, y;
	int d;
	int i, j, k, l;
	int s;
	int min1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		scanf("%d", &c);
		memset(o, 0, sizeof(o));
		memset(xi, 0, sizeof(xi));
		memset(tmpo, 0, sizeof(tmpo));
		while (c--) {
			scanf("%d %d", &x, &y);
			o[x - 1][y - 1] = true;
			tmpo[x - 1][y - 1] = true;
		}
		for (i = 0, d = 1; i < n * 2; i++, d <<= 1) bp[i] = d;
		e[0] = e[1] = 0;
		alsw = false;
		make_start(0, 0, 0, 0);
		for (i = 2; i < m; i++) {
			for (l = 1; l <= e[alsw]; l++) {
				kke[alsw][cut[alsw][l]] = 0;
				int cnt = 0;
				for (j = 0; j < n; j++) {
					if (sav[alsw][l][j][0]) {
						int tmpx = j;
						int tmpy = j + 2;
						if (tmpy >= n) tmpy = n - 1;
						for (k = tmpx; k <= tmpy; k++) o[k][i] = false;
					}
					if (sav[alsw][l][j][1]) {
						int tmpx = j;
						int tmpy = j + 2;
						if (tmpy >= n) tmpy = n - 1;
						for (k = tmpx; k <= tmpy; k++) o[k][i] = false;
					}
					if (o[j][i] == false) cnt++;
				}
				s = 0;
				if (cnt == n) {
					for (j = 0; j < n; j++) {
						xi[j][0] = sav[alsw][l][j][1];
						if (xi[j][0]) s += bp[j];
						xi[j][1] = 0;
					}
					int p = kke[!alsw][s];
					if (p == 0) {
						kke[!alsw][s] = ++e[!alsw];
						cut[!alsw][e[!alsw]] = s;
						dt[!alsw][e[!alsw]] = dt[alsw][l];
						for (j = 0; j<n; j++) {
							sav[!alsw][e[!alsw]][j][0] = xi[j][0];
							sav[!alsw][e[!alsw]][j][1] = xi[j][1];
						}
					}
					else {
						if (dt[!alsw][p] > dt[alsw][l]) {
							dt[!alsw][p] = dt[alsw][l];
						}
					}
				}
				else {
					for (j = 0; j < n; j++) {
						xi[j][0] = sav[alsw][l][j][1];
						if (xi[j][0]) s += bp[j];
						xi[j][1] = 0;
					}
					solv(0, i, dt[alsw][l], s);
				}
				for (j = 0; j < n; j++) o[j][i] = tmpo[j][i];
			}
			e[alsw] = 0;
			alsw = !alsw;
		}
		min1 = 0x7fffffff;
		for (i = 1; i <= e[alsw]; i++) {
			kke[alsw][cut[alsw][i]] = 0;
			if (min1 > dt[alsw][i]) min1 = dt[alsw][i];
		}
		printf("%d\n", min1);
	}
	return 0;
}