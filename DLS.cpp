#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
char target;

bool dls(char node, int depth) {
    if (node == target)
        return true;
    if (depth <= 0)
        return false;

    for (char child : adj[node]) {
        if (dls(child, depth - 1))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    adj['A'].push_back('B');
    adj['A'].push_back('C');
    adj['B'].push_back('D');
    adj['C'].push_back('D');
    adj['C'].push_back('E');
    adj['D'].push_back('F');
    adj['E'].push_back('F');

    char src = 'A';
    target = 'F';
    int maxDepth = 3;

    if (dls(src, maxDepth))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
