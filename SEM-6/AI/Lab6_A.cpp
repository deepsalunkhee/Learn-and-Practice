#include <iostream>
using namespace std;

int side_a[2] = {3, 3};
int side_b[2] = {0, 0};
bool is_boat_on_side_a = true;

void print_state() {
    cout << endl;
    cout << "   Side A            |   Side B" << endl;
    cout << "   Missionaries: " << side_a[0] << "   |   Missionaries: " << side_b[0] << endl;
    cout << "   Cannibals: " << side_a[1] << "      |   Cannibals: " << side_b[1] << endl;

    if (is_boat_on_side_a) {
        cout << "   Boat here         | " << endl;
    } else {
        cout << "                     |   Boat here" << endl;
    }

    cout << endl;
}

bool is_goal() {
    return side_b[0] == 3 && side_b[1] == 3 && !is_boat_on_side_a;
}

void handle_a_to_b() {
    int missionaries, cannibals;

    while (true) {
        cout << "Enter number of missionaries travelling to side b: ";
        cin >> missionaries;
        cout << "Enter number of cannibals travelling to side b: ";
        cin >> cannibals;

        if (!(cannibals >= -1 && cannibals <= 2) || !(missionaries >= -1 && missionaries <= 2) || missionaries + cannibals > 2
            || missionaries > side_a[0] || cannibals > side_a[1] || (side_a[0] - missionaries != 0 && side_a[1] - cannibals > side_a[0] - missionaries)
            || (side_b[0] + missionaries != 0 && side_b[1] + cannibals > side_b[0] + missionaries)) {
            cout << "Invalid input!" << endl;
        } else {
            break;
        }
    }

    side_a[0] -= missionaries;
    side_a[1] -= cannibals;
    side_b[0] += missionaries;
    side_b[1] += cannibals;
    is_boat_on_side_a = false;
}

void handle_b_to_a() {
    int missionaries, cannibals;

    while (true) {
        cout << "Enter number of missionaries travelling to side a: ";
        cin >> missionaries;
        cout << "Enter number of cannibals travelling to side a: ";
        cin >> cannibals;

        if (!(cannibals >= -1 && cannibals <= 2) || !(missionaries >= -1 && missionaries <= 2) || missionaries + cannibals > 2
            || missionaries > side_b[0] || cannibals > side_b[1] || (side_b[0] - missionaries != 0 && side_b[1] - cannibals > side_b[0] - missionaries)
            || (side_a[0] + missionaries != 0 && side_a[1] + cannibals > side_a[0] + missionaries)) {
            cout << "Invalid input!" << endl;
        } else {
            break;
        }
    }

    side_b[0] -= missionaries;
    side_b[1] -= cannibals;
    side_a[0] += missionaries;
    side_a[1] += cannibals;
    is_boat_on_side_a = true;
}

int main() {
    while (!is_goal()) {
        print_state();

        if (is_boat_on_side_a) {
            handle_a_to_b();
        } else {
            handle_b_to_a();
        }
    }

    print_state();
    cout << "Goal reached!" << endl;

    return 0;
}
