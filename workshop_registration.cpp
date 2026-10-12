/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 8 - Functions
 * Description: Manages seat registrations and cancellations for a robotics
 *              workshop with a repeating menu that respects seat capacity.
 * Due Date: [Date]
 */

#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void displayMenu();                                      // Declares a function that only produces output
void registerAttendee(int &availableSeats);              // Declares a function that takes one available seat
void cancelRegistration(int &availableSeats, int maxSeats); // Declares a function that returns one seat up to the limit

int main() {                                             // Starts the program
    int maxSeats;                                        // Stores the fixed workshop capacity
    int availableSeats;                                  // Stores the changing number of available seats
    int menuChoice;                                      // Stores one selected menu option

    do {                                                 // Repeats until the capacity is valid
        cout << "Enter the maximum number of seats (1 or more): "; // Prompts for the capacity
        cin >> maxSeats;                                 // Reads the capacity
        if (maxSeats < 1) {                              // Rejects zero or negative capacities
            cout << "Invalid capacity. Try again." << endl; // Explains the rejection
        }                                                // Ends the capacity check
    } while (maxSeats < 1);                              // Stops once the capacity is valid

    availableSeats = maxSeats;                           // Starts the session with every seat open

    do {                                                 // Repeats the menu until the user ends the session
        displayMenu();                                   // Shows the available options
        cin >> menuChoice;                               // Reads one option on each pass

        switch (menuChoice) {                            // Routes the option to its action
            case 1:                                      // Register an attendee
                registerAttendee(availableSeats);        // Sends the original seat count by reference
                break;                                   // Leaves the switch
            case 2:                                      // Cancel a registration
                cancelRegistration(availableSeats, maxSeats); // Sends seats by reference and the limit by value
                break;                                   // Leaves the switch
            case 3:                                      // End the session
                cout << "Session ended." << endl;       // Confirms the exit
                break;                                   // Leaves the switch
            default:                                     // Any other number
                cout << "Invalid option. Choose 1, 2, or 3." << endl; // Reports the invalid choice
        }                                                // Ends the switch

        cout << "Available seats: " << availableSeats << " / " << maxSeats << endl; // Shows the current status
    } while (menuChoice != 3);                           // Ends the loop when the user selects 3

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void displayMenu() {                                     // Defines the menu-display function
    cout << endl;                                        // Adds a blank line before the menu
    cout << "--- Robotics Workshop Registration ---" << endl; // Displays the menu title
    cout << "1. Register an attendee" << endl;          // Displays option 1
    cout << "2. Cancel a registration" << endl;         // Displays option 2
    cout << "3. End session" << endl;                   // Displays option 3
    cout << "Choose an option: ";                       // Prompts for a choice
}                                                        // Ends the menu-display function

void registerAttendee(int &availableSeats) {             // Defines a function that changes main's seat count
    if (availableSeats > 0) {                            // Prevents available seats from going below zero
        availableSeats--;                                // Takes one seat from the original variable
        cout << "Attendee registered." << endl;         // Confirms the registration
    } else {                                             // Handles a full workshop
        cout << "Workshop is full. Registration denied." << endl; // Explains why nothing changed
    }                                                    // Ends the capacity check
}                                                        // Ends the registration function

void cancelRegistration(int &availableSeats, int maxSeats) { // Defines a function that returns a seat
    if (availableSeats < maxSeats) {                     // Prevents available seats from exceeding capacity
        availableSeats++;                                // Returns one seat to the original variable
        cout << "Registration cancelled." << endl;      // Confirms the cancellation
    } else {                                             // Handles a workshop with no registrations
        cout << "No registrations to cancel." << endl;  // Explains why nothing changed
    }                                                    // Ends the capacity check
}                                                        // Ends the cancellation function

/*
 * Test cases:
 * | Capacity | Sequence of options            | Expected final | Observed final |
 * |----------|--------------------------------|----------------|----------------|
 * |    1     | 1, 1, 2, 2, 3                  |       1        |       1        |
 * |          |  (2nd register -> "full",      |                |                |
 * |          |   2nd cancel -> "no regs")     |                |                |
 * |    2     | 1, 2, 3                        |       2        |       2        |
 * |    2     | 7 (invalid), 3                 |  2 + "Invalid  |  2 + "Invalid  |
 * |          |                                |    option"     |    option"     |
 *
 * Analysis:
 * availableSeats is passed by reference to registerAttendee and
 * cancelRegistration because both actions must leave a permanent change in
 * main; with a copy, every registration would be lost as soon as the function
 * returned. maxSeats does not need & because neither function changes the
 * capacity: cancelRegistration only reads it as the upper limit to compare
 * against. Passing it by value gives the function the number it needs and
 * also protects the fixed capacity from being modified by mistake.
 * displayMenu only produces output, so it takes no parameters at all.
 */
