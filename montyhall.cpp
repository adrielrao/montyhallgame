/* A simple implementation of the Monty Hall game.
    By: Adriel Rao
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void generateDoors();
int assignDoorNumbers(int x, int y);
int getUserSelection();
void switchDoors(int &userDoor, int goatDoor);
void checkAnswer(int selectedDoor, int carDoor);


int main() {
    cout << "Inside one of these doors is a car, while the other two contain goats" << endl;

    generateDoors();
    int carDoor = assignDoorNumbers(0, 0); // Sets the car door randomly.
                                           // Having 0 as the parameters makes it return the first generated number (see function).

    cout << "Which door do you pick?" << endl;

    int userSelection = getUserSelection(); // Gets the user selection.
    cout << endl;

    int goatDoor1 = assignDoorNumbers(carDoor, userSelection); // Assign goat door #1.
    int goatDoor2 = assignDoorNumbers(goatDoor1, userSelection); // Assign goat door #2.

    cout << "Door number " << goatDoor1 << " has a goat" << endl;
    cout << "Do you want to switch to door number " << goatDoor2 << "? (y/n)" << endl;

    switchDoors(userSelection, goatDoor2); // Passes in the user selection by reference to change doors if needed.
    cout << endl;
    checkAnswer(userSelection, carDoor); // Resolves the game.
    system("pause");
    return 0;
}

void generateDoors() {
    cout << " _ _ _ " << " _ _ _ " << " _ _ _ " << endl;
    cout << "| 1   |" << "| 2   |" << "| 3   |" << endl;
    cout << "|     |" << "|     |" << "|     |" << endl;
    cout << "|o    |" << "|o    |" << "|o    |" << endl;
    cout << "|     |" << "|     |" << "|     |" << endl;
    cout << "|_ _ _|" << "|_ _ _|" << "|_ _ _|" << endl;
    cout << endl;
}


/* This will assign the goats and car to the specified doors when called.
 * Entering 0 for the parameters will generate a randomly assigned value from 1-3.
 */
int assignDoorNumbers(int x, int y) {
    srand(unsigned(time(0))); // Seed the generator.
    int retVal = x; // Do this so the while loop can instantiate.

    while (retVal == x || retVal == y) {
        retVal = ((rand() % 3)+1); // Set x to be 1-3.
    }
    return retVal;
}

/* Gets the user selection.
 * Use a char for input in case user puts in a letter accidentally.
 */
int getUserSelection() {
    char userSelection;

    while (true) {
        cin >> userSelection;

        if (userSelection == '1') {
            return 1;
        }
        else if (userSelection == '2') {
            return 2;
        }
        else if (userSelection == '3') {
            return 3;
        } else {
            cout << "Please enter '1', '2', or '3'." << endl;
        }
    }
}

void switchDoors(int &userDoor, int goatDoor) {
    char userSwitches;

    while (true) {
        cin >> userSwitches;

        switch (userSwitches) {
            case 'y':
                userDoor = goatDoor;
                return;

            case 'n':
                return;

            default:
                cout << "Please enter 'y' or 'n'." << endl;
        }
    }
}

/* Checks the answer between user input.
 * Ends the game.
 */
void checkAnswer(int selectedDoor, int carDoor) {
    if (selectedDoor == carDoor) {
        cout << "You win the car! :) (door " << carDoor << ")" << endl;
    } else {
        cout << "You win a goat!" << endl;
        cout << "The car was in door " << carDoor << " :(" << endl;
    }
    cout << "Thanks for playing!" << endl;
}
