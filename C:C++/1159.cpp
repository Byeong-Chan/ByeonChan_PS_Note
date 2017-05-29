#include <stdio.h>
int chk[27];
int main() {
	int i, n;
	char o[32];
	bool sw = false;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", o);
		chk[o[0] - 97] ++;
	}
	for (i = 0; i < 26; i++) if (chk[i] >= 5) {printf("%c", i + 97); sw = true;}
	if (!sw) printf("PREDAJA");
	return 0;
}