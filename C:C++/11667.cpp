#include <cstdio>
#include <algorithm>
using namespace std;
int dt[210][210][2];
int tmp[210][210][2];
struct node {
    int x;
    int y;
    bool sw;
    bool operator <(const node &a) const {
        if(this->sw == false && a.sw == false) {
            if (this->x != a.x) return this->x < a.x;
            return this->y > a.y;
        }
        else {
            if(this->sw == true && a.sw == true) return this->y - this->x > a.y - a.x;
            else if(this->sw == true && a.sw == false) return true;
            return false;
        }
    }
}o[210];
int main() {
    int k, i, j, n, p;
    bool chk;
    scanf("%d %d",&n,&p);
    for(i=0;i<n;i++) scanf("%d %d",&o[i].x,&o[i].y);
    sort(o,o+n);
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(o[i].y >= o[j].y) o[i].sw = true;
        }
    }
    chk = true;
    for(k=0;k<n;k++) {
        if(o[k].sw == true) continue;
        if (chk) {
            dt[k][1][0] = dt[k][1][1] = o[k].y - o[k].x;
            chk = false;
            continue;
        }
        for(i=0;i<n;i++) {
            for(j=1;j<=p;j++) {
                tmp[i][j][0] = dt[i][j][0];
                tmp[i][j][1] = dt[i][j][1];
                dt[i][j][0] = dt[i][j][1] = 0;
            }
        }
        for(j=1;j<=p;j++) {
            for(i=0;i<n;i++) {
                if (tmp[i][j][0] != 0) {
                    if(o[i].y - o[k].x > 0) {
                        if (dt[i][j][0] < tmp[i][j][0] - tmp[i][j][1] + o[i].y - o[k].x) {
                            dt[i][j][0] = tmp[i][j][0] - tmp[i][j][1] + o[i].y - o[k].x;
                            dt[i][j][1] = o[i].y - o[k].x;
                        }
                    }
                    if (j + 1 <= p) {
                        if (dt[k][j+1][0] < tmp[i][j][0] + o[k].y - o[k].x) {
                            dt[k][j+1][0] = tmp[i][j][0] + o[k].y - o[k].x;
                            dt[k][j+1][1] = o[k].y - o[k].x;
                        }
                    }
                }
            }
        }
    }
    sort(o, o+n);
    int h = 0, sum = 0, ans = 0;
    for(j=p;j>=1;j--) {
        for(i=0;i<n;i++) {
            if(dt[i][j][0] > 0) {
                if (dt[i][j][0] + sum > ans) ans  = dt[i][j][0] + sum;
            }
        }
        if (o[h].sw) {
            sum += o[h].y - o[h].x;
            h++;
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}