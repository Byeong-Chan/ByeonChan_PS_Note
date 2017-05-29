#include <stdio.h>
int moth[51];
int que[51];
int son[51];
int allleaf[51];
bool chk[51];
int main() {
	int i, n;
	int tail, head;
	int now, nex;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &moth[i]);
		if(moth[i] >= 0) son[moth[i]]++;
	}
	scanf("%d", &now);
	chk[now] = true;
	if ((nex = moth[now]) != -1) {
		if (son[nex] == 1) allleaf[nex]++;
	}
	tail = head = 0;
	for (i = 0; i < n; i++) {
		if (son[i] == 0) {
			allleaf[i]++;
			que[tail++] = i;
		}
	}
	while (tail > head) {
		now = que[head++];
		nex = moth[now];
		if (nex == -1) break;
		if (--son[nex] == 0) que[tail++] = nex;
		if (!chk[now]) allleaf[nex] += allleaf[now];
	}
	if (chk[que[head - 1]]) printf("0");
	else printf("%d", allleaf[que[head - 1]]);
	return 0;
}