#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int nb_floors, width, nb_rounds, exit_floor, exit_pos, nb_total_clones, nb_additional_elevators, nb_elevators;
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();

    unordered_map<int, int> elevatorPos;
    for (int i = 0; i < nb_elevators; i++) {
        int ef, ep; cin >> ef >> ep; cin.ignore();
        elevatorPos[ef] = ep;
    }

    while (1) {
        int clone_floor, clone_pos;
        string direction;
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        if (clone_floor == -1) {
            cout << "WAIT" << endl;
            continue;
        }

        int target;
        if (clone_floor == exit_floor) target = exit_pos;
        else target = elevatorPos[clone_floor];

        if ((direction == "RIGHT" && clone_pos > target) ||
            (direction == "LEFT" && clone_pos < target)) {
            cout << "BLOCK" << endl;
        }
        else {
            cout << "WAIT" << endl;
        }
    }
    return 0;
}

