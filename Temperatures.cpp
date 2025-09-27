#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    if (n == 0) {
        cout << 0 << endl;
        return 0; 
    }

    int closest;
    cin >> closest; 

    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;

        if (abs(t) < abs(closest) || (abs(t) == abs(closest) && t > closest)) {
            closest = t;
        }
    }

    cout << closest << endl;

 
}
