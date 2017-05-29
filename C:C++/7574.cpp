#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct bung {
    int x;
    int y;
    bool num;
    int chk;
};
bung o[210000], u[210000];
int n, m, r;
int t1, t2;
int e1, e2;
int mxtree[510000], mntree[510000];
int sub[310000];
int kx, ky;
int mchk[110000];
int allx[310000];
int ally[310000];
vector<int> ka[100002];
map<int, int> transx, transy;
bool fsort(bung a, bung b) {
    if (a.y < b.y) return true;
    if (a.y <= b.y && (a.num == true && b.num == false)) return true;
    if (a.y <= b.y && (a.num == true && b.num == true) && a.x < b.x) return true;
    return false;
}
bool ksort(bung a, bung b) {
    if (a.x < b.x) return true;
    if (a.x <= b.x && (a.num == true && b.num == false)) return true;
    if (a.x <= b.x && (a.num == true && b.num == true) && a.y < b.y) return true;
    return false;
}
void mxchange(int, bool);
void mnchange(int d, bool sw) {
    if (sw == true) {
        while (d > 1) {
            if (mntree[d / 2] > mntree[d] || mntree[d / 2] == 0) mntree[d / 2] = mntree[d];
            d /= 2;
        }
        return;
    }
    while (d >= 1) {
        mntree[d] = 0;
        if (mntree[d * 2] != 0 && mntree[d * 2 + 1] == 0) mntree[d] = mntree[d * 2];
        if (mntree[d * 2] == 0 && mntree[d * 2 + 1] != 0) mntree[d] = mntree[d * 2 + 1];
        if (mntree[d * 2] != 0 && mntree[d * 2 + 1] != 0) {
            if (mntree[d * 2] < mntree[d * 2 + 1]) mntree[d] = mntree[d * 2];
            else mntree[d] = mntree[d * 2 + 1];
        }
        d /= 2;
    }
}
void mxchange(int d, bool sw) {
    if (sw == true) {
        while (d > 1) {
            if (mxtree[d / 2] < mxtree[d] || mxtree[d / 2] == 0) mxtree[d / 2] = mxtree[d];
            d /= 2;
        }
        return;
    }
    while (d >= 1) {
        mxtree[d] = 0;
        if (mxtree[d * 2] != 0 && mxtree[d * 2 + 1] == 0) mxtree[d] = mxtree[d * 2];
        if (mxtree[d * 2] == 0 && mxtree[d * 2 + 1] != 0) mxtree[d] = mxtree[d * 2 + 1];
        if (mxtree[d * 2] != 0 && mxtree[d * 2 + 1] != 0) {
            if (mxtree[d * 2] > mxtree[d * 2 + 1]) mxtree[d] = mxtree[d * 2];
            else mxtree[d] = mxtree[d * 2 + 1];
        }
        d /= 2;
    }
}
int main()
{
    int i, sn;
    int st, ed, tmp1, tmp2;
    int max1, min1;
    int d1, d2;
    int sav;
     
    //선분 정리
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        mchk[i + 1] = i + 1;
        ka[i + 1].push_back(i + 1);
 
        scanf("%d %d", &o[i].x, &o[i].y);
        o[i].num = true;
        o[i].chk = i + 1;
 
        u[i] = o[i];
 
        o[i + n] = o[i];
        u[i + n] = u[i];
        u[i + n].num = o[i + n].num = false;
        o[i + n].y += m;
        u[i + n].x += m;
    }
    scanf("%d", &r);
    sn = n * 2;
 
    // 좌표 압축
    t1 = t2 = 0;
    for (i = 0; i < n; i++) {
        allx[t1++] = o[i].x;
        allx[t1++] = ((o[i].x - m - r) < 0 ? 0 : o[i].x - m - r);
        allx[t1++] = o[i].x + m + r;
 
        ally[t2++] = o[i].y;
        ally[t2++] = ((o[i].y - m - r) < 0 ? 0 : o[i].y - m - r);
        ally[t2++] = o[i].y + m + r;
    }
    std::sort(allx, allx + t1);
    std::sort(ally, ally + t2);
    for (i = 0; i < t1; i++) if (transx[allx[i]] == 0) transx[allx[i]] = ++e1;
    for (i = 0; i < t2; i++) if (transy[ally[i]] == 0) transy[ally[i]] = ++e2;
    for (kx = 1; kx < e1; kx <<= 1);
    for (ky = 1; ky < e2; ky <<= 1);
     
    //가로
    std::sort(o, o + sn, fsort);
    for (i = 0; i < sn; i++) {
        if (!o[i].num) {
            tmp1 = transx[o[i].x];
            sub[tmp1] = 0;
            tmp1 += kx - 1;
 
            mxtree[tmp1] = 0;
            mntree[tmp1] = 0;
            mxchange(tmp1/2, false);
            mnchange(tmp1/2, false);
            continue;
        }
        //왼쪽
        tmp1 = ((o[i].x - m - r) < 0 ? 0 : o[i].x - m - r);
        tmp2 = o[i].x;
 
        st = kx + transx[tmp1] - 1;
        ed = kx + transx[tmp2] - 1;
 
        max1 = 0;
        while (1) {
            if (max1 < mxtree[st]) max1 = mxtree[st];
            if (max1 < mxtree[ed]) max1 = mxtree[ed];
            if (st == ed) break;
            if (st & 1) st++;
            if (!(ed & 1)) ed--;
            if (st > ed) break;
            st /= 2;
            ed /= 2;
        }
        if (max1 != 0) {
            d1 = mchk[o[i].chk];
            d2 = mchk[sub[max1]];
            if (d1 != d2) {
                if (ka[d1].size() > ka[d2].size()) {
                    while (ka[d2].size()) {
                        sav = ka[d2].back();
                        ka[d1].push_back(sav);
                        mchk[sav] = d1;
                        ka[d2].pop_back();
                    }
                }
                else {
                    while (ka[d1].size()) {
                        sav = ka[d1].back();
                        ka[d2].push_back(sav);
                        mchk[sav] = d2;
                        ka[d1].pop_back();
                    }
                }
            }
        }
 
        //오른쪽
        tmp1 = tmp2;
        tmp2 = o[i].x + m + r;
 
        st = kx + transx[tmp1] - 1;
        ed = kx + transx[tmp2] - 1;
 
        min1 = 0x7fffffff;
        while (1) {
            if (mntree[st] > 0 && min1 > mntree[st]) min1 = mntree[st];
            if (mntree[ed] > 0 && min1 > mntree[ed]) min1 = mntree[ed];
            if (st == ed) break;
            if (st & 1) st++;
            if (!(ed & 1)) ed--;
            if (st > ed) break;
            st /= 2;
            ed /= 2;
        }
        if (min1 != 0x7fffffff) {
            d1 = mchk[o[i].chk];
            d2 = mchk[sub[min1]];
            if (d1 != d2) {
                if (ka[d1].size() > ka[d2].size()) {
                    while (ka[d2].size()) {
                        sav = ka[d2].back();
                        ka[d1].push_back(sav);
                        mchk[sav] = d1;
                        ka[d2].pop_back();
                    }
                }
                else {
                    while (ka[d1].size()) {
                        sav = ka[d1].back();
                        ka[d2].push_back(sav);
                        mchk[sav] = d2;
                        ka[d1].pop_back();
                    }
                }
            }
        }
 
        tmp1 = transx[o[i].x];
        sub[tmp1] = o[i].chk;
         
        tmp1 += (kx - 1);
        mxtree[tmp1] = tmp1 - (kx - 1);
        mntree[tmp1] = tmp1 - (kx - 1);
        mxchange(tmp1, true);
        mnchange(tmp1, true);
    }
 
    //세로
    std::sort(u, u + sn, ksort);
    for (i = 0; i < sn; i++) {
        if (!u[i].num) {
            tmp1 = transy[u[i].y];
            sub[tmp1] = 0;
            tmp1 += ky - 1;
 
            mxtree[tmp1] = 0;
            mntree[tmp1] = 0;
            mxchange(tmp1 / 2, false);
            mnchange(tmp1 / 2, false);
            continue;
        }
        //아래
        tmp1 = ((u[i].y - m - r) < 0 ? 0 : u[i].y - m - r);
        tmp2 = u[i].y;
 
        st = ky + transy[tmp1] - 1;
        ed = ky + transy[tmp2] - 1;
 
        max1 = 0;
        while (1) {
            if (max1 < mxtree[st]) max1 = mxtree[st];
            if (max1 < mxtree[ed]) max1 = mxtree[ed];
            if (st == ed) break;
            if (st & 1) st++;
            if (!(ed & 1)) ed--;
            if (st > ed) break;
            st /= 2;
            ed /= 2;
        }
        if (max1 != 0) {
            d1 = mchk[u[i].chk];
            d2 = mchk[sub[max1]];
            if (d1 != d2) {
                if (ka[d1].size() > ka[d2].size()) {
                    while (ka[d2].size()) {
                        sav = ka[d2].back();
                        ka[d1].push_back(sav);
                        mchk[sav] = d1;
                        ka[d2].pop_back();
                    }
                }
                else {
                    while (ka[d1].size()) {
                        sav = ka[d1].back();
                        ka[d2].push_back(sav);
                        mchk[sav] = d2;
                        ka[d1].pop_back();
                    }
                }
            }
        }
 
        //위
        tmp1 = tmp2;
        tmp2 = u[i].y + m + r;
 
        st = ky + transy[tmp1] - 1;
        ed = ky + transy[tmp2] - 1;
 
        min1 = 0x7fffffff;
        while (1) {
            if (mntree[st] > 0 && min1 > mntree[st]) min1 = mntree[st];
            if (mntree[ed] > 0 && min1 > mntree[ed]) min1 = mntree[ed];
            if (st == ed) break;
            if (st & 1) st++;
            if (!(ed & 1)) ed--;
            if (st > ed) break;
            st /= 2;
            ed /= 2;
        }
        if (min1 != 0x7fffffff) {
            d1 = mchk[u[i].chk];
            d2 = mchk[sub[min1]];
            if (d1 != d2) {
                if (ka[d1].size() > ka[d2].size()) {
                    while (ka[d2].size()) {
                        sav = ka[d2].back();
                        ka[d1].push_back(sav);
                        mchk[sav] = d1;
                        ka[d2].pop_back();
                    }
                }
                else {
                    while (ka[d1].size()) {
                        sav = ka[d1].back();
                        ka[d2].push_back(sav);
                        mchk[sav] = d2;
                        ka[d1].pop_back();
                    }
                }
            }
        }
 
        tmp1 = transy[u[i].y];
        sub[tmp1] = u[i].chk;
 
        tmp1 += (ky - 1);
        mxtree[tmp1] = tmp1 - (ky - 1);
        mntree[tmp1] = tmp1 - (ky - 1);
        mxchange(tmp1, true);
        mnchange(tmp1, true);
    }
 
    d1 = mchk[o[0].chk];
    max1 = 0;
    for (i = 0; i < sn; i++) {
        if (d1 != mchk[o[i].chk]) continue;
        if (o[i].num) {
            sav = o[i].x + o[i].y + m*2;
            if (max1 < sav) max1 = sav;
        }
    }
    printf("%d", max1);
    return 0;
}