#include <cstdio>
#include <vector>
using namespace std;
int que[100020];
int moth[100020];
int son[100020];
int dt[100020][16];
vector<int> conn[100001];
int min1(int x, int y) {
    if(x < y) return x;
    return y;
}
int main() {
	int i, j;
	int n;
	int x, y;
	int tail, head;
	int tmp;
	int nex;
	int sz;
    int minc;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		conn[x].push_back(y);
		conn[y].push_back(x);
	}
	tail = head = 0;
	que[tail++] = 1;
	moth[1] = -1;
	while (tail > head) {
		tmp = que[head++];
		sz = conn[tmp].size();
		for (i = 0; i < sz; i++) {
			nex = conn[tmp][i];
			if (!moth[nex]) {
				moth[nex] = tmp;
				son[tmp]++;
				que[tail++] = nex;
			}
		}
	}
	tail = head = 0;
	for (i = 1; i <= n; i++) {
        for(j=0;j<16;j++) dt[i][j] = j + 1;
		if (!son[i]) que[tail++] = i;
	}
	while (tail > head) {
		tmp = que[head++];
		nex = moth[tmp];
		if (nex == -1) break;
		if (--son[nex] == 0) que[tail++] = nex;

		for(i=0;i<16;i++) {
            minc = 0x7fffffff;
            for(j=0;j<16;j++) {
                if(i == j) continue;
                minc = min1(minc, dt[tmp][j]);
            }
            dt[nex][i] += minc;
        }
	}
    tmp = 0x7fffffff;
    for(i=0;i<16;i++) tmp = min1(tmp, dt[1][i]);
	printf("%d", tmp);
	return 0;
}