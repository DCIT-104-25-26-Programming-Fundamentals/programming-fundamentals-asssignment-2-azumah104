// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// =============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// -----------------------------------------------------------------------------
// ARITHMETIC FUNCTIONS
// -----------------------------------------------------------------------------

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

// Returns false if the division could not be performed (division by zero)
bool divide(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Returns false if the modulus could not be performed (division by zero)
bool modulo(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

// -----------------------------------------------------------------------------
// MENU DISPLAY
// -----------------------------------------------------------------------------

void printMenu() {
    cout << "============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}

// -----------------------------------------------------------------------------
// MAIN PROGRAM
// -----------------------------------------------------------------------------

int main() {
    cout << fixed << setprecision(2);

    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cout << "Select an operation (1-7): ";

        // Guard against non-numeric menu input
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!\n";
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please select a number between 1 and 7.\n\n";
            continue;
        }

        double num1, num2, result;

        cout << "Enter first number : ";
        if (!(cin >> num1)) {
            cout << "Invalid number entered.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cout << "Invalid number entered.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n\n";
                break;

            case 2:
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n\n";
                break;

            case 3:
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n\n";
                break;

            case 4:
                if (divide(num1, num2, result)) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n\n";
                } else {
                    cout << "Error: Cannot divide by zero.\n\n";
                }
                break;

            case 5:
                if (modulo(num1, num2, result)) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << "\n\n";
                } else {
                    cout << "Error: Cannot divide by zero.\n\n";
                }
                break;

            case 6:
                result = exponentiate(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << "\n\n";
                break;
        }
    }

    return 0;
}