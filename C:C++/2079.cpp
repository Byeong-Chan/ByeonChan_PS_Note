#include <stdio.h>
#include <string.h>
int n;
int p[4010];
int table[4010];
char o[4010];
void manacher() {
	int i;
	int c = -1;
	int k;
	for(i=0;i<n;i++) {
		if(c == -1) k = 0;
		else k = p[2*c-i] <= c+p[c]-i ? p[2*c-i] : c+p[c]-i;

		while(i-k-1 >= 0 && i+k+1 < n && o[i-k-1] == o[i+k+1]) k++;
		if(i+k > c+p[c]) c = i;
		p[i] = k;
	}
}
int main() {
	int i;
	int k1;
	scanf("%s",o);
	n = strlen(o);
	for(i=n-1;i>=0;i--) {
		o[i*2+1] = o[i];
		o[i*2] = '#';
	}
	n *= 2;
	o[n++] = '#';
	manacher();
	int j;
	for(i=0;i<n;i++) table[i] = 100000000;
	table[0] = table[1] = table[2] = 1;
	for(i=0;i<n;i++) {
		for(j=p[i];j>=0;j--) {
			if(i-j == 0) table[i+j] = 1;
			k1 = 0x7fffffff;
			if(o[i-j] == '#') {
				k1 = table[i-j];
				if(i-j-1 >= 0 && k1 > table[i-j-1]) k1 = table[i-j-1];

				if(k1 + 1 < table[i+j]) table[i+j] = k1 + 1;
			}
			else {
				if(i-j-1 >= 0) k1 = table[i-j-1];
				if(i-j-2 >= 0 && k1 > table[i-j-2]) k1 = table[i-j-2];

				if(k1 + 1 < table[i+j]) table[i+j] = k1 + 1;
			}
		}
	}
	printf("%d",table[n-1]);
	return 0;
}