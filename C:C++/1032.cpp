#include <stdio.h>
#include <string.h>
int o[26];
char u[52][52];
int main() {
	int i, j, n, m;
	char tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", u[i]);;
	m = strlen(u[0]);
	for (i = 0; i < m; i++) {
		tmp = u[0][i];
		for (j = 1; j < n; j++) {
			if (tmp == '?' || u[j][i] == '?' || tmp == u[j][i]) tmp = u[j][i] != '?' ? u[j][i] : tmp;
			else break;
		}
		if (j < n) printf("?");
		else printf("%c", tmp);
	}
	return 0;
}