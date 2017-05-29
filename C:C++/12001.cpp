#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100010;
int ut[maxn], dt[maxn];
vector<int> vertex[maxn];

void add(int t[], int i, int value) {
    for (; i < maxn; i += (i + 1) & -(i + 1))
        t[i] += value;
}

// sum[0..i]
int sum(int t[], int i) {
    int res = 0;
    for (; i >= 0; i -= (i + 1) & -(i + 1))
        res += t[i];
    return res;
}

int find_mid(int t[], int st, int ed, int last) {
    int mid;
    int tmp;
    int tmp2;
    tmp2 = sum(t, last);
    while(st < ed) {
        mid = (st + ed) >> 1;
        tmp = sum(t, mid);
        if(tmp2 - tmp < tmp) ed = mid;
        else st = mid + 1;
    }
    return st - 1;
}

int find_right(int t[], int st, int ed, int last, int cmp) {
    int mid;
    int tmp;
    int tmp2;
    tmp2 = sum(t, last);
    while(st < ed) {
        mid = (st + ed) >> 1;
        tmp = sum(t, mid);
        if(tmp2 - tmp > tmp) tmp = tmp2 - tmp;
        
        if (tmp <= cmp) st = mid + 1;
        else ed = mid;
    }
    return st - 1;
}
int find_left(int t[], int st, int ed, int last, int cmp) {
    int mid;
    int tmp;
    int tmp2;
    tmp2 = sum(t, last);
    while(st < ed) {
        mid = (st + ed) >> 1;
        tmp = sum(t, mid);
        if (tmp2 - tmp > tmp) tmp = tmp2 - tmp;
        
        if (tmp <= cmp) ed = mid;
        else st = mid + 1;
    }
    return st;
}
struct node {
    int x;
    int y;
}o[100010];
int px[100010];
int py[100010];
map<int, int> dx;
map<int, int> dy;

int main() {
    bool sw;
    int i, j;
    int n, m;
    int x, y;
    
    int st, mid, ed;
    int center1, center2;
    
    int first1, last1;
    int first2, last2;
    
    int rx = 0, ry = 0;
    
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d %d",&o[i].x,&o[i].y);
        px[i] = o[i].x;
        py[i] = o[i].y;
    }
    sort(px, px+n);
    sort(py, py+n);
    for(i=0;i<n;i++) {
        if(dx[px[i]] == 0) dx[px[i]] = ++rx;
        if(dy[py[i]] == 0) dy[py[i]] = ++ry;
    }
    for(i=0;i<n;i++) {
        x = dx[o[i].x];
        y = dy[o[i].y];
        vertex[x].push_back(y);
        add(dt, y, 1);
    }
    m = ry+1;
    
    st = 1;
    ed = n+1;
    int h;
    while(st < ed) {
        mid = (st + ed) >> 1;
        sw = false;
        for(i=0;i<=rx;i++) {
            for(j=0;j<vertex[i].size();j++) {
                add(dt, vertex[i][j], -1);
                add(ut, vertex[i][j], 1);
            }
            if (i != 0 && vertex[i].size() == 0) continue;
            
            center1 = find_mid(dt, 1, m + 1, m);
            
            first1 = find_left(dt, 1, center1, m, mid);
            last1 = find_right(dt, center1 + 1, m + 1, m, mid);
            if(first1 == last1) {
                h = sum(dt, first1);
                h = max(h, sum(dt, m) - h);
                if (h > mid) continue;
            }
            
            center2 = find_mid(ut, first1, last1 + 1, m);
            
            first2 = find_left(ut, first1, center2, m, mid);
            last2 = find_right(ut, center2 + 1, last1 + 1, m, mid);
            if(first2 == last2) {
                h = sum(ut, first2);
                h = max(h, sum(ut, m) - h);
                if (h > mid) continue;
            }
            
            sw = true;
        }
        swap(ut, dt);
        if(sw) ed = mid;
        else st = mid + 1;
    }
    printf("%d\n",st);
    return 0;
}