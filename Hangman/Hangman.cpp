#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    // List of words
    vector<string> wordList = {"python", "programming", "hangman", "developer", "keyboard", "algorithm"};

    // Randomly choose a word
    srand(time(0));
    string word = wordList[rand() % wordList.size()];

    vector<char> guessedLetters;
    int tries = 6;
    string displayWord(word.size(), '_');

    cout << "🎯 Welcome to Hangman!" << endl;
    cout << displayWord << endl;

    while (tries > 0) {
        char guess;
        cout << "\nEnter a letter: ";
        cin >> guess;
        guess = tolower(guess);

        // Validate: already guessed?
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "⚠️ You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Check guess
        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                displayWord[i] = guess;
                correct = true;
            }
        }

        if (correct) {
            cout << "✅ Good guess!" << endl;
        } else {
            tries--;
            cout << "❌ Wrong guess! Tries left: " << tries << endl;
        }

        cout << displayWord << endl;

        // Win condition
        if (displayWord == word) {
            cout << "\n🎉 Congratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    if (tries == 0) {
        cout << "\n💀 Game Over! The word was: " << word << endl;
    }

    return 0;
}
