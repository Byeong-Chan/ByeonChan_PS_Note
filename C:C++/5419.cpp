#include <cstdio>

int N;
int dx[100010];
int sum[1000010];
struct bung {
    int x;
    int y;
    bool operator < (const bung &a) const {
        if(y != a.y) return y > a.y;
        else return x < a.x;
    }
}o[100010];

void init(int n) {
    N = n + 1;
    for(int i=0;i<=N;i++) sum[i] = 0;
}
void add(int i, int val) {
    while(i <= N) {
        sum[i] += val;
        i += (i & (-i));
    }
}

int find_pos(int st, int ed, int val) {
    int mid;
    while(st < ed) {
        mid = (st+ed) >> 1;
        if(dx[mid] >= val) ed = mid;
        else st = mid + 1;
    }
    return st + 1;
}

int query(int i) {
    int ans = 0;
    while(i) {
        ans += sum[i];
        i -= (i & (-i));
    }
    return ans;
}

int tmpA[100010];
bung tmpS[100010];
void swapA(int &x, int &y) {
    int pp = x;
    x = y;
    y = pp;
}
void swapS(bung &x, bung &y) {
    bung pp = x;
    x = y;
    y = pp;
}
void sortA(int arr[], int st, int ed) {
    if(ed - st == 2) {
        if(arr[st+1] < arr[st]) swapA(arr[st], arr[st+1]);
        return;
    }
    if(ed - st == 1) return;
    
    int mid = (st + ed) >> 1;
    sortA(arr, st, mid);
    sortA(arr, mid, ed);
    int l = st, r = mid, cnt = 0;
    while(l < mid || r < ed) {
        if(l == mid) tmpA[st+cnt++] = arr[r++];
        else if(r == ed) tmpA[st+cnt++] = arr[l++];
        else if(arr[l] < arr[r]) tmpA[st+cnt++] = arr[l++];
        else tmpA[st+cnt++] = arr[r++];
    }
    for(int i=st;i<ed;i++) arr[i] = tmpA[i];
}
void sortS(bung arr[], int st, int ed) {
    if(ed - st == 2) {
        if(arr[st+1] < arr[st]) swapS(arr[st], arr[st+1]);
        return;
    }
    if(ed - st == 1) return;
    
    int mid = (st + ed) >> 1;
    sortS(arr, st, mid);
    sortS(arr, mid, ed);
    int l = st, r = mid, cnt = 0;
    while(l < mid || r < ed) {
        if(l == mid) tmpS[st+cnt++] = arr[r++];
        else if(r == ed) tmpS[st+cnt++] = arr[l++];
        else if(arr[l] < arr[r]) tmpS[st+cnt++] = arr[l++];
        else tmpS[st+cnt++] = arr[r++];
    }
    for(int i=st;i<ed;i++) arr[i] = tmpS[i];
}

int main() {
    int i, n, m;
    int t;
    int cut;
    long long ans;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%d %d",&o[i].x,&o[i].y);
            dx[i] = o[i].x;
        }
        sortA(dx, 0, n);
        sortS(o, 0, n);
        cut = 0;
        m = n;
        for(i=1;i<n;i++) {
            if(dx[i] == dx[i-1]) cut++;
            dx[i-cut] = dx[i];
        }
        m -= cut;
        
        init(m);
        ans = 0;
        for(i=0;i<n;i++) {
            int tmp = find_pos(0, m - 1, o[i].x);
            ans += query(tmp);
            add(tmp, 1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}