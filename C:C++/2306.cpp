#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef pair<char, char> pr;
int table[510][510];
char o[510];
pr cmp[2];
int main() {
	int i, j, k, n;
	int e;
	int ans = 0;
	pr tmp;
	scanf("%s",o);
	n = strlen(o);
	cmp[0] = make_pair('a', 't');
	cmp[1] = make_pair('g', 'c');
	for(i=1;i<n;i++) {
		for(j=i-1;j>=0;j--) {
			tmp = make_pair(o[j], o[i]);

			e = 0;
			if(tmp == cmp[0] || tmp == cmp[1]) e += 2;
			if(j+1 <= i-1) e += table[i-1][j+1];

			if(e >= table[i][j+1]) table[i][j] = e;
			else table[i][j] = table[i][j+1];
		}
		for(j=i-2;j>=0;j--) {
			for(k=i-1;k>=j;k--) {
				if(table[k][j] + table[i][k+1] > table[i][j]) table[i][j] = table[k][j] + table[i][k+1];
			}
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(ans < table[i][j]) ans = table[i][j];
		}
	}
	printf("%d",ans);
	return 0;
}