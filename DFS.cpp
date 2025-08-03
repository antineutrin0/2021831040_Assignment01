#include <bits/stdc++.h>
using namespace std;

const int N = 26;

vector<int> g[N];
bool vis[N];
vector<char> comp;

void dfs(int u) {
  vis[u] = true;
  comp.push_back(char('A' + u));

  for (int v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int m = 7;

  vector<pair<char, char>> edges = {
    {'A','B'}, {'B','C'},
    {'D','E'},
    {'F','G'}, {'G','H'},
    {'I','J'}, {'J','K'}
  };

  for (auto [a, b] : edges) {
    int u = a - 'A';
    int v = b - 'A';
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int cnt = 0;

  for (int u = 0; u < N; u++) {
    if (!g[u].empty() && !vis[u]) {
      comp.clear();
      dfs(u);
      cnt++;

      cout << "Comp " << cnt << ": ";
      for (char ch : comp) cout << ch << " ";
      cout << "\n";
    }
  }

  cout << "Total: " << cnt << "\n";
}
