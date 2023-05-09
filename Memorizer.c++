#include <iostream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

// Function to highlight the incorrect parts of the user input
string highlight_mistakes(const string& original, const string& user_input) {
    string highlighted;
    for (int i = 0; i < original.length(); i++) {
        if (i >= user_input.length() || user_input[i] != original[i]) {
            highlighted += "\033[91m"; // ANSI escape sequence for red text
        }
        highlighted += original[i];
        if (i >= user_input.length() || user_input[i] != original[i]) {
            highlighted += "\033[0m"; // ANSI escape sequence to reset text color
        }
    }
    return highlighted;
}

int main() {
    // Accept input from the user
    string writing;
    cout << "Enter the writing to be memorized: ";
    getline(cin, writing);

    // Accept input from the user to start the test
    cout << "Press Enter to start the memorization test...";
    cin.ignore();

    // Number of rounds to test
    const int num_rounds = 5;

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10, 100);

    // Loop through the desired number of rounds
    for (int i = 0; i < num_rounds; i++) {
        // Randomly select a portion of the writing to test on
        int start_index = rand() % writing.length();
        int end_index = start_index + dis(gen);
        string portion = writing.substr(start_index, end_index - start_index);

        // Display the selected portion
        cout << "Round " << i+1 << ": Memorize the following portion:\n" << portion << endl;

        // Accept input from the user for their recollection of the selected portion
        string response;
        cout << "Enter your recollection of the portion: ";
        getline(cin, response);

        // Highlight the incorrect parts of the user's response
        string highlighted = highlight_mistakes(portion, response);

        // Compare the user's response to the original portion and output the result
        if (response == portion) {
            cout << "Correct!" << endl;
        }
        else {
            cout << "Incorrect. The correct response was:\n" << portion << endl;
            cout << "Your response:\n" << highlighted << endl;
        }

        cout << endl; // Add a newline for formatting
    }

    return 0;
}
