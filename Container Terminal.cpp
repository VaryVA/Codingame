#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        vector<char> stacks; // верхушки стопок

        for (char c : line) {
            bool placed = false;
            // ищем первую стопку, верх которой >= текущей буквы
            for (size_t j = 0; j < stacks.size(); ++j) {
                if (stacks[j] >= c) {
                    stacks[j] = c; // кладём сюда (обновляем верх)
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                stacks.push_back(c); // создаём новую стопку
            }
        }

        // ответ для этой строки
        cout << stacks.size() << endl;
    }
}
