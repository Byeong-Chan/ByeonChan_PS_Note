#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MOD 1000000000

typedef pair<int, int> pr;
vector<pr> o[2][100003];
vector<pr> sta;
vector<int> sta2;
queue<pr> que;
struct bung {
	bool h;
	int wx, wy;
}chk[100003];
bool sw = false;
int n, m, k;
bool ch[2][100003];
bool usex[100003], usey[100003];
short chkx[100003], chky[100003];
int main() {
	int i, j;
	int x, y, z, e = 0;
	int t = 1;
	int s;
	bool sw;
	bool judge;
	pr tmp;
	pr nex;
	pr kke;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<k;i++) {
		scanf("%d %d %d",&x,&y,&z);
		chk[i].wx = x;
		chk[i].wy = y;
		chk[i].h = z^(!((x&1) || (y&1)));

		tmp = make_pair(y, i);
		o[0][x].push_back(tmp);
		tmp = make_pair(x, i);
		o[1][y].push_back(tmp);
	}
	sw = false;
	for(i=1;i<=n;i++) {
		judge = false;
		for(j=0;j<o[0][i].size();j++) {
			nex = o[0][i][j];
			if(chk[nex.second].h) {
				judge = true;
				break;
			}
		}
		if(judge) {
			if(!chkx[i]) chkx[i] = true;
			else {
				sw = true;
				break;
			}
			sta2.push_back(1);
			sta.push_back(make_pair(i, 0));
		}

		while(sta.size()) {
			s = sta2.back();
			tmp = sta.back();
			sta.pop_back();
			sta2.pop_back();
			if(ch[tmp.second][tmp.first]) continue;
			ch[tmp.second][tmp.first] = true;
			if(s == 1) {
				for(j=0;j<o[tmp.second][tmp.first].size();j++) {
					nex = o[tmp.second][tmp.first][j];
					if(chk[nex.second].h) {
						chk[nex.second].h = false;
						if(tmp.second == 0) kke = make_pair(nex.first, 1);
						if(tmp.second == 1) kke = make_pair(nex.first, 0);

						if(kke.second == 0) chkx[kke.first] = 2;
						if(kke.second == 1) chky[kke.first] = 2;

						if(ch[kke.second][kke.first] == false) {
							sta.push_back(kke);
							sta2.push_back(0);
						}
					}
					else {
						chk[nex.second].h = true;
						if(tmp.second == 0) kke = make_pair(nex.first, 1);
						if(tmp.second == 1) kke = make_pair(nex.first, 0);

						if(kke.second == 0 && chkx[kke.first] == 2) {
							sw = true;
							break;
						}
						else if(kke.second == 0) chkx[kke.first] = 1;

						if(kke.second == 1 && chky[kke.first] == 2) {
							sw = true;
							break;
						}
						else if(kke.second == 1) chky[kke.first] = 1;

						if(ch[kke.second][kke.first] == false) {
							sta.push_back(kke);
							sta2.push_back(1);
						}
					}
				}
				if(sw) break;
			}
			else {
				for(j=0;j<o[tmp.second][tmp.first].size();j++) {
					nex = o[tmp.second][tmp.first][j];
					if(chk[nex.second].h) {
						chk[nex.second].h = true;
						if(tmp.second == 0) kke = make_pair(nex.first, 1);
						if(tmp.second == 1) kke = make_pair(nex.first, 0);

						if(kke.second == 0 && chkx[kke.first] == 2) {
							sw = true;
							break;
						}
						else if(kke.second == 0) chkx[kke.first] = 1;

						if(kke.second == 1 && chky[kke.first] == 2) {
							sw = true;
							break;
						}
						else if(kke.second == 1) chky[kke.first] = 1;

						if(ch[kke.second][kke.first] == false) {
							sta.push_back(kke);
							sta2.push_back(1);
						}
					}
					else {
						chk[nex.second].h = false;
						if(tmp.second == 0) kke = make_pair(nex.first, 1);
						if(tmp.second == 1) kke = make_pair(nex.first, 0);

						if(kke.second == 0) chkx[kke.first] = 2;
						if(kke.second == 1) chky[kke.first] = 2;

						if(ch[kke.second][kke.first] == false) {
							sta.push_back(kke);
							sta2.push_back(0);
						}
					}
				}
				if(sw) break;
			}
		}
		if(sw) break;
	}
	if(sw) {
		printf("0");
		return 0;
	}
	for(i=0;i<k;i++) {
		if(chk[i].h == false) {
			e++;
			usex[chk[i].wx] = true;
			usey[chk[i].wy] = true;
			chk[i].h = true;
			tmp = make_pair(chk[i].wx, 0);
			que.push(tmp);
			tmp = make_pair(chk[i].wy, 1);
			que.push(tmp);
			while(que.size()) {
				tmp = que.front();
				que.pop();
				for(j=0;j<o[tmp.second][tmp.first].size();j++) {
					nex = o[tmp.second][tmp.first][j];
					if(!chk[nex.second].h) {
						chk[nex.second].h = true;
						usex[chk[nex.second].wx] = true;
						usey[chk[nex.second].wy] = true;
						tmp = make_pair(chk[nex.second].wx, 0);
						que.push(tmp);
						tmp = make_pair(chk[nex.second].wy, 1);
						que.push(tmp);
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) if(!usex[i]) e++;
	for(i=1;i<=m;i++) if(!usey[i]) e++;
	e--;
	for(i=0;i<e;i++) {
		t *= 2;
		t %= MOD;
	}
	printf("%d",t);
	return 0;
}