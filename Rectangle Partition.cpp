#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w, h, count_x, count_y;
    cin >> w >> h >> count_x >> count_y;

    vector<int> X(count_x + 2), Y(count_y + 2);
    X[0] = 0;
    for (int i = 1; i <= count_x; i++) cin >> X[i];
    X[count_x + 1] = w;

    Y[0] = 0;
    for (int i = 1; i <= count_y; i++) cin >> Y[i];
    Y[count_y + 1] = h;

    int maxLen = max(w, h);
    vector<long long> freqX(maxLen + 1, 0), freqY(maxLen + 1, 0);

    for (int i = 0; i < (int)X.size(); i++) {
        for (int j = i + 1; j < (int)X.size(); j++) {
            freqX[X[j] - X[i]]++;
        }
    }

    for (int i = 0; i < (int)Y.size(); i++) {
        for (int j = i + 1; j < (int)Y.size(); j++) {
            freqY[Y[j] - Y[i]]++;
        }
    }

    long long result = 0;
    for (int len = 1; len <= min(w, h); len++) {
        result += freqX[len] * freqY[len];
    }

    cout << result << endl;
}
