/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 8 - Functions
 * Description: Tracks the spare fuses in a maintenance cabinet and removes
 *              one fuse when the technician reports using it in a repair.
 * Due Date: October 12, 2026
 */

#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void displayCabinetHeading();                            // Declares a function that needs no data
void reportFuseDecision(char usedFuse);                  // Declares a function that only observes the response
void removeOneFuse(int &fuseCount);                      // Declares a function that updates main's inventory

int main() {                                             // Starts the program
    int fuseCount;                                       // Stores the official number of spare fuses
    char usedFuse;                                       // Stores the technician decision

    displayCabinetHeading();                             // Shows the cabinet heading every time
    cout << "Enter the starting number of spare fuses: "; // Prompts for the initial inventory
    cin >> fuseCount;                                    // Reads the official inventory into main
    cout << "Did you use a fuse during the repair? (Y/N): "; // Prompts for the technician decision
    cin >> usedFuse;                                     // Reads one character response

    reportFuseDecision(usedFuse);                        // Sends a copy of the response to be reported

    if (usedFuse == 'Y' || usedFuse == 'y') {            // Accepts both uppercase and lowercase yes
        removeOneFuse(fuseCount);                        // Sends the original inventory by reference
    } else {                                             // Any other response keeps the inventory
        cout << "Inventory unchanged." << endl;         // Confirms that no fuse was removed
    }                                                    // Ends the if/else decision

    cout << "Spare fuses remaining: " << fuseCount << endl; // Displays the final official inventory

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void displayCabinetHeading() {                           // Defines the heading function
    cout << "===== Maintenance Cabinet: Spare Fuses =====" << endl; // Displays the cabinet title
}                                                        // Ends the heading function

void reportFuseDecision(char usedFuse) {                 // Defines a function that receives the response by value
    if (usedFuse == 'Y' || usedFuse == 'y') {            // Checks for a yes response in either case
        cout << "Decision received: a fuse was used." << endl; // Reports that a fuse was used
    } else {                                             // Handles every other response
        cout << "Decision received: no fuse was used." << endl; // Reports that no fuse was used
    }                                                    // Ends the decision report
}                                                        // Ends the reporting function

void removeOneFuse(int &fuseCount) {                     // Defines a function that changes main's inventory
    if (fuseCount > 0) {                                 // Prevents the inventory from going negative
        fuseCount--;                                     // Removes one fuse from the original variable
        cout << "One fuse removed from the cabinet." << endl; // Confirms the permanent update
    } else {                                             // Handles an empty cabinet
        cout << "Warning: no spare fuses left to remove." << endl; // Explains why nothing changed
    }                                                    // Ends the inventory check
}                                                        // Ends the inventory-update function

/*
 * Analysis:
 * Only removeOneFuse needs &, because it is the only function whose work
 * must survive after it returns: subtracting a fuse has to change the
 * official fuseCount that lives in main. displayCabinetHeading needs no data
 * at all, so it has no parameters. reportFuseDecision only reads the
 * technician's answer to print a message; a copy of the char is enough, and
 * passing it by value guarantees that the function cannot accidentally
 * change main's response. If removeOneFuse received fuseCount by value, it
 * would decrement a local copy and main would still print the original
 * number, so the inventory would never go down.
 */
