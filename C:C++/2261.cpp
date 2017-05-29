#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
     
#define rep(x) ((x) * (x))
#define _mindist(x, y) ((x) < (y) ? (x) : (y))
     
struct bung {
    int x;
    int y;
}o[100002];
bool fsort(bung a, bung b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int n;
int ss[2][1700];
int findpair(int st, int ed) {
    if (ed - st > 1) {
        int mid = (st + ed) / 2;
     
        int d1, d2;
        int min_d;
     
        d1 = findpair(st, mid);
        d2 = findpair(mid + 1, ed);
     
        min_d = _mindist(d1, d2);
     
        int s = (int)sqrt(min_d);
        int sx = o[mid].x, sy = o[mid].y;
        int i, j;
        int sizet = 0;
        for (i = st; i <= ed; i++) {
            if (sx - s <= o[i].x && sx + s >= o[i].x) {
                if(sizet > 1000) continue;
                ss[0][sizet] = o[i].x;
                ss[1][sizet++] = o[i].y;
            }
        }
        int d;
        for (i = 0; i < sizet; i++) {
            for (j = i + 1; j < sizet; j++) {
                d = rep(ss[0][i] - ss[0][j]) + rep(ss[1][i] - ss[1][j]);
                min_d = _mindist(min_d, d);
            }
        }
     
        sx = o[mid + 1].x, sy = o[mid + 1].y;
        sizet = 0;
        for (i = st; i <= ed; i++) {
            if (sx - s <= o[i].x && sx + s >= o[i].x) {
                if(sizet > 1000) continue;
                ss[0][sizet] = o[i].x;
                ss[1][sizet++] = o[i].y;
            }
        }
     
        for (i = 0; i < sizet; i++) {
            for (j = i + 1; j < sizet; j++) {
                d = rep(ss[0][i] - ss[0][j]) + rep(ss[1][i] - ss[1][j]);
                min_d = _mindist(min_d, d);
            }
        }
     
     
        return min_d;
    }
    else {
        int i, j;
        int d;
        int min_d = 0x7fffffff;
        for (i = st; i <= ed; i++) {
            for (j = i + 1; j <= ed; j++) {
                d = rep(o[i].x - o[j].x) + rep(o[i].y - o[j].y);
                min_d = _mindist(min_d, d);
            }
        }
        return min_d;
    }
}
int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d %d", &o[i].x, &o[i].y);
    std::sort(o + 1, o + n + 1, fsort);
    printf("%d", findpair(1, n));
    return 0;
}