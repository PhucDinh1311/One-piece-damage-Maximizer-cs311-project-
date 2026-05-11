#include <iostream>
#include <vector>
#include "DamageMaximizer.h"

using namespace std;

int main() {
    DamageMaximizer game;

    int mana = 80;
    int stamina = 70;
    int turns = 4;

    cout << "One Piece Damage Maximizer" << endl;
    cout << "Mana: " << mana << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Turns: " << turns << endl;

    game.loadActions("actions.csv");

    vector<string> combo;

    game.findBestCombo(
        mana,
        stamina,
        turns,
        0,
        combo
    );

    game.printBestCombo();

    return 0;
}