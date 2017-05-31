#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500010;
int N;
int gap;
int sa[MAXN];
int satmp[MAXN];
int tmp[MAXN];
int bucket1[MAXN];
int bucket2[MAXN];
int num[MAXN];
int lcp[MAXN];
int Rank[MAXN];
char str[MAXN];
const bool cmp(const int &a, const int &b) {
    if(num[a] != num[b]) return num[a] < num[b];
    return a + gap < N && b + gap < N ? num[a + gap] < num[b + gap] : a > b;
}
void make_sa() {
    int last = N > 128 ? N : 128;
    for(int i=0;i<N;i++) {
        num[i] = str[i];
        bucket1[num[i]]++;
    }
    for(gap = 1 ; ; gap <<= 1) {
        int cnt = 0;
        for(int i = N - gap < 0 ? 0 : N - gap; i < N; i++) sa[cnt++] = i;
        for(int i = 0; i < N - gap; i++) bucket2[num[i+gap]]++;
        for(int i = 1; i < last; i++) bucket2[i] += bucket2[i-1];
        for(int i = 0; i < N - gap; i++) sa[cnt + (--bucket2[num[i+gap]])] = i;
        
        for(int i=1;i<last;i++) bucket1[i] += bucket1[i-1];
        for(int i=N-1;i>=0;i--) satmp[--bucket1[num[sa[i]]]] = sa[i];
        for(int i=0;i<N;i++) sa[i] = satmp[i];
        
        tmp[0] = 0;
        for(int i=1;i<N;i++) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
        for(int i=0;i<N;i++) num[sa[i]] = tmp[i];
        
        int k;
        for(k=1;k<N;k++) if(tmp[k] == tmp[k-1]) break;
        if(k == N) break;
        
        memset(bucket1, 0, sizeof(int) * (last));
        memset(bucket2, 0, sizeof(int) * (last));
        
        for(int i=0;i<N;i++) bucket1[tmp[i]]++;
    }
}
void make_lcp() {
    for(int i=0;i<N;i++) Rank[sa[i]] = i;
    for(int k = 0, len = 0; k < N; lcp[Rank[k++]] = len > 0 ? len-- : 0) {
        for(int i = sa[Rank[k]], j = Rank[k] - 1 >= 0 ? sa[Rank[k] - 1] : N; i + len < N && j + len < N && str[i + len] == str[j + len]; len++);
    }
}
int main() {
    int n;
    scanf("%s",str);
    n = (int)strlen(str);
    N = n;
    make_sa();
    make_lcp();
    for(int i=0;i<N;i++) printf("%d ",sa[i] + 1);
    printf("\n");
    printf("x ");
    for(int i=1;i<N;i++) printf("%d ",lcp[i]);
    printf("\n");
    return 0;
}
