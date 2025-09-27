#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 2 * n + 2; 
    vector<bool> visited(MAX, false);

    queue<pair<int, int>> q; 
    q.push({ 0, 0 });
    visited[0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (x == n) {
            cout << steps << endl;
            break;
        }

        if (x + 1 < MAX && !visited[x + 1]) {
            visited[x + 1] = true;
            q.push({ x + 1, steps + 1 });
        }
        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push({ x - 1, steps + 1 });
        }
        if (x * 2 < MAX && !visited[x * 2]) {
            visited[x * 2] = true;
            q.push({ x * 2, steps + 1 });
        }
    }

