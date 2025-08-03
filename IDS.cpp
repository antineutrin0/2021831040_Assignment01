#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
char target;

bool dls(char node, int depth) {
    if (node == target) return true;
    if (depth == 0) return false;

    for (char child : adj[node]) {
        if (dls(child, depth - 1))
            return true;
    }
    return false;
}

bool ids(char start, int maxDepth) {
    for (int depth = 1; depth <= maxDepth; depth++) {
        cout << "Depth " << depth << ": ";
        if (dls(start, depth)) {
            cout << "Found\n";
            return true;
        } else {
            cout << "Not found\n";
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Build demo graph using characters directly
    adj.clear();
    adj['A'].push_back('B');
    adj['A'].push_back('C');
    adj['B'].push_back('D');
    adj['C'].push_back('D');
    adj['C'].push_back('E');
    adj['D'].push_back('F');
    adj['E'].push_back('F');

    char start = 'A';
    target = 'F';

    cout << "Start: " << start << ", Target: " << target << ", Max Depth: 3\n\n";

    bool res = ids(start, 3);

    cout << "\nResult: " << (res ? "YES" : "NO") << "\n";

    return 0;
}
