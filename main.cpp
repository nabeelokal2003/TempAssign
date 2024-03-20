#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

string select_word();
void display_blanks(string &word);
void player_guess(char choice, string &word);
void update_choice(char choice, string &word, int pos);

/*
 * 1. Word selection: Create an array of strings and choose randomly.
 * 2. Blanks Display: Display the underscores with same number of characters.
 * 3. Guess Tracker: Create an integer variable and count the times the player has guessed.
 * 4. Update Display: Each time the player guesses the correct character,
 * an underscore disappears and gets replaced with the correct character.
 * 5. Win\Lose Check: Check if the player has guessed all characters.
 * 6. Ask for another Trial using loop.
 */
int main() {
    string word = "Bed";
    display_blanks(word);
    player_guess('e', word);
    display_blanks(word);
    return 0;
}
string select_word() {
    vector<string> list_words {"Sunshine", "Bicycle", "Adventure", "Symphony", "Pineapple",
                             "Bed", "Electronics", "Jacket", "Wall", "Perfume"};

    srand(time(0));
    int choice = rand() % 10;

    return list_words.at(choice);
}

void display_blanks(string &word){
//    string word = select_word();
    for(int i{0}; i < word.size(); i++) {
        cout << " _ ";
    }
}

void player_guess(char choice, string &word){
    int i;
    for(i = 0; i < word.size(); i++) {
        if (word[i] == choice) {
            cout << "\nCorrect!" << endl;
            update_choice(choice, word, i);
            break;
        }
    }
}

void update_choice(char choice, string &word, int pos){
     word[pos] = choice;
     return word;
}