#include <cstdio>
#include <vector>
using namespace std;

const int bufsize = 1 << 16 ;
int bufL1 = 0 , nowL1 = 0 , bufL2 = 0 ;
char buf1[ bufsize ] , buf2[ bufsize ] ;

inline char next_char() {
    if( nowL1 == bufL1 ) {
        bufL1 = fread( buf1 , sizeof( char ) , bufsize , stdin ) ;
        if( bufL1 == 0 ) { return 0; }
        nowL1 = 0 ;
    }
    return buf1[ nowL1++ ] ;
}

inline int next_int() {
    char c ;
    do {
        c = next_char() ;
    } while( c < '-' ) ;
    
    int val = 0 ;
    if( c == '-' ) {
        for( c = next_char() ; c >= '0' ; c = next_char() ) {
            val = val * 10 + ( c - '0' ) ;
        }
        return - val ;
    }
    else {
        for( ; c >= '0' ; c = next_char() ) {
            val = val * 10 + ( c - '0' ) ;
        }
        return val ;
        
    }
}

inline void write_flush() {
    fwrite( buf2 , sizeof( char ) , bufL2 , stdout ) ;
    bufL2 = 0 ;
}

void write_char( char c ) {
    buf2[ bufL2++ ] = c ;
    if( bufL2 == bufsize ) {
        write_flush() ;
    }
}

void write_int( int n ) {
    if( n >= 10 ) {
        write_int( n / 10 ) ;
    }
    write_char( '0' + n % 10 ) ;
}

int main() {
    int i, n;
    int l, r, mid;
    n = next_int();
    vector<int> dp(n+1, 0x7fffffff), pre(n+1), now(n+1), x(n+1), ans;
    dp[0] = -0x7fffffff;
    now[0] = 0;
    for(i=1;i<=n;i++) {
        x[i] = next_int();
        l = 0;
        r = n;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(dp[mid] <= x[i]) l = mid + 1;
            else r = mid - 1;
        }
        if(x[i] == dp[l-1]) continue;
        dp[l] = x[i];
        now[l] = i;
        pre[i] = now[l-1];
    }
    for(i=n;i>=1;i--) if(dp[i] != 0x7fffffff) break;
    write_int(i);
    write_char('\n');
    for(i=now[i];i>0;i=pre[i]) ans.push_back(x[i]);
    while(ans.size()) {
        if(ans.back() < 0) {
            write_char('-');
            write_int(-ans.back());
        }
        else write_int(ans.back());
        write_char(' ');
        ans.pop_back();
    }
    write_char('\n');
    if(bufL2 > 0) write_flush();
    return 0;
}