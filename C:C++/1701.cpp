#include <cstdio>
#include <cstring>

int f[1000010];
char o[1000010];
char u[1000010];

void make_fail(char *str, int m) {
	int i = -2, j = -1;
	while(j < m) {
		if(i < 0 || (i >= 0 && str[i] == str[j])) {
			i++;
			j++;
			f[j] = i;
		}
		else i = f[i];
	}
}

int match(char *str, char *str2, int n, int m) {
	int i = 0;
	int j = 0;
	int cnt = 0;

	while(j < n) {
		if(i == m) {
			cnt++;
			i = f[i];
		}
		else if(i < 0 || (i >=0 && str2[i] == str[j])) {
			i++;
			j++;
		}
		else i = f[i];
	}
	if(i == m) cnt++;

	return cnt;
}

int main() {
	int i, j;
	int n;
	int ans = 0;
	scanf("%s",o);
	n = strlen(o);
	for(i=0;i<n;i++) {
		make_fail(o+i, n-i);
		for(j=0;j<=n-i;j++) {
			if(ans < f[j]) ans = f[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}