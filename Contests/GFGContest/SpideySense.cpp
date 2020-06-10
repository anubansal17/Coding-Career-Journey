//https://practice.geeksforgeeks.org/contest-problem/spidey-sense/0
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) \
    for (int i = (int)a; i <= (int)b; i++) // a to b, and variable i is local!
#define TR(c, it) \
    for (auto it = (c).begin(); it != (c).end(); it++)

#define s(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define set0(a) memset(a, 0, sizeof(a))
#define setdp(a) memset(a, -1, sizeof(a))
#define INF 20000000000000000LL
#define MOD 1000000007

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

queue<pair<int, pii>> q;
int vis[55][55];
int n, m;

bool isValid(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;

    return false;
}

int main()
{
    int t, dist;
    char ch;
    pair<int, pii> cur;
    pii pos;

    cin >> t;

    while (t--)
    {
        set0(vis);
        while (!q.empty())
            q.pop();

        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;

                if (ch == 'B')
                {
                    q.push(mp(1, mp(i, j)));
                }
                else if (ch == 'W')
                {
                    vis[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            dist = cur.fi;
            pos = cur.se;

            if (vis[pos.fi][pos.se] != 0)
                continue;

            vis[pos.fi][pos.se] = dist;

            for (int i = 0; i < 4; i++)
            {
                if (isValid(pos.fi + dx[i], pos.se + dy[i]) && !vis[pos.fi + dx[i]][pos.se + dy[i]])
                    q.push(mp(dist + 1, mp(pos.fi + dx[i], pos.se + dy[i])));
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << (vis[i][j] == -1 ? -1 : vis[i][j] - 1) << " ";
            cout << endl;
        }
    }

    return 0;
}
