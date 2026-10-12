/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Johnatanel Perez Lopez
 * Lab: 8 - Functions
 * Description: Demonstrates the difference between pass-by-value and
 *              pass-by-reference using a safety-inspection counter.
 * Due Date: [Date]
 */

#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void showProjectedCount(int completedInspections);       // Declares a value-parameter function
void recordCompletedInspection(int &completedInspections); // Declares a reference-parameter function

int main() {                                             // Starts the program
    int completedInspections;                            // Stores the official completed-inspection count

    cout << "Enter completed inspections: ";           // Prompts for the official count
    cin >> completedInspections;                         // Reads the value stored by main

    showProjectedCount(completedInspections);            // Sends a copied count to the first function
    cout << "After projection: " << completedInspections << endl; // Shows that main kept its count
    recordCompletedInspection(completedInspections);     // Sends the original count by reference
    cout << "After recording: " << completedInspections << endl; // Shows that main now stores the update

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void showProjectedCount(int completedInspections) {      // Defines a function that changes only its local copy
    completedInspections++;                              // Adds one only to the copied parameter
    cout << "Projected count: " << completedInspections << endl; // Displays the possible next count
}                                                        // Ends the value-parameter function

void recordCompletedInspection(int &completedInspections) { // Defines a function that accesses the original variable
    completedInspections++;                              // Changes the official count through the reference
    cout << "Inspection recorded." << endl;             // Confirms the permanent update
}                                                        // Ends the reference-parameter function

/*
 * Prediction (input 4):
 *   Projected count: 5
 *   After projection: 4
 *   After recording: 5
 *
 * Observed output (input 4):
 *   Enter completed inspections: 4
 *   Projected count: 5
 *   After projection: 4
 *   Inspection recorded.
 *   After recording: 5
 *
 * Explanation:
 * showProjectedCount(completedInspections) receives its parameter by value,
 * so the function gets its own copy of the number 4. The increment changes
 * only that local copy (it prints 5), and the copy is destroyed when the
 * function ends. Because main's variable was never touched, the line
 * "After projection" still shows 4.
 *
 * recordCompletedInspection(completedInspections) receives its parameter by
 * reference (int &). The parameter is an alias for main's variable, not a
 * copy, so the increment changes the original official count. After the
 * call returns, main sees the update and "After recording" shows 5.
 *
 * Analysis:
 * The projection must only observe the official count, so pass-by-value is
 * the safe choice: it lets the function experiment with the number without
 * any risk of corrupting the record. Recording an inspection is a permanent
 * change to main's state, so that function needs pass-by-reference. Note
 * that the call syntax is identical for both functions; the & appears only
 * in the prototype and the function header.
 */
