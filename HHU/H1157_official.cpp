 #include <bits/stdc++.h>
 using namespace std;
 const int N = 110;
 const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
 const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
 int n, m, T, a[N][N], b[N][N];
 inline bool can(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
 }
 int check(int x, int y) {
    if (a[x][y] == -1) return -1;
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i], ty = y + dy[i];
    if (can(tx, ty) && a[tx][ty] == -1) ++cnt;
    }
    return cnt;
 }
int main() {
    cin >> n >> m >> T;
    for (int i = 1; i <= T; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = -1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; j++)
            b[i][j] = check(i, j);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << b[i][m] << endl;
    }
    return 0;
 }