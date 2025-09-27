#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();

    vector<string> diagram;
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        diagram.push_back(line);
    }

    string topLine = diagram[0];
    vector<char> topLabels;
    for (int i = 0; i < topLine.length(); i++) {
        if (topLine[i] != ' ') {
            topLabels.push_back(topLine[i]);
        }
    }

    string bottomLine = diagram[h - 1];
    vector<char> bottomLabels;
    for (int i = 0; i < bottomLine.length(); i++) {
        if (bottomLine[i] != ' ') {
            bottomLabels.push_back(bottomLine[i]);
        }
    }

    for (int topIndex = 0; topIndex < topLabels.size(); topIndex++) {
        int currentCol = topIndex * 3; 
        int currentRow = 1; 

        while (currentRow < h - 1) {
            if (currentCol > 0 && diagram[currentRow][currentCol - 1] == '-') {
                currentCol -= 3;
            }
            else if (currentCol < w - 1 && diagram[currentRow][currentCol + 1] == '-') {
                currentCol += 3;
            }
            currentRow++;
        }

        int bottomIndex = currentCol / 3;

        cout << topLabels[topIndex] << bottomLabels[bottomIndex] << endl;
    }

    return 0;
}
