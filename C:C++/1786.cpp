#include <cstdio>
#include <cstring>

int f[1000010];
int ans[1000010], cnt = 0;
char o[1000010];
char u[1000010];

void make_fail(int m) {
	int i = -2, j = -1;
	while(j < m) {
		if(i < 0 || (i >= 0 && u[i] == u[j])) {
			i++;
			j++;
			f[j] = i;
		}
		else i = f[i];
	}
}

void match(int n, int m) {
	int i = 0;
	int j = 0;
	while(j < n) {
		if(i == m) {
			ans[cnt++] = j-m;
			i = f[i];
		}
		else if(i < 0 || (i >=0 && u[i] == o[j])) {
			i++;
			j++;
		}
		else i = f[i];
	}
	if(i == m) ans[cnt++] = j-m;
}

int main() {
	int i;
	int n, m;
	scanf("%[^\n]\n%[^\n]",o,u);
	n = strlen(o);
	m = strlen(u);
	make_fail(m);
	match(n, m);
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++) printf("%d\n", ans[i]+1);
	return 0;
}