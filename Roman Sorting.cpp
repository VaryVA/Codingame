#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> roman(n); 
    vector<int> nums(n);    

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        int x = nums[i];
        string s = "";

        while (x >= 1000) { s += "M"; x -= 1000; }
        if (x >= 900) { s += "CM"; x -= 900; }
        if (x >= 500) { s += "D"; x -= 500; }
        if (x >= 400) { s += "CD"; x -= 400; }
        while (x >= 100) { s += "C"; x -= 100; }
        if (x >= 90) { s += "XC"; x -= 90; }
        if (x >= 50) { s += "L"; x -= 50; }
        if (x >= 40) { s += "XL"; x -= 40; }
        while (x >= 10) { s += "X"; x -= 10; }
        if (x == 9) { s += "IX"; x -= 9; }
        if (x >= 5) { s += "V"; x -= 5; }
        if (x == 4) { s += "IV"; x -= 4; }
        while (x >= 1) { s += "I"; x -= 1; }

        roman[i] = s;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (roman[i] > roman[j]) {
                string tempS = roman[i];
                roman[i] = roman[j];
                roman[j] = tempS;

                int tempN = nums[i];
                nums[i] = nums[j];
                nums[j] = tempN;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    cout << endl;
}

