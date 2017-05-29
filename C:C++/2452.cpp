#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> con[10050];
pair<int, int> stk[10010];
int o[111][111];
bool cant[11111];
pair<int, int> que[10010];
bool chk[10050][10050];
int _fill[10050];
int p[10050];
int main() {
    int i, j, k, n, m;
    int x, y;
    int e = 2;
    int top;
    int tail, head;
    int sw;
    int ans = 10050;
    int sz, cnt;
    int all, pp = 0;
    int v;
    pair<int, int> tmp;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &o[i][j]);
        }
    }
    top = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (o[i][j] < 2) {
                top = 0;
                sw = o[i][j];
                o[i][j] = e;
                stk[top++] = make_pair(i, j);
                while (top--) {
                    tmp = stk[top];
                    x = tmp.first;
                    y = tmp.second;
                    if (x + 1 < n && o[x + 1][y] == sw) {
                        o[x + 1][y] = e;
                        stk[top++] = make_pair(x + 1, y);
                    }
                    if (x - 1 >= 0 && o[x - 1][y] == sw) {
                        o[x - 1][y] = e;
                        stk[top++] = make_pair(x - 1, y);
                    }
                    if (y + 1 < m && o[x][y + 1] == sw) {
                        o[x][y + 1] = e;
                        stk[top++] = make_pair(x, y + 1);
                    }
                    if (y - 1 >= 0 && o[x][y - 1] == sw) {
                        o[x][y - 1] = e;
                        stk[top++] = make_pair(x, y - 1);
                    }
                }
                e++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i + 1 < n && o[i][j] != o[i + 1][j]) {
                x = o[i][j];
                y = o[i + 1][j];
                if (!chk[x][y]) {
                    chk[x][y] = true;
                    chk[y][x] = true;
                    con[x].push_back(y);
                    con[y].push_back(x);
                }
            }
            if (i - 1 >= 0 && o[i][j] != o[i - 1][j]) {
                x = o[i][j];
                y = o[i - 1][j];
                if (!chk[x][y]) {
                    chk[x][y] = true;
                    chk[y][x] = true;
                    con[x].push_back(y);
                    con[y].push_back(x);
                }
            }
            if (j + 1 < m && o[i][j] != o[i][j + 1]) {
                x = o[i][j];
                y = o[i][j + 1];
                if (!chk[x][y]) {
                    chk[x][y] = true;
                    chk[y][x] = true;
                    con[x].push_back(y);
                    con[y].push_back(x);
                }
            }
            if (j - 1 >= 0 && o[i][j] != o[i][j - 1]) {
                x = o[i][j];
                y = o[i][j - 1];
                if (!chk[x][y]) {
                    chk[x][y] = true;
                    chk[y][x] = true;
                    con[x].push_back(y);
                    con[y].push_back(x);
                }
            }
        }
    }
    
    for(i=2;i<e;i++) {
        if(cant[i]) continue;
        cant[i] = true;
        tail = head = 0;
        que[tail++] = make_pair(i, 0);
        _fill[i] = ++pp;
        all = 0;
        cnt = 3;
        while(head < tail) {
            tmp = que[head++];
            sz = (int)con[tmp.first].size();
            if(tmp.second >= ans) cant[tmp.first] = true;
            if(cnt == e) {
                if(all == tmp.second) cant[tmp.first] = true;
                continue;
            }
            for(k = 0; k < sz; k++) {
                v = con[tmp.first][k];
                if(_fill[v] != pp) {
                    _fill[v] = pp;
                    cnt++;
                    que[tail++] = make_pair(v, tmp.second + 1);
                    if(cnt == e) {
                        all = tmp.second + 1;
                        break;
                    }
                }
            }
        }
        if(ans > all) ans = all;
    }
    printf("%d\n", ans);
    return 0;
}