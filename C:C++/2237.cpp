#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
short dt[110][20012][2];
short o[110];
short tmp[110];
list<short> ans;
int main() {
	short i, j;
	short n, m;
	short d;
	short x;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &o[i]);
	dt[2][o[1] - o[2] + 10000][0] = 1;
	dt[2][o[1] - o[2] + 10000][1] = o[1] + 10000;
	for (i = 3; i <= n; i++) {
		for (j = 20000; j >= 0; j--) {
			if (dt[i - 1][j][1]) {
				dt[i][j + o[i]][0] = 2;
				dt[i][j + o[i]][1] = j;

				dt[i][j - o[i]][0] = 1;
				dt[i][j - o[i]][1] = j;
			}
		}
	}
	d = n;
	m += 10000;
	while (d > 2 && dt[d][m][0] != 0) {
		tmp[d - 1] = dt[d][m][0];
		m = dt[d][m][1];
		d--;
	}
	ans.push_back(1);
	for (i = 2; i < n; i++) {
		if (tmp[i] == 2) {
			ans.pop_back();
			ans.push_back(2);
			ans.push_back(1);
		}
		else ans.push_back(1);
	}
	while (ans.size()) {
		printf("%d\n", ans.front());
		ans.pop_front();
	}
	return 0;
}