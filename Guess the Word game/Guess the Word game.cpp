#include <iostream>
#include <string>

using namespace std;

int main() {
    string word = "apple";      // Secret word
    string guessed(word.length(), '_');
    int attempts = 6;
    char guess;

    cout << "Welcome to the Word Guessing Game!\n";
    cout << "Guess the 5-letter word.\n";

    while (attempts > 0 && guessed != word) {
        cout << "\nWord: " << guessed << endl;
        cout << "Attempts left: " << attempts << "\nEnter a letter: ";
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            cout << "Wrong guess!\n";
            attempts--;
        }
    }

    if (guessed == word) {
        cout << "\nCongratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\nGame Over! The word was: " << word << endl;
    }

    return 0;
}
