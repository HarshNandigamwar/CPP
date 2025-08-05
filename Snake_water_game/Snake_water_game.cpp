#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get computer's choice
char getComputerChoice() {
    int randNum = rand() % 3; // 0, 1, 2
    if (randNum == 0) return 's';
    else if (randNum == 1) return 'w';
    else return 'g';
}

// Function to determine winner
string determineWinner(char user, char computer) {
    if (user == computer) return "It's a Draw!";
    if ((user == 's' && computer == 'w') ||
        (user == 'w' && computer == 'g') ||
        (user == 'g' && computer == 's')) {
        return "You Win!";
    } else {
        return "Computer Wins!";
    }
}

int main() {
    char userChoice, computerChoice;
    srand(time(0)); // Seed random generator

    cout << "Welcome to Snake 🐍 Water 💧 Gun 🔫 Game!\n";
    cout << "Enter 's' for Snake, 'w' for Water, 'g' for Gun: ";
    cin >> userChoice;

    // Validate input
    if (userChoice != 's' && userChoice != 'w' && userChoice != 'g') {
        cout << "Invalid choice! Please run the game again.\n";
        return 0;
    }

    computerChoice = getComputerChoice();

    // Show choices
    cout << "You chose: " << userChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;

    // Show result
    cout << determineWinner(userChoice, computerChoice) << endl;

    return 0;
}
