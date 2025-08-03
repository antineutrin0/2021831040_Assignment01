#include <bits/stdc++.h>
using namespace std;

const int N = 26;

vector<int> g[N];
bool vis[N];
int lvl[N];
int par[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int m = 6;

  vector<pair<char, char>> edges = {
    {'A','B'},
    {'A','C'},
    {'B','D'},
    {'C','E'},
    {'E','F'},
    {'D','F'}
  };

  for (auto [a, b] : edges) {
    int u = a - 'A';
    int v = b - 'A';
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  int src = 'A' - 'A';
  q.push(src);

  vis[src] = true;
  lvl[src] = 0;
  par[src] = -1;

  cout << "Visited Flow:\n";

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    cout << char('A' + u) << " -> ";

    for (int v : g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        lvl[v] = lvl[u] + 1;
        par[v] = u;
        q.push(v);
      }
    }
  }

  cout << "END\n\n";

  cout << "Level:\n";
  for (int i = 0; i < N; i++) {
    if (vis[i]) {
      cout << char('A' + i) << ": " << lvl[i] << "\n";
    }
  }

  cout << "\nParent:\n";
  for (int i = 0; i < N; i++) {
    if (vis[i]) {
      cout << char('A' + i) << ": ";
      if (par[i] == -1) cout << "None";
      else cout << char('A' + par[i]);
      cout << "\n";
    }
  }

  return 0;
}
