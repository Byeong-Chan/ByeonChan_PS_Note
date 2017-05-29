#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
    int len;
    int sufflink;
    int nxt[26];
}ptree[300010];

char o[300010];
long long table[300010];
int suff;
int num = 2;

void init_tree() {
    ptree[1].len = -1;
    ptree[1].sufflink = 1;
    ptree[2].len = 0;
    ptree[2].sufflink = 1;
}
void add_node(int pos, char let) {
    int cur = suff;
    int curlen;
    while(1) {
        curlen = ptree[cur].len;
        if (pos - curlen - 1 >= 0 && o[pos-curlen-1] == let) {
            break;
        }
        cur = ptree[cur].sufflink;
    }
    if (ptree[cur].nxt[let - 'a'] != 0) {
        suff = ptree[cur].nxt[let - 'a'];
        table[suff]++;
        return;
    }
    ptree[cur].nxt[let - 'a'] = suff = ++num;
    ptree[num].len = ptree[cur].len + 2;
    table[num]++;
    
    if (ptree[num].len == 1) {
        ptree[num].sufflink = 2;
        return;
    }
    
    while (1) {
        cur = ptree[cur].sufflink;
        curlen = ptree[cur].len;
        if (pos - curlen - 1 >= 0 && o[pos-curlen-1] == let) {
            ptree[num].sufflink = ptree[cur].nxt[let - 'a'];
            break;
        }
    }
}
long long dfs(int d) {
    int pos;
    long long tmp1 = 0;
    for(int i=0;i<26;i++) {
        if (ptree[d].nxt[i] != 0) {
            pos = ptree[d].nxt[i];
            tmp1 = max(tmp1, dfs(pos));
        }
    }
    long long tmp2 = table[d] * ptree[d].len;
    return max(tmp1, tmp2);
}
int main() {
    int i, n;
    init_tree();
    scanf("%s",o);
    suff = 2;
    n = (int)strlen(o);
    for (i=0;i<n;i++) add_node(i, o[i]);
    for (i=num;i>=1;i--) table[ptree[i].sufflink] += table[i];
    printf("%lld\n",max(dfs(1),dfs(2)));
    return 0;
}