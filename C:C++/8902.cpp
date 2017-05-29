#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[5001][5001];
int p[5001][26];
int q[5001][26];
int l[26];
int main() {
	int t;
	int i, j;
	int x, y;
	int ed;
	int e, sav;
	int pos, tmp;
	string a, b;
	cin >> t;
	while(t--) {
		cin >> a;
		cin >> b;
		for(i=1;i<=a.size();i++) {
			for(j=0;j<26;j++) p[i][j] = p[i-1][j];
			p[i][a[i-1] - 'A']++;
		}
		for(i=1;i<=b.size();i++) {
			for(j=0;j<26;j++) q[i][j] = q[i-1][j];
			q[i][b[i-1] - 'A']++;
		}
		for(i=0;i<26;i++) l[i] = p[a.size()][i] + q[b.size()][i];
		for(i=0;i<=a.size();i++) for(j=0;j<=b.size();j++) dp[i][j] = 0x7fffffff;
		ed = a.size() + b.size();
		dp[0][0] = 0;
		for(i=0;i<ed;i++) {
			x = i+1;
			y = -1;
			while(x > 0) {
				x--;
				y++;
				if(x > a.size()) continue;
				if(y > b.size()) break;
				sav = dp[x][y];
				if(x+1 <= a.size()) {
					e = sav;
					pos = a[x] - 'A';
					tmp = p[x+1][pos] + q[y][pos];

					if(tmp == 1) e -= i;
					if(tmp == l[pos]) e += i;

					if(dp[x+1][y] > e) dp[x+1][y] = e;
				}
				if(y+1 <= b.size()) {
					e = sav;
					pos = b[y] - 'A';
					tmp = p[x][pos] + q[y+1][pos];

					if(tmp == 1) e -= i;
					if(tmp == l[pos]) e += i;

					if(dp[x][y+1] > e) dp[x][y+1] = e;
				}
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}