#include <cstdio>
#define Trap 9
int q[10][2];
bool finalstate[10] = {0, 0, 0, 0, 0, 1, 1, 1, 0, 0};
int main() {
    int t;
    int state;
    char k;
    //Trap
    q[9][0] = Trap;
    q[9][1] = Trap;
    
    //State
    q[0][0] = 1;
    q[0][1] = 2;
    q[1][0] = Trap;
    q[1][1] = 7;
    q[2][0] = 3;
    q[2][1] = Trap;
    q[3][0] = 4;
    q[3][1] = Trap;
    q[4][0] = 4;
    q[4][1] = 5;
    q[5][0] = 1;
    q[5][1] = 6;
    q[6][0] = 8;
    q[6][1] = 6;
    q[7][0] = 1;
    q[7][1] = 2;
    q[8][0] = 4;
    q[8][1] = 7;
    
    scanf("%d%*c",&t);
    while(t--) {
        state = 0;
        while (scanf("%c",&k) == 1) {
            if (k != '0' && k != '1') break;
            state = q[state][k - '0'];
            k = 0;
        }
        if (finalstate[state]) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
    
}