#include <cstdio>
class Trie {
public:
    Trie() {
        nxt[0] = nxt[1] = NULL;
    }
    void make_trie(int state, long long val) {
        if(state == 0) {
            return;
        }
        int nxtstate = state - 1;
        bool p = (val & ((long long)1 << (nxtstate))) ? true : false;
        if(nxt[p] == NULL) nxt[p] = new Trie();
        nxt[p]->make_trie(nxtstate, val);
    }
    long long find_max_trie(int state, long long val, long long sum) {
        if(state == 0) return sum;
        
        int nxtstate = state - 1;
        if(val & ((long long)1 << nxtstate)) {
            if(nxt[0] != NULL) return nxt[0]->find_max_trie(nxtstate, val, sum);
            else return nxt[1]->find_max_trie(nxtstate, val, sum + ((long long)1 << nxtstate));
        }
        else {
            if(nxt[1] != NULL) return nxt[1]->find_max_trie(nxtstate, val, sum + ((long long)1 << nxtstate));
            else return nxt[0]->find_max_trie(nxtstate, val, sum);
        }
    }
    void clear() {
        if(nxt[0] != NULL) {
            nxt[0]->clear();
            delete nxt[0];
            nxt[0] = NULL;
        }
        if(nxt[1] != NULL) {
            nxt[1]->clear();
            delete nxt[1];
            nxt[1] = NULL;
        }
    }
private:
    Trie *nxt[2];
};
int main() {
    int i, n;
    int t;
    long long sum = 0, x;
    long long ans = 0;
    Trie *trie = new Trie();
    scanf("%d",&t);
    while(t--) {
        sum = ans = 0;
        trie->make_trie(32, 0);
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%lld",&x);
            sum ^= x;
            long long tmp = sum ^ trie->find_max_trie(32, sum, 0);
            if(tmp > ans) ans = tmp;
            trie->make_trie(32, sum);
        }
        printf("%lld\n",ans);
        trie->clear();
    }
    return 0;
}