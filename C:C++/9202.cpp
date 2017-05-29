#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int val;
    node *nxt[26];
};

char str[300010][40];
char o[6][6];
char inp[40];
int chk[300010];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
bool visit[6][6];
vector<int> pos;

void make_node(int m, char *gstr, node *here) {
    for(;gstr[m] != '\0';m++) {
        if(here->nxt[gstr[m] - 'A'] == NULL) here->nxt[gstr[m] - 'A'] = (node *)calloc(1, sizeof(node));
        here = here->nxt[gstr[m] - 'A'];
    }
    if(here->val == 0) {
        here->val = (int)pos.size() + 1;
        pos.push_back(0);
    }
    pos[here->val - 1]++;
}

void find(int x, int y, int m, node *here, int &score, int &cnt, int &max1, char *ans) {
    if(here->val > 0 && pos[here->val-1] > chk[here->val]) {
        if (m == 3 || m == 4) score += 1;
        if (m == 5) score += 2;
        if (m == 6) score += 3;
        if (m == 7) score += 5;
        if (m == 8) score += 11;
        
        inp[m] = 0;
        if(m > max1) {
            max1 = m;
            strcpy(ans, inp);
        }
        else if(max1 == m && strcmp(ans, inp) > 0) strcpy(ans, inp);
        
        chk[here->val]++;
        cnt++;
    }
    for(int i=0;i<8;i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 0 || ty < 0 || tx >= 4 || ty >= 4) continue;
        if(visit[tx][ty]) continue;
        if(here->nxt[o[tx][ty]-'A'] == NULL) continue;
        inp[m] = o[tx][ty];
        visit[tx][ty] = true;
        find(tx, ty, m+1, here->nxt[o[tx][ty]-'A'], score, cnt, max1, ans);
        visit[tx][ty] = false;
    }
}

void clear(node *here) {
    for(int i = 0; i < 26; i++) if(here->nxt[i] != NULL) clear(here->nxt[i]);
    free(here);
}


int main() {
    int k, i, j;
    int n, m;
    int max1, score, cnt;
    char ans[40] = {0,};
    node *trie = (node *)calloc(1, sizeof(node));
    //freopen("/Users/SeoByeongChan/Desktop/practice/studyhard2/studyhard2/input.txt","rt",stdin);
    //freopen("/Users/SeoByeongChan/Desktop/practice/studyhard2/studyhard2/output.txt","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",str[i]);
        make_node(0, str[i], trie);
    }
    scanf("%d",&m);
    for(k=0;k<m;k++) {
        for(i=0;i<4;i++) scanf("%s",o[i]);
        
        score = 0;
        cnt = 0;
        max1 = 0;
        for(i=0;i<4;i++) for(j=0;j<4;j++) if(trie->nxt[o[i][j]-'A'] != NULL) {visit[i][j] = true; inp[0] = o[i][j]; find(i, j, 1, trie->nxt[o[i][j]-'A'], score, cnt, max1, ans); visit[i][j] = false;}
        
        ans[max1] = 0;
        printf("%d %s %d\n",score,ans,cnt);
        for(i=1;i<=pos.size();i++) chk[i] = 0;
    }
    clear(trie);
    
    return 0;
}