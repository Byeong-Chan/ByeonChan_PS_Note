#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    int ans = 0, cnt = 0;
    stack<int> stk;
    string str;
    cin >> str;
    for(auto i : str) {
        cnt++;
        if(i == '(') stk.push(cnt);
        else {
            long tmp = cnt;
            
            if(!(tmp - stk.top() - 1)) ans += stk.size() - 1;
            else ans++;
            stk.pop();
        }
    }
    printf("%d\n",ans);
    return 0;
}