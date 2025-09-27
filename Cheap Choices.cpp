#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int c;
    cin >> c; cin.ignore();
    int p;
    cin >> p; cin.ignore();

    vector<string> items;
    for (int i = 0; i < c; i++) {
        string item;
        getline(cin, item);
        items.push_back(item);
    }

    for (int i = 0; i < p; i++) {
        string order;
        getline(cin, order);
        istringstream iss(order);
        string reqCategory, reqSize;
        iss >> reqCategory >> reqSize;

        int minPrice = -1;
        int minIndex = -1;

        for (int j = 0; j < items.size(); j++) {
            if (items[j] == "") continue; 
            istringstream itemStream(items[j]);
            string category, size;
            int price;
            itemStream >> category >> size >> price;

            if (category == reqCategory && size == reqSize) {
                if (minPrice == -1 || price < minPrice) {
                    minPrice = price;
                    minIndex = j;
                }
            }
        }

        if (minIndex == -1) {
            cout << "NONE" << endl;
        }
        else {
            cout << minPrice << endl;
            items[minIndex] = ""; 
        }
    }
}

