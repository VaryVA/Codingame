#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int maxSoFar = values[0];   
    int maxLoss = 0;            

    for (int i = 1; i < n; i++) {
        int currentLoss = values[i] - maxSoFar;
        maxLoss = min(maxLoss, currentLoss); 
        maxSoFar = max(maxSoFar, values[i]); 
    }

    cout << maxLoss << endl;
}

