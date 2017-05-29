#include <stdio.h>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;
struct bung {
	short dt[26];
};
struct fsort {
	bool operator() (bung a, bung b) {
		short i;
		for(i=0;i<26;i++) if(a.dt[i] != b.dt[i]) return a.dt[i] > b.dt[i];
		return false;
	}
};
set<bung, fsort> sig;
short p[1501][26];
short q[1501][26];
char o[1502], u[1502];
bung x;
int main() {
	int i, j, k;
	int n, m;
	int t;
	scanf("%s",o);
	n = strlen(o);
	scanf("%s",u);
	m = strlen(u);
	for(i=1;i<=n;i++) {
		for(j=0;j<26;j++) p[i][j] = p[i-1][j];
		p[i][o[i-1]-'a']++;
	}
	for(i=1;i<=m;i++) {
		for(j=0;j<26;j++) q[i][j] = q[i-1][j];
		q[i][u[i-1]-'a']++;
	}
	t = n < m ? n : m;
	for(i=t;i>=1;i--) {
		for(k=0;k<26;k++) x.dt[k] = q[m][k] - q[m-i][k];
		for(j=m;j>=i;j--) {
			sig.insert(x);
			x.dt[u[j-1]-'a']--;
			if(i != j) x.dt[u[j-i-1]-'a']++;
		}
		for(k=0;k<26;k++) x.dt[k] = p[n][k] - p[n-i][k];
		for(j=n;j>=i;j--) {
			if(sig.find(x) != sig.end()) break;
			x.dt[o[j-1]-'a']--;
			if(i != j) x.dt[o[j-i-1]-'a']++;
		}
		if(j > i-1) break;
		sig.clear();
	}
	printf("%d",i);
	return 0;
}