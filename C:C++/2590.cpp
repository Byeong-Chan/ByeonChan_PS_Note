#include <cstdio>
int o[8];
int main() {
    int i, n = 6;
    int p, q;
    int ans = 0;
    int realans = 0x7fffffff;
    for(i=1;i<=n;i++) scanf("%d",&o[i]);
    p = q = 0;
    for(i=n;i>=3;i--) {
        if (i == 6) {
            ans += o[i];
            continue;
        }
        if(i == 5) {
            ans += o[i];
            q += o[i] * 11;
            continue;
        }
        if(i == 4) {
            ans += o[i];
            p = o[i] * 5;
            continue;
        }
        if(i == 3) {
            ans += o[i]/4;
            o[i] %= 4;
            if(o[i] == 1) {
                ans++;
                p += 5;
                q += 7;
            }
            else if(o[i] == 2) {
                ans++;
                p += 3;
                q += 6;
            }
            else if(o[i] == 3) {
                ans++;
                p += 1;
                q += 5;
            }
            if(o[2] <= p) {
                p -= o[2];
                o[2] = 0;
            }
        }
    }
    for(i=0;i<=p;i++) {
        int tmpp = p - i, tmpq = q + i * 4;
        
        int tmp1 = o[1] <= tmpq ? 0 : o[1] - tmpq, tmp2 = o[2] <= tmpp ? 0 : o[2] - tmpp;
        int tmpans = ans;
        tmpans += tmp2 / 9;
        tmp2 %= 9;
        if(tmp2 > 0) {
            tmpans++;
            o[1] -= (36 - tmp2 * 4);
            if(o[1] < 0) o[1] = 0;
        }
        tmpans += (tmp1+35) / 36;
        if(realans > tmpans) realans = tmpans;
    }
    printf("%d\n",realans);
    return 0;
}