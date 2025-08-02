#include <iostream>
#include <string>

using namespace std;

struct Question {
    string text;
    string options[4];
    char correctOption;
};

void askQuestion(Question q, int &score) {
    cout << "\n" << q.text << "\n";
    cout << "A. " << q.options[0] << "\n";
    cout << "B. " << q.options[1] << "\n";
    cout << "C. " << q.options[2] << "\n";
    cout << "D. " << q.options[3] << "\n";
    cout << "Your answer (A/B/C/D): ";

    char answer;
    cin >> answer;
    answer = toupper(answer);

    if (answer == q.correctOption) {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Wrong. The correct answer was " << q.correctOption << ".\n";
    }
}

int main() {
    int score = 0;

    Question quiz[3] = {
        {
            "What is the capital of France?",
            {"Berlin", "London", "Paris", "Madrid"},
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            'B'
        },
        {
            "What is 5 + 7?",
            {"10", "11", "12", "13"},
            'C'
        }
    };

    cout << "=== Welcome to the Quiz Game ===\n";

    for (int i = 0; i < 3; i++) {
        askQuestion(quiz[i], score);
    }

    cout << "\nYour final score is: " << score << " out of 3\n";
    cout << "Thanks for playing!\n";

    return 0;
}
