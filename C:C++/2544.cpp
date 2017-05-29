#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int o[1220][1220];
int chock[1220];
int st;
int ed;
int moth[1220];
int check1[1220];
int check2[1220];
int e = 0;
int _grid[620][620];
queue<int> que;
int r[321], r_size;
int c[321], c_size;
void sub2();
void sub()
{
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=ed;j++) chock[j] = 0;
        chock[i] = 1;
        moth[i] = -1;
        que.push(i);
        st = i;

        sub2();
    }
}
void sub2()
{
    int i;
    int a;
    while(que.size())
    {
        a = que.front();
        que.pop();
        if(a == ed)
        {
            int pos = ed;
            while(pos != st)
            {
                o[moth[pos]][pos] = 0;
                o[pos][moth[pos]] = 1;

                pos = moth[pos];
            }
            e++;
            break;
        }
        else if(a <= n)
        {
            for(i=n+1;i<=ed;i++)
            {
                if(o[a][i] == 1 && chock[i] == 0)
                {
                    chock[i] = 1;
                    moth[i] = a;
                    que.push(i);
                }
            }
        }
        else
        {
            for(i=1;i<=n+1;i++)
            {
                if(i == n+1) i = ed;
                if(o[a][i] == 1 && chock[i] == 0)
                {
                    chock[i] = 1;
                    moth[i] = a;
                    que.push(i);
                }
            }
        }
    }
    while(que.size()) que.pop();
}
int main()
{
    int a;
    int i, j;
    int k;
    int h1, h2;

    scanf("%d %d", &n, &m);
    scanf("%d",&k);
    ed = n + m + 1;

    int x = 1, y = 0, mid;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&_grid[i][j]);
            if(y < _grid[i][j]) y = _grid[i][j];
        }
    }

    while(x < y)
    {
        mid = (x + y) / 2;

        for(i=1;i<=ed;i++)
        {
            for(j=1;j<=ed;j++)
            {
                o[i][j] = 0;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(_grid[i][j] > mid)
                {
                    o[i][j+n] = 1;
                    o[j+n][ed] = 1;
                }
            }
        }

        e = 0;
        sub();

        if(e <= k)
        {
            for(i=1;i<ed;i++) check2[i] = check1[i] = 0;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(o[j+n][i] == 1)
                    {
                        check1[i] = j+n;
                        check1[j+n] = i;
                    }
                }
            }
            r_size = c_size = 0;
            for(i=1;i<=n;i++)
            {
                if(check1[i] != 0)
                {
                    a = check1[i];
                    for(j=1;j<=n;j++)
                    {
                        if(o[j][a] == 1 && check1[j] == 0) break;
                    }
                    if(j <= n)
                    {
                        c[c_size++] = a;
                        check2[a] = 1;
                    }
                    else
                    {
                        for(j=1;j<=m;j++)
                        {
                            if(o[i][j+n] == 1 && check1[j+n] == 0) break;
                        }
                        if(j <= m)
                        {
                            r[r_size++] = i;
                            check2[i] = 1;
                        }
                    }
                }
            }
            h2 = c_size;
            h1 = r_size;
            for(i=0;i<h1;i++)
            {
                que.push(r[i]);
                while(que.size())
                {
                    a = que.front();
                    a = check1[a];
                    que.pop();

                    if(a <= n)
                    {
                        for(j=n+1;j<ed;j++)
                        {
                            if(o[a][j] == 1 && check2[j] == 0 && check1[j] != 0)
                            {
                                que.push(j);
                                check2[j] = 1;
                                c[c_size++] = j;
                            }
                        }
                    }
                    else
                    {
                        for(j=1;j<=n;j++)
                        {
                            if(o[j][a] == 1 && check2[j] == 0 && check1[j] != 0)
                            {
                                que.push(j);
                                check2[j] = 1;
                                r[r_size++] = j;
                            }
                        }
                    }
                }
            }
            for(i=0;i<h2;i++)
            {
                que.push(c[i]);
                while(que.size())
                {
                    a = que.front();
                    a = check1[a];
                    que.pop();

                    if(a <= n)
                    {
                        for(j=n+1;j<ed;j++)
                        {
                            if(o[a][j] == 1 && check2[j] == 0 && check1[j] != 0)
                            {
                                que.push(j);
                                check2[j] = 1;
                                c[c_size++] = j;
                            }
                        }
                    }
                    else
                    {
                        for(j=1;j<=n;j++)
                        {
                            if(o[j][a] == 1 && check2[j] == 0 && check1[j] != 0)
                            {
                                que.push(j);
                                check2[j] = 1;
                                r[r_size++] = j;
                            }
                        }
                    }
                }
            }
            if(r_size + c_size < k)
            {
                for(i=1;i<=n;i++)
                {
                    if(r_size + c_size == e) break;
                    if(check2[i] == 0 && check1[i] != 0 && check2[check1[i]] == 0)
                    {
                        check2[i] = 1;
                        r[r_size++] = i;
                    }
                }
                for(i=1;i<ed;i++)
                {
                    if(r_size + c_size == k) break;
                    if(check2[i] == 0)
                    {
                        check2[i] = 1;
                        if(i <= n) r[r_size++] = i;
                        if(i > n) c[c_size++] = i;
                    }
                }
            }
            y = mid;
        }
        else x = mid + 1;
    }
    std::sort(r, r + r_size);
    if(r_size + c_size < k) {
    	int tmp = k - r_size - c_size, p = 0, t = 0;
    	for(i=1;i<=n;i++) {
    		if(r[p] == i) p++;
    		else {
    			r[r_size++] = i;
    			t++;
    			if(t == tmp) break;
    		}
    	}
		std::sort(r, r + r_size);
    }
    std::sort(c, c + c_size);
    printf("%d",y);
    printf("\n%d",r_size);
    for(i=0;i<r_size;i++)
    {
        printf(" %d",r[i]);
    }
    printf("\n%d",c_size);
    for(i=0;i<c_size;i++)
    {
        printf(" %d",c[i] - n);
    }
    fcloseall();
    return 0;
}