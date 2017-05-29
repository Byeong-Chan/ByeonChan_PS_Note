#include <stdio.h>
#include <string.h>
int main() {
	int i, n;
	int e = 0;
	char o[110];
	scanf("%s",o);
	n = strlen(o);
	for(i=0;i<n;i++) if(o[i] == ',') e++;
	printf("%d",e+1);
	return 0;
}