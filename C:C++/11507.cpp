#include <cstdio>
char o[1010];
bool chk[26][14];
int h[26];
int main() {
	int i;
	int tmp1, tmp2;
	for (i = 0; i < 26; i++) h[i] = 13;
	i = 0;
	scanf("%s", o);
	while (1) {
		if (o[i] == '\0') break;
		if (i % 3 == 2) {
			tmp1 = o[i - 2] - 'A';
			tmp2 = (o[i - 1] - '0') * 10 + o[i] - '0';
			if (!chk[tmp1][tmp2]) {
				chk[tmp1][tmp2] = true;
				h[tmp1]--;
			}
			else {
				printf("GRESKA\n");
				return 0;
			}
		}
		i++;
	}
	printf("%d %d %d %d\n", h['P' - 'A'], h['K' - 'A'], h['H' - 'A'], h['T' - 'A']);
	return 0;
}