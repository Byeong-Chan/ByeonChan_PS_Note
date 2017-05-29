#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
public:
    static int cnt;
    Trie() {
        val = 0;
        memset(nxt, NULL, sizeof(nxt));
    }
    ~Trie() {
        for(int i = 0; i < 52; i++) {
            if(this->nxt[i] == NULL) continue;
            delete this->nxt[i];
        }
    }
    
    Trie* *getNxt(char a) {
        if(a <= 'Z') a -= 65;
        else a = a - 97 + 26;
        
        return nxt + a;
    }
    
    // 트라이를 만들고 난 뒤 생긴 번째수를 반환
    int makeTrie(const char *k) {
        if(*k == '\0') {
            this->val = ++cnt;
            return cnt;
        }
        Trie* *tmp = getNxt(*k);
        if(*tmp == NULL) *tmp = new Trie();
        return (*tmp)->makeTrie(k+1);
    }
    
    //문자열이 있는지 확인, 없으면 생성, toggle이 1일때는 검사용, 이때 없으면 -1을 반환
    int getTrie(const char *k, bool toggle = false) {
        if(*k == '\0') {
            if(toggle) {
                if(val == 0) return -1;
                else return val;
            }
            else {
                if(val == 0) return val = ++cnt;
                else return val;
            }
        }
        Trie* *tmp = getNxt(*k);
        if(*tmp == NULL) {
            if(toggle) return -1;
            else {
                *tmp = new Trie();
                return (*tmp)->makeTrie(k+1);
            }
        }
        else return (*tmp)->getTrie(k+1, toggle);
    }
    
    void clear() {
        for(int i = 0; i < 52; i++) {
            if(this->nxt[i] == NULL) continue;
            this->nxt[i]->clear();
            
            delete this->nxt[i];
            //this->nxt[i] = NULL;
        }
    }
private:
    int val = 0;
    Trie* nxt[52];
};

int Trie::cnt = 0;

class UnionFind {
public:
    UnionFind() : N(0) {}
    UnionFind(int iN) : N(iN){
        parent.resize(iN+1);
        Rank.resize(iN+1);
        cnt.resize(iN+1);
        for(int i=1;i<=iN;i++) {
            parent[i] = i;
            Rank[i] = 1;
            cnt[i] = 1;
        }
    }
    ~UnionFind() {
        cnt.clear();
        parent.clear();
        Rank.clear();
    }
    int getCnt(int p) {
        p = find(p);
        return cnt[p];
    }
    int find(int p) {
        if(p == parent[p]) return p;
        else return find(parent[p]);
    }
    void uni(int p, int q) {
        p = find(p);
        q = find(q);
        
        if(p == q) return;
        if(Rank[p] < Rank[q]) parent[p] = q, cnt[q] += cnt[p];
        else if(Rank[p] > Rank[q]) parent[q] = p, cnt[p] += cnt[q];
        else Rank[p] = Rank[p] + 1, parent[q] = p, cnt[p] += cnt[q];
    }
    void clear() {
        cnt.clear();
        parent.clear();
        Rank.clear();
    }
private:
    const int N;
    vector<int> cnt;
    vector<int> parent;
    vector<int> Rank;
};

int main() {
    int i, n, t;
    int x, y;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d",&n);
        
        char o[23] = {0,}, u[23] = {0,};
        Trie root;
        UnionFind network(n<<1);
        Trie::cnt = 0;
        
        for(i=0;i<n;i++) {
            scanf("%s %s", o, u);
            x = root.getTrie(o);
            y = root.getTrie(u);
            network.uni(x, y);
            printf("%d\n",network.getCnt(x));
        }
    }
    
    return 0;
}