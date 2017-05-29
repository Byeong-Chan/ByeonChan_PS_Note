#include <cstdio>
int main() {
	int n;
	int i;
	scanf("%d", &n);
	if (n % 7 == 0 || n % 7 == 2) printf("CY");
	else printf("SK");
	return 0;
}