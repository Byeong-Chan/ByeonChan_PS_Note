#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
    int x;
    int y;
    int num;
};
bool fsort(bung a, bung b) {
    if (a.x < b.x) return true;
    if (a.x <= b.x && a.y > b.y) return true;
    return false;
}
bung max1, tree[4300000], o[1120000];
int n, m;
int k;
int moth[1120000];
int son[1120000];
int min1 = 0x7fffffff;
int chk[1120000];
void _find(int x) {
    int d = x, tmp, e = 0;
    int st, ed;
    int mid;
    while (d) {
    	e++;
    	chk[e] = o[d].x;
    	if(o[d].y > m) {
    		tmp = o[d].y - m;
    		st = 1;
    		ed = e+1;
    		chk[e+1] = 0x7fffffff;
    		while(st < ed) {
    			mid = (st+ed)/2;
    			if(chk[mid] <= tmp) st = mid+1;
    			else ed = mid;
    		}
    		if(st > 1 && min1 > e-st+2) min1 = e-st+2;
    	}
        d = moth[d];
    }
}
int main() {
    int i;
    int maxy;
    int d;
    int nx, ny, nnum;
    int st, ed;
    scanf("%d %d", &m, &n);
    for (k = 1; k < m * 2; k <<= 1);
    for (i = 1; i <= n; i++) {
        moth[i] = -1;
        scanf("%d %d", &o[i].x, &o[i].y);
        if (o[i].x > o[i].y) o[i].y += m;
        else {
            o[i].x += m;
            o[i].y += m;
        }
        o[i].y++;
    }
    std::sort(o + 1, o + n + 1, fsort);
    maxy = o[1].y;
    if (o[1].x > m && o[1].y > m) {
        o[1].x -= m;
        o[1].y -= m;
    }
    for (i = 2; i <= n; i++) {
        if (o[i].y <= maxy) o[i].x = 0x7fffffff;
        else maxy = o[i].y;

        if (o[i].x != 0x7fffffff && o[i].x > m && o[i].y > m) {
            o[i].x -= m;
            o[i].y -= m;
        }
    }
    std::sort(o + 1, o + n + 1, fsort);
    for (i = 1; i <= n; i++) {
        if(o[i].x == 0x7fffffff) break;
        o[i].num = i;

        d = k + o[i].x - 1;
        tree[d].x = o[i].x;
        tree[d].y = o[i].y;
        tree[d].num = o[i].num;
        while (d > 1) {
            if (tree[d / 2].y < tree[d].y) tree[d / 2] = tree[d];
            d /= 2;
        }
    }
    for (i = 1; i <= n; i++) {
        if (o[i].x == 0x7fffffff) break;
        if (moth[i] != -1) continue;
        nx = o[i].x;
        ny = o[i].y;
        nnum = o[i].num;
        while (1) {
            max1.num = 0;
            max1.x = 0;
            max1.y = 0;

            st = k + nx;
            ed = k + ny - 1;
            while (1) {
                if (max1.y < tree[st].y) max1 = tree[st];
                if (max1.y < tree[ed].y) max1 = tree[ed];
                if (st == ed) break;
                if (st & 1) st++;
                if (!(ed & 1)) ed--;
                if (st > ed) break;
                st /= 2;
                ed /= 2;
            }

            if (max1.num == 0) {
                moth[nnum] = 0;
                break;
            }
            son[max1.num]++;
            moth[nnum] = max1.num;
            if (moth[max1.num] != -1) break;
            nx = max1.x;
            ny = max1.y;
            nnum = max1.num;
        }
    }
    for (i = 1; i <= n; i++) {
        if (o[i].x == 0x7fffffff) break;
        if (son[i]) continue;
        _find(i);
    }
    if(min1 != 0x7fffffff) printf("%d\n", min1);
    else printf("impossible\n");
    return 0;
}