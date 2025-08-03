#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
int target;

bool dls(int node, int depth) {
    if (node == target) return true;
    if (depth == 0) return false;

    for (int child : adj[node]) {
        if (dls(child, depth - 1))
            return true;
    }
    return false;
}

bool ids(int start, int maxDepth) {
    for (int depth = 1; depth <= maxDepth; depth++) {
        cout << "Depth " << depth << ": ";
        if (dls(start, depth)) {
            cout << "Found\n";
            return true;
        }
        else {
            cout << "Not found\n";
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Build demo graph: A-F
    adj.clear();
    adj['A' - 'A'].push_back('B' - 'A');
    adj['A' - 'A'].push_back('C' - 'A');
    adj['B' - 'A'].push_back('D' - 'A');
    adj['C' - 'A'].push_back('D' - 'A');
    adj['C' - 'A'].push_back('E' - 'A');
    adj['D' - 'A'].push_back('F' - 'A');
    adj['E' - 'A'].push_back('F' - 'A');

    int start = 'A' - 'A';
    target = 'F' - 'A';

    cout << "Start: A, Target: F, Max Depth: 3\n\n";

    bool res = ids(start, 3);

    cout << "\nResult: " << (res ? "YES" : "NO") << "\n";

    return 0;
}
