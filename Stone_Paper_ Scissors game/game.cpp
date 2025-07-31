#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Stone";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

// Returns 0 if draw, 1 if player wins, 2 if computer wins
int determineWinner(int player, int computer) {
    if (player == computer) return 0; // draw

    // Stone(1) beats Scissors(3)
    // Scissors(3) beats Paper(2)
    // Paper(2) beats Stone(1)
    if ((player == 1 && computer == 3) ||
        (player == 3 && computer == 2) ||
        (player == 2 && computer == 1)) {
        return 1;
    }

    return 2;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // seed random number generator

    cout << "Welcome to Stone, Paper, Scissors Game!\n";
    cout << "Choices:\n1. Stone\n2. Paper\n3. Scissors\n";

    char playAgain;
    do {
        int playerChoice;
        cout << "\nEnter your choice (1-3): ";
        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please choose 1, 2, or 3.\n";
            continue;
        }

        int computerChoice = (rand() % 3) + 1;

        cout << "You chose: " << getChoiceName(playerChoice) << endl;
        cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0)
            cout << "It's a draw!\n";
        else if (result == 1)
            cout << "You win!\n";
        else
            cout << "Computer wins!\n";

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}
