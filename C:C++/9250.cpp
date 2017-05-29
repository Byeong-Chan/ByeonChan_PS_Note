#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    bool val;
    node *nxt[26];
    node *fail;
};

struct makef {
    node *i;
    node *j;
    makef() {}
    makef(node *ii, node *ij) {
        i = ii;
        j = ij;
    }
};

queue<makef> q;

char o[110];
char s[10010];

void make_trie(char *gstr, node *here) {
    int i;
    int tmp;
    for(i=0; gstr[i] != '\0'; i++) {
        tmp = gstr[i] - 'a';
        if(here->nxt[tmp] == NULL) here->nxt[tmp] = (node *)calloc(1, sizeof(node));
        here = here->nxt[tmp];
    }
    here->val = true;
}

void make_fail(node *trie, node *negative) {
    q.push(makef(negative, trie));
    trie->fail = negative;
    
    for(int i=0;i<26;i++) negative->nxt[i] = trie;

    while(q.size()) {
        makef here = q.front(), tmp;
        q.pop();
        for(int k=0;k<26;k++) {
            if(here.j->nxt[k] == NULL) continue;
            tmp = here;
            while(tmp.i->nxt[k] == NULL) tmp.i = tmp.i->fail;
            
            tmp.i = tmp.i->nxt[k];
            tmp.j = tmp.j->nxt[k];
            
            tmp.j->fail = tmp.i;
            
            if(tmp.i->val == true) tmp.j->val = true;
            q.push(tmp);
        }
    }
}

int main() {
    int i, j, n, m;
    int p;
    bool sw;
    node *trie = (node *)calloc(1, sizeof(node));
    node *negative = (node *)calloc(1, sizeof(node));
    node *here;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",o);
        make_trie(o, trie);
    }
    make_fail(trie, negative);
    scanf("%d",&m);
    while(m--) {
        scanf("%s",s);
        here = trie;
        sw = false;
        for(j = 0; s[j] != '\0'; j++) {
            p = s[j] - 'a';
            while(here->nxt[p] == NULL) here = here->fail;
            here = here->nxt[p];
            if(here->val) sw = true;
        }
        printf("%s\n",sw ? "YES" : "NO");
    }
    return 0;
}