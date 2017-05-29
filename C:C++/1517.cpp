#include <cstdio>
#include <algorithm>
using namespace std;
int o[500001];
int tmp[500001];
long long ans = 0;
void merge(int st, int ed) {
    if (ed - st <= 2) {
        if (o[st] > o[st + 1]) {
            swap(o[st], o[st + 1]);
            ans++;
            return;
        }
        return;
    }
    int mid = (st + ed) >> 1;
 
    merge(st, mid);
    merge(mid, ed);
 
    long long k = 0;
    int x = st, y = mid;
    int h = st;
    int p = 0;
    while (1) {
        if (x == mid && y == ed) break;
        else if (x == mid) tmp[h++] = o[y++];
        else if (y == ed) tmp[h++] = o[x++];
        else {
            if (o[x] > o[y]) {
                k += (mid - x);
                tmp[h++] = o[y++];
            }
            else tmp[h++] = o[x++];
        }
    }
    while (h-- > st) o[h] = tmp[h];
    ans += k;
    return;
}
int main() {
    int i;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &o[i]);
    merge(0, n);
    printf("%lld", ans);
    return 0;
}