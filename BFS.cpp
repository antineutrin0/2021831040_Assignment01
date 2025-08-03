#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;
  level[1] = 0;
  parent[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        level[v] = level[u] + 1;
        parent[v] = u;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << level[i] << " ";
  cout << "\n";
  for (int i = 1; i <= n; i++) cout << parent[i] << " ";
  cout << "\n";

  return 0;
}
