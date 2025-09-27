#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    string t;
    getline(cin, t);

    transform(t.begin(), t.end(), t.begin(), ::toupper);

    vector<string> rows(h);
    for (int i = 0; i < h; i++) {
        getline(cin, rows[i]);
    }

    for (int i = 0; i < h; i++) {
        string line;
        for (char c : t) {
            int index;
            if (c >= 'A' && c <= 'Z') {
                index = c - 'A';
            }
            else {
                index = 26; // '?'
            }
            line += rows[i].substr(index * l, l);
        }
        cout << line << endl;
    }
}

