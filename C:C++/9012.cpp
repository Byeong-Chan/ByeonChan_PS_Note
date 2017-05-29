#include <stdio.h>
char o[50];
int main() {
	int top;
	int t;
	int i;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", o);
		top = i = 0;
		while (1) {
			if (o[i] == NULL) break;
			if (o[i] == '(') top++;
			if (o[i] == ')') top--;
			if (top < 0) {
				printf("NO\n");
				break;
			}
			i++;
		}
		if (top > 0) printf("NO\n");
		else if (top == 0) printf("YES\n");
	}
	return 0;
}