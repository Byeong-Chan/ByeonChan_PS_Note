#include <stdio.h>
#include <algorithm>
using namespace std;
struct seo {
    int x;
    int y;
    int cost;
};
struct bung {
    int x;
    int y;
    int cost;
}o[1100];
bool ksort(seo a, seo b) {
    if(a.y - a.x < b.y - b.x) return 1;
    return 0;
}
bool fsort(bung a, bung b) {
    if(a.x < b.x) return 1;
    if(a.x == b.x && a.y < b.y) return 1;
    return 0;
}
int wa[42][42];
int n, k, e = 0, lo, clsw = 0;
bool checkx[42][42];
bool checky[42];
seo u[1100];
char prob[42];
void sub2(int, int, int, int, int, int);
void sub(int lc) {
    if(lc == e) {
        clsw = 1;
        printf("%s",prob);
        return;
    }
 
    int i, zz = 0;
    int st = u[lc].x, ed = u[lc].y;
    int xx = 0;
    for(i=st-1;i<ed;i++) {
        if(prob[i] == '#') zz++;
        else if(checky[i]) xx++;
    }
 
    if(clsw == 1) return;
    sub2(st-1, zz, ed, u[lc].cost, xx, lc);
}
void sub2(int pos, int cs, int m, int lo, int cant, int wq) {
    if(pos == m) {
        if(lo == cs) sub(wq+1);
        else return;
    }
 
    if(clsw == 1) return;
    if(checky[pos]) {
        if(prob[pos] == '-') sub2(pos + 1, cs, m, lo, cant-1, wq);
        else sub2(pos + 1, cs, m, lo, cant, wq);
    }
    else {
        if(cs < lo) {
            checky[pos] = true;
            prob[pos] = '#';
            sub2(pos + 1, cs+1, m, lo, cant, wq);
            prob[pos] = '-';
            checky[pos] = false;
        }
 
        if(clsw == 1) return;
        if(cs + (m - pos - 1) - cant >= lo) {
            checky[pos] = true;
            prob[pos] = '-';
            sub2(pos + 1, cs, m, lo, cant, wq);
            checky[pos] = false;
        }
    }
}
int main() {
    int i, j, l;
    int tmpx, tmpy, tmpc;
    int unx, uny, unc;
    int tmpmin;
    int sw = 0;
    scanf("%d %d",&n, &k);
    for(i=0;i<k;i++) scanf("%d %d %d",&o[i].x, &o[i].y, &o[i].cost);
    std::sort(o, o+k, fsort);
    for(i=0;i<k;i++) {
        if(i > 0 && o[i-1].x == o[i].x && o[i-1].y == o[i].y) {
            if(o[i].cost != o[i-1].cost) {
                sw = 1;
                break;
            }
        }
        checkx[o[i].x][o[i].y] = true;
        wa[o[i].x][o[i].y] = o[i].cost;
    }
    for(i=1;i<=n;i++) {
        tmpy = uny = -1;
        for(j=n;j>=i;j--) {
            if(checkx[i][j]) {
                if(j-i+1 < wa[i][j]) {
                    sw = 1;
                    break;
                }
                tmpy = uny;
                tmpc = unc;
                uny = j;
                unc = wa[i][j];
                if(tmpy == -1) continue;
 
                tmpmin = tmpc - unc;
                if(tmpmin < 0) {
                    sw = 1;
                    break;
                }
                if(checkx[uny+1][tmpy] && wa[uny+1][tmpy] != tmpmin) {
                    sw = 1;
                    break;
                }
                checkx[i][tmpy] = 0;
                wa[i][tmpy] = 0;
 
                checkx[uny+1][tmpy] = 1;
                wa[uny+1][tmpy] = tmpmin;
            }
        }
        if(sw == 1) break;
    }
    for(i=n;i>=1;i--) {
        tmpx = unx = -1;
        for(j=1;j<=i;j++) {
            if(checkx[j][i]) {
                if(i-j+1 < wa[j][i]) {
                    sw = 1;
                    break;
                }
                tmpx = unx;
                tmpc = unc;
                unx = j;
                unc = wa[j][i];
                if(tmpx == -1) continue;
 
                tmpmin = tmpc - unc;
                if(tmpmin < 0) {
                    sw = 1;
                    break;
                }
                if(checkx[tmpx][unx-1] && wa[tmpx][unx-1] != tmpmin) {
                    sw = 1;
                    break;
                }
                checkx[tmpx][i] = 0;
                wa[tmpx][i] = 0;
 
                checkx[tmpx][unx-1] = 1;
                wa[tmpx][unx-1] = tmpmin;
            }
        }
    }
    if(sw == 1) {
        printf("NONE");
        return 0;
    }
    for(i=0;i<n;i++) prob[i] = '-';
    for(i=1;i<=n;i++) {
        for(j=n;j>=i;j--) {
            if(checkx[i][j]) {
                if(wa[i][j] == 0) {
                    for(l=i-1;l<j;l++) checky[l] = true;
                    continue;
                }
                if(j - i + 1 == wa[i][j]) {
                    for(l=i-1;l<j;l++) {
                        prob[l] = '#';
                        checky[l] = true;
                    }
                    continue;
                }
                u[e].x = i;
                u[e].y = j;
                u[e++].cost = wa[i][j];
            }
        }
    }
    std::sort(u,u+e, ksort);
    sub(0);
    if(clsw == 0) {
        printf("NONE");
        return 0;
    }
    return 0;
}