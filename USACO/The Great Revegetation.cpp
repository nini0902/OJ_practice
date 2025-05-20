#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("revegetate.in");
  ofstream fout("revegetate.out");

  int n, m;
  fin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0, a, b; i < m; i++) {
    fin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> color(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    bool used[5] = {}; // mark if color 1,2,3,4 is used
    for (int g : adj[i]) {
      if (color[g] != 0) used[color[g]] = true; // mark the color of g
    }
    for (int j = 1; j <= 4; j++) {
      if (!used[j]) {
        color[i] = j;
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) fout << color[i];
  fout << '\n';

  return 0;
}
