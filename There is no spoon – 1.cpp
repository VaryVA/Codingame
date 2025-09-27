#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width; 
    cin >> width; cin.ignore();
    int height; 
    cin >> height; cin.ignore();

    vector<string> grid;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); 
        grid.push_back(line);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == '0') {
                int x2 = -1, y2 = -1;
                int x3 = -1, y3 = -1;

                for (int nx = x + 1; nx < width; nx++) {
                    if (grid[y][nx] == '0') {
                        x2 = nx;
                        y2 = y;
                        break;
                    }
                }

                for (int ny = y + 1; ny < height; ny++) {
                    if (grid[ny][x] == '0') {
                        x3 = x;
                        y3 = ny;
                        break;
                    }
                }

                cout << x << " " << y << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            }
        }
    }
}
