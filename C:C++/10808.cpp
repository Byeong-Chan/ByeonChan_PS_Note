#include <stdio.h>
#include <string.h>
short chk[27];
int main() {
	short n;
	char u[101];
	scanf("%s",u);
	n = strlen(u);
	while(n--) chk[u[n]-'a']++;
	for(n=0;n<26;n++) printf("%d ",chk[n]);
	return 0;
}