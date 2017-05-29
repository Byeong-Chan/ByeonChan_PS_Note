#include <cstdio>
int main() {
	int n;
	int i;
	scanf("%d", &n);
	if (n % 7 == 1 || n % 7 == 3) printf("CY");
	else printf("SK");
	return 0;
}