#include <cstdio>
#include <cstring>
bool o[1010][1010];
bool u[1010][1010];
int n, m;
int sub(int a) {
    bool chko[1010] = { false, };
    bool chku[1010] = { false, };
    int que[2020][3];
    int tail, head;
    int tmpx, tmpy;
    int d;
    int pre;
    tail = head = 0;
    chko[a] = true;
    que[tail][0] = a;
    que[tail][1] = 0;
    que[tail][2] = -1;
    tail++;
    int i;
    while (head < tail) {
        tmpx = que[head][0];
        tmpy = que[head][1];
        if (tmpy && u[tmpx][1003]) {
            u[tmpx][1003] = false;
            break;
        }
        if (tmpy) {
            for (i = 1; i <= n; i++) {
                if (u[tmpx][i] && !chko[i]) {
                    chko[i] = true;
                    que[tail][0] = i;
                    que[tail][1] = !tmpy;
                    que[tail][2] = head;
                    tail++;
                }
            }
        }
        else {
            for (i = 1; i <= m; i++) {
                if (o[tmpx][i] && !chku[i]) {
                    chku[i] = true;
                    que[tail][0] = i;
                    que[tail][1] = !tmpy;
                    que[tail][2] = head;
                    tail++;
                }
            }
        }
        head++;
    }
    if (tail == head) return 0;
    d = head;
    while (1) {
        pre = d;
        d = que[d][2];
        if (d == -1) break;
        if (que[d][1]) {
            u[que[d][0]][que[pre][0]] = false;
            o[que[pre][0]][que[d][0]] = true;
        }
        else {
            o[que[d][0]][que[pre][0]] = false;
            u[que[pre][0]][que[d][0]] = true;
    
        }
    }
    return 1;
}
int main() {
    int i, j;
    int ans;
    int sz;
    int t;
    int x, y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d", &m, &n);
        memset(o, 0, sizeof(o));
        memset(u, 0, sizeof(u));
        for (i = 1; i <= m; i++) u[i][1003] = true;
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &x, &y);
            for (j = x; j <= y; j++) o[i][j] = true;
        }
        ans = 0;
        for (i = 1; i <= n; i++) ans += sub(i);
        printf("%d\n", ans);
    }
    return 0;
}