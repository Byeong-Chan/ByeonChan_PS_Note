#include <stdio.h>
short o[10003];
unsigned int table[2][5003];
short max1[10003];
int main() {
	int i, j, n;
	int e = -1;
	bool sw;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &o[i]);
	if (!(n & 1)) {
		for (i = 0; i < n; i++) {
			if (i < n / 2) e++;
			if (i > n / 2) e--;
			max1[i] = e;
		}
	}
	else {
		for (i = 0; i < n; i++) {
			if (i <= n / 2) e++;
			if (i > n / 2) e--;
			max1[i] = e;
		}
	}
	if (o[0] > 0) {
		printf("0");
		return 0;
	}
	sw = false;
	table[sw][0] = 1;
	for (i = 1; i < n; i++) {
		sw = !sw;

		if (o[i] == -1) {
			for (j = 0; j <= max1[i]; j++) {
				if (j - 1 >= 0) table[sw][j] += table[!sw][j - 1];
				table[sw][j] += table[!sw][j];
				table[sw][j] += table[!sw][j + 1];

				table[sw][j] %= 1000000007;
			}
		}
		else {
			if (o[i] > max1[i]) {
				printf("0");
				return 0;
			}
			if (o[i] - 1 >= 0) table[sw][o[i]] += table[!sw][o[i] - 1];
			table[sw][o[i]] += table[!sw][o[i]];
			table[sw][o[i]] += table[!sw][o[i] + 1];

			table[sw][o[i]] %= 1000000007;
		}
		for (j = 0; j <= max1[i+1]+1; j++) table[!sw][j] = 0;
	}
	printf("%d", table[sw][0]);
	return 0;
}